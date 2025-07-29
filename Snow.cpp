#include<iostream>
#include<vector>
#include<conio.h>
#include<windows.h>
#include<time.h>


using namespace std;


void gotoxy(int x, int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    _COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(hConsole, pos);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

int losuj(int a, int b)
{
    return a+(rand()%(b-a+1));
}

struct platek
{
    int x;
    float y;
    float s;
};

const int N=25;

main()
{
     ShowConsoleCursor(false);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    platek tab[N];
    int pod[N][N];
    for(int i=0; i<N; i++)
        {
            pod[i][N-1]=1;
            gotoxy(i, N-1);
            cout << "*";
        }
    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<N; j++)
        {
            pod[j][i]=0;
        }
    }
    for(int i=0; i<N; i++)
    {
        tab[i]={losuj(0,N-1), 0.0, (float)losuj(10,99)/100.0 /*(float)losuj(0,1)+((float)losuj(25,99)/100.0)*/};
    }
    while(true)
    {
        for(int i=0; i<N; i++)
        {
            if(pod[tab[i].x][(int)tab[i].y] != 1)
           {
                gotoxy(tab[i].x, tab[i].y);
                cout<< " ";
           }
            if(pod[tab[i].x][(int)(tab[i].y + tab[i].s)]!=1)  tab[i].y += tab[i].s;
            else//if(pod[tab[i].x][(int)(tab[i].y + tab[i].s)]==1)
            {

                    if(pod[tab[i].x-1][(int)(tab[i].y + tab[i].s)]==1 && pod[tab[i].x+1][(int)(tab[i].y + tab[i].s)]==1 && tab[i].x != 0 && tab[i].x != N-1)
                    {
                        pod[tab[i].x][(int)tab[i].y]=1;
                        gotoxy(tab[i].x, tab[i].y);
                        cout<< "*";
                        tab[i].x = losuj(0,N-1);
                        tab[i].y = 0;
                        tab[i].s = (float)losuj(10,99)/100.0 /*(float)losuj(0,1)+(float)losuj(25,99)/100.0*/;
                    }
                    if(pod[tab[i].x-1][(int)(tab[i].y + tab[i].s)]!=1 && pod[tab[i].x+1][(int)(tab[i].y + tab[i].s)]==1 && tab[i].x != 0)
                    {
                        tab[i].x -= 1;
                        //tab[i].s = 1.0;
                        tab[i].y += 1.0;
                    }
                    if(pod[tab[i].x-1][(int)(tab[i].y + tab[i].s)]==1 && pod[tab[i].x+1][(int)(tab[i].y + tab[i].s)]!=1 && tab[i].x != N-1)
                    {
                        tab[i].x += 1;
                        //tab[i].s = 1.0;
                        tab[i].y += 1.0;
                    }
                    if(pod[tab[i].x+1][(int)(tab[i].y + tab[i].s)]!=1 && tab[i].x == 0)
                    {
                        tab[i].x += 1;
                        //tab[i].s = 1.0;
                        tab[i].y += 1.0;
                    }
                    if(pod[tab[i].x-1][(int)(tab[i].y + tab[i].s)]!=1 && tab[i].x == N-1)
                    {
                        tab[i].x -= 1;
                        //tab[i].s = 1.0;
                        tab[i].y += 1.0;
                    }
                    if(pod[tab[i].x+1][(int)(tab[i].y + tab[i].s)]==1 && tab[i].x == 0)
                    {
                        pod[tab[i].x][(int)tab[i].y]=1;
                        gotoxy(tab[i].x, tab[i].y);
                        cout<< "*";
                        tab[i].x = losuj(0,N-1);
                        tab[i].y = 0;
                        tab[i].s =(float)losuj(10,99)/100.0 /* (float)losuj(0,1)+(float)losuj(25,99)/100.0*/;
                    }
                    if(pod[tab[i].x-1][(int)(tab[i].y + tab[i].s)]==1 && tab[i].x == N-1)
                    {
                        pod[tab[i].x][(int)tab[i].y]=1;
                        gotoxy(tab[i].x, tab[i].y);
                        cout<< "*";
                        tab[i].x = losuj(0,N-1);
                        tab[i].y = 0;
                        tab[i].s =(float)losuj(10,99)/100.0  /*(float)losuj(0,1)+(float)losuj(25,99)/100.0*/;
                    }
                    if(pod[tab[i].x-1][(int)(tab[i].y + tab[i].s)] != 1 && pod[tab[i].x+1][(int)(tab[i].y + tab[i].s)] != 1 && tab[i].x != 0 && tab[i].x != N-1)
                    {
                        tab[i].y += 1.0;
                        //tab[i].s = 1.0;
                        if(losuj(0,1)==1) tab[i].x -= 1;
                        else tab[i].x += 1;
                    }

            }
            gotoxy(tab[i].x, tab[i].y);
            cout << "*";
        }
        Sleep(100);
    }
}

