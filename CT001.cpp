#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

vector<int> adj[101];

void DFS(int u, int vis[]) {
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            DFS(v, vis);
}

void solve1() {
    int n, m, vis[101] = {};
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int checkEuler = 0, CC = 0;
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            ++CC;
            DFS(u, vis);
        }
    }

    if (CC == 1) {
        int odd = 0;
        for (int u = 1; u <= n; ++u)
            odd += (adj[u].size() % 2);

        checkEuler = (odd ? 2 : 0);
    }

    cout << checkEuler << endl;
}

void solve2() {
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans;
    vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
    stack<int> stk;

    stk.push(s);
    while (m) {
        int u = stk.top();
        bool flag = false;

        for (int v : adj[u]) {
            if (!vis[u][v]) {
                flag = true;
                stk.push(v);

                vis[u][v] = true;
                vis[v][u] = true;

                --m;
                break;
            }
        }

        if (!flag) {
            ans.push_back(stk.top());
            stk.pop();
        }
    }

    while (!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }

    reverse(ans.begin(), ans.end());
    for (int& num : ans) cout << num << ' ';
}

int main() {
    fastio();
    
    int t;
    cin >> t;
    (t == 1 ? solve1() : solve2());

    return 0;
}