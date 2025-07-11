#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main(){

  int n; cin >> n;

  for(int i=1; i<=n; i++) cin >> a[i];

  int max_a = 0; // maior altura vista até agora

  int ans = 0; // quantidade de alunos escondidos

  for(int i=n; i>=1; i--){
    if(a[i] > max_a){
      max_a = a[i];
    } else ans ++;
  }

  cout << ans << "\n";

  return 0;
}
