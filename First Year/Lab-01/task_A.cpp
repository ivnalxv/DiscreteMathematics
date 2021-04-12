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

int a[100 + 7][100 + 7];
int b[100 + 7][100 + 7];
int c[100 + 7][100 + 7];


int ans_a[5];
int ans_b[5];


signed main() {
    fast;
    int n, refl, antirefl, symm, antisymm, trans;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    refl = 1;
    for (int i = 0; i < n; i++) {
        if (!a[i][i]) {
            refl = 0;
            break;
        }
    }
    ans_a[0] = refl;

    antirefl = 1;
    for (int i = 0; i < n; i++) {
        if (a[i][i]) {
            antirefl = 0;
            break;
        }
    }
    ans_a[1] = antirefl;

    symm = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] && !a[j][i]) {
                symm = 0;
                break;
            }
        }
        if (!symm) {
            break;
        }
    }
    ans_a[2] = symm;

    antisymm = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] && a[j][i] && i != j) {
                antisymm = 0;
                break;
            }
        }
        if (!antisymm) {
            break;
        }
    }
    ans_a[3] = antisymm;

    trans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (a[j][k] && !a[i][k]) {
                        trans = 0;
                        break;
                    }
                }
            }
            if (!trans) {
                break;
            }
        }
        if (!trans) {
            break;
        }
    }
    ans_a[4] = trans;


    refl = 1;
    for (int i = 0; i < n; i++) {
        if (!b[i][i]) {
            refl = 0;
            break;
        }
    }
    ans_b[0] = refl;

    antirefl = 1;
    for (int i = 0; i < n; i++) {
        if (b[i][i]) {
            antirefl = 0;
            break;
        }
    }
    ans_b[1] = antirefl;

    symm = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] && !b[j][i]) {
                symm = 0;
                break;
            }
        }
        if (!symm) {
            break;
        }
    }
    ans_b[2] = symm;

    antisymm = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] && b[j][i] && i != j) {
                antisymm = 0;
                break;
            }
        }
        if (!antisymm) {
            break;
        }
    }
    ans_b[3] = antisymm;

    trans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (b[j][k] && !b[i][k]) {
                        trans = 0;
                        break;
                    }
                }
            }
            if (!trans) {
                break;
            }
        }
        if (!trans) {
            break;
        }
    }
    ans_b[4] = trans;

    cout << ans_a[0] << " " << ans_a[1] << " " << ans_a[2] << " " << ans_a[3] << " " << ans_a[4] << endl;
    cout << ans_b[0] << " " << ans_b[1] << " " << ans_b[2] << " " << ans_b[3] << " " << ans_b[4] << endl;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (b[j][k]) {
                        c[i][k] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
