#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  for(int i=1; i<=n; i++) cin >> a[i];

  for(int i=1; i<=n; i++) cin >> b[i];

  ll ans = 0;
  
  // vetor com os ganhos de cada sílaba
  // ao zerar sua resistência
  vector<int> to_add;

  for(int i=1; i<=n; i++){
    if(a[i] >= b[i]){
      
      ans += a[i] - b[i];
      to_add.push_back(b[i]);
      
    } else to_add.push_back(a[i]);
  }

  // ordenando os ganhos em ordem decrescente
  sort(to_add.rbegin(), to_add.rend());

  // adicionando os k + 1 maiores ganhos à nasalidade final
  for(int i=0; i<=k; i++) ans += to_add[i];

  cout << ans << "\n";

  return 0;
}
