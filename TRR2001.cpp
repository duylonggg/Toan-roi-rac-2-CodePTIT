#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, u, v, matrixAdj[101][101], path, parent[101];

void solve1() {
    path = 0;
    for (short x = 1; x <= n; ++x) 
        path += (matrixAdj[u][x] && matrixAdj[x][v]);
    cout << path;
}

void dfs(short node) {
    for (short next = 1; next <= n; ++next) {
        if (matrixAdj[node][next] && parent[next] == -1) { 
            parent[next] = node; 
            dfs(next);
        }
    }
}

void solve2() {
    memset(parent, -1, sizeof(parent));
    parent[u] = 0;  
    dfs(u);

    vector<short> path;
    for (short cur = v; cur != 0; cur = parent[cur]) 
        path.push_back(cur);

    reverse(path.begin(), path.end());

    for (short node : path) 
        cout << node << " ";
}

int main() {
    fastio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    short t;
    cin >> t;

    cin >> n >> u >> v;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            cin >> matrixAdj[u][v];

        }
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}