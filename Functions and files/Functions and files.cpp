#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct scan_info {
    char model[25];
    int price;
    double x_size;
    double y_size;
    int optr;
    int grey;
};

//1 - проверка на открытость файла
//3 - функция вводящая данные о сканере с клавиатуры в структуру

void ProofOpen() {
    setlocale(LC_ALL, "rus");
    ifstream file;
    file.open("C:\\Users\\Rush\\Desktop\\Text.txt");
    if (file.is_open()) //Проверка файла
        cout << "Файл открыт!" << endl;
    else
    {
        cout << "Файл не открыт!" << endl;
    }
    file.close();
}

void ReadFile() {
    setlocale(LC_ALL, "rus");
    cout << endl << "ReadFile: " << endl << endl;
    ifstream file;
    string str;
    file.open("C:\\Users\\Rush\\Desktop\\Text.txt");
    while (!file.eof())
    {
        getline(file, str); 
        cout << str << endl; 
    }
    file.close();
}

void WriteInFile(int a) {
    setlocale(LC_ALL, "rus");
    struct scan_info scan;
    ofstream file("C:\\Users\\Rush\\Desktop\\Text.txt");
    file << " Количество " << a;
    file << " " << "\n";
    for (int i = 1; i <= a; i++)
    {
        file << " " << "\n";
        cout << "Сканер #" << i;
        cout << endl << "Введите модель: \n";
        cin >> scan.model; file << " " << scan.model;
        cout << endl << "Введите цену: \n";
        cin >> scan.price; file << " " << scan.price;
        cout << endl << "Введите горизонтальный размер: \n";
        cin >> scan.x_size; file << " " << scan.x_size;
        cout << endl << "Введите вертикальный размер: \n";
        cin >> scan.y_size; file << " " << scan.y_size;
        cout << endl << "Введите оптическое разрешение: \n";
        cin >> scan.optr; file << " " << scan.optr;
        cout << endl << "Введите градацию: \n";
        cin >> scan.grey; file << " " << scan.grey;
        cout << endl;
    }
    file.close();
}

int main()
{
    ProofOpen();
    int n;
    cout << endl << "Сколько записей будет? "; cin >> n; cout << endl;
    //1 - proof
    //2 - 6 write (записей)
    //3 - write count object
    //4 - замена местами строки (swap)
    //5 - read file
    WriteInFile(n);
    ReadFile();
}
