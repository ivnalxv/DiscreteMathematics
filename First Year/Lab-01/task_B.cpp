#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define int long long
#define pb push_back
#define F first
#define S second

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e11;
const int mod = 1e9 + 7;

int f[1024 + 7];
int cnt[5];

bool is_saving_zero(int n) {
    return !f[0];
}

bool is_saving_one(int n) {
    return f[(1 << n) - 1];
}

bool is_self_dual(int n) {
    for (int i = 0; i < (1 << n); ++i) {
        if (f[i] == f[(1 << n) - i - 1]) {
            return 0;
        }
    }
    return 1;
}

bool is_monotonic(int n) {
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = i; j >= 0; j = (i & (j - 1))) {
            if (f[j] > f[i]) return 0;
            if (!j) break;
        }
    }
    return 1;
}

bool is_linear(int n) {
    for (int i = 0; i < (1 << (n + 1)); i++) {
        int okay = i;
        for (int j = 0; j < (1 << n); j++) {
            int line = (j&i), XOR = ((i >> n) & 1);
            for (int k = 0; k < n; k++) {
                XOR ^= ( (line >> k) & 1 );
            }
            if (XOR != f[j]) {
                okay = -1;
                break;
            }
        }

        if (okay != -1) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    fast;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        for (int j = 0, en = (1 << m); j < en; j++) {
            char c;
            cin >> c;
            f[j] = (c != '0');
        }


        cnt[0] += is_saving_zero(m);
        cnt[1] += is_saving_one(m);
        cnt[2] += is_self_dual(m);
        cnt[3] += is_monotonic(m);
        cnt[4] += is_linear(m);
    }

    for (int i = 0; i < 5; i++) {
        if (cnt[i] == n) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;


    return 0;
}
