// Date : 13.05.2013
// Development Environment : Visual Studio 2012

#include <stdio.h>
#pragma warning ( disable : 4703 )

int findPivot(int[], int);
void matrixTranspose(char[][10], int);
void matrixReverseRows(char[][10], int);
void findCoordinateReversedOne(char[][10], int, int[], int[]);
void matrixReset(char[][10], int);

void main()
{
	FILE *fp, *fPtr;
	char matrix[10][10], xPivot, yPivot, xPivotNew, yPivotNew;
	int coor_x[4], coor_y[4], coorx = 0, coory = 0;
	int changing_x, changing_y;

	if ((fp = fopen("input.txt", "r")) == NULL)
		printf("Dosya acilamadi");

	else
	{
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				fscanf(fp, "%c", &matrix[i][j]);
				fseek(fp, 1, SEEK_CUR); // boþluklar için imleci 1 arttýr.

				if (matrix[i][j] == '1')
				{
					if (coorx >= 4 || coory >= 4)
						return;

					coor_y[coory++] = i;
					coor_x[coorx++] = j;
				}
			}
			fseek(fp, 1, SEEK_CUR); // bir alt satýr için imleci 1 arttýr.

		}

		xPivot = findPivot(coor_x, 4);
		yPivot = findPivot(coor_y, 4);

		matrixTranspose(matrix, 10);
		matrixReverseRows(matrix, 10);

		findCoordinateReversedOne(matrix, 10, coor_x, coor_y);

		xPivotNew = findPivot(coor_x, 4);
		yPivotNew = findPivot(coor_y, 4);

		changing_x = xPivot - xPivotNew;
		changing_y = yPivot - yPivotNew;

		for (int j = 0; j <= 3; j++)
		{
			coor_x[j] += changing_x;
			coor_y[j] += changing_y;
		}

		matrixReset(matrix, 10); // matrisi sýfýrla.

		// 1 olan koordinatlarý bul.
		for (int t = 0; t <= 3; t++)
		{
			if (coor_x[t] <= 9 && coor_y[t] <= 9)
			{
				matrix[coor_y[t]][coor_x[t]] = '1';
			}
			else
			{
				printf("Out of boundary!!");
				break;
			}

		}


		if ((fPtr = fopen("output.txt", "w")) != NULL)
		{
			for (int b = 0; b <= 9; b++) // yeni matrisi output.txt'ye yaz.
			{
				for (int c = 0; c <= 9; c++)
				{
					fprintf(fPtr, "%c ", matrix[b][c]);
				}
				fprintf(fPtr, "\n");
			}

		}

	}

	fclose(fp);
	fclose(fPtr);

	getchar();
	getchar();
}

int findPivot(int z[], int n)
{
	int a = 0;

	for (int p = 0; p <= n - 1; p++)
	{
		for (int w = p + 1; w <= n - 1; w++)
		{
			if (z[p] == z[w])
			{
				a = z[p];
			}
		}
	}

	return a;
}

void matrixTranspose(char a[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			char gecici = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = gecici;
		}
	}

}

void matrixReverseRows(char b[][10], int n)
{
	for (int k = 0; k <= n - 1; k++)
	{
		for (int q = 0; q < n / 2; q++)
		{
			char temp = b[k][q];
			b[k][q] = b[k][n - q - 1];
			b[k][n - q - 1] = temp;
		}
	}

}

void findCoordinateReversedOne(char dizi[][10], int n, int array_x[], int array_y[])
{
	int x = 0, y = 0;

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (dizi[i][j] == '1')
			{
				if (x >= 4 || y >= 4)
					return;

				array_y[y++] = i;
				array_x[x++] = j;
			}

		}

	}

}

void matrixReset(char f[][10], int n)
{
	for (int i = 0; i <= n - 1; i++)
		for (int j = 0; j <= n - 1; j++)
			f[i][j] = '0';
}
