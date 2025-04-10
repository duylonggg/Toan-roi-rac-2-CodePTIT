#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

short n, s, countPath;
set<short> adj[101];
bool vis[101];
short HC[101];

void checkHamilton(short idx, short u) {
    vis[u] = true;
    HC[idx] = u;

    if (idx == n) {
        if (adj[u].find(HC[1]) != adj[u].end()) {
            ++countPath;
        }
        vis[u] = false; 
        return;
    }

    for (auto v : adj[u]) 
        if (!vis[v]) 
            checkHamilton(idx + 1, v);

    vis[u] = false; 
}

void Hamilton(short idx, short u) {
    vis[u] = true;
    HC[idx] = u;

    if (idx == n) {
        if (adj[u].find(HC[1]) != adj[u].end()) {
            for (short i = 1; i <= n; ++i)
                cout << HC[i] << ' ';
            cout << HC[1] << endl;
        }
        vis[u] = false; 
        return;
    }

    for (short v : adj[u]) 
        if (!vis[v]) 
            Hamilton(idx + 1, v);

    vis[u] = false; 
}

int main() {
    fastio();

    cin >> n >> s;
    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            short x;
            cin >> x;
            if (x) adj[u].insert(v);
        }
    }

    checkHamilton(1, s);
    if (!countPath) {
        cout << countPath;
        return 0;
    }

    cout << countPath << endl;
    Hamilton(1, s);
    return 0;
}
