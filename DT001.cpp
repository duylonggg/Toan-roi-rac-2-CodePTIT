#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

short n, matrixAdj[105][105];

void solve1() {
	for (short i = 1; i <= n; ++i) {
		short deg = 0;
		for (short j = 1; j <= n; ++j) 
			deg += matrixAdj[i][j];
		cout << deg << " ";
	}
	cout << '\n';
}

void solve2() {
	vector<pair<short, short>> edge;

	for (short i = 1; i < n; ++i) 
		for (short j = i + 1; j <= n; ++j) 
			if (matrixAdj[i][j]) edge.emplace_back(i, j);

	cout << n << " " << edge.size() << '\n';
	for (auto &[u, v] : edge)
		cout << u << " " << v << '\n';
}

int main() {
	fastio();

	short t;
	cin >> t >> n;
	for (short i = 1; i <= n; ++i) 
		for (short j = 1; j <= n; ++j)
			cin >> matrixAdj[i][j];
	
	(t == 1 ? solve1 : solve2)();

	return 0;
}