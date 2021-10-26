/**
 * Competitive Programming Snippet with test cases and modulo arithmetic
 * 
 * In some questions, we have to perform modulo arithmetic
 * with factorials, exponents or PnC.
 * The base for the modulo operations is usually 1'000'000'007 or 998'244'353.
 * 
 * The solution is usually entirely in the solve() function.
 */

#include <bits/stdc++.h>

#define MOD 1'000'000'007 // 998'244'353
#define fi(n) for (int i = 0; i < n; ++i)
#define fj(n) for (int j = 0; j < n; ++j)

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpi = vector<pii>;

vi fact(500'001);
ll power(ll base, ll exp);
ll invM(ll a);
ll nPr(int n, int r);
ll nCr(int n, int r);

void solve() {
    int n;
    cin >> n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    fi(fact.size() - 1) fact[i + 1] = (ll)(i + 1) * fact[i] % MOD;
    int tc;
    cin >> tc;
    fi(tc) solve();
    return 0;
}

ll power(ll a, ll b) {
    ll c = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2 == 1) c = c * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return c;
}

ll invM(ll a) { return power(a, MOD - 2); }
ll nPr(int n, int r) { return (n < r) ? 0 : fact[n] * invM(fact[n - r]) % MOD; }
ll nCr(int n, int r) { return (n < r) ? 0 : fact[n] * invM(fact[r]) % MOD * invM(fact[n - r]) % MOD; }