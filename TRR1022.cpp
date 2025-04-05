#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int m;
short n, matrixAdj[101][101];

void solve1() {
    for (short u = 1; u <= n; ++u) {
        short in_deg = 0, out_deg = 0;
        for (short v = 1; v <= n; ++v) {
            in_deg += !!matrixAdj[v][u];
            out_deg += !!matrixAdj[u][v];
        }
        cout << in_deg << ' ' << out_deg << endl;
    }
}

void solve2() {
    cout << n << endl;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            if (u == v) cout << 0 << ' ';
            else if (matrixAdj[u][v]) cout << matrixAdj[u][v] << ' ';
            else cout << 10000 << ' ';
        }
        cout << endl;
    }
}

int main() {
    fastio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    short t;
    cin >> t;

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        matrixAdj[u][v] = c;
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}