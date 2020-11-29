#include <iostream>
#include <iomanip>

void write(float table[], float array_size);
float max_result(float table[], float array_size);
float min_result(float table[], float array_size);
void check_max(float table[], float array_size, float value);
void check_min(float table[], float array_size, float value);
void average_year(float table[], float array_size);
void financial_losses(float table[], float array_size);
void change_array_value(float table[], float array_size);

int main()
{
    const int size_of_array = 12;
    float data_last_year[size_of_array] = {-128, 48.5, 72.3, 150.5, -10, 332, 134, 12, 185.9, -54, 100, 332}, max_value, min_value;
    int choice, repeat;

    /* Wyswietla warotsci maksymlana i minimalna*/
    max_value = max_result(data_last_year, size_of_array);
    check_max(data_last_year, size_of_array, max_value);
    min_value = min_result(data_last_year, size_of_array);
    check_min(data_last_year, size_of_array, min_value);

    /* Wyswietla srednia */
    average_year(data_last_year, size_of_array);

    /* Wyswietla straty */
    financial_losses(data_last_year, size_of_array);
    std::cout << "\n";

    /* Petla do - while pozwala na powtórne wykonanie zaimplementowanych funkcji*/
    do
    {
        std::cout << "---> MENU <---\nAby wybrac dzialanie wprowadz cyfre (zatwierdz wybor klikajac ENTER):\n"
            " 1 - Sprawdz miesiac z maksymalnym i minimalnym wynikiem\n"
            " 2 - Wyswietl srednia roczna\n"
            " 3 - Sprawdz straty\n"
            " 4 - Zmien wynik miesiaca\n"
            " 5 - Sprawdz dane analityczne\n";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                system("CLS");
                max_value = max_result(data_last_year, size_of_array);
                check_max(data_last_year, size_of_array, max_value);
                min_value = min_result(data_last_year, size_of_array);
                check_min(data_last_year, size_of_array, min_value);
                break;

            case 2:
                system("CLS");
                average_year(data_last_year, size_of_array);
                break;

            case 3:
                system("CLS");
                financial_losses(data_last_year, size_of_array);
                break;

            case 4:
                system("CLS");
                change_array_value(data_last_year, size_of_array);
                break;

            case 5:
                system("CLS");
                write(data_last_year, size_of_array);
                break;
        }

        std::cout << "\nCzy chcesz przejsc do menu?\n"
                "1 - Tak, przejdz do menu.\n"
                "2 - Nie, wyjdz z programu.\n";
        std::cin >> repeat;
        system("CLS");
    }
    while (repeat == 1);

    std::cout<<"###\n##\n#\n DO ZOBACZENIA!\n#\n##\n###";

    return 0;
}

/* Funkcja wypisuje dane finansowe */
void write(float table[], float array_size)
{
    std::cout << "<--- Dane do analizy --->\n";
    for (int i = 0; i < array_size; i++)
    {
        if(i+1 == 1)
        {
            std::cout << "Styczen: " << table[i] << "\n";
        }
        else if(i+1 == 2)
        {
            std::cout << "Luty: " << table[i] << "\n";
        }
        else if(i+1 == 3)
        {
            std::cout << "Marzec: " << table[i] << "\n";
        }
        else if(i+1 == 4)
        {
            std::cout << "Kwiecien: " << table[i] << "\n";
        }
        else if(i+1 == 5)
        {
            std::cout << "Maj: " << table[i] << "\n";
        }
        else if(i+1 == 6)
        {
            std::cout << "Czerwiec: " << table[i] << "\n";
        }
        else if(i+1 == 7)
        {
            std::cout << "Lipiec: " << table[i] << "\n";
        }
        else if(i+1 == 8)
        {
            std::cout << "Sierpien: " << table[i] << "\n";
        }
        else if(i+1 == 9)
        {
            std::cout << "Wrzesien: " << table[i] << "\n";
        }
        else if(i+1 == 10)
        {
            std::cout << "Pazdziernik: " << table[i] << "\n";
        }
        else if(i+1 == 11)
        {
            std::cout << "Listopad: " << table[i] << "\n";
        }
        else if(i+1 == 12)
        {
            std::cout << "Grudzien: " << table[i] << "\n";
        }
    }
}

/* Funkcja sprawdza maxymalna wartosc i ja zwraca */
float max_result(float table[], float array_size)
{
    float max_value;
    max_value = table[0];

    for(int i = 0; i < array_size - 1; i++)
    {
        if(table[i] >= max_value)
        {
            max_value = table[i];
        }
    }
    return max_value;
}

