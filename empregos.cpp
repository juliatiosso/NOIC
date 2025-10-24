#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 10;

int a[MAXN], b[MAXN];

ll pref[MAXN], suf[MAXN];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  for(int i=1; i<=n; i++) cin >> a[i];

  for(int i=1; i<=n; i++) cin >> b[i];

  for(int i=1; i<=n; i++) pref[i] = pref[i - 1] + b[i];

  for(int i=n; i>=1; i--) suf[i] = suf[i + 1] + max(a[i], 2 * b[i]);

  ll ans = 0;
  
  // caso em que Júlio nunca recebe a promoção
  for(int i=1; i<=n; i++) ans += max(a[i], b[i]);

  priority_queue<int> pq;
    
  for(int i=1; i<k; i++) pq.push(a[i] - b[i]);
  
  ll sum = 0; // ganho ao fazer as trocas

  for(int i=k; i<=n; i++){

    pq.push(a[i] - b[i]);

    if(pq.size() > k){
      sum += pq.top(); // adicionando o maior valor candidato 
      pq.pop();
    }

    ans = max(ans, pref[i] + suf[i + 1] + sum);

  }

  cout << ans << "\n";

  return 0;
}
