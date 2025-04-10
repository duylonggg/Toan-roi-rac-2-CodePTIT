#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

const short INF = 10000;
short n, s;
short matrixAdj[101][101], hamilton[101];
vector<short> bestPath;
bool vis[101];
int minW = INF;
bool isHamilton = false;

void checkHamilton(short idx, short u) {
    vis[u] = true;
    hamilton[idx] = u;

    if (idx == n) {
        if (matrixAdj[u][hamilton[1]]) 
            isHamilton = true;
        vis[u] = false; 
        return;
    }

    for (short v = 1; v <= n; ++v) {
        if (!vis[v] and matrixAdj[u][v]) {
            checkHamilton(idx + 1, v);
        }
    }

    vis[u] = false; 
}

void Hamilton(short idx, short u, int sumW) {
    vis[u] = true;
    hamilton[idx] = u;

    if (idx == n) {
        if (matrixAdj[u][hamilton[1]]) {
            int totalWeight = sumW + matrixAdj[u][hamilton[1]];
            if (minW > totalWeight) {
                minW = totalWeight;
                bestPath.assign(hamilton + 1, hamilton + n + 1); 
                bestPath.push_back(hamilton[1]); 
            }
        }
        vis[u] = false; 
        return;
    }

    for (short v = 1; v <= n; ++v) {
        if (!vis[v] and matrixAdj[u][v]) {
            Hamilton(idx + 1, v, sumW + matrixAdj[u][v]);
        }
    }

    vis[u] = false; 
}

int main() {
    fastio();

    cin >> n >> s;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            cin >> matrixAdj[u][v];
            if (matrixAdj[u][v] == INF) matrixAdj[u][v] = 0;
        }
    }

    checkHamilton(1, s);
    if (!isHamilton) {
        cout << 0;
        return 0;
    }

    Hamilton(1, s, 0);
    cout << minW << endl;
    for (short node : bestPath) 
        cout << node << " ";

    return 0;
}
