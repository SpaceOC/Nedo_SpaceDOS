// Не получилось совершить задуманное... Опять все команды (help, version и т.д) в одном файле будут... 💀👍
#include <iostream>
#include <chrono>
#include <thread>
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
void help(string commandMoment) {
    vector<string> CommandsTextHelp_RU = { // Команды и их описание на русском
        " exit \t Выйти из SpaceDOS",
        " help \t Показывает все доступные команды",
        " settings \t Настройки",
        " version \t Показывает версию этой \"игры\"",
        " hi \t Привет!", 
        " RSP \t Сыграй в \"Камень, Ножницы, Бумага\"!",
        " time \t Показывает сколько времени работает SpaceDOS [Not Real DOS]",
        " counter \t Описание отсутствует", 
        " clear \t Очистить командную строку"
    };

    vector<string> CommandsTextHelp_EN = { // Команды и их описание на английском
        " exit \t Exit SpaceDOS",
        " help \t Shows all available commands",
        " settings \t SpaceDOS settings",
        " version \t Shows the version of this \"game\"",
        " hi \t Hi!", 
        " RSP \t Play \"Rock, Paper, Scissors\"!",
        " time \t Shows how long SpaceDOS has been running",
        " counter \t No description", 
        " clear \t Clear the command line"
    };
    if (commandMoment.empty() and language == "Russian") {
        for (const auto& command : CommandsTextHelp_RU) {
            cout << command << endl;
        }
        LogMessage("DONE", {"", "Команда \"help\" вывела весь список команд (на русском языке) успешно"}, 000);
    }
    else if (commandMoment.empty() and language == "English") {
        for (const auto& command : CommandsTextHelp_EN) {
            cout << command << endl;
        }
        LogMessage("DONE", {"", "Команда \"help\" вывела весь список команд (на английском языке) успешно"}, 000);
    }
    else {
        if (language == "Russian") {
            for (const auto& command : CommandsTextHelp_RU) {
                if (command.find(commandMoment)!= string::npos) {
                    cout << command << endl;
                    LogMessage("DONE", {"", "Команда \"help\" вывела \"" + command + "\" (на русском языке) успешно"}, 000);
                }
            }
        }
        else {
            for (const auto& command : CommandsTextHelp_EN) {
                if (command.find(commandMoment)!= string::npos) {
                    cout << command << endl;
                    LogMessage("DONE", {"", "Команда \"help\" вывела \"" + command + "\" (на английском языке) успешно"}, 000);
                }
            }
        }
    }
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"", "Работа команды \"help\" завершена успешно"}, 000);
}

// Настройки
void settings() {
    int a;
    string b;
    int c;
    int d;

    cout << "What do you want to customize? \n\t1 - Profile\n\t2 - Language\n\t3 - Console Color\n\t4 - Debug Mode\n";
    cout << "Enter: ";
    cin >> a;

    if (a == 1) {
        cout << "New username: ";
        string new_username;
        cin >> new_username;

        /*getline(cin, new_username);*/

        EditData("UserName", new_username);
        ReadDataFile();
    } 
    else if (a == 2) {
        cout << "RU - Russian\nEN - English\n";
        cout << "Enter: ";
        cin >> b;

        if (b == "RU") {
            EditData("Language", "Russian");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"", "Язык сменён на русский"}, 000);
        } 
        else if (b == "EN") {
            EditData("Language", "English");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"", "Язык сменён на английский"}, 000);
        }
        ReadDataFile();
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
            LogMessage("DONE", {"", "Цвет командой строки изменён. Вот код: " + colormoment}, 000);
        }
    } 
    else if (a == 4) {
        cout << "True/ON | False/OFF" << endl;
        cout << "Enter: ";
        cin >> b;

        if (b == "True" || b == "ON") {
            EditData("Debug Mode", "true");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"", "Debug Mode включен"}, 000);
        } 
        else if (b == "False" || b == "OFF") {
            EditData("Debug Mode", "false");
            cout << "----------------------------------------------------------" << endl;
            LogMessage("DONE", {"", "Debug Mode выключен"}, 000);
        }
        ReadDataFile();
        cout << "----------------------------------------------------------" << endl;
    }
}

// HI! Hello! Привет!!!
void hi() {
    cout << "Hi!" << '\n';
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"", "Успешно было отправлено сообщение \"Hi!\" с помощью команды \"hi\""}, 000);
}

// version
void DOSVersion() {
    cout << "SpaceDOS " << "[ " << version << " ]" << '\n';
    cout << "----------------------------------------------------------" << endl;
    LogMessage("DONE", {"", "Успешно было отправлено сообщение о версии SpaceDOS с помощью команды \"version\""}, 000);
}

// Лого
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
    LogMessage("DONE", {"", "Логотип SpaceDOS успешно отправлен"}, 000);
}