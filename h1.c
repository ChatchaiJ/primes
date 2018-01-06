#include <stdio.h>

// #define	MAX	(1000*1000*1000)
#define	MAX	(1000*1000*1000)
#define	N	(1000)

unsigned	primes[MAX];
char		p[MAX];
int		h[N];
int		pcount = 0;

int	main(void) {
	int		i,j;

	for (i=0; i<sizeof(p); i++) p[i]=1;
	p[0]=p[1]=0;
	for (i=0; i<N; i++) h[i]=0;

	i=2;
	while (1) {
		j=i;
		primes[pcount++] = i;
		while (j+i < MAX) {
			p[j + i ] = 0;
			j += i;
		}
		while (i+1 < MAX) {
			i++;
		      	if (p[i] != 0)
				break;
		}
		if (i+1 == MAX)
			break;
	}

	for (i=0; i<pcount; i++) {
		h[ primes[i] / (1000*1000) ]++;
		/* printf("%d\n", primes[i]);	*/
	}

	for (i=0; i<N ; i++) {
		printf("%0.8f\n", (double)h[i] / 1000000);
	}
	return 0;
}
