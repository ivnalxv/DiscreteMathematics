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

struct node {
    node *left = nullptr, *right = nullptr;
    long long size;
    int num = -1;
    char bit;

    node() {}

    node(long long sz) {
        size = sz;
    }

    node(long long sz, int b) {
        size = sz;
        num = b;
    }
};

struct lex_compare {
    bool operator() (node *l, node *r) const {
        if (l->size == r->size) {
            return l->num < r->num;
        }
        return l->size < r->size;
    }
};


int n;
set<node*, lex_compare> srt;
vector<int> len;

void dfs(node* v, int sum) {
    if (v->num < n) {
        len[v->num] = sum;
        return;
    }
    dfs(v->left, sum + 1);
    dfs(v->right, sum + 1);
}

signed main() {
    fast;
    cin >> n;
    vector<int> p(n);
    len = vector<int> (n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(all(p));

    for (int i = 0; i < n; i++) {
        srt.insert(new node(p[i], i));
    }

    int counter = n;

    while (srt.size() != 1) {
        node *newNode = new node();

        newNode->left = *(srt.begin());
        newNode->left->bit = '0';
        srt.erase(newNode->left);

        newNode->right = *(srt.begin());
        newNode->right->bit = '1';
        srt.erase(newNode->right);

        newNode->size = newNode->left->size + newNode->right->size;
        newNode->num = counter++;

        srt.insert(newNode);
    }

    node *root = *(srt.begin());

    dfs(root, 0);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ((long long) len[i]) * ((long long) p[i]);
    }

    cout << ans << endl;

    return 0;
}
