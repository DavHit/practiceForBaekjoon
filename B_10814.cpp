#include <iostream>
#include <cstring>
#include <cstdio>

typedef struct member{
	int age;
	char name[101];
	int order;
} MEMBER;

MEMBER OJ[100000]={0};
MEMBER temp[100000]={0};

void Merge(int start, int mid, int end){
	int left = start;
	int right = mid+1;
	int cnt=start;
	while(left<=mid && right<=end){
		if(OJ[left].age>OJ[right].age)
			temp[cnt++]=OJ[right++];
		else if(OJ[left].age<OJ[right].age)
			temp[cnt++]=OJ[left++];
		else{
			if(OJ[left].order<OJ[right].order)
				temp[cnt++]=OJ[left++];
			else if(OJ[left].order>OJ[right].order)
				temp[cnt++]=OJ[right++];
		}
	}
	int tmp = ( (left>mid) ? right : left );
	while(cnt<=end) temp[cnt++]=OJ[tmp++];

	for(int i=start;i<=end;i++) OJ[i]=temp[i];
}

void SNM(int first, int last){	
	if(first>=last) return;
	int mid = (first + last)/2;
	if(first<last){
		SNM(first,mid);
		SNM(mid+1, last);
		Merge(first, mid, last);
	}
}

int main(){
	int N,i;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d %s", &OJ[i].age, OJ[i].name);
		OJ[i].order = i;
	}
	
	SNM(0,N-1);

	for(i=0;i<N;i++)
		printf("%d %s\n", OJ[i].age, OJ[i].name);
	
	return 0;
}