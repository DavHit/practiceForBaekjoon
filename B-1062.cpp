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


// 비트마스크 사용 방법은 1. 배운 단어의 마스크 : mask1 / 2. 말하고 싶은 단어의 마스크 : mask2 라고 한다면
// mask2 & ((1<<26) - 1 - mask1) == 0 임을 이용해서 값을 찾는다.

bool alphabet[26];

int ans =0;

void count(vector<string> &word){
  int cnt=0;

  int n = word.size();
  for(int i=0;i<n;i++){
    bool ok = true;
    for(char x : word[i] ){
      if(!alphabet[x-'a']){
        ok=false;
        break;
      }
    }
    if(ok) cnt++;
  }
/*
  if(cnt!=0){
    for(int i=0;i<26;i++){
          if(alphabet[i]){
        cout<<(char)(i+'a')<<' ';
      }
    }
    cout<<"    cnt is "<<cnt<<'\n';
  }
*/

  if(ans<cnt) ans=cnt;

  return;
}

void select(int index, int k, vector<string> &word){
  if(26<index) return;
  if(k<0) return;

  if(k==0){
    count(word);
    return;
  }

  if(index == 'a'-'a' || index == 'n'-'a' || index == 't'-'a' || index == 'i'-'a' || index == 'c'-'a'){
    select(index+1, k, word);
  } else{
    alphabet[index] = true;
    select(index+1, k-1, word);
    alphabet[index] = false;
    select(index+1, k, word);
  }

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  alphabet['a'-'a'] = true;
  alphabet['n'-'a'] = true;
  alphabet['t'-'a'] = true;
  alphabet['i'-'a'] = true;
  alphabet['c'-'a'] = true;

  int n,k;
  cin>>n>>k;

  vector<string> word(n);

  for(int i=0;i<n;i++){
    cin>>word[i];
  }

  select(0, k-5, word);

  cout<<ans;

  return 0;
}