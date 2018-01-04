#include <stdio.h>
#include <stdlib.h>

#define	DEBUG		(0)
#define	BLOCKSIZE	(500*1000*1000)
#define	MAX		((unsigned long long)1000*1000*1000)
#define	MAXPRIMES	(500*1000*1000)

unsigned long long		blockstart = 0;
unsigned long long		primecount = 0;
unsigned long long 		primes[ MAXPRIMES ];
char				p[ BLOCKSIZE ];


void	print_p(void) {
	unsigned long long	i;

	printf("\t");
	for (i=0; i<BLOCKSIZE; i++) {
		if (i != 0 && i%10 == 0) printf(" ");
		printf("%d", p[i]);
	}
	printf("\n");
}

int	main(void) {
	long long	i,j,k;

	/* initialize first prime number */
	primes[ primecount++ ] = 2;
	blockstart = 0;

	while (1) {
		/* p[] init */
		for (i=0; i<BLOCKSIZE; i++) p[i]=1;
		if (blockstart == 0) { p[0]=p[1]=0; }

		while (1) {
			for (i=0; i<primecount; i++) {
				unsigned long long prime = primes[i];
				k = -1 * (blockstart % prime);

				if (k == 0) p[0] = 0;
				while (k + prime < BLOCKSIZE) {
					p[ k + prime ] = 0;
					k += prime;
				}
				if (DEBUG) print_p();
			}

			j = 0;
			while( p[j] == 0 && j < BLOCKSIZE)
				j++;
			if (j == BLOCKSIZE)
				break;
			primes[ primecount++ ] = blockstart + j;
			printf("%Lu: %Lu\n", primecount, primes[ primecount - 1]);
		}

		blockstart += BLOCKSIZE;
		if (blockstart > MAX) break;
	}

	for (i=0; i<primecount; i++) {
		printf("%Lu: %Lu\n", i+1, primes[i]);
	}
}
