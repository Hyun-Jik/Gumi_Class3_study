#include<stdio.h>
int a, b, c;
int dp[21][21][21];
int f(int n1, int n2, int n3) {
	if (n1 <= 0 || n2 <= 0 || n3 <= 0) {
		return 1;
	}
	else if (n1 > 20 || n2 > 20 || n3 > 20) {
		return f(20, 20, 20);
	}
	else {
		if (dp[n1][n2][n3] == -1) {
			if (n1 < n2 && n2 < n3) {
				dp[n1][n2][n3] = f(n1, n2, n3 - 1) + f(n1, n2 - 1, n3 - 1) - f(n1, n2 - 1, n3 - 1);
			}
			else {
				dp[n1][n2][n3] = f(n1 - 1, n2, n3) + f(n1 - 1, n2 - 1, n3) + f(n1 - 1, n2, n3 - 1) - f(n1 - 1, n2 - 1, n3 - 1);
			}
		}
		return dp[n1][n2][n3];
	}
}
int main(void) {
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 21; k++)
				dp[i][j][k] = -1;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		printf("w(%d, %d, %d) = %d\n", a, b, c, f(a, b, c));
	}
	return 0;
}
