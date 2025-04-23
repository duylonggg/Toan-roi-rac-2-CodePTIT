#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n;
short matrixAdj[101][101];
vector<array<int, 2>> bridges;

short BFS(short e1, short e2) {
    bool vis[101] = {}; 
    short tmpCC = 0;  

    for (short u = 1; u <= n; ++u) {
        if (!vis[u]) {
            tmpCC++;
            queue<short> q;
            q.push(u);
            vis[u] = true;

            while (!q.empty()) {
                short nu = q.front();
                q.pop();

                for (short v = 1; v <= n; ++v) {
                    if (matrixAdj[nu][v] && !vis[v]) {
                        if ((nu == e1 && v == e2) || (nu == e2 && v == e1)) 
                            continue; 

                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return tmpCC;
}

int main() {
    fastio()
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    for (short u = 1; u <= n; ++u) 
        for (short v = 1; v <= n; ++v) 
            cin >> matrixAdj[u][v];

    short CC = BFS(-1, -1);

    for (short u = 1; u <= n; ++u) {
        for (short v = u; v <= n; ++v) {
            if (matrixAdj[u][v]) {
                short rmvCC = BFS(u, v);
                if (rmvCC > CC) bridges.push_back({u, v});
            }
        }
    }

    cout << bridges.size() << endl;
    for (auto& [u, v] : bridges) cout << u << ' ' << v << endl;
    return 0;
}