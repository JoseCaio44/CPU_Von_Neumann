#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char palavra[50] = {"86;d;a"};
    char *pt;
    int count = 0;

    unsigned int endInicio;
    unsigned int tipoPalavra;
    unsigned int dado, instrucao;
    unsigned int opc;
    unsigned int reg1;
    unsigned int reg2;
    unsigned int endMemOuImediato;

    pt = strtok(palavra, ";");

    while(pt) {
        printf("token: %s\n", pt);
        if (count == 0) {
            endInicio = (int) strtol(pt, NULL, 16);
            printf("%i -- %x\n", endInicio, endInicio);
        }
        else if (count == 1) {
            tipoPalavra = (*pt == 'i')? 1:0;
            printf("%i\n", tipoPalavra);
        }
        else {
            if (tipoPalavra == 0) {
                dado = (int) strtol(pt, NULL, 16);
                printf("%i -- %x\n", dado, dado);
            }
            else {
                //instrução

                instrucao = ((opc & 0xff) << 24) | ((reg1 & 0x7) << 21) | (endMemOuImediato && 0x1fffff);
            }
        }
    }
    memoria[endInicio++] = (palavra >> 24) & 0xff;
    memoria[endInicio++] = (palavra >> 16) & 0xff;
    memoria[endInicio++] = (palavra >> 8) & 0xff;
    memoria[endInicio++] = palavra & 0xff;

    return 0;
}