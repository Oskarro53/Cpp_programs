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

struct segment
{
    int x;
    int y;

};

main()
{
    ShowConsoleCursor(false);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));
    SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
    int kols, kolm, interfejs;
   while(true)
   {


        cout <<
     R"(  ________  _____  ___        __       __   ___  _______
 /"       )(\"   \|"  \      /""\     |/"| /  ")/"     "|
(:   \___/ |.\\   \    |    /    \    (: |/   /(: ______)
 \___  \   |: \.   \\  |   /' /\  \   |    __/  \/    |
  __/  \\  |.  \    \. |  //  __'  \  (// _  \  // ___)_
 /" \   :) |    \    \ | /   /  \\  \ |: | \  \(:      "|
(_______/   \___|\____\)(___/    \___)(__|  \__)\_______)
                                                         )";


        SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
        cout << endl<< R"(  _
 / \  _ |   _. ._ ._ _     _   _| o _|_ o  _  ._
 \_/ _> |< (_| |  | (_)   (/_ (_| |  |_ | (_) | |
                                                  )";


        SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
        cout<< endl << endl <<"1. How to play" <<endl;
        SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
        cout << "2. Start game" <<endl;
        while(true)
        {
            cin >> interfejs;
            if(interfejs == 1 || interfejs == 2) break;
            else cout << "There are only options 1 and 2 :{" << endl;
        }
        if(interfejs==1)
        {
            while(true)
            {
                cout << endl << "Use arrows to change direction of snake (***o). If head (o) touches a wall (|, -) or snake's body (*) you loose. Fruits (O) give you points but also make the snake longer and faster. Poison (X) works the other way around. There are also portals (@) that allow you to go through walls. The game ends when you loose. Have fun!!!"<<endl<<"Press any button to continue";
                //if(kbhit()) break;
                Sleep(200);
                system("cls");
                if(kbhit())break;

            }
        }
        if(interfejs==2)break;
   }
    while(true)
    {


    cout << endl << "Choose snake color" << endl << "1 - blue"<< endl << "2 - green" << endl << "3 - ocean blue"<< endl<< "4 - red"<< endl<< "5 - pink"<< endl<< "6 - yellow"<< endl<< "7 - white"<< endl<< "8 - gray"<< endl<< "9 - light blue"<< endl<< "10 - light green"<< endl<< "11 - light ocean blue"<< endl<< "12 - light red"<< endl<< "13 - light pink"<< endl<< "14 - light yellow"<< endl<< "15 - snow-white"<< endl<< "420 - colorful madness"<< endl;
    while(true)
    {
        cin >> kols;
        if(kols>=1 && kols<=15)break;
        if(kols == 420) break;
        if(kols<1 || kols>15 && kols != 420) cout << "Ma byc liczba od 1 do 15 lub 420!"<<endl;
    }
    cout << endl << "Choose map color" << endl << "1 - blue"<< endl << "2 - green" << endl << "3 - ocean blue"<< endl<< "4 - red"<< endl<< "5 - pink"<< endl<< "6 - yellow"<< endl<< "7 - white"<< endl<< "8 - gray"<< endl<< "9 - light blue"<< endl<< "10 - light green"<< endl<< "11 - light ocean blue"<< endl<< "12 - light red"<< endl<< "13 - light pink"<< endl<< "14 - light yellow"<< endl<< "15 - snow-white"<< endl<< "420 - colorful madness"<< endl;
    while(true)
    {
        cin >> kolm;
        if(kolm>=1 && kolm<=15)break;
        if(kolm == 420) break;
        if(kolm<1 || kolm>15 && kolm != 420) cout << "1 to 15 or 420!"<<endl;
    }

    system("cls");
    break;
 }

    //srand(time(0));
vector <segment> szczur;
vector <segment> wolneMiejsca;
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

szczur.push_back({12,12});
szczur.push_back({13,12});
szczur.push_back({14,12});
szczur.push_back({15,12});
szczur.push_back({16,12});

int kodznaku, kodstrzalki, pauza=0, owoc=-1, trutka=-2, trutkax=-2, trutkay=-2, portal=-3, portalx=-3, portalon=0, portaly=-3, owocx=-1, owocy=-1, mapszer=25, mapdlg=25, score=0, sleep=220, stop=0, czaspauza=0, czaswpauzie=0,czass=0, czas=time(NULL),  k=2;

    while(true)
    {

    if(pauza==0)
   {

    for(int i=0; i<25; i++)
    {
        gotoxy(0,i);
        if(kolm != 420)
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, kolm);
            else SetConsoleTextAttribute(hConsole, 18);
            cout << "*";
        }
        else
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
            else SetConsoleTextAttribute(hConsole, losuj(16, 250));
            cout << "*";
        }
    }
    for(int i=0; i<26; i++)
    {
        gotoxy(25,i);
        if(kolm != 420)
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, kolm);
            else SetConsoleTextAttribute(hConsole, 18);
            cout << "*";
        }
        else
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
            else SetConsoleTextAttribute(hConsole, losuj(16, 250));
            cout << "*";
        }
    }
    for(int i=0; i<25; i++)
    {
        gotoxy(i,0);
        if(kolm != 420)
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, kolm);
            else SetConsoleTextAttribute(hConsole, 18);
            cout << "*";
        }
        else
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
            else SetConsoleTextAttribute(hConsole, losuj(16, 250));
            cout << "*";
        }
    }
    for(int i=0; i<25; i++)
    {
        gotoxy(i,25);
        if(kolm != 420)
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, kolm);
            else SetConsoleTextAttribute(hConsole, 18);
            cout << "*";
        }
        else
        {
            if(portalon==0)SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
            else SetConsoleTextAttribute(hConsole, losuj(16, 250));
            cout << "*";
        }
    }

        if(kbhit())
        {
            kodznaku = getch();
            if(kodznaku==224)
            {
                kodstrzalki=getch();
                if(kodstrzalki==72 && k!=3) k=1; //gora
                if(kodstrzalki==75 && k!=2) k=4; //lewo
                if(kodstrzalki==77 && k!=4) k=2; //prawo
                if(kodstrzalki==80 && k!=1) k=3; //dol
            }
            if(kodznaku == 32) pauza++;
        }

        if(owoc != -1) szczur.erase(szczur.begin());//usuwanie dupy szczura

        switch(k)
        {
            case 1:
                szczur.push_back({szczur[szczur.size()-1].x, szczur[szczur.size()-1].y-1}); // nowy leb szczura
            break;
            case 2:
                szczur.push_back({szczur[szczur.size()-1].x+1, szczur[szczur.size()-1].y});
            break;
            case 3:
                szczur.push_back({szczur[szczur.size()-1].x, szczur[szczur.size()-1].y+1});
            break;
            case 4:
                szczur.push_back({szczur[szczur.size()-1].x-1, szczur[szczur.size()-1].y});
            break;
        }
        for(int i=0; i<szczur.size()-1; i++)
        {
            if(szczur[szczur.size()-1].x == szczur[i].x && szczur[szczur.size()-1].y == szczur[i].y) stop++;
        }
        if(portalon==0)
        {
            if(szczur[szczur.size()-1].x == 0 || szczur[szczur.size()-1].x == mapszer || szczur[szczur.size()-1].y == 0 || szczur[szczur.size()-1].y == mapdlg) stop++;
        }
        if(portalon>0)
        {
            if(szczur[szczur.size()-1].x == 0) szczur.push_back({mapszer-1, szczur[szczur.size()-1].y});
            if(szczur[szczur.size()-1].x == mapszer) szczur.push_back({1, szczur[szczur.size()-1].y});
            if(szczur[szczur.size()-1].y == 0) szczur.push_back({szczur[szczur.size()-1].x, mapdlg-1});
            if(szczur[szczur.size()-1].y == mapdlg) szczur.push_back({szczur[szczur.size()-1].x, 1});
        }
       if(stop==0)
       {
            wolneMiejsca.clear(); // sektor elementów jadalnych

        for(int i=1; i<25; i++)
           {
                for(int j=1; j<25; j++)
                {
                    bool czyZajete = false;
                    for(int m=0; m<szczur.size(); m++)
                    {
                        if(szczur[m].x ==j  && szczur[m].y == i) czyZajete = true;
                    }
                   if(!czyZajete) wolneMiejsca.push_back({j,i});
                }
           }

        if(owoc==-1)
        {
            owoc = rand()%wolneMiejsca.size();
            while(owocx==trutkax && owocy==trutkay)owoc = rand()%wolneMiejsca.size();
            while(owocx==portalx && owocy==portaly)owoc = rand()%wolneMiejsca.size();
            owocx = wolneMiejsca[owoc].x;
            owocy = wolneMiejsca[owoc].y;
        }

        if(trutka==-2 && losuj(0,30)==5)
        {
            trutka = rand()%wolneMiejsca.size();
            while(owocx==trutkax && owocy==trutkay)trutka = rand()%wolneMiejsca.size();
            while(trutkax==portalx && trutkay==portaly)trutka = rand()%wolneMiejsca.size();
            trutkax = wolneMiejsca[trutka].x;
            trutkay = wolneMiejsca[trutka].y;

        }

        if(portal==-3 && losuj(0,50)==5 && portalon==0)
        {
            portal = rand()%wolneMiejsca.size();
            while(portalx==trutkax && portaly==trutkay)portal = rand()%wolneMiejsca.size();
            while(owocx==portalx && owocy==portaly)portal = rand()%wolneMiejsca.size();
            portalx = wolneMiejsca[portal].x;
            portaly = wolneMiejsca[portal].y;

        }

        if(owocx==szczur[szczur.size()-1].x && owocy==szczur[szczur.size()-1].y)
        {
            owoc = -1;
            score++;
           if(sleep>100) sleep-=10;
        }
        if(trutkax==szczur[szczur.size()-1].x && trutkay==szczur[szczur.size()-1].y)
        {
            trutka = -2;
            score--;
            sleep+=10;
            trutkax=-1;
            trutkay=-1;
            szczur.erase(szczur.begin());
        }
        if(portalx==szczur[szczur.size()-1].x && portaly==szczur[szczur.size()-1].y)
        {
            portal = -3;
            portalon=18;
            portalx=-2;
            portaly=-2;
        }

        if(owoc>-1)
        {
            gotoxy(owocx, owocy);
            cout << "O";
        }
        if(trutka>-1)
        {
            gotoxy(trutkax, trutkay);
            cout << "X";
        }

        if(portal>-1)
        {
            gotoxy(portalx, portaly);
            cout << "@";
        }
        gotoxy(szczur[szczur.size()-1].x,szczur[szczur.size()-1].y);
        if(kols!=420)SetConsoleTextAttribute(hConsole, kols);
        else SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
        cout << "o";

        for(int i=0; i<szczur.size()-1; i++)
        {
            if(kols!=420)SetConsoleTextAttribute(hConsole, kols);
            else SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
            gotoxy(szczur[i].x,szczur[i].y);
            cout<<"*";
        }
        gotoxy(35, 10);

        if(kolm!=420)SetConsoleTextAttribute(hConsole, kolm);
        else SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
        cout << "Time: "<< time(NULL) - czas - czass;
        gotoxy(35, 11);
        cout << "Score: " << score;
        gotoxy(35, 12);
        cout << "Press space to pause the game";
        Sleep(sleep);
        if(score<0) stop++;
        if(portalon>0)portalon--;
        }
        system("cls");

    if(stop!=0)
    {
        if(kolm!=420)SetConsoleTextAttribute(hConsole, kolm);
        else SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
            cout << R"(
  _______      ___      .___  ___.  _______      ______   ____    ____  _______ .______       __
 /  _____|    /   \     |   \/   | |   ____|    /  __  \  \   \  /   / |   ____||   _  \     |  |
|  |  __     /  ^  \    |  \  /  | |  |__      |  |  |  |  \   \/   /  |  |__   |  |_)  |    |  |
|  | |_ |   /  /_\  \   |  |\/|  | |   __|     |  |  |  |   \      /   |   __|  |      /     |  |
|  |__| |  /  _____  \  |  |  |  | |  |____    |  `--'  |    \    /    |  |____ |  |\  \----.|__|
 \______| /__/     \__\ |__|  |__| |_______|    \______/      \__/     |_______|| _| `._____|(__)
                                                                                                  )" << endl << "Score: " << score;
                                                                                                  if(score<=-1)cout <<  endl << "(Good job :})";
                                                                                                    cout << endl << "Time: " << time(NULL)-czas << endl;
            cout << "Press 1 to continue, press 2 to finish" << endl;
            int l =0;
            while(true)
           {

                cin >> l;
                if(l==2 || l==1) break;
                if(l!=2 && l!=1) cout << "1 OR 2!" << endl;
           }

            if(l==2)break;
            if(l==1)
            {
                l=0;
                k=2;
                czas = time(NULL);
                score = 0;
                szczur.clear();
                szczur.push_back({12,12});
                szczur.push_back({13,12});
                szczur.push_back({14,12});
                szczur.push_back({15,12});
                szczur.push_back({16,12});
                stop=0;
                system("cls");
                wolneMiejsca.clear();
                owoc=-1;
                trutka=-2;
                portal=-3;
                czaswpauzie=0;
                czass=0;

        for(int i=1; i<25; i++)
           {
                for(int j=1; j<25; j++)
                {
                    bool czyZajete = false;
                    for(int m=0; m<szczur.size(); m++)
                    {
                        if(szczur[m].x ==j  && szczur[m].y == i) czyZajete = true;

                    }
                   if(!czyZajete) wolneMiejsca.push_back({j,i});
                }
           }
        if(owoc==-1)
        {
            owoc = rand()%wolneMiejsca.size();
            owocx = wolneMiejsca[owoc].x;
            owocy = wolneMiejsca[owoc].y;
        }
        if(owoc>-1)
        {
            gotoxy(owocx, owocy);
            cout << "O";
        }
            }
    }
   }
    else
    {
        if(czaspauza==0)czaspauza = time(NULL) - czas- czass;
        if(czaswpauzie==0)czaswpauzie = time(NULL);
        if(kolm!=420)SetConsoleTextAttribute(hConsole, kolm);
        else SetConsoleTextAttribute(hConsole, rand() % 14 + 1);
        cout << R"(.______      ___      __    __   ________      ___
|   _  \    /   \    |  |  |  | |       /     /   \
|  |_)  |  /  ^  \   |  |  |  | `---/  /     /  ^  \
|   ___/  /  /_\  \  |  |  |  |    /  /     /  /_\  \
|  |     /  _____  \ |  `--'  |   /  /----./  _____  \
| _|    /__/     \__\ \______/   /________/__/     \__\
                                                        )" << endl
    << "Time: " << czaspauza << endl << "Score: " << score<< endl << "Press space to continue game"<< endl <<"Press x to finish game";
     if(kbhit())
        {
            kodznaku = getch();
            if(kodznaku == 32)
            {
                pauza=0;
                czaspauza=0;
                czass+=time(NULL)-czaswpauzie;
                czaswpauzie=0;
            }
            if(kodznaku == 120) break;

        }
    Sleep(sleep);
    system("cls");
    }
    }
}
