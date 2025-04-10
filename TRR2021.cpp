#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n;
vector<short> adj[101];
short num[101], low[101], timeDFS;
bool joint[101], vis[101];

void DFS(short u, short par) {
    num[u] = low[u] = ++timeDFS;
    vis[u] = true;
    short child = 0;

    for (short v : adj[u]) {
        if (!vis[v]) {
            DFS(v, u);

            low[u] = min(low[u], low[v]); 
            ++child;

            if (par == -1) {
                if (child > 1) joint[u] = true;
            } else if (low[v] >= num[u]) {
                joint[u] = true;
            }
        } else if (v != par) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    fastio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            bitset<1> bit;
            cin >> bit;
            if (bit.all()) adj[u].push_back(v);
        }
    }

    for (short i = 1; i <= n; ++i) {
        if (!vis[i]) DFS(i, -1);
    }

    vector<short> ans;
    for (short i = 1; i <= n; ++i) {
        if (joint[i]) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (short x : ans) cout << x << ' ';
    cout << endl;

    return 0;
}
