#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int n, matrixAdj[101][101];

inline void solve1() {
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += !!matrixAdj[i][j];
        cout << deg << ' ';
    }
}

void solve2() {
    short edgeCount = 0;
    for (short i = 1; i < n; ++i)
        for (short j = i + 1; j <= n; ++j)
            edgeCount += !!matrixAdj[i][j];

    cout << n << " " << edgeCount << '\n';
    for (short i = 1; i < n; ++i)
        for (short j = i + 1; j <= n; ++j)
            if (matrixAdj[i][j]) cout << i << " " << j << " " << matrixAdj[i][j] << '\n';
}

int main() {
    fastio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;

    cin >> n;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            cin >> matrixAdj[u][v];
            if (matrixAdj[u][v] == 10000) matrixAdj[u][v] = 0;
        }
    }
    
    (t == 1 ? solve1 : solve2)();
    return 0;
}