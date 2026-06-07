#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<vector<int>> &adj, vector<int> &color, bool &pos) {
		// Early exit if we've already determined it's impossible
		if (!pos) return;
		for (auto y : adj[x]) {
				if (color[y] != -1) {
						// If an edge connects same-colored vertices, the graph is not bipartite
						if (color[y] == color[x]) {
								pos = false;
								return;
						}
						continue;
				}
				// Assign opposite color to the neighbor and continue DFS
				color[y] = 1 - color[x];
				dfs(y, adj, color, pos);
		}
}

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);

		int tc;
		cin >> tc;
		while (tc--) {
				int n;
				cin >> n;

				// For each number v in [1..n], store indices of dominoes where v appears
				vector<vector<int>> doms_for_num(n);
				vector<pair<int, int>> domino(n);

				for (int i = 0; i < n; i++) {
						cin >> domino[i].first >> domino[i].second;
						// Store domino index for both endpoints (1-based to 0-based index)
						doms_for_num[domino[i].first - 1].push_back(i);
						doms_for_num[domino[i].second - 1].push_back(i);
				}

				bool pos = true;
				vector<vector<int>> adj(n);

				for (int v = 0; v < n; v++) {
						// Any number appearing more than twice makes it impossible
						if (doms_for_num[v].size() > 2) {
								pos = false;
								break;
						}
						if (doms_for_num[v].size() == 2) {
								int a = doms_for_num[v][0], b = doms_for_num[v][1];
								// Connect the two dominoes sharing number v; they must go to different sets
								// Note: if both entries are the same domino (ai == bi), this creates a self-loop
								// which will be detected as non-bipartite later.
								adj[a].push_back(b);
								adj[b].push_back(a);
						}
				}

				if (!pos) {
						cout << "NO\n";
						continue;
				}

				// Check if the domino-conflict graph is bipartite
				vector<int> color(n, -1);
				for (int i = 0; i < n && pos; i++) {
						if (color[i] != -1) continue; // already visited component
						color[i] = 0;
						dfs(i, adj, color, pos);
				}

				cout << (pos ? "YES\n" : "NO\n");
		}

		return 0;
}

/*
Time complexity per test case: O(n)
Space complexity per test case: O(n)
*/
