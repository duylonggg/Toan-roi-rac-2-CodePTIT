#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n, s, t;
vector<array<int, 3>> edges;
vector<int> dist, path;
bool negaCycle;

void BellmanFord() {
    dist.assign(n + 1, INT_MAX);
    path.assign(n + 1, 0);
    dist[s] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    negaCycle = false;
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
            negaCycle = true;
            break;
        }
    }
}

void Shortest_Path() {
    if (dist[t] == INT_MAX) {
        cout << 0 << endl;
        return;
    }

    if (negaCycle) {
        cout << -1 << endl;
        return;
    }

    cout << dist[t] << endl;

    stack<int> trace;
    int u = t;
    while (u != s) {
        trace.push(u);
        u = path[u];
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
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int w;
            cin >> w;

            if (w >= -50 and w <= 50)
                edges.push_back({u, v, w});
        }
    }

    BellmanFord();
    Shortest_Path();
    return 0;
}
