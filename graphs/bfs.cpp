#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > edge;
vector<bool> visited(100,false);


void bfs(int val)
{
  queue<int> q;
  q.push(val);
  visited[val]=true;
  while(!q.empty())
  {
    int front = q.front();
    q.pop();
    cout<<front<< " ";
    for(auto i = edge[front].begin(); i!=edge[front].end(); i++)
    {
      if(!visited[*i])
      {
        q.push(*i);
        visited[*i] = true;
      }
    }
  }
}

int main()
{
  int vertices,edges;
  cin>>vertices>>edges;
  int tempin,tempout;
  int printout;
  edge.assign(vertices, vector<int>());
  for (int i = 0; i < edges; i++) {
    scanf("%d %d",&tempin,&tempout);
    edge[tempin].push_back(tempout);
  }
  // for(int i = 0;i < vertices;i++) {
  //   cout<<"node "<<i<<" makes an edge with:\n";
  //   for(auto it = edge[i].begin(); it!=edge[i].end(); it++)
  //   {
  //     printout = *it;
  //     cout << "node "<< printout<<"\n";
  //   }
  //   cout<<"\n";
  // }
  for(int i=0;i<vertices;i++)
  {
    if(!visited[i])
      bfs(i);
  }
  cout<<"\n";
}
