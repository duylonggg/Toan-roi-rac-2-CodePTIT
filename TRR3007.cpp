#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

short n, s, countPath = 0;
bool adj[101][101], vis[101];
short path[101];

void Hamilton(short idx, short u) {
    path[idx] = u;
    vis[u] = true;

    if (idx == n) {
        if (adj[u][s]) {
            ++countPath;
            for (short i = 1; i <= n; ++i)
                cout << path[i] << ' ';
            cout << s << endl;
        }
        vis[u] = false;
        return;
    }

    for (short v = 1; v <= n; ++v) {
        if (!vis[v] && adj[u][v]) {
            Hamilton(idx + 1, v);
        }
    }

    vis[u] = false;
}

int main() {
    fastio();
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    cin >> n >> s;

    for (short i = 1; i <= n; ++i)
        for (short j = 1; j <= n; ++j)
            cin >> adj[i][j];

    Hamilton(1, s);
    cout << countPath;

    return 0;
}
