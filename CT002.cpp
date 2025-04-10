#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

set<int> adj[101];

void solve1() {
    int n;
    cin >> n;

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int x;
            cin >> x;
            if (x) {
                adj[u].insert(v);
            }
        }
    }

    int odd = 0;
    for (int u = 1; u <= n; ++u)
        odd += (adj[u].size() % 2);

    if (odd == 0) cout << 1;
    else if (odd == 2) cout << 2;
    else cout << 0;
}

void solve2() {
    int n, s, m = 0;
    cin >> n >> s;

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int x;
            cin >> x;
            if (x) {
                ++m;
                adj[u].insert(v);
            }
        }
    }

    stack<int> stk;
    vector<int> path;

    stk.push(s);
    while (!stk.empty()) {
        int u = stk.top();

        if (adj[u].size()) {
            int v = *adj[u].begin();
            stk.push(v);

            adj[u].erase(v);
            adj[v].erase(u);
        } else {
            stk.pop();
            path.push_back(u);
        }
    }

    reverse(path.begin(), path.end());
    for (int u : path) cout << u << ' ';
}

int main() {
    fastio();
    
    int t;
    cin >> t;
    (t == 1 ? solve1 : solve2)();

    return 0;
}