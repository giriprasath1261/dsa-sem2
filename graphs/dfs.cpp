#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> edge[100];
vector<bool> visited(100,false);
int count=0;

int dfsrec(int i,int sum,int flag)
{
  visited[i] = true;
  for( int j=0; j<edge[i].size();j++)
  {
    if(edge[i][j].first==i && flag==0)
    {
      sum+=edge[i][j].second;
      flag=1;
    }
    if(visited[edge[i][j].first]==false)
    {
      sum+=edge[i][j].second;
      sum = dfsrec(edge[i][j].first,sum,0);
    }
  }
  return sum;
}

void dfs(int vertices)
{
  for(int i=1;i<=vertices;i++)
  {
    if(visited[i]==false)
    {
      count++;
      int sum=0;
      sum = dfsrec(i,sum,0);
      cout<<sum<<" ";
    }
  }
}

int main()
{
  int vertices,edges;
  cin>>vertices>>edges;
  int tempin,tempout,tempweight;
  int printout;
  for (int i = 0; i < edges; i++) {
    scanf("%d %d %d",&tempin,&tempout,&tempweight);
    edge[tempin].push_back(make_pair(tempout,tempweight));
    edge[tempout].push_back(make_pair(tempin,tempweight));
  }
  for(int i = 1;i <=vertices;i++) {
    cout<<"node "<<i<<" makes an edge with:\n";
    for(auto it = edge[i].begin(); it!=edge[i].end(); it++)
    {
      cout << "node "<<it->first<<"\n";
    }
    cout<<"\n";
  }
  dfs(vertices);
  cout<<"\n";
}
