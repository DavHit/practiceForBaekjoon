#include <iostream>     // 재귀함수 이용

int move(int n){        // 움직이는 횟수 파악
    if(n==1)
        return 1;
    else
        return 1+2*move(n-1);
}

void move(int n, int from, int to){ // 몇번에서 몇번으로 움직이는지 파악
    if(n==1){
        printf("%d %d\n", from, to);
    }
    else{
        move( (n-1)/2 , from, 6-from-to );
        move(1, from , to );
        move( (n-1)/2 , 6-from-to , to);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    printf("%d\n", move(N));
    move(move(N),1,3);
}