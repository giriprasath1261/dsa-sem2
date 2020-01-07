#include<bits/stdc++.h>
using namespace std;

vector < pair < int, int > > adj[1000010];
vector < bool > visited(1000010, false);
priority_queue < int > priority;
int u, v, w;
long long n, m, k, count = 0;

void addEdge(int u, int v, int wt)
{
  adj[u].push_back(make_pair(wt,v));
  adj[v].push_back(make_pair(wt,u));
}

void getinput()
{

    ios_base::sync_with_stdio(false);  cin.tie(NULL);
    cin >> n >> m >> k;


    for( int i = 0; i < m; i++ )
    {
      cin >> u >> v >> w;
      addEdge(u,v,w);
    }


}

int main(void)
{
  getinput();

  priority_queue < pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> >> Q;
  long long mcost = 0;
  Q.push( make_pair(0,1) );

  while( !Q.empty() )
  {
    pair < int, int > tnode = Q.top();
    Q.pop();

    if( !visited[tnode.second] )
    {
      mcost += tnode.first;
      priority.push( tnode.first );
      visited[tnode.second] = true;

      for( int i = 0; i < adj[tnode.second].size(); i++ )
      {
        if( !visited[adj[tnode.second][i].second] )
        {
          Q.push( adj[tnode.second][i] );
        }
      }
    }

  }

  long long cost = mcost;
  if( priority.size() < n-1 )
  {
    cout << "-1" << endl;
    return 0;
  }
  if( cost <= k )
  cout << count << endl;
  {
    return 0;
  }

  while( !priority.empty() )
  {
    int temp = priority.top();
    priority.pop();
    cost = cost - temp + 1;
    count++;

    if( cost <= k )
    {
      cout << count << endl;
      return 0;
    }
  }

  cout << "-1" << endl;
  return 0;
}
