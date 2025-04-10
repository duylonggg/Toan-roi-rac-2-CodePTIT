#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, start, finish;
vector<short> adj[101];

void solve1() {
    int count = 0;
    for (auto u : adj[start])
        for (auto v : adj[u])
            if (v == finish)
                ++count;
    cout << count;
}

void solve2() {
    int vis[101] = {};
    queue<int> q;
    vis[start] = -1; 
    q.push(start);

    while (!q.empty()) {
        short u = q.front();
        q.pop();

        if (u == finish) break; 

        for (short v : adj[u]) {
            if (!vis[v]) { 
                vis[v] = u; 
                q.push(v);
            }
        }
    }

    if (!vis[finish]) {
        cout << 0; 
        return;
    }

    vector<short> path;
    for (short v = finish; v != -1; v = vis[v])
        path.push_back(v);
    
    reverse(path.begin(), path.end());

    for (short v : path)
        cout << v << " ";
}


int main() {
    fastio();
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

    short t;
    cin >> t;

    cin >> n >> start >> finish;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            short x;
            cin >> x;
            if (x) {
                adj[u].push_back(v);
            }
        }
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}