#include <stack>

template <class T>
class MinStack {
private:
    std::stack<pair<T, T>> st;

public:
    T min() const;

    void push(T t);
    T top() const;
    void pop();

    int size();
    bool empty();
};

template <class T>
inline T MinStack<T>::min() const {
    return st.top().second;
}

template <class T>
void MinStack<T>::push(T t) {
    st.push({t, std::min(t, min())});
}

template <class T>
inline T MinStack<T>::top() const {
    return st.top().first;
}

template <class T>
inline void MinStack<T>::pop() {
    st.pop();
}

template <class T>
inline int MinStack<T>::size() {
    return st.size();
}

template <class T>
inline bool MinStack<T>::empty() {
    return st.empty();
}