/* Funkcja sprawdza minimalna wartosc i ja zwraca */
float min_result(float table[], float array_size)
{
    float min_value;
    min_value = table[0];

    for(int i = 0; i < array_size - 1; i++)
    {
        if(table[i] <= min_value)
        {
            min_value = table[i];
        }
    }
    return min_value;
}

/* Funkcja sprawdza w jakim miesiacu wystapila wartosc przekazana
   jako parametr i zwraca numer miesiaca */
void check_max(float table[], float array_size, float value)
{
    float month = 0;
    int counter = 0;

    std::cout << "\n<--- Najwyzsze przychody w roku --->\n";

    for(int i = 0; i < array_size; i++)
    {
        if(table[i] == value)
        {
            month = i + 1;
            counter++;

            if(month == 1)
            {
                std::cout << counter << ". Styczen wartosc: " << value << "\n";
            }
            else if(month == 2)
            {
                std::cout << counter << ". Luty wartosc: " << value << "\n";
            }
            else if(month == 3)
            {
                std::cout << counter << ". Marzec wartosc: " << value << "\n";
            }
            else if(month == 4)
            {
                std::cout << counter << ". Kwiecien wartosc: " << value << "\n";
            }
            else if(month == 5)
            {
                std::cout << counter << ". Maj wartosc: " << value << "\n";
            }
            else if(month == 6)
            {
                std::cout << counter << ". Czerwiec wartosc: " << value << "\n";
            }
            else if(month == 7)
            {
                std::cout << counter << ". Lipiec wartosc: " << value << "\n";
            }
            else if(month == 8)
            {
                std::cout << counter << ". Sierpien wartosc: " << value << "\n";
            }
            else if(month == 9)
            {
                std::cout << counter << ". Wrzesien wartosc: " << value << "\n";
            }
            else if(month == 10)
            {
                std::cout << counter << ". Pazdziernik: " << value << "\n";
            }
            else if(month == 11)
            {
                std::cout << counter << ". Listopad wartosc: " << value << "\n";
            }
            else if(month == 12)
            {
                std::cout << counter << ". Grudzien wartosc: " << value << "\n";
            }
            else
            {
                std::cout << "Sprawdz rozmiar tablicy!";
            }
        }
    }
    std::cout << "\nPODSUMOWANIE:\n"
            "Ilosc miesiecy z najwyzszym przychodem to: " << counter << "\n"
            "Suma najwyzszych przychodow to: " << counter * value << "\n";
}

/* Funkcja sprawdza wartosci minimalne */
void check_min(float table[], float array_size, float value)
{
    float month = 0;
    int counter = 0;

    std::cout << "\n<--- Najnizsze przychody w roku --->\n";
    for(int i = 0; i < array_size; i++)
    {
        if(table[i] == value)
        {
            month = i + 1;
            counter++;
            if(month == 1)
            {
                std::cout << counter << ". Styczen wartosc: " << value << "\n";
            }
            else if(month == 2)
            {
                std::cout << counter << ". Luty wartosc: " << value << "\n";
            }
            else if(month == 3)
            {
                std::cout << counter << ". Marzec wartosc: " << value << "\n";
            }
            else if(month == 4)
            {
                std::cout << counter << ". Kwiecien wartosc: " << value << "\n";
            }
            else if(month == 5)
            {
                std::cout << counter << ". Maj wartosc: " << value << "\n";
            }
            else if(month == 6)
            {
                std::cout << counter << ". Czerwiec wartosc: " << value << "\n";
            }
            else if(month == 7)
            {
                std::cout << counter << ". Lipiec wartosc: " << value << "\n";
            }
            else if(month == 8)
            {
                std::cout << counter << ". Sierpien wartosc: " << value << "\n";
            }
            else if(month == 9)
            {
                std::cout << counter << ". Wrzesien wartosc: " << value << "\n";
            }
            else if(month == 10)
            {
                std::cout << counter << ". Pazdziernik: " << value << "\n";
            }
            else if(month == 11)
            {
                std::cout << counter << ". Listopad wartosc: " << value << "\n";
            }
            else if(month == 12)
            {
                std::cout << counter << ". Grudzien wartosc: " << value << "\n";
            }
            else
            {
                std::cout << "Sprawdz rozmiar tablicy!";
            }
        }
    }
    std::cout << "\nPODSUMOWANIE:\n"
            "Ilosc miesiecy z najnizszym przychodem to: " << counter << "\n"
            "Suma najnizszych przychodow to: " << counter * value << "\n";
}

