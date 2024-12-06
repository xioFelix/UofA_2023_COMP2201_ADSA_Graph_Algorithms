#include <algorithm>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readCountry(vector<vector<int>>& v) {
  string s;
  cin >> s;
  size_t t = 0;
  while (t < s.size()) {
    v.push_back(vector<int>());
    while (t < s.size() && s[t] != ',') {
      v.back().push_back(s[t] - '0');
      t++;
    }
    if (t != s.size()) t++;
  }
}

void readBuild(vector<vector<int>>& v) {
  string s;
  cin >> s;
  size_t t = 0;
  while (t < s.size()) {
    v.push_back(vector<int>());
    while (t < s.size() && s[t] != ',') {
      if (islower(s[t])) {
        v.back().push_back(s[t] - 'a' + 26);
      } else {
        v.back().push_back(s[t] - 'A');
      }
      t++;
    }
    if (t != s.size()) t++;
  }
}

void readDestory(vector<vector<int>>& v) {
  string s;
  cin >> s;
  size_t t = 0;
  while (t < s.size()) {
    v.push_back(vector<int>());
    while (t < s.size() && s[t] != ',') {
      if (islower(s[t])) {
        v.back().push_back(s[t] - 'a' + 26);
      } else {
        v.back().push_back(s[t] - 'A');
      }
      t++;
    }
    if (t != s.size()) t++;
  }
}

int prim(vector<vector<int>>& input) {
  int n = input.size();
  vector<bool> vis(n, false);
  vector<int> key(n, INT_MAX);
  key[0] = 0;
  int answer = 0;
  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && (u == -1 || key[j] < key[u])) u = j;
    }
    vis[u] = true;
    answer += key[u];
    for (int j = 0; j < n; j++) {
      if (!vis[j] && key[j] > input[u][j]) {
        key[j] = input[u][j];
      }
    }
  }
  return answer;
}

int main() {
  vector<vector<int>> country, build, destroy;
  readCountry(country);
  readBuild(build);
  readDestory(destroy);
  vector<vector<int>> graph = build;
  int n = country.size();
  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (country[i][j] == 1) {
        graph[i][j] = -destroy[i][j];
        answer += destroy[i][j];
      }
    }
  }
  answer /= 2;
  answer += prim(graph);
  cout << answer << endl;
  return 0;
}