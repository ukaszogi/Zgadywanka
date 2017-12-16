#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <algorithm>

using namespace std;

void zgaduj()
{
    char odp = '-';
    int x;
    bool wygrana = true, a = true;
    int y[7];

        system("cls");
        y [0] = 64;   y [1] = 32;   y [2] = 16;   x = 128;
        y [3] = 8;    y [4] = 4;    y [5] = 2;    y [6] = 1;
        cout << "Zgadne twa liczbe maksymalnie w 7 pytankach." << endl << "Pomysl liczbe ( calkowita ;) ) z zakresu 1 do 127"<< endl;
        cout << "Zasady sa proste: " << endl <<
        "1. Jesli Twoja liczba bedzie mniejsza, wpisz -"<< endl <<
        "2. Jesli Twoja liczba bedzie wieksza, wpisz +"<< endl <<
        "3. Jesli zgadlem wpisz, ="<< endl <<
        "4. I prosze, NIE WPISUJ WIECEJ NIZ JEDEN ZNAK!"<< endl <<
        "Nacisnij Enter by kontynuowac...";
        getchar();getchar();
        system("cls");
        cout << "Start!" << endl;
        for(int i = 0 ; wygrana ; i++)
        {
            switch(odp)
            {
                case '-':
                {
                    cout << "Czy to: " << x - y[i] << "?" <<endl;
                    cin >> odp;
                    while(a)
                    {
                        if((odp != '-') && (odp != '+') && (odp != '='))
                        {
                            cout << "Nie rozumiem. Sproboj wpisac '-', '+' lub '=': ";
                            cin >> odp;
                        }
                        else
                            a = false;
                    }
                    x = x - y[i];
                }
                break;
                case '+':
                {
                    cout << "Czy to: " << x + y[i] << "?" <<endl;
                    cin >> odp;
                    while(a)
                    {
                        if((odp != '-') && (odp != '+') && (odp != '='))
                        {
                            cout << "Nie rozumiem. Sproboj wpisac '-', '+' lub '=': ";
                            cin >> odp;
                        }
                        else
                            a = false;
                    }
                    x = x + y[i];
                }
                break;
                case '=':
                {
                    cout <<"Wiedzialem, ze wygram";
                    wygrana = false;
                    getchar(); getchar();
                }
                break;
                default:;
            }
        }
}

void wymysl()
{
    int liczba, strzal, proby=0;

        system("cls");
        cout << "Liczba z zakresu 1 do 127." << endl;
        srand(time(NULL));
        liczba = rand()% 127+1;

        while(strzal!=liczba)
        {
            proby++;
            cout << "Zgadnij jaka: (to twoja: " << proby <<" proba): ";
            cin >>strzal;
            if (strzal==liczba)
                cout << "Wygrales!!! Twoja liczba prob: "<<proby<<endl;
            else if (strzal<liczba)
                cout << "To za malo!!!"<<endl;
            else if (strzal>liczba)
                cout << "To za duzo!!!"<<endl;
        }
    getchar();getchar();
}


int main()
{
    bool a;
    string odp, odpo;

    system("title Zgadywanka");
    system("color 03");

    while(true)
    {
        a = true;
        system("cls");
        cout << "Kto zgaduje? Ty czy Ja?: ";
        while(a)
        {
            cin >> odp;
            transform(odp.begin(), odp.end(), odp.begin(), ::tolower);
            if(odp=="ty")
            {
                zgaduj();
                system("cls");
            }
            else if(odp=="ja")
            {
                wymysl();
                system("cls");
            }
            else
                cout << "Nie rozumiem. Sproboj wpisac 'ja', lub 'ty': ";
            cout << "Gramy dalej?: ";
            while(a)
            {
                cin >> odp;
                transform(odp.begin(), odp.end(), odp.begin(), ::tolower);
                if(odp == "nie")
                    exit(0);
                else if(odp != "tak")
                    cout <<  "Nie rozumiem. Sproboj wpisac 'tak', lub 'nie': ";
                else
                    a = false;
            }
        }
    }
    return 0;
}
