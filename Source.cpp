#include <stdio.h>
#include <string.h>

int arr[40];
int main()
{
	int m, n, i, j;
	freopen("data.txt", "r", stdin);
	while (scanf("%d%d", &m, &n) != EOF && m || n)
	{
		memset(arr, 0, sizeof(arr));
		arr[1] = 1;

		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n && i + j <= m; j++)
			{
				arr[i + j] += arr[i];
			}
		}
		printf("%d\n", arr[m]);
	}
	return 0;
}