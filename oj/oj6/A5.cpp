#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

#define MAXN 200010
int N, M;
vector<int> G[MAXN], GG[2][MAXN];
int V[MAXN], vi[MAXN], dbg[MAXN], ded[MAXN];
int dis[2][MAXN], bg[2][MAXN], ed[2][MAXN];
int no[2] = {1, 1};

class FenwickTree
{
  vector<int> tree;
  public:
  FenwickTree(int n = 0) {
    tree.resize(n);
  }

  void update(int i, int delta) {
    for (; i < (int)tree.size(); i |= i + 1)
      tree[i] += delta;
  }

  int sum(int ind) {
    int sum = 0;
    while (ind>=0)
    {
      sum += tree[ind];
      ind &= ind + 1;
      ind--;
    }
    return sum;
  }

  void myUpdate(int i, int j, int delta) {
    update(i, delta);
    update(j+1, -delta);
  }
};

void rebuild(int gp, int p, int n, int d)
{
  if (vi[n]) return;
  vi[n] = true;
  if (gp != -1)
    GG[d][gp].push_back(n);
  dbg[n] = -1;
  ded[n] = -1;
  for (int i = 0; i < G[n].size(); i++) {
    if (G[n][i] != p) {
      if (dbg[n] == -1) dbg[n] = G[n][i];
      ded[n] = G[n][i];
    }
    rebuild(p, n, G[n][i], 1-d);
  }
}


int dfs(int d, int n)
{
  int b = no[d];
  dis[d][no[d]++] = n;
  int e = b;
  for (int i = 0; i < GG[d][n].size(); i++)
    e = dfs(d, GG[d][n][i]);
  bg[d][n] = b;
  ed[d][n] = e;
  return e;
}

int find(int v)
{
  if (bg[0][v] != 0)
    return 0;
  return 1;
}

int main()
{
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    scanf("%d", &V[i]);
  for (int i = 0; i < N-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rebuild(-1, 0, 1, 1);
  dfs(0, 0);
  dfs(1, 1);

  FenwickTree fts[2];
  for (int j = 0; j < 2; j++) {
    fts[j] = FenwickTree(N+1);
    for (int i = 1; i <= no[j]; i++)
      fts[j].myUpdate(i, i, V[dis[j][i]]);
  }

  while (M--) {
    int op, x, val;
    scanf("%d%d", &op, &x);
    int t = find(x);
    if (op == 1) {
      scanf("%d", &val);
      fts[t].myUpdate(bg[t][x], ed[t][x], val);
      if (dbg[x] != -1)    // if child exist
        fts[1-t].myUpdate(bg[1-t][dbg[x]], ed[1-t][ded[x]], -val);
    } else {
      printf("%d\n", fts[t].sum(bg[t][x]));
    }
  }
  return 0;
}
