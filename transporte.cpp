#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, t; cin >> n >> t;

  // tempo do primeiro estudante do ônibus atual
  int tj; cin >> tj;

  // contador da quantidade de transportes
  int cnt = 1; 

  for(int i=2; i<=n; i++){

    int ti; cin >> ti;

    // se a diferença ultrapassa t, um novo ônibus é necessário
    if(ti - tj > t){
      tj = ti;
      cnt ++;
    }

  }

  cout << cnt << "\n";

  return 0;
}
