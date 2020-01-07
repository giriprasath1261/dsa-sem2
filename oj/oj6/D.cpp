#include<bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> adj[100];
vector<bool> visited(100, false);

void addEdge(long long int u, long long int v, long long int wt)
{
  adj[u].push_back(make_pair(v,wt));
  adj[v].push_back(make_pair(u,wt));
}

void DFSUtil(long long int u)
{
  visited[u] = true;
  // cout << u << " ";
  for (long long int i=0; i<adj[u].size(); i++)
  if (visited[adj[u][i].first] == false)
  DFSUtil(adj[u][i].first);
}


void printGraph(long long int V)
{
  long long int v, w;
  for (long long int u = 1; u <= V; u++)
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

vector<bool> v;
vector<vector<int> > g;

void edge(int a, int b)
{
  g[a].push_back(b);

  // for undirected graph add this line
  // g[b].pb(a);
}

void bfs(int u)
{
  queue<int> q;

  q.push(u);
  v[u] = true;

  while (!q.empty()) {

    int f = q.front();
    q.pop();

    cout << f << " ";

    // Enqueue all adjacent of f and mark them visited
    for (auto i = g[f].begin(); i != g[f].end(); i++) {
      if (!v[*i]) {
        q.push(*i);
        v[*i] = true;
      }
    }
  }
}

int main(void)
{
  long long int n,m,k,a,b,c,count=0;
  int flag,err=-1;
  cin>>n>>m>>k;
  long long int arr[n+1];
  for(long long int i=0;i<m;i++)
  {
    cin>>a>>b>>c;
    arr[i]=c;
    addEdge(a,b,c);
  }
  // for(int i=0;i<m;i++)
  // cout<<arr[i];
  // cout<<"\n";
  DFSUtil(1);
  for(long long int i=1;i<=n;i++)
  {
    if(visited[i]==false)
    {flag=1;break;}
  }
  if(flag==1)
  {
    cout<<err;
    return 0;
  }
  else
  {
    if(k<m)
    {
      cout<<err;
      return 0;
    }
    sort(arr, arr+m);
    for(int i=0;i<m;i++)
      cout<<arr[i]<<" ";
    long long int j=m-1,i=m-1;
    long long int sum=arr[m-1];
    while(i<=j&&i>=0)
    {
      if(sum>k)
      {
        sum=sum-arr[j]+1;
        count++;
        j--;
      }
      else
      {
        i--;
        sum=sum+arr[i];
      }
    }
  }
  cout<<count<<"\n";
  return 0;
}
