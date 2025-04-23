#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, s;
set<short> adj[101];
bitset<101> vis;

inline void DFS(short u) {
    vis[u] = true;

    for (short v : adj[u])
        if (!vis[v])
            DFS(v);
}

inline void solve1() {
    cin >> n;
    
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            bitset<1> x;
            cin >> x;
            if (x.all()) adj[u].insert(v);
        }
    }

    short CC = 0;
    for (short u = 1; u <= n; ++u) {
        if (!vis[u]) {
            ++CC;
            DFS(u);
        }
    }

    if (CC > 1) {
        cout << 0;
        return;
    }
    
    short inDeg[n + 1] = {}, outDeg[n + 1] = {};
    for (short u = 1; u <= n; ++u) {
        outDeg[u] = adj[u].size();
        for (short v : adj[u])
            ++inDeg[v];
    }

    short cnt1 = 0, cnt2 = 0;
    for (short u = 1; u <= n; ++u) {
        if (abs(inDeg[u] - outDeg[u]) > 1) ++cnt1;
        else if (abs(inDeg[u] - outDeg[u]) == 1) ++cnt2;
    }

    if (cnt1) cout << 0;
    else if (cnt2 == 2) cout << 2;
    else cout << 1;
}

inline void solve2() {
    cin >> n >> s;
    
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            bitset<1> x;
            cin >> x;
            if (x.all()) adj[u].insert(v);
        }
    }

    stack<short> stk;
    vector<short> res;
    
    stk.push(s);
    while (!stk.empty()) {
        short u = stk.top();

        if (adj[u].size()) {
            short v = *adj[u].begin();

            adj[u].erase(v);

            stk.push(v);
        } else {
            stk.pop();
            res.push_back(u);
        }
    }

    reverse(res.begin(), res.end());
    for (short node : res) cout << node << ' ';
}

int main() {
    fastio();
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    short t;
    cin >> t;

    (t == 1 ? solve1 : solve2)();
    return 0;
}