/* Funkcja sprawdza srednia uzyskana w roku*/
void average_year(float table[], float array_size)
{
    float sum = 0;
    std::cout << "\n<--- Srednia roczna --->\n";
    for(int i = 0; i < array_size; i++)
    {
        sum += table[i];
    }
    std::cout << "Srednia uzyskana w roku to: " << sum / array_size << "\n";
}

/* Funkcja sprawdza i wyswietla starty w tabeli danych */
void financial_losses(float table[], float array_size)
{
    int month = 0, counter = 0;
    float value = 0, sumary = 0;

    std::cout << "\n<--- Straty w ciagu roku --->\n";
    for(int i = 0; i < array_size; i++)
    {
        if(table[i] < 0)
        {
            month = i + 1;
            value = table[i];
            counter++;
            sumary += value;
            if(month == 1)
            {
                std::cout << counter << ". Styczen wartosc straty: " << value << "\n";
            }
            else if(month == 2)
            {
                std::cout << counter << ". Luty wartosc straty: " << value << "\n";
            }
            else if(month == 3)
            {
                std::cout << counter << ". Marzec wartosc straty: " << value << "\n";
            }
            else if(month == 4)
            {
                std::cout << counter << ". Kwiecien wartosc straty: " << value << "\n";
            }
            else if(month == 5)
            {
                std::cout << counter << ". Maj wartosc straty: " << value << "\n";
            }
            else if(month == 6)
            {
                std::cout << counter << ". Czerwiec wartosc straty: " << value << "\n";
            }
            else if(month == 7)
            {
                std::cout << counter << ". Lipiec wartosc straty: " << value << "\n";
            }
            else if(month == 8)
            {
                std::cout << counter << ". Sierpien wartosc straty: " << value << "\n";
            }
            else if(month == 9)
            {
                std::cout << counter << ". Wrzesien wartosc straty: " << value << "\n";
            }
            else if(month == 10)
            {
                std::cout << counter << ". Pazdziernik wartosc straty: " << value << "\n";
            }
            else if(month == 11)
            {
                std::cout << counter << ". Listopad wartosc straty: " << value << "\n";
            }
            else if(month == 2)
            {
                std::cout << counter << ". Grudzien wartosc straty: " << value << "\n";
            }
            else
            {
                std::cout << "Sprawdz rozmiar tablicy!";
            }
        }
    }
    std::cout << "\nPODSUMOWANIE:\n"
            "Ilosc miesiecy ze strata to: " << counter << "\n"
            "Suma strat to: " << sumary << "\n";
}

/* Funkcja pozwala na zmiane wartosci w tabeli dnaych */
void change_array_value(float table[], float array_size)
{
    int i = 0, month;
    float new_value;

    std::cout << "W jakim miesiacu chcesz dokonac zmiany?\n";
    std::cin >> month;
    std::cout << "Podaj nowa wartosc:\n";
    std::cin >> new_value;

    i = month;
    if(i == 1)
    {
        table[i - 1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w styczniu to: " << new_value << "\n";
    }
    else if(i == 2)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w lutym to: " << new_value << "\n";
    }
    else if(i == 3)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w marcu to: " << new_value << "\n";
    }
    else if(i == 4)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w kwietniu to: " << new_value << "\n";
    }
    else if(i == 5)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w maju to: " << new_value << "\n";
    }
    else if(i == 6)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w czerwcu to: " << new_value << "\n";
    }
    else if(i == 7)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w lipcu to: " << new_value << "\n";
    }
    else if(i == 8)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w sierpniu to: " << new_value << "\n";
    }
    else if(i == 9)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w wrzesniu to: " << new_value << "\n";
    }
    else if(i == 10)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w pazdzierniku to: " << new_value << "\n";
    }
    else if(i == 11)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w listopadzie to: " << new_value << "\n";
    }
    else if(i == 12)
    {
        table[i -1] = new_value;
        std::cout << "ZROBIONE!\nAktualny wynik w grudniu to: " << new_value << "\n";
    }
    else
    {
        std::cout << "Ups!\nMiesiac o numerze "<< i << " nie istnieje. \n Wybierz z zakresu od 1 do 12\n###\n##\n#\nNIC NIE ZMIENIONO :-(\n";
    }
}
