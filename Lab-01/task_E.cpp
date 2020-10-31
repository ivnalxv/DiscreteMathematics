#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
//#define int long long
#define pb push_back
#define F first
#define S second

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e11;
const int mod = 1e9 + 7;

int f[1024 + 7][1024 + 7];

signed main() {
    fast;
    int n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            char x; cin >> x;
        }
        cin >> f[0][i];
    }

    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n) - i; j++) {
            f[i][j] = (f[i - 1][j] + f[i - 1][j + 1])%2;
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << ( (i >> j)&1 );
        }
        cout << " " << f[i][0] << endl;
    }


    return 0;
}
