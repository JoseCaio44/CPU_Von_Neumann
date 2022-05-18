# CPU_Von_Neumann
O objetivo deste projeto é compreender como o ciclo de instrução da Máquina de von Neumann funciona na linguagem C, sendo assim simulei uma CPU com o conjunto de instruções (ISA – Instruction Set Architecture), o conjunto de registradores arquiteturais e o formato de instrução do mesmo. Esse simulador mostra o conteúdo dos registradores no fim de cada ciclo de máquina, quando haverá uma pausa até apertar uma tecla para iniciar o próximo ciclo.


1. MBR – Memory Buffer Register – contém a palavra a ser armazenada na memória. Também é o registrador usado para receber uma palavra lida da memória. Todo o tráfego de e para a memória RAM deve passar pelo MBR. Deve ser implementado como uma variável de 32 bits (unsigned int mbr);

2. MAR – Memory Address Register – especifica o endereço de memória da palavra a ser lida da ou escrita na memó-ria. Todo endereço de memória deve ser indicado nesse registrador antes da execução da instrução. Teoricamente, ele deveria ter o tamanho de 21 bits, mas como não existe variável de 21 bits na linguagem C, ele deve ser implementado como uma variável de 32 bits (unsigned int mar);

3. IR – Instruction Register – contém o opcode da instrução a ser executada. Deve ser implementado como uma variável de oito bits (unsigned char ir);

4. RO0 – Register Operand 0 – contém o endereço do primeiro operando registrador da instrução. Teoricamente, ele deveria ter o tamanho de três bits, mas como não existe variável de três bits na linguagem C, ele deve ser implementado como uma variável de oito bits (unsigned char ro0);

5. RO1 – Register Operand 1 – contém o endereço do segundo operando registrador da instrução. Teoricamente, ele deveria ter o tamanho de três bits, mas como não existe variável de três bits na linguagem C, ele deve ser implementado como uma variável de oito bits (unsigned char ro1);

6. IMM – Immediate – contém o operando imediato da instrução. Teoricamente, ele deveria ter o tamanho de 21 bits, mas como não existe variável de 21 bits na linguagem C, ele deve ser implementado como uma variável de 32 bits (unsigned int imm);

7. PC – Program Counter – contém o endereço da próxima palavra de instrução a ser buscada na memória. Caso não haja nenhum desvio, halt ou nop, o PC deve ser incrementado em cada ciclo de instrução. Deve ser implementado como uma variável de 32 bits (unsigned int pc);

8. E, L e G – registradores internos que armazenam as flags ‘equal to’, ‘lower than’ e ‘greater than’. Cada uma delas contém um bit indicando se o conteúdo do primeiro operando registrador é, ao ser comparado pela instrução cmp, respectivamente 1) igual a, 2) menor do que ou 3) maior do que o conteúdo do segundo operando registrador. Como não há maneira de implementar variáveis de um bit, devem ser implementados como variáveis de oito bits (unsigned char e, unsigned char l, unsigned char g);

9. r0 a r7 – registradores de propósito-geral (GPRs) utilizados para manter temporariamente os operandos na ALU. Devem ser implementados como um vetor com posições de 32 bits (unsigned int reg[8]).
