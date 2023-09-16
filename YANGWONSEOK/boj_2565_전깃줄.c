#include <stdio.h>
#include <stdlib.h>
#define max(x, y) (((x)>(y))?((x)):((y)))
typedef struct{
    int start;
    int end;
}info;
int N;
info arr[100];
int dp[100];
int res;
int compare(void *a1, void *a2){
    if(((info*)a1)->start > ((info*)a2)->start){
        return 1;
    }
    else{
        return -1;
    }
}
int f(){
    int res = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(arr[i].end >= arr[j].end){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}
int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&arr[i].start, &arr[i].end);
        dp[i] = 1;
    }
    qsort(arr,N,sizeof(info),compare);
    res = f();
    printf("%d\n",N-res);
    return 0;
}

