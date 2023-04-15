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
    cout << "������� ��� ��������:" << endl;
    cin >> lol;
    fs::create_directory(lol);
}
void print(fs::path path)
{

    cout << "������� � ���������� ������, ������� �� ������ �������:" << endl;
    cout << "������� ������:" << endl;
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
    cout << "������� ����� ������ ��� ���������, ������� �� ������ �������:" << endl;
    cin >> lol;
    cout << "Enter way:" << endl;
    cin >> path;
    std::uintmax_t n = fs::remove_all(path / lol);
    std::cout << "������� " << n << " ����� ��� ��������\n";
}
void reName(fs::path path)
{
    cout << "������� ������:" << endl;
    cin >> path;
    cout << "������� ��� ����� ����� �������, ��� �� ������ ��������:" << endl;
    string lol;
    cin >> lol;
    cout << "������� ����� ��� �����" << endl;
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
    cout << "������� ��� �����, �� �������� �� ������ �����������" << endl;
    cin >> lol;
    string lol3;
    cout << "������� ����� ���" << endl;
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
        cout << "1. ������� ������������ �������" << endl;
        cout << "2. �������� ���������� �������� � �����" << endl;
        cout << "3. �������� ���� " << endl;
        cout << "4. ������������� " << endl;
        cout << "5. ����� " << endl;
        cout << "6. �������_������� " << endl;
        cout << "7. ���������� " << endl;
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


        cout << "�� ������ ������� ������?\t1.��\t2.���" << endl;

        cin >> s;
        cin.ignore();

    } while (s == 1);
    return 0;


}