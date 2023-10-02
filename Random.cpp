#include <iostream>
#include<ctime>
#include<string>
#include<Windows.h> 

using namespace std;

void Help();//ф-н виводу інструкції

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);   //для укр мови 

    
    Help();//вивід інструкції

    string player1;//змінна для вводу команди гравцем

    while (player1 != "Стоп") {

        cout << "\t\tГра триватиме доки не напишете ''Стоп'' " << endl;


        srand(time(NULL));
        int k = rand() % 5;//задаєм рандом

        string player2;//змінна для команди пк

        if (k == 0) {//присвоєння в змінну для команди компа рандомне значення з допустимих
            player2 = "Камінь";
        }
        else if (k == 1) {
            player2 = "Ножиці";
        }
        else if (k == 2) {
            player2 = "Папір";
        }
        else if (k == 3) {
            player2 = "Ящірка";
        }
        else if (k == 4) {
            player2 = "Спок";
        }

        getline(cin,player1);//зчитуєм команду гравця

        if (player1 == "help"|| player1 == "Help" ) {
            Help();
            Sleep(5000);
        }
        else if (player1 != "Камінь" && player1 != "Ножиці" && player1 != "Папір" && player1 != "Ящірка" && player1 != "Спок")
        {
            cout << "Ви ввели невірну операцію" << endl;
        }
        else if (player1== player2) {//перевірка на виграш і нічию
             cout << "Нічия" << endl;
        }
        else if ((player1 == "Камінь" && player2 == "Ножиці") or (player1 == "Камінь" && player2 == "Ящірка") or//можна було зробити перевід у якийсь з регістрів щоб користувач міг ввести команду як хоч(НоЖиці - приклад , але я полінувавсь)
                (player1 == "Ножиці" && player2 == "Папір") or (player1 == "Ножиці" && player2 == "Ящірка") or
                (player1 == "Папір" && player2 == "Камінь") or (player1 == "Папір" && player2 == "Спок") or
                (player1 == "Ящірка" && player2 == "Спок") or (player1 == "Ящірка" && player2 == "Папір") or
                (player1 == "Спок" && player2 == "Ножиці") or (player1 == "Спок" && player2 == "Камінь"))
             {
                cout << "Перемога. Комп вибрав - " << player2 << endl << endl;
             }         

        else 
        {
            
                cout << "Поразка. Комп вибрав - " << player2 << endl << endl;
        }
        Sleep(1000);//пауза перед очищенням консолі
        system("cls");
    }
}

void Help()
{
    cout << "\t\t\t\tПривіт!!!\n\tВи y грі камінь – ножиці – папір – ящірка – спок!" << endl;
    cout << "Вводьте одну із наступних команд : Камінь, Ножиці, Папір, Ящірка, Спок" << endl;//типу меню
}
