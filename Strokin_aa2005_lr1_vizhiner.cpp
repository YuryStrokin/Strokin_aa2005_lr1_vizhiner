
#include <iostream>
#include <locale.h>

#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#pragma execution_character_set("ASCII") //менияем кодировку файла на аски

using namespace std;

void encoder(string key, string filename) {
    filename += ".txt";
    fstream fin(filename);
    ofstream fout("out.txt");
    //открыли оба файла для ввода/вывода информации
    char symbol;
    //проверка на существование файла
    if (fin.is_open()) {
        int lenth_of_kw = key.length();//получаем длину кодового слова для кодирования по кодам символа
        while (true) {
            for (int i = 0; i < lenth_of_kw; i++)
            {
                symbol = fin.get();
                if (fin.eof())break;
                fout << char((symbol + key[i]));
            }
            if (fin.eof()) { fin.close(); fout.close(); break; } //проверка дошел ли цикл до конца файла
        }
    }
    else cout << "cant find input file" << endl;
}

int main()
{
    
    string key = "";
    cout << "Inter the keyword: ";
    cin >> key;
    string inputfile;
    cout << "inter the filename to encrytp: ";
    cin >> inputfile;
    encoder(key, inputfile);
    return 0;
}
