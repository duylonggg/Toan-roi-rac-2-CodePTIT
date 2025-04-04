#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int n, m, matrixAdj[101][101];

void solve1() {
    for (int u = 1; u <= n; ++u) {
        int deg = 0;
        for (int v = 1; v <= n; ++v)
            deg += !!matrixAdj[u][v];
        cout << deg << ' ';
    }
}

void solve2() {
    cout << n << endl;
    
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (u == v) cout << 0 << ' ';
            else if (!!matrixAdj[u][v]) cout << matrixAdj[u][v] << ' ';
            else cout << 10000 << ' ';
        }
        cout << endl;
    }
}

int main() {
    fastio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        matrixAdj[u][v] = matrixAdj[v][u] = c;
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}