#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = 1e9;
const int MAX = 200010;
long long int m,n,b;
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

// BIT is 0 indexed
struct BIT{
    int bit[MAX+1], N;
    BIT(){}
    BIT(int N):N(N){
        memset(bit, 0, sizeof(bit));
    }
    // sum [0,i]
    int sum(int i){
        i++;
        int ret = 0;
        while(i){
            ret += bit[i];
            i -= i&-i;
        }
        return ret;
    }
    // sum [i,j)
    int sum(int i, int j){
        return sum(j-1) - sum(i-1);
    }
    void add(int i, int x){
        i++;
        while(i <= N){
            bit[i] += x;
            i += i&-i;
        }
    }
};

int N, M, a[MAX], depth[MAX], in[MAX], out[MAX], par[MAX];
vector<int> G[MAX];
BIT bits[2];

void dfs(int v, int u, int &f, int &g){
    in[v] = f++;
    depth[v] = depth[u]+1;
    par[v] = u;
    for(int &w: G[v])
        if(w != u) dfs(w, v, g, f);
    out[v] = f;
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

void solve(){
    depth[0] = -1;
    int f = 0, g = 0;
    dfs(0,0,f,g);
    bits[0] = BIT(f+1);
    bits[1] = BIT(g+1);
    rep(i,N) {
        bits[depth[i]%2].add(in[i],a[i]);
        bits[depth[i]%2].add(in[i]+1,-a[i]);
    }
    int type, x, val;
    for(int w=0;w<M;w++){
        cin >> type >> x;
        x--;
        if(type == 1){
            cin >> val;
            bits[depth[x]%2].add(in[x], val);
            bits[depth[x]%2].add(out[x], -val);
            for(int &v: G[x])if(v!=par[x]){
                bits[depth[v]%2].add(in[v],-val);
                bits[depth[v]%2].add(out[v],val);
            }
        }
        else cout << bits[depth[x]%2].sum(in[x]) << endl;
    }
}

void input(){
    cin >> N >> M;
    rep(i,N) cin >> a[i];
    rep(i,N-1){
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(12);
    input();
    solve();
    return 0;
}
