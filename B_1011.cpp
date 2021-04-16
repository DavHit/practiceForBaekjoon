#include <iostream>

typedef unsigned long long ULL;

ULL Combinate(ULL a, ULL b){
    if(a==0||b==a||b==0){
        return 1;
    }
    else{
        return Combinate(a-1,b)+Combinate(a-1,b-1);
    }
}


int main(void){

    ULL T[10001];
    scanf("%lld", &T[0]);
    int i;
    ULL k, n;
    
    for(i=1;i<=T[0];i++){
        scanf("%lld", &k);
        scanf("%lld", &n);      // k+n C k+1  왜 인지 모르겠지만 컴비네이션자체를 구성하려고 하니 큰 수에서 계산값이 이상하게 나옴
        T[i]=Combinate( (n+k), (k+1) );     // 그래서 n C k = n-1 C k-1 + n-1 C K 를 함수로 구현해서 푸는게 나음.
    }

    for(i=1;i<=T[0];i++){
        printf("%lld\n", T[i]);
    }

    return 0;
}