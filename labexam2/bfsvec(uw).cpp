#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100];
vector<bool> visited(100, false);

void edge(int a, int b, int c)
{
    adj[a].push_back(make_pair(b,c));
    adj[b].push_back(make_pair(a,c));
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";
        for (auto it = adj[f].begin(); it != adj[f].end(); it++)
        {
            if (!visited[it->first])
            {
                q.push(it->first);
                visited[it->first] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int a, b, c;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        edge(a, b, c);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i]==false)
            bfs(i);
    }
    return 0;
}
