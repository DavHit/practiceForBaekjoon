#include <iostream>

#include <stack>
#include <queue>
#include <vector>
#include <cstring>

#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
string a[20];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int go(int x1,int y1, int x2, int y2, int cnt){
    if(cnt>10) return -1;
    
    bool fall1=false, fall2=false;
    if( x1<0 || n<=x1 || y1<0 || m<=y1 ) fall1=true;
    if( x2<0 || n<=x2 || y2<0 || m<=y2 ) fall2=true;
    
    if(fall1 && fall2) return -1;
    if(fall1 || fall2) return cnt;

    int ans=-1;
    int nx1,ny1,nx2,ny2;
    for(int i=0;i<4;i++){
        nx1=x1+dx[i];
        ny1=y1+dy[i];
        nx2=x2+dx[i];
        ny2=y2+dy[i];
        if( 0<=nx1 && nx1<n && 0<=ny1 && ny1<m && a[nx1][ny1]=='#'){
            nx1=x1;
            ny1=y1;
        }
        if( 0<=nx2 && nx2<n && 0<=ny2 && ny2<m && a[nx2][ny2]=='#'){
            nx2=x2;
            ny2=y2;
        }

        int tmp=go(nx1,ny1,nx2,ny2,cnt+1);              //이 부분이 핵심 포인트
        if(tmp==-1) continue;
        if(ans==-1 || ans>tmp){
            ans=tmp;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    int x1,y1,x2,y2;
    x1=y1=x2=y2=-1;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'o') {
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
                a[i][j] = '.';
            }
        }
    }

    cout<<go(x1,y1,x2,y2,0);

    return 0;
}