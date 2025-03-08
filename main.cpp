#include <iostream>
#include <graphics.h>
#include <cstring>
#include <stdio.h>

using namespace std;

struct nod
{
    int info;
    nod *st, *dr;
};

int n, pozx, pozy, pozy2, p=0;

char arr[50], arr2[50];



void inserare( nod *&rad, int a, int x, int y, int n )
{
    float m;
   if(n<=5)
        m=n*7.2;
    else
        if(n>=6 && n<=7)
            m=n*6.2;
        else
            if(n>=8 && n<= 9)
                m=n*4.5;
            else
                if(n>=10 && n<= 11)
                    m=n*3.65;
                else
                   if(n>=12 && n<= 13)
                      m=n*3;
                   else
                        m=n*2.6;


    if(rad == NULL)
    {
        rad = new nod;
        rad->info = a;
        rad->st = NULL;
        rad->dr = NULL;

        circle(x, y, 30);
        sprintf(arr, "%d", a);
        outtextxy(x-10, y-10, arr);
    }
    else
    {
        setlinestyle(0, 0, 2);
        setcolor(LIGHTMAGENTA);
        circle(x, y, 30);
        delay(600);
        setcolor(WHITE);
        circle(x, y, 30);
        //pozy2=pozy2+25;
        sprintf(arr, "%d", a);
        sprintf(arr2, "%d", rad->info);
         p++;

        if(rad->info <=a )
            {
                 delay(1000);
                 outtextxy(pozx, pozy2, "                                                    ");
                 outtextxy(pozx, pozy2, arr );
                 outtextxy(pozx+55, pozy2, ">");
                 outtextxy(pozx+85, pozy2, arr2 );

                 outtextxy(pozx+115, pozy2, "  --> dreapta");

                if(rad->dr == NULL)
                    line(x+30, y+30, x+160 - p*m, y+ 150 - m);

                inserare(rad->dr, a, x+190 - p*m, y+180 - m, n );
            }

        else
            {

                delay(1000);
                outtextxy(pozx, pozy2, "                                                    ");
                outtextxy(pozx, pozy2, arr );
                outtextxy(pozx+55, pozy2, "<");
                outtextxy(pozx+85, pozy2, arr2 );

                outtextxy(pozx+115, pozy2, "  --> stanga");

                if(rad->st == NULL)
                    line(x-30, y+30, x-160 + p*m, y+150 - m );

                inserare(rad->st, a, x-190 + p*m, y+180 - m, n );

            }
    }

}

void SRD( nod *rad, int &c )
{
    if(rad)
    {
        SRD(rad->st, c);

        sprintf(arr, "%d", rad->info);
        outtextxy(c, pozy+50, arr);
        if(rad->info >=0 && rad->info <=9)
            c=c+25;
            else
                if(rad->info >=10 && rad->info <=99 || rad->info >=-99 && rad->info <=-10 )
                    c=c+45;
                else
                    c=c+75;

        SRD(rad->dr, c);
    }
}

int cautare( nod *rad, int a , int x, int y, int n)
{

    float m;
   if(n<=5)
        m=n*7.2;
    else
        if(n>=6 && n<=7)
            m=n*6.2;
        else
            if(n>=8 && n<= 9)
                m=n*4.5;
            else
                if(n>=10 && n<= 11)
                    m=n*3.65;
                else
                   if(n>=12 && n<= 13)
                      m=n*3;
                   else
                        m=n*2.6;

    if( rad !=0 )
    {

        setcolor(LIGHTRED);
        setlinestyle(0, 0, 2);
        delay(400);
        circle(x, y, 30);
        delay(400);
        p++;

        if(rad->info == a)
            {
                setcolor(LIGHTGREEN);
                setlinestyle(0, 0, 2);
                delay(400);
                circle(x, y, 30);
                delay(400);

                sprintf(arr, "%d", a);
                outtextxy(pozx, pozy, arr);
                outtextxy(pozx+60, pozy,"=");
                sprintf(arr2, "%d", rad->info);
                outtextxy(pozx+85, pozy,arr2);
                pozy=pozy+25;
                setcolor(CYAN);
                return 1;

            }
        else
            if(rad->info < a)
                {
                    setcolor(CYAN);
                    sprintf(arr, "%d", a);
                    outtextxy(pozx, pozy, arr);
                    outtextxy(pozx+60, pozy,">");
                    sprintf(arr2, "%d", rad->info);
                    outtextxy(pozx+85, pozy,arr2);
                     pozy=pozy+25;

                    cautare(rad->dr, a, x+190 - p*m, y+180 - m, n );
                }
            else
                {
                    setcolor(CYAN);
                    sprintf(arr, "%d", a);
                    outtextxy(pozx, pozy, arr);
                    outtextxy(pozx+60, pozy,"<");
                    sprintf(arr2, "%d", rad->info);
                    outtextxy(pozx+85, pozy,arr2);
                     pozy=pozy+25;

                    cautare(rad->st, a, x-190 +p*m, y+180 - m, n );
                }
    }
    else
        return 0;

}

