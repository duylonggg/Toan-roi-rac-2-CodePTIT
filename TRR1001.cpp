#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short t, n, matrixAdj[101][101], edges;

inline void solve1() {
    for (short u = 1; u <= n; ++u) {
        short deg = 0;
        for (short v = 1; v <= n; ++v)
            deg += matrixAdj[u][v];
        cout << deg << ' ';
    }
}

inline void solve2() {
    cout << n << ' ' << (edges >> 1) << endl;

    for (short u = 1; u <= n; ++u)
        for (int v = u; v <= n; ++v)
            (matrixAdj[u][v] and (cout << u << ' ' << v << endl));
}

int main() {
    fastio()
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    cin >> t >> n;

    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            cin >> matrixAdj[u][v];
            edges += matrixAdj[u][v];
        }
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}