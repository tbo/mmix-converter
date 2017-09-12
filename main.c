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

char * getBinaryString(long dec, unsigned short byteCount) {
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

char * getHexString(long dec, unsigned short byteCount) {
    int digitCount = byteCount * 2;
    char *hexString = malloc(digitCount + 2);
    sprintf(hexString, "#%0*.*lX", digitCount, digitCount, dec);
    return hexString;
}

void printType(long dec, struct Type type) {
    char *binaryString = getBinaryString(dec, type.byteCount);
    char *hexString = getHexString(dec, type.byteCount);
    printf(" %s\t%64s\t%17s\n", type.name, binaryString, hexString);
}

int main(int argc, char* argv[]) {
    if(argc != 2) {
        printf("Invalid argument count\n");
        return 1;
    }
    int t;
    long dec = atol(argv[1]);
    for(t = 0; t < 4 ; t++) {
        printType(dec, types[t]);
    }
    return 0;
}
