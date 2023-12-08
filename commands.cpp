#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <locale>
#include "data.h"

using namespace std;

bool LoadCommands = false;
extern wstring version;
extern wstring language;

// команда help - показывает все команды
void help() {
    wcout << L"help - displays a list of all commands" << endl << L"version - shows the version of this \"game\"" << endl << L"delete - removes user from Real Life (DANGER!)" << endl << L"hi - Hi!" << endl << L"calculator - Calculator" << endl << L"RSP - Rock, Scissors, Paper!" << endl << L"time - Work Time" << endl << L"zmeika - Game.... (WHAT)" << endl << L"counter - ..." << endl;
    wcout << L"----------------------------------------------------------" << endl;
}

// команда calculator - КАЛЬКУЛЯТОР НА МИНИМАЛКАХ
void calculator() {
    double Fnum;
    double Snum;
    char op;

    wcout << L"Enter the first number: ";
    wcin >> Fnum;
    wcout << L"Enter the operator (+, -, *, /): ";
    cin >> op;
    wcout << L"Enter the second number: ";
    wcin >> Snum;

    double result;
    switch (op) {
        case '+':
            result = Fnum + Snum;
            break;
        case '-':
            result = Fnum - Snum;
            break;
        case '*':
            result = Fnum * Snum;
            break;
        case '/':
            if (Snum != 0) {
                result = Fnum / Snum;
            } else {
                    wcout << L"Error: Cannot divide by zero!" << L'\n';
            }
            break;
        default:
            wcout << L"Error: Invalid operator!" << L'\n';
        }

    wcout << L"Done! The result is: " << result << L'\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// HI! Hello! Привет!!!
void hi() {
    wcout << L"Hi!" << '\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// Камень, ножницы, бумага!
void RSP() {
    int a;
    wcout << L"Enter a number between one and three. 1 - Rock, 2 - Scissors, 3 - Paper: ";
    cin >> a;

    int v = rand() % 3 + 1;

    if (a == v) {
        wcout << "Tie!" << endl;
    }
    else if (a == 1 && v == 2) {
        wcout << "The rock breaks the scissors! The computer lost." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 2 && v == 3) {
        wcout << "The scissors cut the paper. The computer lost!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 2 && v == 1) {
        wcout << "The rock breaks the scissors! Player lost." << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 3 && v == 2) {
        wcout << "The scissors cut the paper. The player has lost!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 1 && v == 3) {
        wcout << "Paper covers stone... The player has lost!" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else if (a == 3 && v == 1) {
        wcout << "Player wins! Paper covers rock" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
    else {
        wcout << L"Вы, возможно, написали неверное число или символы. Чтобы игра нормальна работала пишите только \"1\", \"2\" и \"3\"" << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
}

// блокнот? 💀💀💀💀💀
void notepad() {
    string name_file;
    string data_text;
    string execute;
    string create;
    string tochka = ".";

    wcout << L"Создать файл или нужно изменить готовый? 1 - создать, 2 - изменить";
    cin >> create;
    wcout << L"Напиши имя файла (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, name_file);
    cin >> name_file;
    wcout << L"Что будет в этом файле? (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, data_text);
    cin >> data_text;
    wcout << L"Расширение файла (НА АНГЛИЙСКОМ ТОЛЬКО): ";
    getline(cin, execute);
    cin >> execute;

    string fileName = name_file + tochka + execute;

    if (create == "1") {
        ofstream data(fileName);
        data << data_text << L'\n';
        data.close();
        wcout << L"----------------------------------------------------------" << endl;
    }
    else {
        wcout << L"Ничего ещё не готово. Уходите\n";
        wcout << L"----------------------------------------------------------" << endl;
    }
    /*
    wifstream file("data.data");
    if (!file) {
        wofstream data("data.data");
            if (data) {
                data << L"Language: " << DefaultLanguage << L'\n';
                data << L"UserName: " << DefaultUserName << L'\n';
                data.close();
            }
            else {
                wcout << L"Error opening\\create the data file." << L'\n';
            }
        }
        else {
            file.close();
    }
    */
}

// Настройки
void settings() {
    int a;
    wstring b;
    int c;
    int d;

    wcout << L"What do you want to customize?\n1 - Profile\n2 - Language\n3 - Console Color\n";
    cin >> a;

    if (a == 1) {
        wstring new_username;
        wcout << L"New username: ";
        wcin >> new_username;

        EditData(L"UserName", new_username);
    } 
    else if (a == 2) {
        wcout << L"RU - Russian\nEN - English\n";
        wcin >> b;

        if (b == L"RU") {
            EditData(L"Language", L"Russian");
            wcout << L"----------------------------------------------------------" << endl;
        } 
        else if (b == L"EN") {
            EditData(L"Language", L"English");
            wcout << L"----------------------------------------------------------" << endl;
        }
    } 
    else if (a == 3) {
        wcout << L"[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
        wcout << L"Type in: ";
        cin >> c;
        wcout << L"Type in: ";
        cin >> d;

        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            string colorCode = "color " + to_string(c) + to_string(d);
            system(colorCode.c_str());
            wcout << L"----------------------------------------------------------" << endl;
        }
    } 
    else if (a == 4) {
        wcout << L"ТЫ ЧТО СМОТРИШЬ?! " << endl;
        wcout << L"----------------------------------------------------------" << endl;
    }
}

// version
void DOSVersion() {
    wcout << L"SpaceDOS " << L"[ " << version << L" ]" << L'\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// Повторялка
void say() {
    wstring say_text;

    if (language == L"Russian") {
        wcout << L"Введите текст, который должен быть сказан: ";
    }
    else {
        wcout << L"Enter text to say: ";
    }

    wcin.ignore();
    getline(wcin, say_text);
    wcout << say_text << '\n';
    wcout << L"----------------------------------------------------------" << endl;
}

// Шуточное удаления пользователя из реал лайф
void FUNdelete() {
    wstring d_user;
    wstring text;

    if (language == L"Russian") {
        wcout << L"Напишите username пользователя, которого вы хотите удалить: ";
    }
    else {
        wcout << L"Write the username of the user you want to delete: ";
    }

    cin.ignore();
    wcin >> d_user;

    if (language == L"Russian") {
        wcout << L"Напишите причину удаления пользователя: ";
    }
    else {
        wcout << L"The reason you want to delete the user?: ";
    }

    wcin >> text;

    if (language == L"Russian") {
        wcout << L"Начинаем процесс удаления юзера \"" << d_user << L"\"..." << L'\n';
    }
    else {
        wcout << L"Begin the process of deleting the user \"" << d_user << L"\"..." << L'\n';
    }

    Sleep(2000);

    if (language == L"Russian") {
        wcout << L"Пользователь был успешно удалён по причине: \"" << text << L"\"" << L'\n';
    }
    else {
        wcout << L"The user was successfully deleted for a reason: \"" << text << L"\"" << L'\n';
    }
    wcout << L"----------------------------------------------------------" << endl;
}

// Не работает лого :(
void logo() {
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣤⣤⣤" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡿⢿⣿⣿" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣟⢛⠛⢛⣉⣤⣉⡀⢸⣿⣿" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⡿⠋⠁⠀⠈⢷⣄⠈⢿⣿⣿⡇⣼⣿⡿" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠙⢷⣤⡈⠻⢧⣿⣿⠇" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⡀⢀⡀⠀⠀⠀⠀⠙⢿⣇⣼⣿⡟⠀" << '\n';
    wcout << L"⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣶⣶⣶⣿⣿⠿⠁⠀⠀⢀⠂⠀⠀⠀⠪⢂⠀⠀⠀⠀⠀⣸⣿⣿⠁⠀" << '\n';
    wcout << L"⠀⠀⠀⣠⣾⣿⡿⠋⠉⠭⠭⠭⢭⠟⠃⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⣰⣿⡿⠁⠀⠀" << '\n';
    wcout << L"⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠣⠄⠀⠀⠀⠀⠀⠀⢠⣾⣿⡿⠁⠀⠀⠀" << '\n';
    wcout << L"⠀⠙⢿⣿⣷⣄⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠏⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⠀⠙⢿⣿⣷⣞⠁⠀⠀⠀⠀⠀⠀⣠⣾⠏⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⠀⠀⣼⣿⡿⠘⠳⣄⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⠀⢠⣿⣿⠃⠀⠀⠈⠳⣤⣾⠟⠁⠀⠀⠀⠀⠀⢀⠔⢹⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⠀⣠⣿⣿⠟⢦⡀⠀⠀⠀⠘⠳⣄⠀⠀⠀⠀⢀⠔⠁⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⢰⣿⣿⠁⢰⠃⠙⢦⡀⠀⠀⠀⠘⠷⡀⢀⡔⠁⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠀⣿⣿⡇⠀⡇⠀⠀⡀⠙⢦⢀⣀⣠⣴⣾⣧⡁⠀⠀⠀⢠⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⢰⣿⣿⠀⠘⠁⠒⠈⣀⣴⣾⣿⣿⠿⠿⠿⣿⣿⣧⣀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⢸⣿⣿⣤⣤⣵⣶⣿⣿⡿⠟⠉⠀⠀⠀⠀⠈⠻⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"⠘⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << '\n';
    wcout << L"----------------------------------------------------------" << endl;
}