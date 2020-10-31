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

int sz[1000 + 7];
int f[1000 + 7][1024 + 7];

bool smaller(int a, int b, int size) {
    bool flag = 1;
    for (int i = 0; i < size; i++) {
        if ((a&1) > (b&1)) {
            return 0;
        }
        a = (a >> 1);
        b = (b >> 1);
    }
    return 1;
}

int check(int a, int i, int size) {
    int Xor = 0;
    for(int j = 0; j < size; j++) {
        int bob = ((a >> j)&1) * ((i >> j)&1);
        Xor = (Xor != bob);
    }
    return Xor;
}

signed main() {
    fast;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sz[i];

        for (int j = 0, en = (1 << sz[i]); j < en; j++) {
            char c;
            cin >> c;
            f[i][j] = (c != '0');
        }
    }


    // saving zero
    bool saving_zero = 1;
    for (int i = 0; i < n; i++) {
        if (f[i][0] == 1) {
            saving_zero = 0;
            break;
        }
    }
    if (saving_zero) {
        //cout << "NO saving zero" << endl;
        cout << "NO" << endl;
        return 0;
    }

    // saving one
    bool saving_one = 1;
    for (int i = 0; i < n; i++) {
        if (f[i][(1 << sz[i]) - 1] == 0) {
            saving_one = 0;
            break;
        }
    }
    if (saving_one) {
        //cout << "NO saving one" << endl;
        cout << "NO" << endl;
        return 0;
    }

    // self_dual
    bool self_dual = 1;
    for (int i = 0; i < n; i++) {
        int mx = (1 << sz[i]) - 1;
        for (int j = 0; j < (mx + 1)/2; j++) {
            if (f[i][j] == f[i][mx - j]) {
                self_dual = 0;
                break;
            }
        }
        if (!self_dual) {
            break;
        }
    }
    if (self_dual) {
        //cout << "NO self dual" << endl;
        cout << "NO" << endl;
        return 0;
    }

    // monotonic
    bool monotonic = 1;
    for (int i = 0; i < n; i++) {
        int mx = (1 << sz[i]);
        for (int j = 0; j < mx; j++) {
            for (int k = j + 1; k < mx; k++) {
                if (smaller(j, k, sz[i]) && f[i][j] > f[i][k]) {
                    monotonic = 0;
                    break;
                }
            }
            if (!monotonic) {
                break;
            }
        }
        if (!monotonic) {
            break;
        }
    }
    if (monotonic) {
        //cout << "NO monotonic" << endl;
        cout << "NO" << endl;
        return 0;
    }

    // linear
    bool linear = 1;
    for (int i = 0; i < n; i++) {
        int mx = (1 << sz[i]);
        int found = -1;

        for (int a = 0; a < 2*mx; a++) {
            //int XOR = ((a >> sz[i])&1);
            int XOR = 0;
            found = a;
            for (int j = 0; j < mx; j++) {
                int line = (check(a, j, sz[i]) != XOR);
                if (line != f[i][j]) {
                    found = -1;
                    break;
                }
            }

            if (found != -1) {
                break;
            }
        }

        if (found == -1) {
            linear = 0;
            break;
        }
    }
    if (linear) {
        //cout << "NO linear" << endl;
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    return 0;
}
