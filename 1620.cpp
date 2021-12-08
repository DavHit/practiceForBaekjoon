#include <iostream>

#include <stack>
#include <queue>
#include <vector>
#include <string>

#include <cmath>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n,m;
  cin>>n>>m;

  unordered_map<int,string> pokemonIS;  // unordered_map 활용 -> 추가 공부 필요..!
  unordered_map<string,int> pokemonSI;

  for(int i=1;i<=n;i++){
    string name;
    cin>>name;
    pokemonIS[i]=name;
    pokemonSI[name]=i;
  }

  for(int i=1;i<=m;i++){
    string find;
    cin>>find;
    if('0'<=find[0] && find[0]<='9') cout<<pokemonIS[stoi(find)]<<"\n";   //stoi : string to int func. 이런거 몇개 더 외워두기
    else cout<<pokemonSI[find]<<"\n";
  }

  return 0;
}