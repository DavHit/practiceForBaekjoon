#include <iostream>

using namespace std;

bool find(int x, int y, int c){
    if(c==3){
        if(x==2&&y==2)
            return true;
        else
            return false;
    }
    else{
        c/=3;
        if(  x>c&&x<=2*c  &&   y>c&&y<=2*c )
            return true;
        else{
            if(x>2*c)
                x-=2*c;
            else if(x>c)
                x-=c;

            if(y>2*c)
                y-=2*c;
            else if(y>c)
                y-=c;
                            
            return find(x,y,c);
        }
    }
}

void PrintStar(int n,int m,int a,int b,int c){
    int i,j;
    if(m!=1){
        i=m/3;
        PrintStar(n,m/3,a,b-2*i,c);
        cout<<endl;
        PrintStar(n,m/3,a,b-i,c);
        cout<<endl;
        PrintStar(n,m/3,a,b,c);
    }
    else if(n!=1){
        i=n/3;
        PrintStar(n/3,m,a-2*i,b,c);
        PrintStar(n/3,m,a-i,b,c);
        PrintStar(n/3,m,a,b,c);
    }
    else{
        if( find(a,b,c)==true  )
            cout<<" ";
        else
            cout<<"*";
    }
}

int main(){
    int N;
    cin>>N;
    PrintStar(N,N,N,N,N);
    return 0;
    
}