#include <stdio.h>
#include <string.h>
#include "ficheiro.h"

/* executa uma linha de comando */
void process_command(const char *line)
{
    int a,b,c,d;
    if(sscanf(line,"create %d,%d+%d,%d",&a,&b,&c,&d)==4){
        if(create_rectangle(a,b,c,d)==0) draw_world();
        return;
    }
    if(sscanf(line,"moveleft %d,%d+%d",&a,&b,&c)==3){
        if(move_rectangle(a,b,c,-1)==0)  draw_world();
        return;
    }
    if(sscanf(line,"moveright %d,%d+%d",&a,&b,&c)==3){
        if(move_rectangle(a,b,c,+1)==0)  draw_world();
        return;
    }
    puts("Erro: comando desconhecido.");
}

/* lê comandos contínuos de um ficheiro (stdin por omissão) */
void command_loop(FILE *in)
{
    char buf[256];
    while(fgets(buf,sizeof buf,in)){
        if(buf[0]=='#'||buf[0]=='\n') continue;
        process_command(buf);
    }
}
