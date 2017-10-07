#include <bits/stdc++.h>
using namespace std;

const int N = 52;

char s[N][N] = {0};
bool visited[N][N] = {0};
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool res = false;

void dfs(int i, int j, int pi, int pj) {
  for (int k = 0; k < 4; k++) {
    int u = i + dx[k];
    int v = j + dy[k];
    if (s[u][v] != s[i][j]) {
      continue;
    }
    if (visited[u][v]) {
      if (u != pi || v != pj) {
        res = true;
      }
    } else {
      visited[u][v] = true;
      dfs(u, v, i, j);
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (visited[i][j]) {
        continue;
      }
      visited[i][j] = true;
      dfs(i, j, -1, -1);
      if (res) {
        break;
      }
    }
    if (res) {
      break;
    }
  }
  puts(res ? "Yes" : "No");
  return 0;
}