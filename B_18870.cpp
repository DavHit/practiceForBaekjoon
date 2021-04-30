#include <iostream>

enum A{
    INPUT=1, ORDER=2
};

typedef struct x{
    int input;
    int order;
    int below;
} X;

int N;
X arr[1000001]={0};
X temp[1000001]={0};

void MergeByInput(int first, int last, int mid){
    int left = first;
    int right = mid + 1;
    int k=first;
    while(left<=mid && right <= last){
        if(arr[left].input>arr[right].input)
            temp[k++]=arr[right++];
        else if(arr[left].input <= arr[right].input)
            temp[k++]=arr[left++];
    }
    int tmp = left>mid ? right : left ;
    while(k<=last) temp[k++]=arr[tmp++];
    for(int i=first;i<=last;i++) arr[i]=temp[i];
}

void MergeByOrder(int first, int last, int mid){
    int left = first;
    int right = mid + 1;
    int k=first;
    while(left<=mid && right <= last){
        if(arr[left].order > arr[right].order)
            temp[k++]=arr[right++];
        else if(arr[left].order < arr[right].order)
            temp[k++]=arr[left++];
    }
    int tmp = left>mid ? right : left ;
    while(k<=last) temp[k++]=arr[tmp++];
    for(int i=first;i<=last;i++) arr[i]=temp[i];
}

void SeperateAndMerge(int first, int last, int which){
    if(first>=last) return;
    int mid = (first+last)/2;
    if(first<last){
        if(which==INPUT){
            SeperateAndMerge(first, mid, INPUT);
            SeperateAndMerge(mid+1, last, INPUT);
            MergeByInput(first, last, mid);
        }
        else if(which==ORDER){
            SeperateAndMerge(first, mid, ORDER);
            SeperateAndMerge(mid+1,last,ORDER);
            MergeByOrder(first, last, mid);
        }
    }
}

void DecideBelow(){
    int B=0;
    arr[0].below=B;
    for(int i=1;i<N;i++){
        if(arr[i].input!=arr[i-1].input){
            B++;
        }
        arr[i].below=B;
    }
}


int main(){
    scanf("%d", &N);
    int i;
    for(i=0;i<N;i++){
        scanf("%d", &arr[i].input);
        arr[i].order=i;
    }


    SeperateAndMerge(0,N-1,INPUT);      // 입력값 비교해서 오름차순으로 정렬

    DecideBelow();                  // 입력값 기준으로 해서 below값 결정

    SeperateAndMerge(0,N-1,ORDER);      // 다시 원래 순서(order)대로 정렬

    for(i=0;i<N;i++)
        printf("%d ",arr[i].below);

    return 0;
}