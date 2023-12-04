/* Meteoroloski podaci, zadatak: unesi matricu od 3 do 10 redaka(5 stupaca), potom zapisi podatke u tablicu. Nakon toga u novu matricu unesi
vrijednosti koje su manje od prosjeka tog stupca.(unose se svi podaci iz reda)Zatim iz te nove matrice izdvojite redak koji ima najmanju vrijednost navedenog stupca.

FALE TEST CASEOVI!
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main()
{
int i, j, n, m = 5, mat[10][10], mat2[10][10], avg = 0, k = 0, f = 0, slab = 0;

do {
	scanf("%d", &n);
	if (n < 3 || n > 10) {
		printf("Ponovi unos!\n");
	}
} while (n < 3 || n > 10);

for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++) {
		scanf("%d", &mat[i][j]);
	}
}

for (i = 0; i < n; i++) {
	avg += mat[i][3];
}

avg /= n;


for (i = 0; i < n; i++) {
	for (j = 0; j < m; j++) {
		if (mat[i][3] < avg) {
			mat2[k][j] = mat[i][j];
			f = 1;
		}
	}
	if (f == 1) {
		f = 0;
		k++;
	}
}

for (i = 0; i < k; i++) {
	for (j = 0; j < m; j++) {
		if (j == 0) {
			printf("%0.3d ", mat2[i][j]);
		}
		else {
			printf("%d ", mat2[i][j]);
		}

	}
	printf("\n");
}

slab = mat2[0][1];

printf("\nNajslabiji vjetar:\n");

for (i = 0; i < k; i++) {
	if (mat2[i][1] <= slab) {
		slab = mat2[i][1];
	}
}

for (i = 0; i < k; i++) {
	if (mat2[i][1] <= slab) {
		for (j = 0; j < m; j++) {
			if (j == 0) {
				printf("%0.3d ", mat2[i][j]);
			}
			else {
				printf("%d ", mat2[i][j]);
			}
		}
		printf("\n");
	}
}


return 0;
}
