#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

struct Type {
    char name[6];
    int byteCount;
}; 

struct Type types[] = {
    {.name = "byte", .byteCount = 1},
    {.name = "wyde", .byteCount = 2},
    {.name = "tetra", .byteCount = 4},
    {.name = "octa", .byteCount = 8}
};

char * getBinaryString(int dec, unsigned short byteCount) {
	int i;
    int bitCount = byteCount * 8;
    char *binaryString = malloc(bitCount + 1);
    unsigned long long highOrderBitMask = ((unsigned long long) 1 << (bitCount - 1));
	for (i = 0; i < bitCount; i++) {
		binaryString[i] = !!((((unsigned long long) dec) << i) & highOrderBitMask) ? '1' : '0';
	}
    binaryString[bitCount] = '\0';
    return binaryString;
}

void printType(int dec, struct Type type) {
    printf(" %s\t%64s\n", type.name, getBinaryString(dec, type.byteCount));
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Invalid argument count\n");
        return 1;
    }
	int t;
    int dec = atoi(argv[1]);
    for(t = 0; t < 4 ; t++) {
        printType(dec, types[t]);
    }
	return 0;
}
