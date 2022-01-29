#include "menu.h"

void sfondo(){

    WINDOW *screen;
    screen = newwin(24,80,0,0);
    keypad(screen,1);
    char stringa[4][30]={
            " _____ _____ _____ ____ ____ ",
            "|  ___|  _  |  _  | ___|  __|",
            "|____ | ____|  _  | |__|  __|",
            "|_____|_|   |_| |_|____|____|"};
    char stringa2[4][46]={
            " _____ ____ ____ ____ _   _ _____ ____ _____ ",
            "|  _  |  __|  __|  __| \\ | |  _  |  __|  _  |",
            "| |_| |  __|  __|  __| |\\  | |_| |  __|  _-- ",
            "|_____|____|__| |____|_| \\_|_____|____|_| \\_\\"
    };
    int frecciaMenu;
    int sy=(MAXY/2+2);
    while(true) {

        wclear(screen);

        int g,y=1;
        for(g=0;g<4;g++){
            mvwprintw(screen,y,MAXX/2-15,"%s",stringa[g]);
            y++;
        }
        int z=5;
        for(g=0;g<4;g++){
            mvwprintw(screen,z,MAXX/2-22,"%s",stringa2[g]);
            z++;
        }
        int i;
        for (i = 0; i <= MAXY; i++){
            int x = rand()%MAXX;
            mvwprintw(screen, i, x, ".");
            usleep(1000);
        }

        char avvio[] = "Avvia gioco";
        char impostazioni[] = "Impostazioni";
        char esci[] = "Esci";
        char selezione[] = "==>";
        mvwprintw(screen, MAXY/2+2, MAXX/2-sizeof(avvio)/2, avvio);
        mvwprintw(screen, MAXY/2+4, MAXX/2-sizeof(impostazioni)/2, impostazioni);
        mvwprintw(screen, MAXY/2+6, MAXX/2-sizeof(esci)/2, esci);

        mvwprintw(screen, sy, MAXX/2-10, selezione);
        timeout(1);

        frecciaMenu=wgetch(screen);
        switch(frecciaMenu){
            case KEY_UP:
                if(sy>MAXY/2+2)
                    sy-=2;
                break;
            case KEY_DOWN:
                if(sy<MAXY/2+6)
                    sy+=2;
                break;
            case 113:
                caricamento();
        }

        wrefresh(screen);
        }
}

void caricamento(){
    WINDOW *screen;
    WINDOW *testo;

    screen = newwin(24,80,0,0);
    testo = newwin(5, 20, MAXY/2-2, MAXX/2-10);
    char amogus[5][13]={
            "    _______ ",
            " __|  ___  |",
            "|  | |___| |",
            "|__|       |",
            "   |___|___|"};
    int g;

    char caricamento[]="CARICAMENTO";
    while (true) {

        int x=1;
        int y,z;

        while(x<MAXX-5) {
            wclear(screen);
            wclear(testo);
            box(testo, ACS_VLINE, ACS_HLINE);
            mvwprintw(testo, 2, 10-(sizeof (caricamento)/2), caricamento);
            y=MAXY-7;
            z=2;
            for (g = 0; g < 5; g++) {
                mvwprintw(screen, z, x, "%s", amogus[g]);
                z++;
                usleep(10000);
            }
            for (g = 0; g < 5; g++) {
                mvwprintw(screen, y, x, "%s", amogus[g]);
                y++;
                usleep(10000);
            }
            x+=5;
            wrefresh(screen);
            wrefresh(testo);
        }
    }
}




