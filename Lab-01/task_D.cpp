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

int n, m;
int F[1024 + 7];


vector<pair<pair<int, int>, int>> ans;
vector<int> con;
vector<int> ones;

signed main() {
    fast;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int x;
        cin >> x >> x;
        if (x) {
            ones.push_back(i);
        }
    }

    // 1 - NOT
    // 2 - AND
    // 3 - OR

    if (ones.size() == 0) {
        cout << n + 2 << endl;

        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << n + 1 << " " << 1 << endl;
        return 0;
    }


    cout << 2*n + (n - 1) * ones.size() + ones.size() - 1 << endl;

    for (m = n + 1; m <= 2*n; m++) {
        cout << 1 << " " << m - n << endl;
    }

    //m = 2*n + 1

    for (int k = 0; k < ones.size(); k++) {
        for (int p = n - 1; p >= 0; p--, m++) {
            cout << 2 << " ";
            if (p == n - 1) {
                int bit = ((ones[k] >> p) & 1);
                cout << n*(2 - bit) - p << " ";

                p--;

                bit = ((ones[k] >> p) & 1);
                cout << n*(2 - bit) - p << endl;
            } else {
                int bit = ((ones[k] >> p) & 1);
                cout << n*(2 - bit) - p << " " << m - 1 << endl;
            }
        }
    }

    if (ones.size() == 1) {
        return 0;
    }

    for (int k = 1; k <= ones.size(); k++, m++) {
        int num = 2*n + k*(n - 1);
        if (k == 1) {
            cout << 3 << " " << num << " " << num + n - 1 << endl;
            k++;
        } else {
            cout << 3 << " " << m - 1 << " " << num << endl;
        }

    }

    return 0;
}
