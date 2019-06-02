#include <stdio.h>

int place_number (int n, int sudoku[9][9])
{
	int i, j, k;
	int conflict, t;
	int row, col, block_row, block_col;
	
	if (n == 81)
	{
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
				printf ("%d ", sudoku[i][j]);
			printf ("\n");
		}
		return 1;
	}
	
	row = n / 9;
	col = n % 9;
	block_row = row / 3;
	block_col = col / 3;
	
	if (sudoku[row][col] != 0)
		return (place_number(n + 1, sudoku));
	for (t = 1; t <= 9; t ++)
	{
		conflict = 0;
		for (i = 0; i < 9 && !conflict; i++)
			if (((col != i) && (sudoku[row][i] == t)) || 
				((row != i) && (sudoku[i][col]) == t))
				conflict = 1;
			if (!conflict)
			{
				for (i = 0; i < 3 && !conflict; i++)
					for (j = 0; j < 3 && !conflict; j++)
						if (sudoku[3 * block_row + i][3 * block_col + j] == t)
							conflict = 1;
				if (!conflict)
				{
					sudoku[row][col] = t;
					if (place_number(n + 1, sudoku))
						return 1;
				}
			}
	}
	sudoku[row][col] = 0;
	return 0;
}

int main ()
{
	int i, j;
	int sudoku[9][9];
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			scanf ("%d", &(sudoku[i][j]));
	
	place_number (0, sudoku);
	return 0;
}

