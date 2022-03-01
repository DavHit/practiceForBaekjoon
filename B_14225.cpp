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

bool c[20*100000+10];
int a[20];
int n;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i=0; i<n; i++) {
      cin >> a[i];
  }
  for (int i=0; i<(1<<n); i++) {
      int sum = 0;
      for (int j=0; j<n; j++) {
          if (i & (1<<j)) {   //비트마스크 사용 :  ' & ' **!!
              sum += a[j];
          }
      }
      cout<<sum<<' ';
      c[sum] = true;
  }

  for (int i=1;; i++) {
      if (c[i] == false) {
          cout << '\n' << i << '\n';
          break;
      }
  }
  return 0;
}