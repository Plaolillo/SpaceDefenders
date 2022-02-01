#include "menu.h"
#include "gioco.h"
struct pos{
    char sprite[3][4];
    int x, y;
};

void gioco
void navicella(int pipeout){
    int i;
    for(i=0; i<12; i++) {

        int x=MAXX/2;
        int y=0;
        int i;
        for(i=0; i<;i++){
            struct pos navicella;
            navicella.sprite =
                    " | ",
                    "-0-",
                    " | ";
            navicella.y=y;
            navicella.x=x;
            if(i%4==0){
                y=0;
            }else{
                y+=5;
            }
            if(i%4==0){
                x+=5;
            }
            write(pipeout,&navicella, sizeof(navicella));
            usleep (100000);
        }
    }
}