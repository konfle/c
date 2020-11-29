#include <iostream>
#include <ctime>
#include <conio.h>

void dice_throw(int throw_amount, int table_points[]);
void show_points(int table_points[], int amount_of_cube);
int sum_of_points(int table_points[], int amount_of_cube);
int check_win(int points);
int second_win_check(int points_to_win, int points);


int main()
{
    srand(time(0));
    const int THROW_NO = 2, CUBE_AMOUNT = 2;
    int points[CUBE_AMOUNT], points_amount = 0, win = 0, win2 = 0;

    std::cout << "Kostki\n";
    dice_throw(THROW_NO, points); // pierwszy rzut kostka
    show_points(points, CUBE_AMOUNT); // wyswietla ile oczek na kostce 1 i 2
    points_amount = sum_of_points(points, CUBE_AMOUNT); // sumuje ilosc wyrzuconych oczek i przypisuje do zmiennej
    std::cout << "Po pierwszym rzucie masz " << points_amount << " punktow.\n";

    win = check_win(points_amount); /* sprawdza czy wygrana 7 i 11
                                       2, 3, 12 przegrana
                                       4, 5, 6, 8, 9, 10 = punkty
                                       wynik zapisujemy w zmiennej win*/

    std::cout << "----------------------------------------\n";

    /* jesli win ma wartosc punktow to:
    rzucamy kostka,
    wyswietlamy oczka kostki 1 i 2
    sumujemy ilosc oczek i zapisujemy w zminnej points_amount
    sprawdzamy czy suma drugiego rzutu jest równa punktom*/

        if(win == 4)
        {
            do
            {
                std::cout << "Nacisnij jakis klawisz aby rzucic ponownie\n";
                getch();
                system("CLS");
                dice_throw(THROW_NO, points);
                show_points(points, CUBE_AMOUNT);
                points_amount = sum_of_points(points, CUBE_AMOUNT);
                win2 = second_win_check(win, points_amount);
            }
            while(win2 !=1);
        }
        else if(win == 5)
        {
            do
            {
                std::cout << "Nacisnij jakis klawisz aby rzucic ponownie\n";
                getch();
                system("CLS");
                dice_throw(THROW_NO, points);
                show_points(points, CUBE_AMOUNT);
                points_amount = sum_of_points(points, CUBE_AMOUNT);
                win2 = second_win_check(win, points_amount);
            }
            while(win2 !=1);
        }
        else if(win == 6)
        {
            do
            {
                std::cout << "Nacisnij jakis klawisz aby rzucic ponownie\n";
                getch();
                system("CLS");
                dice_throw(THROW_NO, points);
                show_points(points, CUBE_AMOUNT);
                points_amount = sum_of_points(points, CUBE_AMOUNT);
                win2 = second_win_check(win, points_amount);
            }
            while(win2 !=1);
        }
        else if(win == 8)
        {
            do
            {
                std::cout << "Nacisnij jakis klawisz aby rzucic ponownie\n";
                getch();
                system("CLS");
                dice_throw(THROW_NO, points);
                show_points(points, CUBE_AMOUNT);
                points_amount = sum_of_points(points, CUBE_AMOUNT);
                win2 = second_win_check(win, points_amount);
            }
            while(win2 !=1);
        }
        else if(win == 9)
        {
            do
            {
                std::cout << "Nacisnij jakis klawisz aby rzucic ponownie\n";
                getch();
                system("CLS");
                dice_throw(THROW_NO, points);
                show_points(points, CUBE_AMOUNT);
                points_amount = sum_of_points(points, CUBE_AMOUNT);
                win2 = second_win_check(win, points_amount);
            }
            while(win2 !=1);
        }
        else if(win == 10)
        {
            do
            {
                std::cout << "Nacisnij jakis klawisz aby rzucic ponownie\n";
                getch();
                system("CLS");
                dice_throw(THROW_NO, points);
                show_points(points, CUBE_AMOUNT);
                points_amount = sum_of_points(points, CUBE_AMOUNT);
                win2 = second_win_check(win, points_amount);
            }
            while(win2 != 1);
        }
    return 0;
}


void dice_throw(int throw_amount, int table_points[])
{
    int cube_end = 6;
    int cube_start = 1;
    for (int i = 0; i < throw_amount; i++)
        table_points[i] = cube_start + rand() % (cube_end - cube_start + 1);
}

void show_points(int table_points[], int amount_of_cube)
{
    int counter = 0;
    for(int i = 0; i < amount_of_cube; i++)
    {
        std::cout << counter + 1 << " kostka --> " << table_points[i] << "\n";
        counter++;
    }
}

int sum_of_points(int table_points[], int amount_of_cube)
{
    int sum = 0;
    for(int i = 0; i < amount_of_cube; i++)
    {
        sum += table_points[i];
    }
    return sum;
}

int check_win(int points)
{
    int pkt = 0;
    if(points == 7)
    {
        std::cout << "***___WYGRANA___***\n";
        pkt = points;
    }
    else if (points == 11)
    {
        std::cout << "***___WYGRANA___***\n";
        pkt = points;

    }
    else if (points == 2)
    {
        std::cout << "***___PZEGRYWASZ___***\n";
        pkt = points;

    }
    else if (points == 3)
    {
        std::cout << "***___PZEGRYWASZ___***\n";
        pkt = points;

    }
    else if (points == 12)
    {
        std::cout << "***___PZEGRYWASZ___***\n";
        pkt = points;

    }
    else if (points == 4)
    {
        std::cout <<
                "Zdobywasz " << points << " punktow.\n"
                "Aby wygrac musisz wyrzucic dokladnie " << points << "\n";
                pkt = points;
    }
    else if (points == 5)
    {
        std::cout <<
                "Zdobywasz " << points << " punktow.\n"
                "Aby wygrac musisz wyrzucic dokladnie " << points << "\n";
                pkt = points;
    }
    else if (points == 6)
    {
        std::cout <<
                "Zdobywasz " << points << " punktow.\n"
                "Aby wygrac musisz wyrzucic dokladnie " << points << "\n";
                pkt = points;
    }
    else if (points == 8)
    {
        std::cout <<
                "Zdobywasz " << points << " punktow.\n"
                "Aby wygrac musisz wyrzucic dokladnie " << points << "\n";
                pkt = points;
    }
    else if (points == 9)
    {
        std::cout <<
                "Zdobywasz " << points << " punktow.\n"
                "Aby wygrac musisz wyrzucic dokladnie " << points << "\n";
                pkt = points;
    }
    else if (points == 10)
    {
        std::cout <<
                "Zdobywasz " << points << " punktow.\n"
                "Aby wygrac musisz wyrzucic dokladnie " << points << "\n";
                pkt = points;
    }
    return pkt;
}

int second_win_check(int points_to_win, int points)
{
    int win = 0;
    if(points_to_win == points)
    {
        std::cout << "***___WYGRANA___***\n"
                "Wyrzuciles " << points << " oczek\n";
                win = 1;
    }
    else if(points == 7)
    {
        std::cout << "***___PZEGRYWASZ___***\n"
                "Wyrzuciles " << points << " oczek\n";
                win = 1;
    }
    else
    {
        std::cout << "Niestety, sprobuj jeszcze raz!\n"
                "Wyrzuciles " << points << " oczek. Wygrana to " << points_to_win << " oczka.\n";
                win = 0;
    }
    return win;
}
