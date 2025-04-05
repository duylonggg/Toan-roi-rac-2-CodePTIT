#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int n, m;
short matrixAdj[101][101];

void solve1() {
    for (int u = 1; u <= n; ++u) {
        int in_deg = 0, out_deg = 0;
        for (int v = 1; v <= n; ++v) {
            in_deg += matrixAdj[v][u];
            out_deg += matrixAdj[u][v];
        }
        cout << in_deg << ' ' << out_deg << endl;
    }
}

void solve2() {
    cout << n << endl;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v)
            cout << matrixAdj[u][v] << ' ';
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
        int u, v;
        cin >> u >> v;
        matrixAdj[u][v] = 1;
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}