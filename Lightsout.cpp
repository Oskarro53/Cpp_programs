#include<iostream>
#include<cmath>
#include<time.h>
#include<conio.h>
#include<windows.h>
using namespace std;

    int tab[10][10]={0};

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

void wyptab()
{
       for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            tab[i][j] = rand()%2;
}

main()
{
    srand(time(0));
    ShowConsoleCursor(false);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int l;
    cout << "Choose color from 1 to 15 " << endl;
    while(true)
    {
        cin >> l;
        if(l>=1 && l<=15)break;
        if(l<1 || l>15) cout << "I said from 1 to 15!"<<endl;
    }
    system("cls");

    SetConsoleTextAttribute(hConsole, l);

    l=0;

    int znak, k, x=0, y=0,a=0, b=0; //k - kierunek

    wyptab();

    int czasstart = time(NULL);
    while(true)
    {
        a=0;
        l=0;
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                gotoxy(j+1,i+1);
                cout << tab[i][j];
            }
        }


        if(kbhit())
        {
            znak = getch();

            if(znak==32)
            {
                tab[y][x] = !tab[y][x];

                if(y!=9)tab[y+1][x] = !tab[y+1][x];
                if(y!=0)tab[y-1][x] = !tab[y-1][x];
                if(x!=0)tab[y][x-1] = !tab[y][x-1];
                if(x!=9)tab[y][x+1] = !tab[y][x+1];

                b++;
            }

            if(znak==224)
            {
                k=getch();
                gotoxy(x+1,0);
                cout << " ";
                gotoxy(0,y+1);
                cout << " ";
                if(k==72 && y>0) y--;
                if(k==75 && x>0) x--;
                if(k==77 && x<9) x++;
                if(k==80 && y<9) y++;
            }
        }
        gotoxy(x+1,0);
        cout << "|";
        gotoxy(0,y+1);
        cout << "-";

        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                a+=tab[i][j];
            }
        }
        if(a==0 || a==100)
        {
            for(int i=0; i<10; i++)cout << endl;
            cout<< "You won!!!" << endl << "Time: "<<time(NULL)-czasstart << endl << "Moves: "<< b <<endl;
            cout << "To continue press 1, if that's enough press 2" << endl;

            while(true)
           {

                cin >> l;
                if(l==2 || l==1) break;
                if(l!=2 && l!=1) cout << "1 OR 2!" << endl;
           }

            if(l==2)break;
            if(l==1)
            {
                wyptab();


                       for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            tab[i][j] = rand()%2;
                system("cls");
            }
        }
    }
}
