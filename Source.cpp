#include <stdio.h>
#include <string.h>

double ar[1005], br[1005];
int main()
{
	int N, i, j;
	while (scanf("%d", &N) != EOF && N)
	{
		memset(ar, 0, sizeof(ar));
		memset(br, 0, sizeof(br));
		double max, sum;
		max = sum = 0;
		for (i = 1; i <= N; i++)
			scanf("%lf", &ar[i]);
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (ar[i] > ar[j] && br[j] + ar[i] > br[i])
					br[i] = br[j] + ar[i];
			}
			if (br[i] > max)
				max = br[i];
		}
		printf("%.0lf\n", max);
	}

	return 0;
}