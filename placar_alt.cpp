#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int gols[MAXN][2];

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int p; cin >> p;

  for(int i=1; i<=p; i++) cin >> gols[i][0];

  int c; cin >> c;

  for(int i=1; i<=c; i++) cin >> gols[i][1];

  /* 
    adicionamos o tempo 101 no final das listas para facilitar
    a comparação quando um dos ponteiros chega no fim do vetor
  */

  gols[p + 1][0] = gols[c + 1][1] = 101;

  int l = 0, r = 0;

  int pontos[2] = {0, 0};

  int placar = p + c + 1;

  while(placar--){
    
    cout << pontos[0] << " " << pontos[1] << "\n";

    if(gols[l + 1][0] < gols[r + 1][1]){ // próximo gol é de Paulo
      pontos[0] ++;
      l ++;
    } else{ // próximo gol é de Camila
      pontos[1] ++;
      r ++;
    }

  }

  return 0;
}
