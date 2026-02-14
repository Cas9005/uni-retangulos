#include "ficheiro.h"
#include <stdio.h>

// verifica se um ponto está dentro de r
static bool contains(const Rect *r,int px,int py){
  return px>=r->x && px<=r->x+r->w-1
      && py>=r->y && py<=r->y+r->h-1;
}
// encontra índice pelo ponto
static int find_by_point(int px,int py){
  for(int i=0;i<nR;++i)
    if(contains(&R[i],px,py)) return i;
  return -1;
}

// apaga rectângulo que contém (x,y)
int delete_rectangle(int x,int y){
  int idx = find_by_point(x,y);
  if(idx<0){ puts("Erro: ponto sem rectângulo."); return -1; }
  // shift left
  for(int i=idx;i<nR-1;++i) R[i]=R[i+1];
  --nR;
  apply_gravity();
  return 0;
}

// verifica colisão lateral entre pares
void alertaColisaoLateral(void){
  for(int i=0;i<nR;++i) for(int j=i+1;j<nR;++j){
    Rect *A=&R[i], *B=&R[j];
    // faces verticais encostadas?
    bool lado = (A->x + A->w == B->x) || (B->x + B->w == A->x);
    // sobreposição vertical?
    bool sobe = !(A->y + A->h-1 < B->y || B->y + B->h-1 < A->y);
    if(lado && sobe){
      printf("Colisão lateral detetada entre os retângulos %d e %d.\n",
             A->id, B->id);
    }
  }
}

