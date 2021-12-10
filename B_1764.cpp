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

  unordered_map<string, int> notSeen;
  vector<string> notHeard;
  string name1="";
  string name2="";
  int nm = ( n > m ? n : m );
  for(int i=0;i<n;i++){
    cin>>name1;
    notSeen[name1]=0;
  }
  for(int i=0;i<m;i++){
    cin>>name2;
    if(notSeen.find(name2)!=notSeen.end()){    //(unordered_map이름)에서 (key)를 찾는 방법 => unordered_map[key]!=unordered_map.end() 으로 검색
      notHeard.push_back(name2);
    }
  }

  sort(notHeard.begin(), notHeard.end() );

  int siz=notHeard.size();
  cout<<siz<<'\n';
  for(int i=0;i<siz;i++){
    cout<<notHeard[i]<<'\n';
  }

  return 0;
}