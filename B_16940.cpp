#include <iostream>

#include <stack>
#include <queue>
#include <vector>
#include <cstring>

#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> a[100001];      //인접리스트를 위한 벡터 선언
    bool check[100001];             //숫자를 지났는지 확인을 위한 bool 배열 선언
    int order[100000];          //순서 입력을 위한 배열
    int parent[100001];

    int n;
    cin>>n;
    int from, to;
    for(int i=1;i<n;i++){
        cin>>from>>to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    int tmp;
    for(int i=0;i<n;i++){
        cin>>order[i];
    }

    queue<int> q;
    q.push(1);
    check[1]=true;
    int m=1;        //확인한 것까지의 번호 (?)
    for(int i=0;i<n;i++){
        /*      참고 코드에 있는 부분인데 사실 왜 있는지는 잘 모르겠음
        if (q.empty()) {
            cout << 0 << '\n';
            return 0;
        }
        */
        int x=q.front();
        q.pop();
        if(x != order[i]){      //  q에 i번째로 넣은 값과 order[i]가 다를 때
            cout<<0;
            return 0;
        }
        int cnt=0;
        for(int y=0;y<a[x].size();y++){
            if(check[ a[x][y]]==false){
                parent[a[x][y]] = x;
                cnt+=1;
            }
        }
        for(int j=0;j<cnt;j++){
            if(m+j>=n || parent[order[m+j]] !=x){
                cout<<0;
                return 0;
            }
            q.push(order[m+j]);
            check[order[m+j]]=true;
        }
        m+=cnt;
    }
    cout<<1;

    return 0;
}