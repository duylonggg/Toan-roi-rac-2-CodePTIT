#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, matrixAdj[101][101];

inline void solve1() {
    for (int u = 1; u <= n; ++u) {
        int deg = 0;
        for (int v = 1; v <= n; ++v)
            deg += matrixAdj[u][v];
        cout << deg << ' ';
    }
}

void solve2() {
    short edgeCount = 0;
    for (short i = 1; i < n; ++i)
        for (short j = i + 1; j <= n; ++j)
            edgeCount += matrixAdj[i][j];

    cout << n << " " << edgeCount << '\n';
    for (short i = 1; i < n; ++i)
        for (short j = i + 1; j <= n; ++j)
            if (matrixAdj[i][j]) cout << i << " " << j << '\n';
}

int main() {
    fastio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t;
    cin >> t;

    cin >> n;
    for (int u = 1; u <= n; ++u) {
        string str, ver;
        getline(cin >> ws, str);
        stringstream ss(str);
        ss >> ver;
        while (ss >> ver) {
            int v = stoi(ver);
            matrixAdj[u][v] = matrixAdj[v][u] = 1;
        }
    }

    (t == 1 ? solve1 : solve2)();
    return 0;
}