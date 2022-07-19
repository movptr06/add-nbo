#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
	FILE *fp;
	uint32_t n1 = 0;
	uint32_t n2 = 0;
	uint32_t *p;
	if(argc != 3) return 0;
	fp = fopen(argv[1], "rb");
	if(!fp) return 0;
	p = &n1;
	fread(p, sizeof(uint32_t), 1, fp);
	fclose(fp);
	fp = fopen(argv[2], "rb");
	if(!fp) return 0;
	p = &n2;
	fread(p, sizeof(uint32_t), 1, fp);
	fclose(fp);
	n1 = ntohl(n1);
	n2 = ntohl(n2);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);
	return 0;
}
