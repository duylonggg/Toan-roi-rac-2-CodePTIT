#include <iostream>
#include <vector>
using namespace std;

int n, m, u;
vector<int> a[105];
int visited[105];
vector<int> path;
vector<vector<int>> res;

void Try(int cur, int cnt) {
    if (cnt == n) {
        for (const int& v : a[cur]) {
            if (v == u) {
                path.emplace_back(u);
                res.emplace_back(path);
                path.pop_back();
                break;
            }
        }
        return;
    }

    for (const int& v : a[cur]) {
        if (!visited[v]) {
            visited[v] = 1;
            path.emplace_back(v);
            Try(v, cnt + 1);
            path.pop_back();
            visited[v] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("CT.INP", "r", stdin);
	//freopen("CT.OUT", "w", stdout);

    cin >> n >> m >> u;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }

    visited[u] = 1;
    path.emplace_back(u);
    Try(u, 1);

    cout << res.size() << '\n';
    for (const auto& cycle : res) {
        for (int v : cycle)
            cout << v << ' ';
        cout << '\n';
    }
    return 0;
}