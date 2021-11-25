#ifndef SEGMENT_TREE_HPP
#define SEGMENT_TREE_HPP

#include <vector>

template <class T>
class SegmentTree {
private:
    std::vector<T> tree;
    int size;
    T (*merge)(T, T);

public:
    SegmentTree(const std::vector<T> &arr, T (*f)(T, T))
        : tree(4 * arr.size()), size(arr.size()), merge(f) {
        build(arr, 0, 0, size - 1);
    }

    void build(const std::vector<T> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    T query(int start, int end) {
        return query(0, 0, size - 1, start, end);
    }

    T query(int node, int start, int end, int left, int right) {
        if (start == left && end == right) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        if (mid > right) {
            return query(2 * node + 1, start, mid, left, right);
        } else if (mid < left) {
            return query(2 * node + 2, mid + 1, end, left, right);
        } else {
            return merge(query(2 * node + 1, start, mid, left, mid),
                         query(2 * node + 2, mid + 1, end, mid + 1, right));
        }
    }

    void update(int pos, T val) {
        update(0, 0, size - 1, pos, val);
    }

    void update(int node, int start, int end, int pos, T val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if (pos <= mid) {
            update(2 * node + 1, start, mid, pos, val);
        } else {
            update(2 * node + 2, mid + 1, end, pos, val);
        }

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
};

#endif /* SEGMENT_TREE_HPP */
