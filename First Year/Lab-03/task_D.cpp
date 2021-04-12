#include <bits/stdc++.h>
#define file freopen("lrsigma.in", "r", stdin); freopen("lrsigma.out", "w", stdout);
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e11;
const int mod = 1e9 + 7;



signed main() {
    fast;
    int n;
    string s;
    cin >> s;
    n = s.size();

    vector<char> arr(26);

    for (int i = 0; i < 26; i++) {
        arr[i] = (char) ('a' + i);
    }

    for (auto c: s) {
        int spot = 0;
        for (int i = 0; i < 26; i++) {
            if (arr[i] == c) {
                spot = i;
                break;
            }
        }

        cout << spot + 1 << " ";

        for (int i = spot - 1; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }

        arr[0] = c;
    }


    return 0;
}
