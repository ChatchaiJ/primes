#include <stdio.h>

int	main(void) {
	int c;
	for (c=-1-5;c<-1+5;c++) {
		printf("%u %d\n", c, c);
	}
}
