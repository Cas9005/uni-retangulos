#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ficheiro.h"

static bool fits_inside(const Rect *r)
{
    return r->x>=1 && r->y>=1 &&
           r->x+r->w-1<=W_MAX && r->y+r->h-1<=H_MAX;
}

int create_rectangle(int x,int y,int w,int h)
{
    if(nR==10){ puts("Erro: maximo de rectangulos (10).");
         return -1;
         }

    Rect r={x,y,w,h,nR+1};

    if(!fits_inside(&r))           { puts("Erro: fora dos limites."); return -2; }
    if(collides_with_others(&r,-1)){ puts("Erro: colisao.");          return -3; }
    bool used[10] = {0};
    for(int i=0;i<nR;++i) used[R[i].id] = true;
    int try;
    do {
      try = rand() % 10;
    } while(used[try]);
    r.id = try;
    R[nR++]=r;
    apply_gravity();
    return 0;
}
