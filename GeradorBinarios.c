#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	//char teste = 0x05;
	//printf("%d",teste);
	
	unsigned int mbr, mar, imm, pc, reg[8];
	unsigned char ir, ro0, ro1, e, l, g, memoria[154];
	
	pc = 0x00;
	
	memoria[0] = 0x13;
	memoria[1] = 0x20;
	memoria[2] = 0x00;
	memoria[3] = 0x04;
	
	memoria[4] = 0xaa;
	memoria[5] = 0xbb;
	memoria[6] = 0xcc;
	memoria[7] = 0xdd;
	
	mar = pc;
	mbr = memoria[mar++];
	mbr = (mbr << 8) | memoria[mar++];
	mbr = (mbr << 8) | memoria[mar++];
	mbr = (mbr << 8) | memoria[mar++];
		
	//printf("%x",ir);
	//printf("%x",mbr);
	/// descodifica
	///teste da fase inicial 
	ir = (mbr >> 24);
	//ir = memoria[0];
	printf("%x \n",mbr);
	
	if (ir == 0 || ir == 1) {
		
	};
	if (ir >= 2 && ir <= 10){
		
	};
	if (ir == 11) {
		
	};
	if (ir >= 12 && ir <= 18){
		
	};
	if (ir == 19 || ir == 20) {
		ro0 = ((mbr & 0xe00000) >> 21);
		mar = (mbr & 0x1ffff);
		printf("%x \n", mar);
		printf("entrei no if \n");
		printf("%d \n", mar);
		printf("%d \n", ro0);
		if (ir == 19) {
			printf("entrei no segundo \n");
			mbr = memoria[mar++];
			mbr = (mbr << 8) | memoria[mar++];
			mbr = (mbr << 8) | memoria[mar++];
			mbr = (mbr << 8) | memoria[mar++];
			reg[ro0] = mbr;
			pc += 4;
			printf("%x", reg[ro0]);
		};
		
		//ro0 = (mbr & 0x00e00000) >> 21;
		//mar = mbr & 0x001fffff;
	};
	
	//printf("%x", reg[1], "\n MBR: %x", mbr, "%x \n MAR: ", mar);
	
	//executa
	
	
/*	FILE *arq;
	char Linha[150];
	char *result;
  	int i;
	
	arq = fopen("teste.txt", "rt");

  	if (arq == NULL)
 	{
    	printf("Problemas na abertura do arquivo\n");
    	return;
	}

  	i = 1;
  	while (!feof(arq))
  	{
		result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      	if (result){
		  	printf("Linha %d : %s",i,Linha);
      		i++;	
		  }
  }
  
  fclose(arq);*/
}
