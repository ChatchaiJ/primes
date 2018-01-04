#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define	BLOCKSIZE	(100)
#define	MAXPRIMES	(100)

int		blockstart = 0;
int		primecount = 0;
char		p[ BLOCKSIZE ];
unsigned	primes[ MAXPRIMES ];

void	print_p(void) {
	int	i, j;

	printf("\t");
	for (i=0; i<BLOCKSIZE; i++) {
		if (i != 0 && i%10 == 0) printf(" ");
		printf("%d", p[i]);
	}
	printf("\n");
}

int	main(void) {
	int	i,j,k;

	/* initialize first prime number */
	primes[ primecount++ ] = 2;
	blockstart = 0;

	while (1) {
		/* p[] init */
		for (i=0; i<BLOCKSIZE; i++) p[i]=1;
		if (blockstart == 0) { p[0]=p[1]=0; }

		for (i=0; i<primecount; i++) {
			unsigned prime = primes[i];
			k = -1 * (blockstart % prime);

			while (k + prime < BLOCKSIZE) {
				p[ k + prime ] = 0;
				k += prime;
			}
			print_p();

			j = 0;
			while( p[j] == 0 && j < BLOCKSIZE)
				j++;
			if (j == BLOCKSIZE)
				break;
			primes[ primecount++ ] = j;
		}

		for (i=0; i<primecount; i++) {
			printf(" %d", primes[i]);
		}
		printf("\n");
		exit(0);
	}
}
