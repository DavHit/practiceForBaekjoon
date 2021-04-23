#include <iostream>
#include <cstring>

using namespace std;

char chessW[8][8]={
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
};

char chessB[8][8]={
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66},
    {66, 87, 66, 87, 66, 87, 66, 87},
    {87, 66, 87, 66, 87, 66, 87, 66}
};

int CountChangeSpot(char (* chess)[8] , char (* wood)[8] ){
    int i, j;
    int cnt=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if( chess[i][j] != wood[i][j]  )
                cnt++;
        }
    }

    return cnt;
}

int MakeChess(int i, int j, char (* wood)[50]){
    char test[8][8];
    int k,l;
    for(k=0;k<8;k++){
        for(l=0;l<8;l++){
            test[k][l]= wood[i+k][j+l];
        }
    }
    return ( CountChangeSpot(chessW,test)>CountChangeSpot(chessB,test) ? CountChangeSpot(chessB,test) : CountChangeSpot(chessW,test) );  
}

int main(){
    int N, M,i,j;
    scanf("%d %d\n", &N, &M);
    char origin[50][50],temp;
    for(i=0;i<N;i++){
        for(j=0;j<=M;j++){
            scanf("%c", &temp);
            origin[i][j]=temp;
        }
    }

    int min=64;
    for(i=0;i<N-7;i++){
        for(j=0;j<M-7;j++){
            if(MakeChess(i, j, origin)<min)
                min=MakeChess(i,j,origin);
        }
    }

    printf("%d", min);

    return 0;
}