#include <stdio.h>
#include <string.h>

#define	MAX	(1*1000*1000*1000)

unsigned	primes[MAX];
char		p[MAX];
int		pcount = 0;

void	primes_add(unsigned p) {
	primes[pcount++] = p;
}

int	main(void) {
	int		i,j;

	for (i=0; i<sizeof(p); i++) p[i]=1;
	p[0]=p[1]=0;

	i=2;
	while (1) {
		j=i;
		primes_add(i);
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

	printf("Number of primes = %d\n", pcount);
}
