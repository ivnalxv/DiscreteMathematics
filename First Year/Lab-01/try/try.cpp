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

int n, s;

int F[1024 + 7];
int a[5 + 7];
vector<string> sdnf;

void out(int x, int size) {
    string bits = "";
    for (int i = 0; i < size; i++) {
        if (x&1) bits += "1";
        else bits += "0";
        x /= 2;
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << bits[i];
    }
    cout << endl;
}


signed main() {
    fast;
    //~1 & 2 // 1 5 4
    int a = 5, b = 6, c = 8, d = 9;
    cout << ((~a&~b&c&d)|(a&b&~c&~d));

    return 0;
}
