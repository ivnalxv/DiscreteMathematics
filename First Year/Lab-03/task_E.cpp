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

    map<string, int> mp;

    int counter = 1;

    for (int i = 0; i < 26; i++) {
        mp[string(1, (char) ('a' + i))] = counter++;
    }

    string t = "";

    for (auto c: s) {
        if (mp[t + c] == 0) {
            cout << mp[t] - 1 << " ";
            mp[t + c] = counter++;
            t = c;
        } else {
            t = t + c;
        }
    }

    cout << mp[t] - 1 << endl;;


    return 0;
}
