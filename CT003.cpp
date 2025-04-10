#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, s;
set<short> adj[101];

inline void solve1() {
    cin >> n;

    for (short u = 1; u <= n; ++u) {
        string str;
        getline(cin >> ws, str);
        stringstream ss(str);
        string v;
        ss >> v;
        while (ss >> v) {
            adj[u].insert(stoi(v));
        }
    }

    short inDeg[n + 1] = {}, outDeg[n + 1] = {};
    for (short i = 1; i <= n; ++i) outDeg[i] = (short) adj[i].size();
    for (short u = 1; u <= n; ++u)
        for (auto v : adj[u])
            ++inDeg[v];

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (abs(inDeg[i] - outDeg[i]) > 1) ++cnt1;
        if (abs(inDeg[i] - outDeg[i]) == 1) ++cnt2;
    }

    if (cnt1) cout << 0;
    else if (cnt2 == 2) cout << 2;
    else cout << 1;
}

inline void solve2() {
    cin >> n >> s;

    for (short u = 1; u <= n; ++u) {
        string str;
        getline(cin >> ws, str);
        stringstream ss(str);
        string v;
        ss >> v;
        while (ss >> v) {
            adj[u].insert(stoi(v));
        }
    }

    stack<short> stk;
    vector<short> path;

    stk.push(s);
    while (!stk.empty()) {
        short u = stk.top();

        if (adj[u].size()) {
            short v = *adj[u].begin();

            adj[u].erase(v);
            adj[v].erase(u);

            stk.push(v);
        } else {
            stk.pop();
            path.push_back(u);
        }
    }

    reverse(path.begin(), path.end());
    for (short u : path) cout << u << ' ';
}

signed main() {
    fastio();

    short t;
    cin >> t;

    (t == 1 ? solve1 : solve2)();
    return 0;
}