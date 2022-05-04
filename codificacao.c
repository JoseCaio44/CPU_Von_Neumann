#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char palavra[50] = {"86;i;add;3;6"};
    char *pt;
    char aux, aux2;
    int count = 0;
    char memoria[154];

    unsigned int endInicio;
    unsigned int tipoPalavra;
    unsigned int dado, instrucao;
    unsigned int opc;
    unsigned int reg1 = 0x0;
    unsigned int reg2 = 0x0;
    unsigned int endMemOuImediato;

    pt = strtok(palavra, ";");

    while(pt) {
        printf("token: %s\n", pt);
        printf("count %d \n", count);
        if (count == 0) {
            endInicio = (int) strtol(pt, NULL, 16);
            printf("%i -- %x\n", endInicio, endInicio);
        }
        else if (count == 1) {
            tipoPalavra = (*pt == 'i')? 1:0;
            printf("%i\n", tipoPalavra);
            //printf("entrei no if do count I");
        } else if (count == 2) {
        	if (tipoPalavra == 0) {
            	//palavra = (int) strtol(pt, NULL, 16);
                reg1 = (int) strtol(pt, NULL, 16);
                printf("%i -- %x\n", reg1, reg1);
            }
            else {
            	pt = strtok(NULL, ";");
            	reg1 = (int) strtol(pt, NULL, 16);
            	pt = strtok(NULL, ";");
            	reg2 = (int) strtol(pt, NULL, 16);
                printf("%i -- %x\n", reg1, reg1);
                printf("%i -- %x\n", reg2, reg2);
			}
		} else {
            if (tipoPalavra == 0) {
            	//palavra = (int) strtol(pt, NULL, 16);
                dado = (int) strtol(pt, NULL, 16);
                printf("%i -- %x\n", dado, dado);
            }
            else {
            	printf("acesso else");
                //instrução
                if (pt == "hlt") { 
                	printf("acesso hlt");
                	opc = 0x00;
				} else if (pt == 'nop') {
					opc = 0x01;
				} else if (pt == 'add') {
					printf("acesso add");
					opc = 0x02;					
					aux = pt;
					aux2 = pt;					
				};
				
				

                //instrucao  = ((opc & 0xff) << 24) | ((reg1 & 0x7) << 21) | (endMemOuImediato && 0x1fffff);
                //printf("reg1 %s -- reg2 %s \n", aux, aux2);
                //printf("\n instru %x", instrucao);
            };
        } 
		printf("reg1 %x \n", reg1);
		printf("reg2 %x \n", reg2);
		
		printf("%x \n", instrucao);
        count++;
        pt = strtok(NULL, ";");
    };
    //memoria[endInicio++] = (palavra >> 24) & 0xff;
    //memoria[endInicio++] = (palavra >> 16) & 0xff;
    //memoria[endInicio++] = (palavra >> 8) & 0xff;
    //memoria[endInicio++] = palavra & 0xff;

    return 0;
}
