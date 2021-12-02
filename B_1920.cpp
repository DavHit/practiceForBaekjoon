#include <iostream>

#include <stack>
#include <queue>
#include <vector>
#include <cstring>

#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int n,m;
vector<int> a;

int find(int key){    // 정렬된 배열에서 검색할 때
  int start=0;
  int end=n-1;
  int mid;      // arr[mid]랑 key를 비교하여 빠르게 찾는 방법.

  while(start<=end){
    mid=(start+end)/2;
    
    if(a[mid]==key){
      cout<<"1\n";
      return 0;

    } else if(key<a[mid]){
      end=mid-1;    //핵심
    } else{
      start=mid+1;  //핵심
    }
  }
  cout<<"0\n";

  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int tmp;

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>tmp;
    a.push_back(tmp);
  }
  sort(a.begin(),a.end());

  cin>>m;
  for(int i=0;i<m;i++){
    cin>>tmp;
    find(tmp);
  }
 
  return 0;
}