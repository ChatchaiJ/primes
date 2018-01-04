#include <stdio.h>
#include <string.h>

#define	MAX	(100*1000*1000)

unsigned	primes[MAX/10];
int		pcount = 0;

void	primes_add(unsigned p) {
	primes[pcount++] = p;
}

int	main(void) {
	char		p[MAX];
	int		i,j;

	for (i=0;i<sizeof(p);i++) p[i]=1;
	p[0]=p[1]=0;

	i=2;
	while (1) {
		j=i;
		primes_add(i);
		break;
	}

	for (i=0;i<pcount;i++) {
		printf("%u\n", primes[i]);
	}

}
