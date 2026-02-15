#include <stdio.h>
#include "ficheiro.h"

/* definição das variáveis globais */
Rect R[MAX_R];
int  nR = 0;

int main(int argc,char *argv[])
{
    FILE *in = stdin;
    if(argc==2){
        in=fopen(argv[1],"r");
        if(!in){ perror(argv[1]); return 1; }
    }
    command_loop(in);
    if(in!=stdin) fclose(in);
    return 0;
}
