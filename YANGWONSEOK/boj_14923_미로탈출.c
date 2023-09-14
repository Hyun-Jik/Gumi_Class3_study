#include<stdio.h>

int N, M;
int Hx, Hy;
int Ex, Ey;
int ans;
int graph[1000][1000];
int used[1000][1000][2];
int d[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int queue[1000000][3];
int front = -1;
int rear = -1;

int main(void){
    scanf("%d %d",&N, &M);
    scanf("%d %d",&Hx, &Hy);
    scanf("%d %d",&Ex, &Ey);
    Hx--;Hy--;Ex--;Ey--;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&graph[i][j]);
            used[i][j][0] = 0;
            used[i][j][1] = 0;
        }
    }
    ans = -1;
    queue[++rear][0] = Hx;
    queue[rear][1] = Hy;
    queue[rear][2] = 1;
    used[Hx][Hy][1] = 1;
    while(1){
        int r = queue[++front][0];
        int c = queue[front][1];
        int chance = queue[front][2];
        if(r == Ex && c == Ey){
            ans = used[r][c][chance]-1;
            break;
        }
        for(int i=0;i<4;i++){
            int nr = r + d[i][0];
            int nc = c + d[i][1];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M){
                if(graph[nr][nc]==0 && used[nr][nc][chance] == 0){
                    used[nr][nc][chance] = used[r][c][chance]+1;
                    queue[++rear][0] = nr;
                    queue[rear][1] = nc;
                    queue[rear][2] = chance;
                }
                else if(graph[nr][nc]==1 && used[nr][nc][chance] == 0 && chance==1){
                    used[nr][nc][chance-1] = used[r][c][chance]+1;
                    queue[++rear][0] = nr;
                    queue[rear][1] = nc;
                    queue[rear][2] = chance-1;
                }
            }
        }
        if(front==rear){
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
