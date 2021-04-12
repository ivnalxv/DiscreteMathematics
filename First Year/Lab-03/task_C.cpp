#include <bits/stdc++.h>
#define fast cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

using namespace std;

int main() {
    fast;
    int n, x = 0;
    string s;
    cin >> s;
    n = s.size();

    vector<string> srt;
    for (int i = 0; i < n; i++) {
        srt.push_back(s.substr(i) + s.substr(0, i));
    }

    sort(all(srt));

    for (int i = 0; i < n; i++) {
        if (s == srt[i]) {
            x = i;
            break;
        }
    }

    vector<int> cnt(32, 0);

    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        cnt[c]++;
    }

    int temp = 0;
    for (int i = 0; i < 32; i++) {
        temp += cnt[i];
        cnt[i] = temp - cnt[i];
    }

    vector<int> t(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int c = (int) (s[i] - 'a');
        t[cnt[c]] = i;
        cnt[c]++;
    }

    string res = "";
    int j = t[x];
    for (int i = 0; i < n; i++) {
        res = res + s[j];
        j = t[j];
    }

    srt.clear();

    for (int i = 0; i < n; i++) {
        srt.push_back(res.substr(i) + res.substr(0, i));
    }

    sort(all(srt));

    cout << srt[0] << endl;

    return 0;
}