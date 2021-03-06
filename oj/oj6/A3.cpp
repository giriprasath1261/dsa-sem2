#include <cstdio>
#include <vector>
using namespace std;

#define D(x)

const int MAX_N = int(1e5) * 2 + 10;

int n, m;
int value[MAX_N];
vector<int> edge[MAX_N];
int dfn[MAX_N], dfn2[MAX_N];
int time_count;
int binary_indexed_tree[MAX_N];
int depth[MAX_N];

void dfs(int u, int father, int cur_depth)
{
	depth[u] = cur_depth;
	dfn[u] = time_count++;
	for (int i = 0; i < (signed)edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != father)
			dfs(v, u, cur_depth + 1);
	}
	dfn2[u] = time_count;
}

int low_bit(int x)
{
	return x & (-x);
}

void add(int pos, int val)
{
	for (int i = pos; i < MAX_N; i += low_bit(i))
	{
		binary_indexed_tree[i] += val;
	}
}

int sum(int pos)
{
	int ret = 0;
	for (int i = pos; i > 0; i -= low_bit(i))
	{
		ret += binary_indexed_tree[i];
	}
	return ret;
}

int main()
{
	//input
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", value + i);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	//work
	time_count = 1;
	dfs(1, -1, 1);
	for (int i = 0; i < m; i++)
	{
		int command, x, val;
		scanf("%d", &command);
		if (command == 1)
		{
			scanf("%d%d", &x, &val);
			if (depth[x] & 1)
				val = -val;
			add(dfn[x], val);
			add(dfn2[x], -val);
			continue;
		}
		scanf("%d", &x);
		val = sum(dfn[x]);
		D(printf("%d\n", val));
		if (depth[x] & 1)
			val = -val;
		printf("%d\n", value[x] + val);
	}
	return 0;
}
