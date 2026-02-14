#ifndef FICHEIRO_H
#define FICHEIRO_H

#include <stdbool.h>
#include <stdio.h>

/* — limites do “mundo” — */
#define MAX_R 128
#define W_MAX 80
#define H_MAX 25

/* — tipo principal — */
typedef struct {
    int x, y;              /* canto inferior esquerdo (1-based) */
    int w, h;              /* largura e altura                  */
    int id;                /* opcional (debug)                  */
} Rect;

/* — variáveis globais (definidas em main.c) — */
extern Rect R[MAX_R];
extern int  nR;

/* — API dos módulos — */
void apply_gravity(void);                                    /* modulo1.c */
int  create_rectangle(int x,int y,int w,int h);              /* modulo2.c */

int  delete_rectangle(int x,int y);
void alertaColisaoLateral(void);

int  move_rectangle(int px,int py,int p,int dir);            /* modulo4.c */
bool collides_with_others(const Rect *r,int skip);           /* modulo4.c */

void draw_world(void);                                       /* modulo5.c */
void process_command(const char *line);                      /* modulo3.c */
void command_loop(FILE *in);                                 /* modulo3.c */

#endif /* FICHEIRO_H */
