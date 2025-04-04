#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n, matrixAdj[101][101], edges;

void solve1() {
    for (int u = 1; u <= n; ++u) {
        int out_deg = 0, in_deg = 0;
        for (int v = 1; v <= n; ++v) {
            out_deg += matrixAdj[u][v];
            in_deg  += matrixAdj[v][u]; 
        }
        cout << in_deg << ' ' << out_deg << endl;
    }  
}

void solve2() {
    vector<pair<int, int>> edgeList;
    for (int u = 1; u <= n; ++u) 
        for (int v = 1; v <= n; ++v) 
            if (matrixAdj[u][v]) 
                edgeList.emplace_back(u, v);

    int m = edgeList.size();
    vector<vector<int>> incidenceMatrix(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; ++i) {
        int u = edgeList[i - 1].first, v = edgeList[i - 1].second;
        incidenceMatrix[u][i] = 1;
        incidenceMatrix[v][i] = -1;
    }

    cout << n << " " << m << endl;
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= m; ++v) {
            cout << incidenceMatrix[u][v] << " ";
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

    cin >> n;
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v) {
            cin >> matrixAdj[u][v];
            edges += matrixAdj[u][v];
        }

    (t == 1 ? solve1 : solve2)();
    return 0;
}