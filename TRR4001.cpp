#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int n, s;
vector<int> adj[105];
vector<pair<int, int>> ST;
bitset<105> vis;

void input() {
    cin >> n >> s;
    
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            int x;
            cin >> x;

            if (x == 1) adj[u].push_back(v);
        }
    }
}

void DFS(int u) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            ST.push_back({min(u, v), max(u, v)});
            DFS(v);
        }
    }
}

void BFS(int u) {
    vis[u] = 1;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                ST.push_back({min(u, v), max(u, v)});
                q.push(v);
            }
        }
    }
}

void Spanning_Tree() {
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            cout << 0;
            return;
        }
    }

    cout << ST.size() << endl;
    for (auto [u, v] : ST) 
        cout << u << " " << v << endl;
}

void solve1() {
    DFS(s);
    Spanning_Tree();
}

void solve2() {
    BFS(s);
    Spanning_Tree();
}

int main() {
    fastio;
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int t;
    cin >> t;

    input();

    (t == 1 ? solve1 : solve2) ();
    
    return 0;
}