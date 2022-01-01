/*
 ============================================================================
 Name        : dcf77-chip-seq.c
 Author      : Felix Erckenbrecht
 Version     :
 Copyright   : BSD
 Description : Calculates and prints DCF77 chip-sequence
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    uint16_t sr;
    int i;
    uint16_t poly;

    sr = 0;
    //
    poly = 0x110;
    for(i=0;i<512;i++){
        uint16_t calc;
        uint16_t sum;

        calc = sr & poly;
        sum  = (calc >> 4) & 1;
        sum ^= (calc >> 8) & 1;

        printf("%c", sum ? '1' : '0');
        //printf("%04x %03x %1x\n", sr, calc, sum);

        sr <<= 1;
        sr = (i==0) ? 1 : sr | sum;
        sr &= 0x1ff;
    }
    printf("\n");
	return EXIT_SUCCESS;
}
