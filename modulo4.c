#include <stdio.h>
#include <stdlib.h>
#include "ficheiro.h"

/* — funcoes de apoio (visiveis fora do modulo se necessario) — */
bool collides_overlap(int a1,int a2,int b1,int b2){ return !(a2<b1||b2<a1); }

static bool intersects(const Rect *a,const Rect *b)
{
    return collides_overlap(a->x,a->x+a->w-1,b->x,b->x+b->w-1) &&
           collides_overlap(a->y,a->y+a->h-1,b->y,b->y+b->h-1);
}

bool collides_with_others(const Rect *t,int skip)
{
    for(int i=0;i<nR;++i)
        if(i!=skip && intersects(t,&R[i])) return true;
    return false;
}

static bool contains(const Rect *r,int px,int py)
{
    return px>=r->x && px<=r->x+r->w-1 &&
           py>=r->y && py<=r->y+r->h-1;
}

static int find_by_point(int px,int py)
{
    for(int i=0;i<nR;++i) if(contains(&R[i],px,py)) return i;
    return -1;
}

/* — interface publica: movimento horizontal — */
/* dir = +1 direita, -1 esquerda */
int move_rectangle(int px,int py,int p,int dir)
{
    int idx=find_by_point(px,py);
    if(idx==-1){ puts("Erro: ponto sem rectangulo."); return -1; }

    Rect *r=&R[idx];
    for(int s=0;s<p;++s){
        Rect t=*r; t.x+=dir;
        if(!(t.x>=1 && t.x+t.w-1<=W_MAX) ||
           collides_with_others(&t,idx)){
            puts("Erro: movimento bloqueado.");
            return -2;
        }
        r->x=t.x;
    }
    apply_gravity();
    draw_world();
    return 0;
}