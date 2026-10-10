#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 10;

vector<int> adj[MAXN];

bool marc[MAXN];

int tam[MAXN], comp[MAXN];

void dfs(int v, int c){

  marc[v] = true;
  comp[v] = c;
  tam[v] = 1;

  for(auto u : adj[v]){
    if(!marc[u]){

      dfs(u, c);
      tam[v] += tam[u];

    }
  }

}

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q; cin >> n >> m >> q;

  for(int i=0; i<m; i++){

    int a, b; cin >> a >> b;
    
    adj[a].push_back(b);
    adj[b].push_back(a);

  }

  for(int i=1; i<=n; i++) if(!marc[i]) dfs(i, i);

  while(q--){

    int a, b; cin >> a >> b;

    if(comp[a] == comp[b]){
      cout << "-1\n";
      continue;
    } 

    int t = min(tam[comp[a]], tam[comp[b]]);

    ll arestas = (ll) n * (n - 1) / 2 - (ll) (n - t) * t;

    // temos que subtrair m no final, porque o problema
    // pede apenas as arestas adicionadas, excluindo
    // aquelas que estavam no grafo inicial
    
    cout << arestas - m << "\n";

  }

  return 0;
}
