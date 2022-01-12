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

  int n;
  cin>>n;

  priority_queue<int, vector<int>, greater<int> > pq; //큰거를 top에다 두기, 반대로 하려면 less<int> 사용
                                                      //priority_queue : queue에 자동 정렬
  while(n--){
    int x;
    cin>>x;
    if(x==0){
      if(pq.empty()) cout<<"0\n";
      else{
        cout<<pq.top()<<'\n';
        pq.pop();
      }
    } else{
      pq.push(x);
    }
  }
  return 0;
}