int cautare2( nod *rad, int a , int x, int y, int n)
{
    float m;
   if(n<=5)
        m=n*7.2;
    else
        if(n>=6 && n<=7)
            m=n*6.2;
        else
            if(n>=8 && n<= 9)
                m=n*4.5;
            else
                if(n>=10 && n<= 11)
                    m=n*3.65;
                else
                   if(n>=12 && n<= 13)
                      m=n*3;
                   else
                        m=n*2.6;

    if( rad !=0 )
    {

        setcolor(WHITE);
        setlinestyle(0, 0, 2);

        circle(x, y, 30);

        p++;

        if(rad->info == a)
            {
                circle(x, y, 30);
                return 1;
            }
        else
            if(rad->info < a)
                cautare2(rad->dr, a, x+190 - p*m, y+180 - m, n );
            else
                cautare2(rad->st, a, x-190 + p*m, y+180 - m, n );

    }
    else
        return 0;

}

int main()
{

    initwindow(1550, 800);



    pozx=65, pozy=250;

    settextstyle(1, HORIZ_DIR, 4);
    outtextxy(pozx+5, pozy, "Bine ati venit in programul de sortare si cautare folosind ");
    outtextxy(pozx, pozy+30, "arbori binari! Pentru inceput, introduceti numarul de noduri (n <=15),");
    outtextxy(pozx, pozy+60, "precum si valorile pe care doriti sa le adaugati in arbore (numere");
    outtextxy(pozx, pozy+90, "naturale de maximum doua cifre).");
    int i, c=230, OK=0;
    float n, a;
    nod *rad = NULL;

    pozy=pozy+150;

    outtextxy(pozx+5, pozy, "Apasati orice tasta pentru a incepe.");
    getch();
    delay(250);
    cleardevice();

    pozx=5; pozy=20;

    settextstyle(1, HORIZ_DIR, 1);
    outtextxy( pozx, pozy, "n =");

    while(OK==0)
    {
        cin>>n;

        if( (int)n == n && n>=0 && n<=15 )
        {
            sprintf(arr, "%d", (int)n);
            outtextxy(pozx+45, pozy, arr);
            OK=1;
        }
        else
        {
            settextstyle(1,  HORIZ_DIR , 2);
            setcolor(LIGHTRED);
            outtextxy(pozx+20, pozy+30, "Valoare invalida! introduceti alta valoare.");
            delay(2000);
            outtextxy(pozx+20, pozy+30, "                                                                  ");
            settextstyle(1,  HORIZ_DIR , 1);
            setcolor(WHITE);
        }
    }

    pozy=pozy+35;

    int x= 950, y=130;

    pozy2=pozy+50;

    outtextxy( pozx, pozy, "valori:");
    for(i=1; i<=n; i++)
    {
        cin>>a;

        if( (int)a == a && a>=0 && a<=99 )
        {
            sprintf(arr, "%d", int(a));
            outtextxy(pozx+50+55*i, pozy, arr);
            p=0;
            inserare(rad, a, x, y, n);
        }
        else
        {
            settextstyle(1,  HORIZ_DIR , 2);
            setcolor(LIGHTRED);
            outtextxy(pozx+20, pozy2+30, "Valoare invalida! introduceti alta valoare.");
            delay(2400);
            outtextxy(pozx+20, pozy2+30, "                                                                  ");
            settextstyle(1,  HORIZ_DIR , 1);
            setcolor(WHITE);
        }

    }


    pozy=pozy+50;

    outtextxy(10, pozy+50 ,"valorile ordonate:");
    SRD(rad,c);

    int val, ok=1;
    pozx=10;
    pozy=240;
    pozy2=pozy;
    settextstyle(1, HORIZ_DIR, 2);
    rectangle(pozx, pozy-25, 400, 720);
    pozx=pozx+20;


    setlinestyle(3, 0, 1);

    while( ok==1)
    {
        setcolor(CYAN);
        outtextxy(pozx, pozy, "Introduceti o");
        outtextxy(pozx, pozy+25, "valoare de cautat:");
        pozy=pozy+25;

        cin>>val;

        sprintf(arr, "%d", val);
        outtextxy(pozx+250, pozy, arr);
        pozy=pozy+35;
        p=0;

        if(cautare(rad, val, x, y, n) == 1)
           outtextxy(pozx, pozy+15, "Este in arbore");
        else
            outtextxy(pozx, pozy+15, "Nu este in arbore");

        outtextxy(pozx, pozy+ 50, "Doriti sa introduceti o");
        outtextxy(pozx, pozy+ 75, "noua valoare?");
        outtextxy(pozx, pozy+ 100, "(DA=1, NU=0)");
        cin>>ok;
        sprintf(arr, "%d", ok);
        outtextxy(pozx+170, pozy+75, arr);
        p=0;
        cautare2(rad, val, x, y, n);

        setfillstyle(1, BLACK);
        floodfill(pozx, pozy2, WHITE);

        pozy=pozy2;
    }


    return 0;
}
