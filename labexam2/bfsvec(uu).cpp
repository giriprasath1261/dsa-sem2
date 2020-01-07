#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];
vector<bool> visited(100, false);

void edge(int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
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
            if (!visited[*it])
            {
                q.push(*it);
                visited[*it] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        edge(a, b);
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i]==false)
            bfs(i);
    }

    return 0;
}
