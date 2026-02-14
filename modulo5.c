#include "ficheiro.h"
#include <stdio.h>

void draw_world(void) {
    char g[H_MAX][W_MAX];
    // 1) limpa o mundo
    for(int y=0;y<H_MAX;++y)
      for(int x=0;x<W_MAX;++x) g[y][x]=' ';
    // 2) desenha cada rectângulo
    for(int k=0;k<nR;++k){
      Rect r = R[k];
      int x0 = r.x-1, y0 = r.y-1;
      // a) bordas
      for(int dx=0; dx<r.w; ++dx){
        g[y0][x0+dx]           = 'x';
        g[y0+r.h-1][x0+dx]     = 'x';
      }
      for(int dy=0; dy<r.h; ++dy){
        g[y0+dy][x0]           = 'x';
        g[y0+dy][x0+r.w-1]     = 'x';
      }
      // b) interior com '+'
      for(int dy=1; dy<r.h-1; ++dy)
        for(int dx=1; dx<r.w-1; ++dx)
          g[y0+dy][x0+dx] = '+';
      // c) coloca o ID no centro aproximado
      int cx = x0 + r.w/2;
      int cy = y0 + r.h/2;
      g[cy][cx] = '0' + r.id;
    }
    // 3) imprime do topo para baixo
    for(int row=H_MAX-1; row>=0; --row){
      for(int col=0; col<W_MAX; ++col) putchar(g[row][col]);
      putchar('\n');
    }
    putchar('\n');
}
