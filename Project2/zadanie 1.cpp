#include <iostream>
#include <fstream>
#include <filesystem>
#include <cassert>
#include <string>
#include <windows.h>


namespace fs = std::filesystem;
using std::filesystem::directory_iterator;
using namespace std;
void create_directory(fs::path path)
{
    setlocale(LC_ALL, "Russian");
    string lol;
    cout << "Введите имя каталога:" << endl;
    cin >> lol;
    fs::create_directory(lol);
}
void print(fs::path path)
{

    cout << "Каталог и содержимое файлов, которые вы хотите увидеть:" << endl;
    cout << "Введите способ:" << endl;
    cin >> path;
    auto current = fs::current_path();
    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {

            cout << entry.path().filename() << " DIR  " << endl;
        }
        if (entry.is_regular_file()) {
            cout << entry.path().filename() << " FILE " << endl;
        }
    }
}
void r1emove(fs::path path) {
    string lol;
    cout << "Введите имена файлов или каталогов, которые вы хотите удалить:" << endl;
    cin >> lol;
    cout << "Enter way:" << endl;
    cin >> path;
    std::uintmax_t n = fs::remove_all(path / lol);
    std::cout << "Удалено " << n << " файлы или каталоги\n";
}
void reName(fs::path path)
{
    cout << "Введите способ:" << endl;
    cin >> path;
    cout << "Введите имя файла таким образом, что вы хотите изменить:" << endl;
    string lol;
    cin >> lol;
    cout << "Введите новое имя файла" << endl;
    string lol2;
    cin >> lol2;
    fs::rename(path / lol, path / lol2);
}
void showFile(fs::path source)
{
    cin >> source;
    cout << source;
    ifstream file(source);
    cout << (file.is_open() ? "Y" : "N") << endl;
    string buffer;
    while (getline(file, buffer))
    {
        cout << buffer;
    }
    file.close();
}
void copy()
{

    string lol;
    cout << "Введите имя файла, из которого вы хотите скопировать" << endl;
    cin >> lol;
    string lol3;
    cout << "Введите новое имя" << endl;
    cin >> lol3;
    fs::copy(lol, lol3);
}
void search(fs::path path, string parametr)
{

    for (const auto& entry : fs::directory_iterator(path)) {
        if (entry.is_directory()) {
            cout << entry.path().filename() << " DIR  " << endl;
        }
        if (entry.is_regular_file()) {
            //  
            if (entry.path().extension() == parametr)
            {
                cout << entry.path().filename() << " FILE " << endl;
            }
        }
    }

}

int main()
{
    int s;
    int var;
    do {
        cout << "1. Удалить существующий каталог" << endl;
        cout << "2. Показать содержимое каталога и файла" << endl;
        cout << "3. Показать файл " << endl;
        cout << "4. переименовать " << endl;
        cout << "5. поиск " << endl;
        cout << "6. создать_каталог " << endl;
        cout << "7. копировать " << endl;
        cin >> var;
        cin.ignore();
        system("CLS");
        cout << var;
        switch (var)
        {
        case 1: r1emove("");
            break;
        case 2:   print("");
            break;
        case 3:   showFile("");
            break;
        case 4:   reName("");
            break;
        case 5:   search("E:/Console/Console/4831284", ".zip");
            break;
        case 6:  create_directory("");
            break;
        case 7:  copy();
            break;
        }


        cout << "Вы хотите сделать больше?\t1.да\t2.нет" << endl;

        cin >> s;
        cin.ignore();

    } while (s == 1);
    return 0;


}