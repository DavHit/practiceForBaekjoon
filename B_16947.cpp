#include <iostream>

#include <stack>
#include <queue>
#include <vector>
#include <cstring>

#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

    vector<int> station[3001];
    int dist[3001];
    int check[3001];        // 0 unvisited, 1 visited, 2 cycle

int go(int idx, int pidx){     // pidx가 1~n 중 한 값일 경우 : pidx가 순환 시작점 / 0일 경우 : 아직 검사x / -1인 경우 : 순환 포함 x
    if(check[idx]==1){  //idx를 이미 방문한 적이 있을 때,
        return idx;     //go(idx,pidx)=idx값으로 리턴, 
    }
    check[idx]=1;
    for(int i=0;i<station[idx].size();i++){
        if(station[idx][i]==pidx) continue;
        int res = go(station[idx][i],idx);  // 1.idx으로 리턴 받을 경우 
        if(res == -1) return -1;
        if(res>=1) {
            check[idx]=2;   //순환에 포함된다고 체크
            if(idx==res) return -1; //맨 처음 순환 기준점에 다다랐을 때, -1 리턴 or 종료
            else return res;        //아직 순환 기준점에 다다르기 전에 계속 같은 res(=순환 기준점 idx) 리턴
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    int from, to;
    for(int i=0;i<n;i++){
        cin>>from>>to;
        station[from].push_back(to);
        station[to].push_back(from);
    }

    go(1,0);        // 1 대신 1~n 중 아무 숫자나 대입해도 됨, 0은 pidx 이전의 값을 나타내는데, 시작이므로 0으로 대입.

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(check[i]==2){
            dist[i]=0;
            q.push(i);
        }
        else{
            dist[i]=-1;
        }
    }
    while( !q.empty() ){
        int x=q.front();
        q.pop();
        for(int i=0;i<station[x].size();i++){
            if(dist[ station[x][i] ] == -1){
                q.push(station[x][i]);
                dist[station[x][i]]=dist[x]+1;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}