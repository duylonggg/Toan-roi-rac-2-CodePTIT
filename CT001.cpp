#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

void solve1() {
    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        ++degree[x];
        ++degree[y];
    }

    int oddDeg = count_if(degree.begin(), degree.end(), [](int d) { return d % 2; });

    cout << (oddDeg == 0 ? 1 : (oddDeg == 2 ? 2 : 0));
}

void solve2() {
    int n, m, u;
    cin >> n >> m >> u;

    vector<multiset<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    stack<int> stk;
    vector<int> circuit;
    stk.push(u);
    
    while (!stk.empty()) {
        int v = stk.top();
        if (!graph[v].empty()) {
            int next = *graph[v].begin();
            graph[v].erase(graph[v].begin());
            graph[next].erase(graph[next].find(v));
            stk.push(next);
        } else {
            circuit.push_back(v);
            stk.pop();
        }
    }

    reverse(circuit.begin(), circuit.end());
    for (int v : circuit) cout << v << ' ';
    cout << endl;
}

int main() {
    fastio();
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    
    int t;
    cin >> t;
    (t == 1 ? solve1() : solve2());

    return 0;
}
