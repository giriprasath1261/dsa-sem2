#include<bits/stdc++.h>
using namespace std;

long long int m,n,a,b;
vector<long long int> adj[200100];
vector<bool> visited(200100 ,false);
long long int st[200100][3];  // 0-start 1-end 2-value
long long int data[200100][2]; // 0-start 1-end
long long int timeindex[200100];
struct node
{
  long long int start;
  long long int end;
  long long int str;
  long long int level;
}arr[200100];

void addEdge(long long int u, long long int v)
{
  adj[u].push_back(v);
}

long long int num=0;
void DFSUtil(long long int u,long long int level)
{
  visited[u] = true;
  arr[u].start=++num;
  timeindex[num]=u;
  arr[u].level=level;
  for (long long int i=0; i<adj[u].size(); i++)
  DFSUtil(adj[u][i],level+1);
  arr[u].end=num;
}

void DFS(long long int V)
{
  for (long long int u=1; u<=V; u++)
  if (visited[u] == false)
  DFSUtil(u,1);
}

long long int segment(long long int index,long long int left,long long int right,long long int flag)
{
  if(left==right)
  {
    // cout<<left<<" "<<index<<"\n";
    st[index][0] = data[left][0];
    st[index][1] = data[left][1];
    if(flag==0)
    {
      return st[index][0];
    }
    else
    {
      return st[index][1];
    }
  }
  else
  {
    long long int mid=(left+right)/2;
    st[index][0]=segment(2*index+1,left,mid,0);
    st[index][1]=segment(2*index+2,mid+1,right,1);
    if(flag==0)
    {
      return st[index][0];
    }
    else
    {
      return st[index][1];
    }
  }
}

long long int addstrutil(long long int index,long long int level,long long int left,long long int right,long long int val)
{
  if(st[index][0]>=left&&st[index][1]<=right)
  {
    if(level%2==arr[timeindex[st[index][0]]].level%2)
    {
      st[index][2]+=val;
      return 0;
    }
    else
    {
      st[index][2]-=val;
      return 0;
    }
  }
  else
  {
    if(st[2*index+1][1]>=left && 2*index+1<2*n-1)
    addstrutil(2*index+1,level,left,right,val);
    if(st[2*index+2][2]<=right && 2*index+2<2*n-1)
    addstrutil(2*index+2,level,left,right,val);
  }
  return 0;
}

long long int addstr(long long int index,long long int val)
{
  long long int left = arr[index].start;
  long long int right = arr[index].end;
  long long int level = arr[index].level;
  addstrutil(0,level,left,right,val);
  return 0;
}

long long int findvalutil(long long int index,long long int left,long long int right,long long int level,long long int sum)
{
  // cout<<index<<"  ";
  if(st[index][0]==left&&st[index][1]==left)
  {
    sum+=st[index][2];
    // cout<<sum<<"f"<<endl;
    return sum;
  }
  else
  {
    if(level%2==arr[timeindex[st[index][0]]].level%2)
    {
      sum+=st[index][2];
    }
    else
    {
      sum-=st[index][2];
    }
    //cout<<sum<<endl;
    if(left>=st[2*index+1][0] && left<=st[2*index+1][1] && 2*index+1<2*n-1)
    {
      return findvalutil(2*index+1,left,right,level,sum);
    }
    if(left>=st[2*index+2][0] && left<=st[2*index+2][1] && 2*index+2<2*n-1)
    {
      return findvalutil(2*index+2,left,right,level,sum);
    }

  }
}

long long int findval(long long int index)
{
  long long int left = arr[index].start;
  long long int right = arr[index].end;
  long long int level = arr[index].level;
  long long int sum=findvalutil(0,left,right,level,0);
  cout<<sum+arr[index].str<<endl;
  return 0;
}

int main(void)
{
  cin>>n>>m;
  // int str[n+1];
  for(long long int i=1;i<=n;i++)
  {
    cin>>arr[i].str;
  }
  for(long long int i=1;i<n;i++)
  {
    cin>>a>>b;
    addEdge(a,b);
  }
  DFS(n);
  // for(int i=1;i<=n;i++)
  // {
  //   cout<<i<<" "<<arr[i].start<<" "<<arr[i].end<<endl;
  // }
  for(long long int i=1;i<=n;i++)
  {
    data[i][0]=data[i][1]=i;
  }
  segment(0,1,n,0);
  // for(int i=0;i<2*n-1;i++)
  // cout<<i<<" "<<st[i][0]<<" "<<st[i][1]<<" "<<st[i][2]<<endl;
  // cin>>a>>b;
  // addstr(a,b);
  // for(int i=0;i<2*n-1;i++)
  // cout<<i<<" "<<st[i][0]<<" "<<st[i][1]<<" "<<st[i][2]<<endl;
  // cin>>a;
  // findval(a);
  long long int ch,x,y;
  for(long long int i=0;i<m;i++)
  {
    cin>>ch;
    if(ch==1)
    {
      cin>>x>>y;
      addstr(x,y);
    }
    else
    {
      cin>>x;
      findval(x);
    }
  }
}
