// Не получилось совершить задуманное... Опять все команды (help, version и т.д) в одном файле будут... 💀👍
#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>
#include "data.h"
#include "other.h"

using namespace std;

extern string language;
extern string version;

string description;

// команда help - показывает все команды
void help() {
    cout << "exit - выйти из SpaceDOS" << endl << 
        "help - displays a list of all commands" << endl << 
        "settings - настройки" << endl << 
        "version - shows the version of this \"game\"" << endl << 
        "hi - Hi!" << endl << 
        "RSP - Rock, Scissors, Paper!" << endl << 
        "time - Work Time" << endl << 
        "counter - ..." << endl << 
        "clear - Очистить командную строку" << endl << 
        "say - say" << endl;
    /*
    * А ЧТО ТАК МОЖНО БЫЛО?
    */
    cout << "----------------------------------------------------------" << endl;
}

// Настройки
void settings() {
    int a;
    string b;
    int c;
    int d;

    cout << "What do you want to customize?\n1 - Profile\n2 - Language\n3 - Console Color\n";
    cout << "Enter: ";
    cin >> a;

    if (a == 1) {
        cout << "New username: ";
        string new_username;
        cin >> ws;

        getline(cin, new_username);

        EditData("UserName", new_username);
        ReadData();
    } 
    else if (a == 2) {
        cout << "RU - Russian\nEN - English\n";
        cout << "Enter: ";
        cin >> b;

        if (b == "RU") {
            EditData("Language", "Russian");
            cout << "----------------------------------------------------------" << endl;
        } 
        else if (b == "EN") {
            EditData("Language", "English");
            cout << "----------------------------------------------------------" << endl;
        }
        ReadData();
    } 
    else if (a == 3) {
        cout << "[0 - 9] - Console Color\n[0 - 9] - Text Color\n";
        cout << "Type in (Console Color): ";
        cin >> c;
        cout << "Type in (Text Color): ";
        cin >> d;

        if (c >= 0 && c <= 9 && d >= 0 && d <= 9) {
            string colorCode = "color " + to_string(c) + to_string(d);
            string colormoment(to_string(c) + to_string(d));
            system(colorCode.c_str());
            EditData("ColorsConsole", colormoment);
            cout << "----------------------------------------------------------" << endl;
        }
    } 
    else if (a == 4) {
        cout << "ТЫ ЧТО СМОТРИШЬ?! " << endl;
        cout << "----------------------------------------------------------" << endl;
    }
}

// HI! Hello! Привет!!!
void hi() {
    cout << "Hi!" << '\n';
    cout << "----------------------------------------------------------" << endl;
}

// version
void DOSVersion() {
    cout << "SpaceDOS " << "[ " << version << " ]" << '\n';
    cout << "----------------------------------------------------------" << endl;
}

// Лого НЕ РАБОТАЕТ! :(
void logo() {
    std::vector<std::string> vs
    {
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣠⣤⣤⣤)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣶⣿⣿⣿⣿⣿⡿⢿⣿⣿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣾⣿⣿⣟⢛⠛⢛⣉⣤⣉⡀⢸⣿⣿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⡿⠋⠁⠀⠈⢷⣄⠈⢿⣿⣿⡇⣼⣿⡿)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠉⠀⠀⠀⠀⠀⠀⠙⢷⣤⡈⠻⢧⣿⣿⠇)",
        R"(⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⡀⢀⡀⠀⠀⠀⠀⠙⢿⣇⣼⣿⡟⠀)",
        R"(⠀⠀⠀⠀⠀⣠⣶⣶⣶⣶⣶⣶⣶⣿⣿⠿⠁⠀⠀⢀⠂⠀⠀⠀⠪⢂⠀⠀⠀⠀⠀⣸⣿⣿⠁⠀)",
        R"(⠀⠀⠀⣠⣾⣿⡿⠋⠉⠭⠭⠭⢭⠟⠃⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠸⠀⠀⠀⠀⣰⣿⡿⠁⠀⠀)",
        R"(⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠣⠄⠀⠀⠀⠀⠀⠀⢠⣾⣿⡿⠁⠀⠀⠀)",
        R"(⠀⠙⢿⣿⣷⣄⠀⠀⢀⠔⠁⠀⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⠏⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⠙⢿⣿⣷⣞⠁⠀⠀⠀⠀⠀⠀⣠⣾⠏⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⠀⣼⣿⡿⠘⠳⣄⠀⠀⠀⣠⣾⠟⠁⠀⠀⠀⠀⠀⢀⣴⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⠀⢠⣿⣿⠃⠀⠀⠈⠳⣤⣾⠟⠁⠀⠀⠀⠀⠀⢀⠔⢹⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⠀⣠⣿⣿⠟⢦⡀⠀⠀⠀⠘⠳⣄⠀⠀⠀⠀⢀⠔⠁⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⢰⣿⣿⠁⢰⠃⠙⢦⡀⠀⠀⠀⠘⠷⡀⢀⡔⠁⠀⠀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠀⣿⣿⡇⠀⡇⠀⠀⡀⠙⢦⢀⣀⣠⣴⣾⣧⡁⠀⠀⠀⢠⣾⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⢰⣿⣿⠀⠘⠁⠒⠈⣀⣴⣾⣿⣿⠿⠿⠿⣿⣿⣧⣀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⢸⣿⣿⣤⣤⣵⣶⣿⣿⡿⠟⠉⠀⠀⠀⠀⠈⠻⣿⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)",
        R"(⠘⠿⠿⠿⠿⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀)"
    };
    for (auto s : vs)
        std::cout << s << "\n";
    cout << "----------------------------------------------------------" << endl;
}