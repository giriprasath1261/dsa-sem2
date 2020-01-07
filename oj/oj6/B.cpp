#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> adj[100100];
vector<bool> visited(100100, false);
long long int n,m,k;
priority_queue < pair<long long int,long long int>, vector <pair<long long int,long long int> >, greater <pair<long long int,long long int> >> pq;
vector<long long int> dist2(100100,INT_MAX);
vector<long long int> dist(100100,INT_MAX);
long long int str;

void addEdge(long long int u, long long int v, long long int wt)
{
  adj[u].push_back(make_pair(v,wt));
  adj[v].push_back(make_pair(u,wt));
}

void djikstras()
{
  while(!pq.empty())
  {
    long long int u = pq.top().second;
    pq.pop();
    if(visited[u]==false)
    {
      for(auto it = adj[u].begin(); it!=adj[u].end();++it)
      {
        long long int v = (*it).first;
        long long int wt = (*it).second;
        if(dist2[v]>dist2[u]+wt)
        {
          if(wt+dist2[u]<dist[v])
          {
            dist2[v]=dist[v];
            dist[v]=wt+dist2[u];
            pq.push(make_pair(dist2[v],v));
          }
          else
          {
            dist2[v]=wt+dist2[u];
            pq.push(make_pair(dist2[v],v));
          }
        }
        visited[u]=1;
      }
    }
  }
  // for(long long int i=0;i<n;++i)
  // {
    // cout<<i<<" "<<dist[i]<<"\n";
    // arr[i][0]=dist[i];
  // }
}

int main(void)
{
  long long int num;
  long long int a,b,c;
  cin>>n>>m>>k;
  for(long long int i=0;i<m;i++)
  {
    cin>>a>>b>>c;
    addEdge(a,b,c);
  }
  for(long long int i=0;i<k;i++)
  {
    cin>>str;
    pq.push(make_pair(0,str));
    dist[str]=0;
    dist2[str]=0;
  }
  djikstras();
  int err=-1;
  if(dist2[0]==INT_MAX)
    cout<<err<<"\n";
  else
    cout<<dist2[0]<<"\n";

  return 0;
}
