/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/accf6c944c590b45bc54ad1c82a8797e1b96bdc5/tekstovi%20i%20test%20caseovi/%5B5%5DBrojevna%20spojka%201.pdf
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

void ispis(long long int a, long long int b, long long int c, long long int d, long long* ab, long long* cd) {
	if (b == 0) {
		a *= 10;
	}
	if (c ==0) {
		long long int temp = d;
		d = c;
		c = temp;
	}

	long long int y = d;
	int brojacD = 0;

	while (y > 0) {
		brojacD++;
		y /= 10;
	}

	while (b > 0) {
		if (a < 0) {
			a *= 10;
			a -= (b % 10);
			b /= 10;
		}
		else {
			a *= 10;
			a += (b % 10);
			b /= 10;
		}
		
	}

	int znamenka = 0;

	while (d > 0) {
		if (c < 0) {
			c *= 10;
			c -= (d % 10);
			d /= 10;
		}
		else {
				c *= 10;
				znamenka = (d / (long long int)pow(10, brojacD - 1));
				c += znamenka ;
				d -= znamenka*(long long int)pow(10,brojacD-1);
				brojacD--;
			
			
		}
		
	}

	*ab = a;
	*cd = c;
}

int main() {

	long long int a=0, b=0, c=0, d = 0;
	long long int ab = 0, cd = 0;

	do {
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		if (a < -1000000 || c>1000000 || b < 0 || d>1000000 || d < 0 || c < 0) {
			printf("Neispravan unos!\n");
		}
	} while (a < -1000000 || c>1000000 || b < 0 || d>1000000 || d<0 || c<0);

	ispis(a, b, c, d, &ab, &cd);

	printf("%lld+%lld=%lld\n%lld-%lld=%lld \n%lld*%lld=%lld", ab,cd,ab+cd, ab, cd, ab - cd, ab, cd, ab * cd );
	


	return 0;

}
