#include "ficheiro.h"
#include <stdio.h>

void draw_world(void)
{
    char g[H_MAX][W_MAX];
    for(int y=0;y<H_MAX;++y)
        for(int x=0;x<W_MAX;++x) g[y][x]=' ';

    for(int k=0;k<nR;++k){
        Rect r=R[k];
        /* horizontais */
        for(int dx=0;dx<r.w;++dx){
            g[r.y-1][r.x-1+dx]='x';
            g[r.y+r.h-2][r.x-1+dx]='x';
        }
        /* verticais */
        for(int dy=0;dy<r.h;++dy){
            g[r.y-1+dy][r.x-1]='x';
            g[r.y-1+dy][r.x+r.w-2]='x';
        }
    }
    for(int row=H_MAX-1;row>=0;--row){
        for(int col=0;col<W_MAX;++col) putchar(g[row][col]);
        putchar('\n');
    }
    putchar('\n');
}
