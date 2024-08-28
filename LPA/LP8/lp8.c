#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define START_CODE "\x00\x00\x01"

int main(int argc, char** argv){
    FILE* file = fopen(argv[1],"rb");

    unsigned char buffer[3];

    while(1){
        fread(buffer, 1, )
    }

    unsigned char byte1 = fgetc(file);
    unsigned char byte2 = fgetc(file);
    unsigned char byte3 = fgetc(file);
    unsigned char byte4 = fgetc(file);

/*    unsigned int largura = byte1 * 16 + (byte2 >> 4);
    unsigned int altura = (byte2 & 0x0F) * 256 + byte3;
    unsigned int frame_rate = byte4 & 0x0f;


    printf("LARGURA = %d\n", largura);
    printf("ALTURA = %d\n", altura);
    printf("FRAME RATE = %d\n", frame_rate); */


}



if(memcmp(buffer, START_CODE,3) == 0)
if(memcmp(buffer, "\xb3", 1) == 0)