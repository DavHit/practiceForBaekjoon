#include <iostream>

int main(){
    int N;
    scanf("%d", &N);
    int i,j,cnt,num[10000001]={0};
    for(i=2;;i++){
        if(N==1)
            break;
        
        if(num[i]==0){
         
            while(N%i==0){
                printf("%d\n",i);
                N/=i;
            }

            j=2;
            while(i*j<=N){
                num[i*j]++;     //에라토스테네스의 채 이용해서 소수 나누기 진행;
                j++;
            }
        }
        else
            continue;
    }

    return 0;
}