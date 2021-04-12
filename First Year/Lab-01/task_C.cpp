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

int n, vars;
vector<int> from[27 + 7];
vector<int> to[27 + 7];
vector<int> F[27 + 7];


vector<int> im_val(27 + 7);

int dfs(int v) {
    int mx = 0;
    for (auto u: from[v]) {
        mx = max(mx, dfs(u));
    }

    return mx + (from[v].size() != 0);
}



signed main() {
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        if (!m) {
            ++vars;
        } else {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                from[i].push_back(x);
                to[x].push_back(i);
            }
            for (int j = 0; j < (1 << m); j++) {
                int x;
                cin >> x;
                F[i].push_back(x);
            }
        }
    }

    cout << dfs(n) << endl;

    for (int line = 0; line < (1 << vars); line++) {
        int p = vars - 1;
        for (int i = 1; i <= n; i++) {
            if (from[i].size() == 0) {
                im_val[i] = ((line >> p)&1);
                //cout << "LEAF: " << i << " " << im_val[i] << endl;
                --p;
                continue;
            }
            //cout << "NODE: " << i << endl;
            int num = 0;
            for (auto j: from[i]) {
                num = (num << 1);
                num += im_val[j];
                //cout << im_val[j];
            }
            im_val[i] = F[i][num];
            //cout << endl << im_val[i] << endl;
        }
        //cout << "_EOL_" << endl;
        cout << im_val[n];
    }

    return 0;
}
