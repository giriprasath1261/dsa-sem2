#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N = 200010;
typedef long long LL;
int mak[N<<2];
int d[N];
int deep[N];
int le[N],ri[N];
vector<int>G[N];
int num;
void DFS(int x, int dep)
{
    le[x] =++num;
    deep[num] = dep;
    for(int i=0; i<G[x].size(); i++)
    {
        int v = G[x][i];
        if(le[v]!=-1)
        {
            continue;
        }
        DFS(v,dep^1);
    }
    ri[x] = num;
}
void update(int L, int R, int d, int l, int r, int rt)
{
    if(L<=l && R>=r)
    {
        mak[rt]+=d;
        return;
    }
    int m = l+r>>1;
    if(L<=m) update(L,R,d,l,m,rt<<1);
    if(R>m)    update(L,R,d,m+1,r,rt<<1|1);

}
int query(int pos, int l, int r, int rt)
{
    if(l==r) return deep[l]&1? -mak[rt] : mak[rt];
    int m = l+r>>1;
    if(mak[rt])
    {
        mak[rt<<1]+=mak[rt];
        mak[rt<<1|1]+=mak[rt];
        mak[rt] = 0;
    }
    return pos<=m ? query(pos,l,m,rt<<1) : query(pos,m+1,r,rt<<1|1);
}
int main()
{
    //freopen("date.in","r",stdin);
    int i,j,k,m,n,p,x,val;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(i=1; i<=n; i++) scanf("%d",d+i);
        for(i=1; i<=n; i++) G[i].clear();
        k = n-1;
        while(k--)
        {
            scanf("%d%d",&i,&j);
            G[i].push_back(j), G[j].push_back(i);
        }
        memset(le,-1,sizeof(le));
        num = 0;
        DFS(1,0);
        memset(mak,0,sizeof(mak));
        while(m--)
        {
            scanf("%d",&p);
            if(p==1)
            {
                scanf("%d %d",&x,&val);
                if(deep[le[x]]&1) val = -val;
                update(le[x],ri[x],val,1,n,1);
            }
            else
                scanf("%d",&k),
                      printf("%d\n",d[k]+query(le[k],1,n,1));
        }
    }
    return 0;
}
