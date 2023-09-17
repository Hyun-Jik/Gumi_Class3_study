#include <stdio.h>
#include <stdlib.h>
#define min(x, y) (((x)<(y))?((x)):((y)))
int dp[1000001];
int N;
int main() {
    dp[1] = 0;
    for(int i=2;i<1000001;i++){
        int tmp = dp[i-1]+1;
        if(i%2==0 && i > 0)
            tmp = min(tmp, dp[i/2]+1);
        if(i%3==0 && i > 0)
            tmp = min(tmp, dp[i/3]+1);
        dp[i] = tmp;
    }
    scanf("%d",&N);
    printf("%d\n",dp[N]);
    return 0;
}
