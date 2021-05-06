#include <iostream>

using namespace std;

int n;
long long d[100001][4]={
    {0,0,0,0},
    {1,1,0,0},
    {1,0,1,0},
    {3,1,1,1}
};

void SumD(){

    int m=4;
    while(m<=100000){           

        d[m][1]=(d[m-1][2]+d[m-1][3])%1000000009;       // d[m][0]에서 %1000000009해야 하고,
        d[m][2]=(d[m-2][1]+d[m-2][3])%1000000009;       // 각각에서도 미리 해줘야, 계산의 오차 발생 x
        d[m][3]=(d[m-3][1]+d[m-3][2])%1000000009;
        
        d[m][0]=(d[m][1]+d[m][2]+d[m][3])%1000000009;

        m++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    SumD();
    while(t--){
        cin>>n;
        cout<<d[n][0]<<"\n";
    }
    return 0;
}