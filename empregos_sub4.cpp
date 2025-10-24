#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e3 + 10;

int a[MAXN], b[MAXN];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  for(int i=1; i<=n; i++) cin >> a[i];

  for(int i=1; i<=n; i++) cin >> b[i];

  ll ans = 0;

  // caso em que Júlio nunca recebe a promoção
  for(int i=1; i<=n; i++) ans += max(a[i], b[i]);

  for(int i=k; i<=n; i++){

    ll cur = 0;

    // cur := resposta se Júlio trabalhasse
    // exatamente k vezes no shopping até o dia i

    for(int j=1; j<=i; j++) cur += b[j];

    for(int j=(i + 1); j<=n; j++) cur += max(a[j], 2 * b[j]);

    vector<int> vals;
      
    for(int j=1; j<=i; j++) vals.push_back(a[j] - b[j]);  

    // ordenando em ordem decrescente
    sort(vals.rbegin(), vals.rend());

    // adicionando os i - k maiores valores na resposta atual
    for(int j=0; j<(i - k); j++) cur += vals[j];

    ans = max(ans, cur);

  }

  cout << ans << "\n";

  return 0;
}
