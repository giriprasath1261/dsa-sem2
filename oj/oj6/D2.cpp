#include <bits/stdc++.h>
#define ll long long

using namespace std;
struct edge
{
  ll u,v,w;
  bool operator<(const edge& p)
  {
    return w<p.w;
  }
};
ll pr[2000];
ll find(ll r)
{
  return (pr[r] == r) ? r : find(pr[r]);
}
vector<edge>e,ee;
void mst(ll n)
{
  sort(e.begin(), e.end());
  for (int i = 1; i <= n; i++)
  pr[i] = i;

  ll ct = 0, s = 0;
  for (int i = 0; i < (int)e.size(); i++)
  {
    ll u = find(e[i].u);
    ll v = find(e[i].v);
    if (u != v)
    {
      pr[u] = v;
      edge temp;
      temp.u=e[i].u;
      temp.v=e[i].v;
      temp.w=e[i].w;
      ee.push_back(temp);
      if (ct == n - 1)
      break;
    }
  }
}
int main()
{
  ee.clear();
  e.clear();
  ll n,m;
  cin>>n>>m;
  while(m--)
  {
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    edge temp;
    temp.u=a;
    temp.v=b;
    temp.w=c;
    e.push_back(temp);
  }
  mst(n);
  sort(ee.begin(),ee.end());
  ll sum=0;
  for(ll i=0;i<ee.size();i++)
  {
    sum+=ee[i].w;
    // if(ee[i].u<ee[i].v)
    // printf("%lld %lld %lld\n",ee[i].u,ee[i].v,ee[i].w);
    // else
    // printf("%lld %lld %lld\n",ee[i].v,ee[i].u,ee[i].w);
  }
  printf("%lld\n",sum);
  return 0;
}
