#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, matrixAdj[101][101], edges;

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
    cout << n << ' ' << edges << endl;
    for (int u = 1; u <= n; ++u) 
        for (int v = 1; v <= n; ++v) 
            (matrixAdj[u][v]) && (cout << u << ' ' << v << ' ' << matrixAdj[u][v] << endl); 
}

int main() {
    fastio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    short t;
    cin >> t;

    cin >> n;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            cin >> matrixAdj[u][v];
            if (matrixAdj[u][v] == 10000) matrixAdj[u][v] &= 0x00;
            edges += !!matrixAdj[u][v];
        }
    }
    
    (t == 1 ? solve1 : solve2)();
    return 0;
}