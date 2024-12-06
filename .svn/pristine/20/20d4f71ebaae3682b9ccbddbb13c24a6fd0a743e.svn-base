#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> country, build, destroyCost;
vector<bool> visited;

void dfs(int u) {
  visited[u] = true;
  for (int v = 0; v < N; v++) {
    if (country[u][v] && !visited[v]) {
      dfs(v);
    }
  }
}

bool isConnected(int u, int v) {
  fill(visited.begin(), visited.end(), false);
  dfs(u);
  return visited[v];
}

// Prim's algorithm
int prim(vector<vector<int>>& graph) {
  int n = graph.size();
  vector<bool> vis(n, false);
  vector<int> key(n, INT_MAX);
  key[0] = 0;
  int total = 0;
  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && (u == -1 || key[j] < key[u])) u = j;
    }
    vis[u] = true;
    total += key[u];
    for (int j = 0; j < n; j++) {
      if (!vis[j] && key[j] > graph[u][j]) {
        key[j] = graph[u][j];
      }
    }
  }
  return total;
}

int main() {
  string s_country, s_build, s_destroyCost;
  cin >> s_country >> s_build >> s_destroyCost;

  N = count(s_country.begin(), s_country.end(), ',') + 1;

  country.resize(N, vector<int>(N, 0));
  build.resize(N, vector<int>(N, 0));
  destroyCost.resize(N, vector<int>(N, 0));
  visited.resize(N, false);

  // Parse input strings
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      country[i][j] = s_country[i * (N + 1) + j] - '0';
      build[i][j] = (isupper(s_build[i * (N + 1) + j]))
                        ? s_build[i * (N + 1) + j] - 'A'
                        : s_build[i * (N + 1) + j] - 'a' + 26;
      destroyCost[i][j] = (isupper(s_destroyCost[i * (N + 1) + j]))
                              ? s_destroyCost[i * (N + 1) + j] - 'A'
                              : s_destroyCost[i * (N + 1) + j] - 'a' + 26;
    }
  }

  int cost = 0;
  vector<vector<int>> graph = build;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (country[i][j] == 1) {
        graph[i][j] = -destroyCost[i][j];
        cost += destroyCost[i][j];
      }
    }
  }

  cost /= 2;
  cost += prim(graph);

  cout << cost << endl;
  return 0;
}
