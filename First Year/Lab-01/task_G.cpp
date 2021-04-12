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
const int SZ = 31;

int n, s;

int F[1024 + 7];
int a[5 + 7];
vector<string> sdnf;



void out(int x, int size) {
    string bits = "";
    for (int i = 0; i < size; i++) {
        if (x&1LL) bits += "1";
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
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;


    if (s == 0LL) {
        cout << "1&~1" << endl;
        return 0;
    }


    //for (int i = 0; i < n; i++) out(a[i], SZ);
    //cout << endl;
    //out(s, SZ);

    for (int i = 0; i < (1LL << n); i++) {
        F[i] = -1LL;
    }

    int ans = 0LL;

    for (int i = SZ - 1LL; i >= 0; i--) {
        int line = 0, f = ((s >> i)&1LL);

        for (int j = 0; j < n; j++) {
            int bit = ((a[j] >> i)&1LL);
            line = (line << 1LL) + bit;
        }
        if (F[line] == -1LL || F[line] == f) {
            F[line] = f;
        } else {
            cout << "Impossible" << endl;
            return 0;
        }

        if (f == 1LL) {
            int temp = -(1LL);
            string con = "";
            //cout << "ONE: " << i << endl;
            for (int j = n - 1; j >= 0; j--) {
                int bit = ((line >> j)&1LL);
                if (!bit) {
                    con += "~";
                    temp &= (~a[n - j - 1]);
                } else {
                    temp &= (a[n - j - 1]);
                }
                con += to_string(n - j);
                if (j) con += "&";
            }
            sdnf.push_back(con);
            ans |= temp;
            //cout << "TEMP: " << temp << endl;
        }
    }

    if (s != ans) {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 0; i < sdnf.size(); i++) {
        if (i) cout << "|";
        cout << '(' <<  sdnf[i] << ')';
    }





    return 0;
}
