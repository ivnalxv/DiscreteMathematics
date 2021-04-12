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
const int SZ = 32;

string brackets(string A, string B) {
    return "(" + A + "|" + B + ")";
}

string stroke(int x) {
    string An = "A" + to_string(x);
    string Bn = "B" + to_string(x);

    if (!x) {
        return brackets(brackets(An, Bn), brackets(An, Bn));
    }

    string prev = stroke(x - 1);
    return brackets(brackets(prev, brackets(brackets(An, An), brackets(Bn, Bn))), brackets(An, Bn));
}

signed main() {
    fast;
    int n;
    cin >> n;

    cout << stroke(n - 1);
    return 0;
}
