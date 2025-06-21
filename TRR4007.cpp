#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int n, m, cost;
vector<array<int, 3>> edges, MST;
vector<int> par, siz;

void make_set() {
    par.resize(n + 1);
    siz.resize(n + 1);
    
    for (int u = 1; u <= n; ++u) {
        par[u] = u;
        siz[u] = 1;
    }
}

int find_par(int u) {
    if (u == par[u])
        return u;
    return par[u] = find_par(par[u]);
}

bool unite(int u, int v) {
    u = find_par(u);
    v = find_par(v);

    if (u == v) return false;

    if (u < v) swap(u, v);
    par[v] = u;
    siz[u] += siz[v];
    
    return true;
}

void Kruskal() {
    make_set();

    sort(edges.begin(), edges.end());

    for (auto [w, u, v] : edges) {
        if (unite(u, v)) {
            cost += w;
            MST.push_back({min(u, v), max(u, v), w});
        }
    }
}

void Spanning_Tree() {
    int SC = 0;
    for (int u = 1; u <= n; ++u) 
        if (par[u] == u)
            ++SC;

    if (SC != 1) {
        cout << 0 << endl;
        return;
    }

    cout << cost << endl;
    for (auto [u, v, w] : MST)
        cout << u << " " << v << " " << w << endl;
}

int main() {
    fastio;
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> n >> m;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({w, u, v});
        edges.push_back({w, v, u});
    }

    Kruskal();
    Spanning_Tree();
    return 0;
}