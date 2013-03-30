#include <stdio.h>
#define INF 0x6ffffff
int main()
{
	int T, N, i, a, l, h, ml, mh, j;
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (i = 1; i <= T; i++)
	{
		scanf("%d", &N);
		int sum = 0;
		int maxsum = -INF;
		l = 1;h = 0;
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &a);
			sum += a;
			h++;
			if (sum > maxsum)
			{
				maxsum = sum, ml = l, mh = h;
			}
			if (sum < 0)
			{
				sum = 0;
				if (j < N)
					l = j + 1, h = j;
			}


		}
		
		printf("Case %d:\n%d %d %d\n", i, maxsum, ml, mh);
		if (i != T)
			printf("\n");
	}
	return 0;
}