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

int n, k;
int con[100 + 7][100 + 7];
int u[100 + 7];

int ans[100 + 7];


signed main() {
    fast;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> con[i][j];
        }
    }

    for (int i = 0; i < n; i++ ) {
        ans[i] = -1;
    }

    for (int en = 0; en < k; en++) {
        for (int i = 0; i < k; i++) {
            int not_done = 0;
            for (int j = 0; j < n; j++) {
                if (con[i][j] == -1) continue;
                if (ans[j] == -1) {
                    not_done++;
                }
            }


            int alone = -1, good = 0;
            for (int j = 0; j < n; j++) {
                if (con[i][j] == -1) continue;
                if (ans[j] == -1) {
                    alone = j;
                }
                if (con[i][j] == ans[j]) {
                    good = 1;
                }
            }

            if (good) continue;

            if (not_done == 1) {
                ans[alone] = con[i][alone];
            }

            if (!not_done) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
