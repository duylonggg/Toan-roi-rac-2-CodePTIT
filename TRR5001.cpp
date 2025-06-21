#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n, s, t;
vector<array<int, 2>> adj[105];
vector<int> dist, path;

void Dijkstra() {
    dist.assign(n + 1, INT_MAX);
    path.assign(n + 1, 0);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [len, u] = pq.top();
        pq.pop();

        if (len > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void Shortest_Path() {
    if (dist[t] == INT_MAX) {
        cout << 0 << endl;
        return;
    }

    cout << dist[t] << endl;

    stack<int> trace;
    while (t != s) {
        trace.push(t);
        t = path[t];
    }
    trace.push(s);

    while (!trace.empty()) {
        cout << trace.top() << ' ';
        trace.pop();
    }
    cout << endl;
}

int main() {
    fastio;
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    
    cin >> n >> s >> t;

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int w;
            cin >> w;
            if (w > 0 and w <= 50)
                adj[u].push_back({v, w});
        }
    }

    Dijkstra();
    Shortest_Path();
    return 0;
}
