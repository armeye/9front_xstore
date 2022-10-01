#include <u.h>
#include <libc.h>

extern void repxstore(void *buf, long count);

void xstorebuf(void *b1, ulong l)
{
	ulong i;
	static char buf[16+8];
	char *b = b1;

	for(i = 0; i < l>>4; i++){
		repxstore(buf, 16);
		memmove(b, buf, 16);
		b+=16;
	}

	repxstore(buf, 16);
	memmove(b, buf, l&0xf);
}

void main(int argc, char **argv)
{
	char *b = malloc(8*1024);

	xstorebuf((char *)b, 8*1024);

	write(1, b, 8*1024);
}