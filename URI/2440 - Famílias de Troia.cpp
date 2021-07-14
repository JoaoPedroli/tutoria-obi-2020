#include <bits/stdc++.h>
using namespace std;

#define vt vector
typedef pair<int, int> ii; typedef long long ll; typedef vt<int> vi;
typedef vt<vt<int>> vvi; typedef vt<string> vs; typedef vt<ii> vii;

#define _outputConfig(a) if(a) ios::sync_with_stdio(0);cin.tie(0)
#define _fixAll(x) if(x >= 0) cout.precision(x);cout.setf(ios::fixed)
#define eb emplace_back
#define pb push_back
#define f(a, b, c) for(int a = b; a < c; ++a)
#define fd(a, b, c) for(int a = b; a >= c; --a)
#define w(a) while(a--)
#define s(a) int(a.size())
#define l(a) a.length()
#define be(ns) ns.begin(), ns.end()
#define rbe(ns) ns.rbegin(), ns.rend()
#define F first
#define S second
#define mdc(a, b) __gcd(a, b)

const int MAX = 1e3 + 2, mVI = 1<<20, mVJ = 1<<10, mVZ = 105;
const int INF = 0x3f3f3f3f, OUT = -INF, OUT2 = -1, MOD = 1e9 + 7;

void log() { cout<<'\n'; }
void log(int a) { cout<<a<<'\n'; }
void log(vi a, int s = 0) {
  cout<<a[s];
  f(i, s+1, s(a))
    cout<<' '<<a[i];
  log();
}
void log(vvi a, int s1 = 0, int s2 = 0) {
  f(i, s1, s(a)) {
    cout<<a[s1][s2];
    f(j, s2+1, s(a[i]))
      cout<<' '<<a[i][j];
    log();
  }
}

void CIN(vi &ns, int I, int s = 0) {
  ns = vi(I);
  f(i, s, I)
    cin>>ns[i];
}
void CIN(vvi &ns, int I, int J, int s1 = 0, int s2 = 0) {
  ns = vvi(I, vi(J));
  f(i, s1, I)
    f(j, s2, J)
      cin>>ns[i][j];
}

int n, m, u, v, sum=0;
vi vis;
vvi ns;

void dfs(int u) {
  if(vis[u]) return;
  vis[u] = 1;
  for(int v:ns[u]) {
    if(!vis[v]) dfs(v);
  }
}

int main() {_outputConfig(0);_fixAll(0);

  cin>>n>>m;
  ns = vvi(n+1), vis = vi(n+1, 0);
  f(i,0,m) {
    cin>>u>>v;
    ns[u].eb(v), ns[v].eb(u);
  }
  f(i,1,n+1)
    if(!vis[i]) ++sum, dfs(i);
  log(sum);

return 0;}

/* ALERTAS:

  conflitos: [[
    f(i,0,n) {
      f(i,0,m) {
      }
    }

    ns[i] > ns[i] /// ns1[i] > ns2[i]
    ns[i] > ns[i] /// ns[i] > ns[j]
  ]]

  começos e limites de iterações: [[
    f(i,a,b) /// f(i,a,b+1)
    f(i,a,b) /// f(i,a-1,b)
  ]]

*/
