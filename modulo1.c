#include "ficheiro.h"

/* auxiliares internos */
static bool can_fall_one(const Rect *r,int idx)
{
    if(r->y==1) return false;
    Rect t=*r; t.y--;
    return !collides_with_others(&t,idx);
}

/* interface pública */
void apply_gravity(void)
{
    bool moved;
    do{
        moved=false;
        for(int i=0;i<nR;++i)
            while(can_fall_one(&R[i],i)){
                R[i].y--;
                moved=true;
            }
    }while(moved);
}
