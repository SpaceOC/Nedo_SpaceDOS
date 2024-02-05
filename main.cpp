// Даже не спрашивайте почему тут так много библиотек (или как там их называть)....
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <locale>
#endif

#include <chrono>
#include <thread>
#include <fstream>
#include <locale>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>

#ifdef _WIN32
    #include <shellapi.h> // ..............
#else
    #include <cstdlib>
#endif

//#include "Other/Notepad.h"
#include "RSP.h"
#include "commands.h"
#include "data.h"
#include "time.h"
#include "counters.h"
#include "other.h"
#include "json.h"

// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!

using namespace std;

extern string version;
extern string DefaultLanguage;
extern string DefaultUserName;
extern string language;
extern string username;
extern string Debug_Mode;

// DOS
void DOS() {
    vector<string> allowedCommands = { // Доступные команды
        "help", "help ", "logo", "calculator", "version", "exit", 
        "hi", "RSP", "settings", 
        "counter", "work_time", "clear", "source code", "time"
    };

    printMessage(true, {"Welcome to SpaceDOS!", "Добро пожаловать в SpaceDOS!"});
    cout << "Version SpaceDOS - [ " << version << " ]" << '\n';

    LogMessage("DONE", {"SpaceDOS [Not Real DOS] successfully launched", "SpaceDOS [Not Real DOS] успешно запущен"}, 000);

    PrintTimeMonth();
    CurrentTime();

    while (true){
        printMessage(false, {"Enter command: ", "Введите команду: "});

        string command_input;
        cin >> ws;

        getline(cin, command_input);

        if (command_input == "clear") {
            system("cls");
        }

        if (command_input == "work_time") {
            calculateWorkTime();
        }

        if (command_input == "time") {
            CurrentTime();
        }

        if (command_input == "exit"){
            LogMessage("DONE", {"Exiting SpaceDOS [Not Real DOS]", "Выход из SpaceDOS [Not Real DOS]"}, 000);
            system("color 07");
            break;
        }

        if (command_input == "source code") {
            system("start https://github.com/SpaceOC/SpaceDOS-Not-real-DOS-");
            LogMessage("DONE", {"The \"source code\" command was successfully activated.", "Команда \"source code\" была приведена в действие успешно"}, 000);
        }

        if (command_input == "hi"){
            hi();
        }

        if (command_input == "version"){
            DOSVersion();
        }

        if (command_input == "counter"){
            counter();
        }

        if (command_input.substr(0, 5) == "help "){
            string CommandLmao = command_input.substr(5);
            help(CommandLmao);
        }

        if (command_input == "help") {
            string EmptyCommandMoment = "";
            help(EmptyCommandMoment);
        }

        if (find(allowedCommands.begin(), allowedCommands.end(), command_input) == allowedCommands.end()) {
            cout << "Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
            cout << "----------------------------------------------------------" << endl;
        }

        if (command_input == "calculator") {
        }

        if (command_input == "RSP") {
            RSP();
        }

        if (command_input == "logo"){
            logo();
        }

        if (command_input == "settings") {
            settings();
        }
    }
}


int main(){
    CreateFolders();
    CreateLogFile();
    CreateDataFile();
    ReadDataFile();

    CheckAddons();

    #ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
        LogMessage("DONE", {"Operating System - Windows | Use windows.h to customize the command line", "Операционная система - Windows | Используется windows.h для настройки командной строки"}, 000);
    #else
        locale::global(locale("en_US.UTF-8"));
        cout.imbue(locale());
        cin.imbue(locale());
        LogMessage("DONE", {"Operating system is not Windows | Use locale for command line customization", "Операционная система - не Windows | Используется locale для настройки командной строки"}, 000);
    #endif
    
    this_thread::sleep_for(std::chrono::seconds(1));

    DOS();
}