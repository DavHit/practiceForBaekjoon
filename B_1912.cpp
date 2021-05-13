#include <iostream>
#include <stack>

using namespace std;

    int N;
    int A[1001]={0};
    int D[1001]={0};

int V[1001]={0};

void go(int p){
    if(p==-1) return ;
    else{
        go(V[p]);
        cout<<A[p]<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int maxD=1;             // N=1인 경우 에 대해서 값이 나오게 하기 위해서 이렇게 설정.    
    int p=1;

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        D[i]=1;
        V[i]=-1;
        for(int j=1;j<i;j++){
            if(A[j]<A[i] && D[i] < D[j]+1){
                D[i]=D[j]+1;
                V[i]=j;
                
                if(maxD<D[i]){
                    maxD=D[i];
                    p=i;
                }
            }
        }
    }

    cout<<maxD<<"\n";
    go(p);

    return 0;
}