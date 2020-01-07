#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<int> edge[100];
vector<bool> visited(100,false);
vector<bool> stacker(100,false);
int count=0;

bool dfsrec(int i)
{
  if(visited[i]==false)
  {
    visited[i]=true;
    stacker[i]=true;
    for(auto it = edge[i].begin();it!=edge[i].end();it++)
    {
      if(!visited[*it]&&dfsrec(*it))
        return true;
      else if(stacker[*it])
        return true;
    }
  }
  stacker[i]=false;
  return false;
}

bool dfs(int vertices)
{
  for(int i=1; i<=vertices; ++i)
    if(dfsrec(i))
      return true;

  return false;
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
  if(dfs(vertices))
    cout<<"Contains cycles\n";
  else
    cout<<"Does not contain cycles\n";
}
