#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int n, m;
short matrixAdj[101][101];

inline void solve1() {
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += matrixAdj[i][j];
        cout << deg << ' ';
    }
}

void solve2() {
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << matrixAdj[i][j] << ' ';
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
        matrixAdj[u][v] = matrixAdj[v][u] = 1;
    }

    (t == 1 ? solve1 : solve2)();

    return 0;
}