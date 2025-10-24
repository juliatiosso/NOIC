#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e5 + 10;

ll a[MAXN], b[MAXN];

ll pref[MAXN];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  for(int i=1; i<=n; i++) cin >> a[i];

  for(int i=1; i<=n; i++) cin >> b[i];

  // como todos os b's são iguais, não importa a ordem dos a's
  // então podemos ordenar o vetor para facilitar

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  // pref[i] := soma dos i maiores valores de a
  for(int i=1; i<=n; i++) pref[i] = pref[i - 1] + a[i];

  ll ans = 0;

  for(int i=0; i<=k; i++) ans = max(ans, b[1] * i + pref[n - i]);

  for(int i=(k + 1); i<=n; i++) ans = max(ans, b[1] * k + 2LL * b[i] * (i - k) + pref[n - i]);

  cout << ans << "\n";

  return 0;
}
