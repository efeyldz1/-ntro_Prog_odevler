#include <stdio.h>

// functions prototypes
void baseConvert(int[], int);
void arrow(int, int[][60], char[][41]);
void assignBlank(char[][41]);

void main()
{
	char dizi[60][60], dizi2[41][41];
	int arr[4], size, matris[60][60];
	int coor_x[41], coor_y[41];
	int x = 0, y = 0, j = 0, p = 1;
	char path[41];

label:

	printf("Matris Boyutu : ");
	scanf("%d", &size);

	printf("\nDegerler ( her satirda %d deger olacak sekilde \n", size);
	printf("satir bazli giriliyor) :");

	// deðerleri al ve matrise yerleþtir..
	for (int r = 1; r < 3 * size; r = r + 3)
	{
		for (int c = 1; c < 3 * size; c = c + 3)
		{
			scanf(" %c", &dizi[r][c]);

			// A nýn ascii kodu : 65, F nin : 70
			if (dizi[r][c] >= 'A' && dizi[r][c] <= 'F')
			{
				matris[r][c] = dizi[r][c];
				matris[r][c] -= 55;
			}
			// 0 ýn ascii kodu : 48, 9 un : 57
			else if (dizi[r][c] >= '0' && dizi[r][c] <= '9')
			{
				matris[r][c] = dizi[r][c];
				matris[r][c] -= 48;
			}

		}
	}

	// sayilarýn ikilik tabandaki deðerlerini dört bir tarafýna yerleþtir..
	for (int r = 1; r < 3 * size; r = r + 3)
	{
		for (int c = 1; c < 3 * size; c = c + 3)
		{
			baseConvert(arr, matris[r][c]);

			matris[r - 1][c] = arr[0];
			matris[r][c + 1] = arr[1];
			matris[r + 1][c] = arr[2];
			matris[r][c - 1] = arr[3];
		}

	}

	// Tutarlýlýðý kontrol et.
	for (int r = 1; r < 3 * size; r = r + 3)
	{
		for (int c = 1; c < 3 * size; c = c + 3)
		{
			if (matris[r + 1][c] == matris[r + 2][c])
			{
				printf("Tutarsiz Yeniden giris yapin\n");
				goto label;
			}
			else  if (matris[r][c + 1] == matris[r][c + 2])
			{
				printf("Tutarsiz Yeniden giris yapin\n");
				goto label;
			}

		}

	}

	printf("Tutarli\n");

	assignBlank(dizi2);
	arrow(size, matris, dizi2);

	// baþlangýç noktasýný iþaretle
	dizi2[0][0] = '#';



	while (!(x == 2 * size && y == 2 * size))
	{

		if (y + 2 <= 2 * size && dizi2[x][y + 1] == '>' && dizi2[x][y + 2] != '#')
		{
			dizi2[x][y + 2] = '#';
			coor_x[j] = x;
			coor_y[j] = y + 2;
			y = y + 2;
			path[j++] = '>';
		}
		else if (x + 2 <= 2 * size && dizi2[x + 1][y] == 'V' && dizi2[x + 2][y] != '#')
		{
			dizi2[x + 2][y] = '#';
			coor_x[j] = x + 2;
			coor_y[j] = y;
			x = x + 2;
			path[j++] = 'V';
		}
		else if (y - 2 >= 0 && dizi2[x][y - 1] == '<' && dizi2[x][y - 2] != '#')
		{
			dizi2[x][y - 2] = '#';
			coor_x[j] = x;
			coor_y[j] = y - 1;
			path[j++] = '<';
			y = y - 2;
		}
		else if (x - 2 >= 0 && dizi2[x - 1][y] == 'n' && dizi2[x - 2][y] != '#')
		{
			dizi2[x + 2][y] = '#';
			coor_x[j] = x;
			coor_y[j] = y + 2;
			y = y + 2;
			path[j++] = 'n';
		}
		else
		{
			dizi2[x][y] = '#';
			x = coor_x[j - 2];
			y = coor_y[j - 2];
			j--;
		}
		if (x == 0 && y == 0)
		{
			printf("Yol yok.\n");
			break;
		}


	}

	// sonucu yazdýr.
	if (x == 2 * size && y == 2 * size)
	{
		printf("Yol var.\n");

		for (int h = 0; h <= j; h++)
		{
			if (h != 0)
			{
				if (path[h] == '>')
					printf(" sag ");

				if (path[h] == 'V')
					printf(" asagi ");

				if (path[h] == '<')
					printf(" sol ");

				if (path[h] == 'n')
					printf(" yukari ");
			}
			else
			{
				if (path[h] == '>')
					printf("sag ");

				if (path[h] == 'V')
					printf("asagi ");

				if (path[h] == '<')
					printf("sol ");

				if (path[h] == 'n')
					printf("yukari ");
			}
		}
	}


	getchar();
	getchar();
}

