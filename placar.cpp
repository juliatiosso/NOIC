#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int marc[MAXN];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int p; cin >> p;

  while(p--){
    int t; cin >> t;
    marc[t] = 1;
  }

  int c; cin >> c;

  while(c--){
    int t; cin >> t;
    marc[t] = 2;
  }

  int pontos[2] = {0, 0}; 

  cout << "0 0\n"; // placar inicial 

  for(int i=1; i<=100; i++){
    if(!marc[i]) continue; // não houve gol no tempo i    
    pontos[marc[i] - 1] ++;
    cout << pontos[0] << " " << pontos[1] << "\n";
  }

  return 0;
}
