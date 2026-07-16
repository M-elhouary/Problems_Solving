#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

char **setup(int h, int w)
{
	char **board = malloc(h * sizeof(char*));
	for (int i = 0; i < h; i++)
	{
		board[i] = malloc(w);
		for (int j = 0; j < w; j++)
			board[i][j] = ' ';
	}
	return board;
}
char **life(char **board, int h, int w, int it)
{
	int iset[] = {-1,-1,-1,0,0,1,1,1};
	int jset[] = {-1,0,1,-1,1,-1,0,1};
	while (it--)
	{
		char **next = setup(h, w);
		for (int i = 0; i < h; i++)
		{
			for ( int j = 0; j < w; j++)
			{
				int alive_n = 0;
				for (int n = 0; n < 8; n++)
				{
					int in = i + iset[n];
					int jn = j + jset[n];
					if (in >= 0 && in < h && jn >= 0 && jn < w && board[in][jn] == '0')
						alive_n++;
				}
				if (alive_n == 3 || (alive_n == 2 && board[i][j] == '0'))
					next[i][j] = '0';
			}
		}
		for (int i = 0; i < h; i++)
			free(board[i]);
		free(board);
		board = next;
	}
	return board;
}
int main(int ac, char** av)
{
	if (ac != 4)
		return 1;
	int w = atoi(av[1]);
	int h = atoi(av[2]);
	int it = atoi(av[3]);
	char **board = setup(h, w);
	int x = 0, y = 0, draw = 0;
	char cmd;
	while (read(0, &cmd, 1) == 1)
	{
		if (cmd == 'w' && x > 0)
			x--;
		if (cmd == 's' && x < h - 1)
			x++;
		if (cmd == 'a' && y > 0)
			y--;
		if (cmd == 'd' && y < w - 1)
			y++;
		if (cmd == 'x')
			draw = !draw;
		if (draw)
			board[x][y] = '0';
	}
	board = life(board, h, w, it);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			putchar(board[i][j]);
		putchar('\n');
		free(board[i]);
	}
	free(board);
	return 0;
}