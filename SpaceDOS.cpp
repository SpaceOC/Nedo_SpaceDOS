#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!
// By SpaceOC!!!!!!!!!



// Запасайтесь таблетками от кринжа и г###окодинга! Мы погружаемся в самый ужас!

using namespace std;

wstring version = L"0.7 Alpha";
wstring DefaultLanguage = L"English";
wstring DefaultUserName = L"defaultuser0";
wstring language;
wstring username;

void printMessage(const wstring& messageEn, const wstring& messageRu) {
    if (language == L"Russian") {
        wcout << messageRu << L'\n';
    }
    else {
        wcout << messageEn << L'\n';
    }
}

void CreateData() {
    wifstream file("data.data");
    if (!file) {
        wofstream data("data.data");
        if (data) {
            data << L"Language: " << DefaultLanguage << L'\n';
            data << L"UserName: " << DefaultUserName << L'\n';
            data.close();
        }
        else {
            wcout << L"Error opening the data file." << L'\n';
        }
    }
    else {
        file.close();
    }
}

void ReadData() {
    wifstream data("data.data");
    if (data) {
        wstring line;
        bool foundLanguage = false;
        bool foundUsername = false;
        while (getline(data, line)) {
            if (!foundLanguage && line.find(L"Language: ") != wstring::npos) {
                language = line.substr(10);
                wcout << language << L'\n';
                foundLanguage = true;
            }
            if (!foundUsername && line.find(L"UserName: ") != wstring::npos) {
                username = line.substr(10);
                wcout << username << L'\n';
                foundUsername = true;
            }
            if (foundLanguage && foundUsername) {
                break;
            }
        }
        data.close();
    }
    else {
        wcout << L"Error opening the data file." << std::endl;
    }
}

void EditData(const wstring& field, const wstring& value) {
    wifstream inputFile("data.data");
    wofstream tempFile("temp.data");
    if (inputFile && tempFile) {
        wstring line;
        bool fieldFound = false;
        while (getline(inputFile, line)) {
            if (line.find(field) != wstring::npos) {
                tempFile << field << L": " << value << L'\n';
                fieldFound = true;
            }
            else {
                tempFile << line << L'\n';
            }
        }
        inputFile.close();
        tempFile.close();
        remove("data.data");
        rename("temp.data", "data.data");
        
        if (!fieldFound) {
            wcout << L"Field not found." << L'\n';
        }
    }
    else {
        wcout << L"Error opening the data file." << L'\n';
    }
}

void fakeLoading() {
    char symbols[] = {'|', '/', '-', '\\'};
    int index = 0;

    for (int i = 0; i < 3; i++) {
        wcout << L"Loading " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 3; i < 6; i++) {
        wcout << L"Loading kernel " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 6; i < 8; i++) {
        wcout << L"Loading commands " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }
    for (int i = 8; i < 10; i++) {
        wcout << L"Launching SpaceDOS " << symbols[index];
        wcout.flush();
        index = (index + 1) % 4;
        Sleep(1000);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    }

    bool errorCondition = false;
    if (errorCondition) {
        wcout << L"SpaceDOS launched with serious errors. Apologies for the inconvenience. Here is the error:" << L'\n';
        wcout << L"error" << L'\n';
    }
    else {
        wcout << L"SpaceDOS launched successfully!" << L'\n';
    }
}

int main(){
    CreateData();
    ReadData();
    setlocale(LC_ALL, "");

    fakeLoading();

    Sleep(2000);

    printMessage(L"Welcome to SpaceDOS!", L"Добро пожаловать в SpaceDOS!");
    wcout << L"Version SpaceDOS - [ " << version << L" ]" << L'\n';

    while (true){
        wstring command_input;
        

        if(language == L"Russian"){
            wcout << L"Введите команду: ";
        }
        else{
            wcout << L"Enter command: ";
        }
        wcin >> command_input;

        if(command_input == L"delete"){
            wstring d_user;
            wstring text;

            if (language == L"Russian") {
                wcout << L"Напишите username пользователя, которого вы хотите удалить: ";
            }
            else {
                cout << L"Write the username of the user you want to delete: ";
            }

            cin.ignore(); // Игнорируем символ новой строки оставшийся после предыдущего ввода
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
        }

        if(command_input == L"exit"){
            break;
        }

        if(command_input == L"hi"){
            wcout << L"Hi!" << '\n';
        }

        if(command_input == L"say"){
            wstring say_text;

            if (language == L"Russian") {
                wcout << L"Введите текст, который должен быть сказан: ";
            }
            else {
                wcout << L"Enter text to say: ";
            }

            wcin.ignore(); // Игнорируем символ новой строки оставшийся после предыдущего ввода
            getline(wcin, say_text);
            wcout << say_text << '\n';
        }

        if(command_input == L"version"){
            wcout << L"SpaceDOS " << L"[ " << version << L" ]" << L'\n';
        }

        if(command_input == L"help"){
            wcout << L"help - displays a list of all commands" << L'\n' << L"version - shows the version of this \"game\"" << L'\n' << L"delete - removes user from Real Life (DANGER!)" << L'\n' << L"hi - Hi!" << L'\n' << L"calculator - Calculator" << L'\n' << L"RSP - Rock, Scissors, Paper!" << L'\n';
        }

        if(command_input != L"help" && command_input != L"logo" && command_input != L"calculator" && command_input != L"version" && command_input != L"exit" && command_input != L"delete" && command_input != L"hi" && command_input != L"say" && command_input != L"RSP" && command_input != L"settings"){
            wcout << L"Unknown command! Write \"help\" to find out what commands exist in SpaceDOS" << '\n';
        }

        if (command_input == L"calculator") {
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
                            return 0;
                    }
                    break;
                default:
                    wcout << L"Error: Invalid operator!" << L'\n';
                    return 0;
                }

            wcout << L"Done! The result is: " << result << L'\n';
        }

        if(command_input == L"RSP"){ // Rock, Scissors, Paper // Да.. Я не знаю как по другому написать. У меня не работает просто, если напишу Rock, Scissors, Paper вместо "RSP"
            srand(time(0));

            int a;
            wcout << L"Enter a number between one and three. 1 - Rock, 2 - Scissors, 3 - Paper: ";
            cin >> a;

            int v = rand() % 3 + 1;

            if (a == v) {
                wcout << "Tie!" << endl;
            }
            else if (a == 1 && v == 2) {
                wcout << "The rock breaks the scissors! The computer lost." << endl;
            }
            else if (a == 2 && v == 3) {
                wcout << "The scissors cut the paper. The computer lost!" << endl;
            }
            else if (a == 2 && v == 1) {
                wcout << "The rock breaks the scissors! Player lost." << endl;
            }
            else if (a == 3 && v == 2) {
                wcout << "The scissors cut the paper. The player has lost!" << endl;
            }
            else if (a == 1 && v == 3) {
                wcout << "Paper covers stone... The player has lost!" << endl;
            }
            else if (a == 3 && v == 1) {
                wcout << "Player wins! Paper covers rock" << endl;
            }
        }

        if (command_input == L"logo"){ // Не работает :(
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
        }

        if (command_input == L"settings") {
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
                } 
                else if (b == L"EN") {
                    EditData(L"Language", L"English");
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
                }
            } 
            else if (a == 4) {
                wcout << L"ТЫ ЧТО СМОТРИШЬ?! " << std::endl;
            }
        }

    }

    return 0;
}
