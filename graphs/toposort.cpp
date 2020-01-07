#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> edge[100];
vector<bool> visited(100,false);
stack<int> stacker;

void dfsrec(int i)
{
  visited[i]=true;

  for(auto it = edge[i].begin();it!=edge[i].end();it++)
  {
    if(!visited[*it])
      dfsrec(*it);
  }
  stacker.push(i);
}

void dfs(int vertices)
{
  for(int i = 1; i<=vertices;i++)
    if(visited[i]==false)
      dfsrec(i);
  while(stacker.empty()==false)
  {
    cout<<stacker.top()<<" ";
    stacker.pop();
  }
}

int main()
{
  int vertices,edges;
  cin>>vertices>>edges;
  int tempin,tempout,tempweight;
  int printout;
  for (int i = 0; i < edges; i++) {
    scanf("%d %d",&tempin,&tempout);
    edge[tempin].push_back(tempout);
  }
  dfs(vertices);
}
  cout<<"\n";
