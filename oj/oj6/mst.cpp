#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector < pair < int, int > > adj[1000010];
vector < bool > visited(1000010, false);
priority_queue < int > queues;

struct pandi
{
  int start;
  int end;
}pandi1;

void addEdge(int u, int v, int wt)
{
  adj[u].push_back(make_pair(v,wt));
  adj[v].push_back(make_pair(u,wt));
}

void getinput(int m)
{
  int u, v, w;
  for( int i = 0; i < m; i++ ) {
    scanf("%d",&u);
    scanf("%d",&v);
    scanf("%d",&w);
    addEdge(u,w,v);
    addEdge(v,w,u);
  }
}

int main(void)
{
  long long int n, m, k, count = 0;
  scanf("%d",&n);
  scanf("%d",&m);
  scanf("%d",&k);
  getinput(m);
  priority_queue < pair<int,int>, vector <pair<int,int> >, greater <pair<int,int> >> priorityqueue;
  long long int dist = 0;
  priorityqueue.push( make_pair(0,1) );
  while( !priorityqueue.empty() ) {
    pair < int, int > nad = priorityqueue.top();
    priorityqueue.pop();
    pandi1.start=nad.first;
    pandi1.end=nad.second;
    if( !visited[pandi1.end] ) {
      dist=dist+ pandi1.start;
      queues.push( pandi1.start );
      visited[pandi1.end] = true;
      int i=0;
      while( i < adj[pandi1.end].size()) {
        if( !visited[adj[pandi1.end][i].second] )
        {
          priorityqueue.push( adj[pandi1.end][i] );
        }
        i++;
      }
    }
  }
  long long int finaldist = dist;
  if( queues.size() < n-1 ) {
    cout << "-1" << endl;
    return 0;
  }
  while( !queues.empty() ) {
    if( finaldist <= k )
    {
      cout << count << endl;
      return 0;
    }
    int temp = queues.top();
    queues.pop();
    finaldist -= temp + 1;
    count++;
  }
  cout << "-1" << endl;
  return 0;
}
