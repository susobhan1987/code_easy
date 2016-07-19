#include <stdio.h>
#include <stdlib.h>


int reverse_int (int a) {

	unsigned int tmp = 0x0f;
	unsigned int rev = 0;
	rev = (a&tmp)<<28 | ((a>>4)&tmp)<<24 | ((a>>8)&tmp)<<20 | ((a>>12)&tmp)<<16 |((a>>16)&tmp)<<12 | ((a>>20)&tmp)<<8 | ((a>>24)&tmp)<<4 | ((a>>28)&tmp);
	return rev;
}

int main () {

	int a = 0xaabbccdd;
	int b = reverse_int (a);
	printf ("rev %x\n\r",b);
	return 0;
}
