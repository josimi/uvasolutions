// problem 10496
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int dp[1024 * 12];
int x[12];
int y[12];
int n;

int f(int v, int p)
{

}

int main() {
	int ntests;
	scanf("%d", &ntests);

	while(ntests--)
	{
		int w, h;
		scanf("%d %d", &w, &h);

		memset(dp, -1, sizeof(dp));

		dp[0] = 0;

		scanf("%d %d", &x, &y);

		scanf("%d", &n);

		for(int i = 1;i <= n;i++)
		{
			scanf("%d %d", x + i, y + i);
		}

		printf("The shortest path has length %d\n", f((1 << n) - 1, 0));
	}

	return 0;
}