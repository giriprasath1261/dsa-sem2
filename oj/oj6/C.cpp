#include<bits/stdc++.h>
using namespace std;

int n,m,s,t;
vector<pair<int, int>> adj[100100];
vector<pair<int, int>> adj2[100100];
vector<bool> visited(100100, false);
int arr[100100][5];

void addEdge(int u, int v, int wt)
{
  adj[u].push_back(make_pair(v,wt));
  adj2[v].push_back(make_pair(u,wt));
}

void printGraph(int V)
{
    int v, w;
    for (int u = 1; u <= V; u++)
    {
      cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

void djikstras(int str)
{
  priority_queue < pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> >> pq;
  vector<int> dist(n+1,INT_MAX);
  pq.push(make_pair(0,str));
  dist[str]=0;
  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    for(auto it = adj[u].begin(); it!=adj[u].end();++it)
    {
      int v = (*it).first;
      int wt = (*it).second;

      if(dist[v]>dist[u]+wt)
      {
        dist[v] = dist[u]+wt;
        pq.push(make_pair(dist[v],v));
      }
    }
  }
  for(int i=1;i<=n;++i)
  {
    // cout<<i<<" "<<dist[i]<<"\n";
    arr[i][0]=dist[i];
  }
}

void djikstras2(int str)
{
  priority_queue < pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> >> pq;
  vector<int> dist(n+1,INT_MAX);
  pq.push(make_pair(0,str));
  dist[str]=0;
  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    for(auto it = adj[u].begin(); it!=adj[u].end();++it)
    {
      int v = (*it).first;
      int wt = (*it).second;

      if(dist[v]>dist[u]+wt)
      {
        dist[v] = dist[u]+wt;
        pq.push(make_pair(dist[v],v));
      }
    }
  }
  for(int i=1;i<=n;++i)
  {
    // cout<<i<<" "<<dist[i]<<"\n";
    arr[i][1]=dist[i];
  }
}

void djikstras3(int str)
{
  priority_queue < pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> >> pq;
  vector<int> dist(n+1,INT_MAX);
  pq.push(make_pair(0,str));
  dist[str]=0;
  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    for(auto it = adj2[u].begin(); it!=adj2[u].end();++it)
    {
      int v = (*it).first;
      int wt = (*it).second;

      if(dist[v]>dist[u]+wt)
      {
        dist[v] = dist[u]+wt;
        pq.push(make_pair(dist[v],v));
      }
    }
  }
  for(int i=1;i<=n;++i)
    {
      // cout<<i<<" "<<dist[i]<<"\n";
      arr[i][2]=dist[i];
    }
}

void djikstras4(int str)
{
  priority_queue < pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> >> pq;
  vector<int> dist(n+1,INT_MAX);
  pq.push(make_pair(0,str));
  dist[str]=0;
  while(!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
    for(auto it = adj2[u].begin(); it!=adj2[u].end();++it)
    {
      int v = (*it).first;
      int wt = (*it).second;

      if(dist[v]>dist[u]+wt)
      {
        dist[v] = dist[u]+wt;
        pq.push(make_pair(dist[v],v));
      }
    }
  }
  for(int i=1;i<=n;++i)
  {
    // cout<<i<<" "<<dist[i]<<"\n";
    arr[i][3]=dist[i];
  }
}

int main(void)
{
  cin>>n>>m>>s>>t;
  int a,b,w;
  for(int i=0;i<m;i++)
  {
    cin>>a>>b>>w;
    addEdge(a,b,w);
  }
  // printGraph(n);
  // cout<<"\n";
  djikstras(s);
  // cout<<"\n";
  djikstras2(t);
  // cout<<"\n";
  djikstras3(s);
  // cout<<"\n";
  djikstras4(t);
  // cout<<"\n";
  int min = INT_MAX;
  int err=-1;
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<4;j++)
    {
      if(arr[i][j]==INT_MAX)
      {
        arr[i][4]=INT_MAX;
        break;
      }
      arr[i][4]+=arr[i][j];
    }
    if(i==s||i==t)
      min=min;
    else
    {
      if(min>arr[i][4])
        min=arr[i][4];
    }
  }
  for(int i=1;i<=n;++i)
    cout<<arr[i][4]<<" ";
  cout<<"\n";
  if(min==INT_MAX)
    cout<<err<<"\n";
  else
    cout<<min<<"\n";
}
