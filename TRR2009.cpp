#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short CC;
vector<short> adj[101];
bitset<101> vis;
vector<short> res[101];

void DFS(int u) {
    vis[u] = 1;
    res[CC].push_back(u);

    for (int v : adj[u])
        if (!vis[v])
            DFS(v);
}

signed main() {
    fastio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    short n;
    cin >> n;

    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            bitset<1> x;
            cin >> x;
            if (x.all()) adj[u].push_back(v);      
        } 
    }

    for (short u = 1; u <= n; ++u) {
        if (!vis[u]) {
            DFS(u);
            ++CC;
        }
    }

    cout << CC << endl;
    for (short i = 0; i < CC; ++i) {
        sort(res[i].begin(), res[i].end());
        for (short node : res[i]) cout << node << ' ';
        cout << endl;
    }
    return 0;
}