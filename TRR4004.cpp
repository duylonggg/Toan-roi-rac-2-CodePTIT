#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int n, s;
vector<array<int, 2>> adj[105];
bitset<105> inMST;
int cost;
vector<array<int, 3>> MST;

void Prim() {
    inMST[s] = 1;
    priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
    for (auto [v, w] : adj[s]) {
        pq.push({w, s, v});
    }

    while (!pq.empty() && MST.size() < n - 1) {
        auto [w, u, v] = pq.top(); pq.pop();

        if (inMST[v]) continue;
        inMST[v] = 1;

        cost += w;
        MST.push_back({min(u, v), max(u, v), w});

        for (auto [to, wt] : adj[v]) 
            if (!inMST[to])
                pq.push({wt, v, to});
    }
}

void Spanning_Tree() {
    if (MST.size() < n - 1) {
        cout << 0 << '\n';
        return;
    }

    cout << cost << '\n';
    for (auto [u, v, w] : MST)
        cout << u << " " << v << " " << w << '\n';
}

signed main() {
    fastio;
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> s;

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int w;
            cin >> w;
            if (u != v && w <= 50) {
                adj[u].push_back({v, w});
            }
        }
    }    

    Prim();
    Spanning_Tree();
    return 0;
}