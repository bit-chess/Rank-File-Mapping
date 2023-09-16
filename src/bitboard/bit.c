#include "bit.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

void read_bitboard(char board[8][8]){
    char binary[70] = "64'b";
    int64_t integer = 0;

    int counter = 0;
    //littler-endian
    for(int i=7;i>=0;i--) {
        for(int j=0;j<8;j++) {
            strcat(binary, (board[7-i][7-j] == 'M' ? "1" : "0"));
            integer += powl(2, counter) * (board[i][j] == 'M' ? 1 : 0);

            counter++;
        }
    }

    printf("\n\n-------------------------------------------\n");
    printf("- Binary value: %s\n- Decimal value: %lld\n", binary, integer);
    printf("-------------------------------------------\n\n");

}