void baseConvert(int d[], int sayi)
{
	// 0000 0001
	if (0 == sayi || 1 == sayi)
	{
		d[3] = sayi;
		d[2] = 0;
		d[1] = 0;
		d[0] = 0;
	}
	// 0010 0011
	else if (2 == sayi || 3 == sayi)
	{
		d[3] = sayi % 2;
		d[2] = 1;
		d[1] = 0;
		d[0] = 0;
	}
	// 0100 0101 0110 0111
	else if (sayi >= 4 && sayi <= 7)
	{
		d[3] = sayi % 2;
		sayi /= 2;
		d[2] = sayi % 2;
		d[1] = 1;
		d[0] = 0;
	}
	// 1000 1001 1010 1011 1100 1101 1110 1111
	else if (sayi >= 8 && sayi <= 15)
	{
		d[3] = sayi % 2;
		sayi /= 2;
		d[2] = sayi % 2;
		sayi /= 2;
		d[1] = sayi % 2;
		d[0] = 1;
	}
	else
		printf("Lutfen 16 tabaninda bir rakam giriniz.");

}

void arrow(int size, int matris[][60], char a[][41])
{

	// üst ve alt kenara oklarý yerleþtir..
	for (int r = 1, i = 0; r <= 3 * size + 1; r = r + 3, i = i + 2)
	{
		for (int c = 1, j = 1; c <= 3 * size + 1 && j < 3 * size - (size - 1); c = c + 3, j = j + 2)
		{
			if (r == 3 * size + 1)
			{
				r = r - 2;

				// alt kenar için 0 sol, 1 sað.
				if (matris[r][c] == 0)
				{
					a[i][j] = '<';
				}
				else if (matris[r][c] == 1)
				{
					a[i][j] = '>';
				}

				r = r + 2;

			}
			else
			{

				// üst kenar için 0 sað, 1 sol.
				if (matris[r - 1][c] == 0)
				{
					a[i][j] = '>';
				}
				else if (matris[r - 1][c] == 1)
				{
					a[i][j] = '<';
				}

				// alt kenar için 0 sol, 1 sað.
				else if (matris[r + 1][c] == 0)
				{
					a[i][j] = '<';
				}
				else if (matris[r + 1][c] == 1)
				{
					a[i][j] = '>';
				}

			}

		}
	}

	// sað ve sol kenara oklarý yerþeþtir..
	for (int r = 1, i = 1; r <= 3 * size + 1 && i < 3 * size - (size - 1); r = r + 3, i = i + 2)
	{
		for (int c = 1, j = 0; c <= 3 * size + 1 && j < 3 * size - (size - 1); c = c + 3, j = j + 2)
		{
			if (c == 3 * size + 1)
			{
				c = c - 2;

				// sað kenar için 0 sol, 1 sað.
				if (matris[r][c] == 0)
				{
					a[i][j] = 'V';

				}
				else if (matris[r][c] == 1)
				{
					a[i][j] = 'n';

				}

				c = c + 2;

			}
			else
			{
				// sol kenar için 0 yukarý, 1 aþaðý
				if (matris[r][c - 1] == 0)
				{
					a[i][j] = 'n';
				}
				else if (matris[r][c - 1] == 1)
				{
					a[i][j] = 'V';
				}

				// sað kenar için 0 aþaðý, 1 yukarý.
				else if (matris[r][c + 1] == 1)
				{
					a[i][j] = 'n';
				}
				else if (matris[r][c + 1] == 0)
				{
					a[i][j] = 'V';
				}


			}



		}

	}
}

void assignBlank(char b[][41])
{
	for (int i = 0; i < 41; i++)
		for (int j = 0; j < 41; j++)
			b[i][j] = ' ';

}