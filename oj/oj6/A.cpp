#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100100];
vector<bool> visited(100100, false);

struct Node
{
  int start;
  int end;
};

Node array1[100100];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void DFSUtil(int u, int num)
{
    visited[u] = true;
    array1[u].start=num;
    for (int i=0; i<adj[u].size(); i++)
      DFSUtil(adj[u][i], ++num);
    array1[u].end=num;
}

void DFS(int V)
{
    for (int u=1; u<=V; u++)
        if (visited[u] == false)
            DFSUtil(u,1);
}
void printGraph(int V)
{
    int v, w;
    for (int u = 1; u <= V; u++)
    {
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = *it;
            cout << "Node " << u << " makes an edge with \n";
            cout << "\tNode " << v;
        }
        cout << "\n";
    }
}

int main()
{
    int n,m;
    int arr[n];
    int ch;
    int a,b;
    int u,num;
    cin>>n>>m;
    for(int i=0;i<n;i++)
      cin>>arr[i];
    // cout<<"hi";
    for(int i=1;i<n;i++)
    {
      cin>>a>>b;
      addEdge(a,b);
    }
    // cout<<"hi";
    // printGraph(n);
    DFS(n);
    for(int i=1;i<=n;i++)
      cout<<i<<" "<<array1[i].start<<" "<<array1[i].end<<"\n";
    return 0;
}
