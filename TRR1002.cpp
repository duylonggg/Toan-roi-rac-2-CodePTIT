#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short n;
short matrixAdj[101][101];

inline void solve1() {
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += matrixAdj[i][j];
        cout << deg << ' ';
    }
}

inline void solve2() {
    cout << n << endl;

    for (int i = 1; i <= n; ++i) {
        vector<int> adjVer;
        for (int j = 1; j <= n; ++j)
            if (matrixAdj[i][j])
                adjVer.push_back(j);
        
        cout << adjVer.size() << ' ';
        for (auto v : adjVer)
            cout << v << ' ';
        cout << endl;
    }
}

int main() {
    fastio()
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    short t;
    cin >> t;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)    
            cin >> matrixAdj[i][j];

    (t == 1 ? solve1 : solve2)();
    return 0;
}