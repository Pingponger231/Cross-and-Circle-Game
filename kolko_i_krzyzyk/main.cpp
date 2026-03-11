#include <iostream>

using namespace std;

int wygrana( char plansza[3] [3], char y)
{
    if (plansza [0] [0] == y && plansza [0] [1] == y && plansza [0] [2] == y)
    {
        return 0;
    }
    if (plansza [1] [0] == y && plansza [1] [1] == y && plansza [1] [2] == y)
    {
        return 0;
    }
    if (plansza [2] [0] == y && plansza [2] [1] == y && plansza [2] [2] == y)
    {
        return 0;
    }
    if (plansza [0] [0] == y && plansza [1] [0] == y && plansza [2] [0] == y)
    {
        return 0;
    }
    if (plansza [0] [1] == y && plansza [1] [1] == y && plansza [2] [1] == y)
    {
        return 0;
    }
    if (plansza [0] [2] == y && plansza [1] [2] == y && plansza [2] [2] == y)
    {
        return 0;
    }
    if (plansza [0] [0] == y && plansza [1] [1] == y && plansza [2] [2] == y)
    {
        return 0;
    }
    if (plansza [0] [2] == y && plansza [1] [1] == y && plansza [2] [0] == y)
    {
        return 0;
    }
    return 1;
}
int remis(char plansza[3] [3])
{
    int ile = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (plansza [i] [y] != ' ')
            {
                ile++;
            }
        }
    }
    return ile;

}

int main()
{
    char plansza [3] [3];
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int y = 0; y < 3; y++)
        {
            plansza[i] [y] = ' ';
            cout << plansza[i] [y];
            if (y == 0||y == 1)
            {
                cout << " | ";
            }
        }
        cout << endl;
        if (i == 0||i == 1)
        {
            cout << "-----------";
        }
        cout << endl;

    }
    int k1a,k1b, p1a,p1b;
    int puszczacz = 0;
    while (wygrana(plansza, 'x') == 1 && wygrana(plansza, 'o') == 1)
    {
        while (puszczacz == 0) // krzyzyk
        {
            cout << "Podaj miejsce w wierszu (krzyzyk): ";
            cin >> k1a;
            cout << "Podaj miejsce w kolumnie (krzyzyk): ";
            cin >> k1b;
            if (k1a > 3|| k1b > 3)
            {
                cout << "Wymiar nie moze byc wiekszy niz 3!" << endl;
                cout << "Wpisz jeszcze raz: " << endl;
            }
            else
            {
                if (plansza [k1a-1] [k1b-1] == ' ')
                {
                    puszczacz++;
                }
                else
                {
                    cout << "To miejsce jest juz zajete!" << endl;
                }

            }
        }
        plansza [k1a - 1] [k1b - 1] = 'x';
        for (int i = 0; i < 3; i++) // wyœwietlanie planszy po krzyzyku
        {
            cout << " ";
            for (int y = 0; y < 3; y++)
            {
                cout << plansza[i] [y];
                if (y == 0||y == 1)
                {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i == 0||i == 1)
            {
                cout << "-----------";
            }
            cout << endl;
        }
        puszczacz = 0;
        if (wygrana(plansza, 'x') == 0 || remis(plansza)== 9)
        {
            break;
        }
        int puszczacz2 = 0;
        while (puszczacz2 == 0) // kolko
        {
            cout << "Podaj miejsce w wierszu (kolko): ";
            cin >> p1a;
            cout << "Podaj miejsce w kolumnie (kolko): ";
            cin >> p1b;
            if (p1a > 3|| p1b > 3)
            {
                cout << "Wymiar nie moze byc wiekszy niz 3!" << endl;
                cout << "Wpisz jeszcze raz: " << endl;
            }
            else
            {
                if (plansza [p1a-1] [p1b-1] == ' ')
                {
                    puszczacz2++;
                }
                else
                {
                    cout << "To miejsce jest juz zajete!" << endl;
                }
            }
        }
        puszczacz2 == 0;
        plansza [p1a - 1] [p1b - 1] = 'o';
        for (int i = 0; i < 3; i++) // wyswietlanie planszy po kolko
        {
            cout << " ";
            for (int y = 0; y < 3; y++)
            {
                cout << plansza[i] [y];
                if (y == 0||y == 1)
                {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i == 0||i == 1)
            {
                cout << "-----------";
            }
            cout << endl;
        }
    }
    if (wygrana(plansza, 'x') == 0)
    {
        cout << "Krzyzyk wygral!!!";
    }
    else
    {
        if(wygrana(plansza, 'o') == 0)
           {
               cout << "Kolko wygralo!!!";
           }
           else
            {
                cout << "Jest remis!!!";
            }
    }
}
