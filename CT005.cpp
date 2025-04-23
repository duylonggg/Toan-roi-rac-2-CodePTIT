#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, m, s, countPath;
set<short> adj[101];
bitset<101> vis;
short HC[101];

inline void checkHamilton(short idx, short u) {
    vis[u] = 1;
    HC[idx] = u;

    if (idx == n) {
        if (adj[u].find(HC[1]) != adj[u].end())
            ++countPath;
        vis[u] = 0;
        return;
    }

    for (short v : adj[u])
        if (!vis[v])
            checkHamilton(idx + 1, v);

    vis[u] = 0;
    return;
}

inline void Hamilton(short idx, short u) {
    vis[u] = 1;
    HC[idx] = u;

    if (idx == n) {
        if (adj[u].find(HC[1]) != adj[u].end()) {
            for (short i = 1; i <= idx; ++i)
                cout << HC[i] << ' ';
            cout << HC[1] << endl;
            vis[u] = 0;
            return;
        }
    }

    for (short v : adj[u])
        if (!vis[v])
            Hamilton(idx + 1, v);

    vis[u] = 0;
    return;
}

signed int main() {
    fastio();
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> n >> m >> s;
    while (m--) {
        short u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }

    checkHamilton(1, s);
    if (!countPath) {
        cout << countPath;
        return 0;
    }

    cout << countPath << endl;
    Hamilton(1, s);
    return 0;
}