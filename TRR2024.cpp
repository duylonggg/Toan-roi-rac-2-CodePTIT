#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

const short MAXN = 100;
short n;
vector<short> adj[MAXN + 1];

short BFS(short skip) {
    vector<bool> vis(n + 1, false);
    short components = 0;

    for (short i = 1; i <= n; ++i) {
        if (i == skip || vis[i]) continue;

        queue<short> q;
        q.push(i);
        vis[i] = true;
        components++;

        while (!q.empty()) {
            short u = q.front(); q.pop();
            for (short v : adj[u]) {
                if (v != skip && !vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return components;
}

int main() {
    fastio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (short i = 1; i <= n; ++i) {
        for (short j = 1; j <= n; ++j) {
            short x; cin >> x;
            if (x) adj[i].push_back(j);
        }
    }

    short initial_components = BFS(-1);
    vector<short> articulation_poshorts;

    for (short i = 1; i <= n; ++i) {
        if (BFS(i) > initial_components) {
            articulation_poshorts.push_back(i);
        }
    }

    cout << articulation_poshorts.size() << endl;
    for (short v : articulation_poshorts) cout << v << " ";
    return 0;
}
