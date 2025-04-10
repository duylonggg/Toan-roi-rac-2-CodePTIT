#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

vector<short> undirAdj[101], dirAdj[101], revAdj[101];
bitset<101> vis;
stack<short> finishStack;
short n, sccCount, undirCC;

void DFS1(short u) {
    vis[u] = 1;
    for (short v : dirAdj[u])
        if (!vis[v]) DFS1(v);
    finishStack.push(u);
}

void DFS2(short u) {
    vis[u] = 1;
    for (short v : revAdj[u])
        if (!vis[v]) DFS2(v);
}

void DFS3(short u) {
    vis[u] = 1;
    for (short v : undirAdj[u])
        if (!vis[v]) DFS3(v);
}

short checkConnectivity() {
    vis.reset();
    for (short u = 1; u <= n; ++u)
        if (!vis[u]) DFS1(u);

    vis.reset();
    while (!finishStack.empty()) {
        short u = finishStack.top();
        finishStack.pop();
        if (!vis[u]) {
            ++sccCount;
            DFS2(u);
        }
    }

    if (sccCount == 1) return 1; 

    vis.reset();
    for (short u = 1; u <= n; ++u)
        if (!vis[u]) {
            ++undirCC;
            DFS3(u);
        }

    return (undirCC == 1) ? 2 : 0; 
}

int main() {
    fastio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    
    cin >> n;

    for (short u = 1; u <= n; ++u) {
        for (short v = 1; v <= n; ++v) {
            bitset<1> bit;
            cin >> bit;
            if (bit.all()) {
                undirAdj[u].push_back(v);
                undirAdj[v].push_back(u);
                dirAdj[u].push_back(v);
                revAdj[v].push_back(u);
            }
        }
    }

    cout << checkConnectivity();
    return 0;
}
