#include <stdio.h>
#include <math.h>

char maze[10][10];
int N, M, T, dx, dy;
int isSucc = 0;
void dfs(int x, int y, int cnt)
{
	if (cnt > T)
		return;
	if (x == dx && y == dy && cnt == T)
	{
		isSucc = 1;
		return;
	}

	int temp = (T - cnt) - abs(dx - x) - abs(dy - y);
	if (temp < 0 || temp % 2 == 1)
		return;

	maze[x][y] = 'X';

	if (x - 1 >= 0 && maze[x - 1][y] != 'X')
		dfs(x - 1, y, cnt + 1);
	if (x + 1 < N && maze[x + 1][y] != 'X')
		dfs(x + 1, y, cnt + 1);
	if (y - 1 >= 0 && maze[x][y - 1] != 'X')
		dfs(x, y - 1, cnt + 1);
	if (y + 1 < M && maze[x][y + 1] != 'X')
		dfs(x, y + 1, cnt + 1);

	maze[x][y] = '.';
}

int main()
{
	freopen("data.txt", "r", stdin);
	while (scanf("%d%d%d", &N, &M, &T) != EOF && N || M || T)
	{
		int i, j, si, sj, w = 0;
		isSucc = 0;
		getchar();
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				scanf("%c", &maze[i][j]);
				if (maze[i][j] == 'X')
					w++;
				else if (maze[i][j] == 'D')
					dx = i, dy = j;
				else if (maze[i][j] == 'S')
					si = i, sj = j;
			}
			getchar();
		}
		if (M * N - w > T)
			dfs(si, sj, 0);

		if (isSucc)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}