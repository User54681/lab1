#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;

string task1();
int task2();
bool check(char s, string signs);
string sorting(string newstr);
int hosoya(int* n, int* i);
int fibNum(int n);
//int AddTask();
//template <typename T>
//T summ_all(T data, int n);

/*
1 задание часть А:
    1) strlen - string::length
    2) strcpy - аналога нет, пишем a = b
    3) strcmp - compare()
    4) strcat - ___.append() или str1 + str2
    5) someString[index] -  someString.at(index) (getting the character at index)
    6) аналога нет(можно использовать strcat) - push_back
    7) аналога нет - pop_back

    Функции могут не иметь точного аналога в библиотеке другого языка.Почему ? – объясните главную разницу строк в С и С++.

    Строки в C - массив элементов char с null-байтом в окончании
    Строки в C++ - объект класса String с динамической памятью

2 задание часть А:
    1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int
    2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int* ptrArr = new int[N]
    3) free(ptr) - delete ptr
    4) free(ptrArr) - delete[] ptrArr
    В С++ необходимо ли освобождать динамическую память? Да, оператором delete.
    Можно ли освободить одну и ту же выделенную память дважды? Нет, это приводит к недокументированному поведению.
    А можно ли освободить невыделенную память? Нет.
*/

int main()
{
    std::locale loc("ru_RU.utf8");
    task1();
    task2();
    /*AddTask();*/
}


string task1() {
    string str;
    string newstr;
    cout << "enter the string: ";
    cin >> str;

    string signs = "! @ # $ % ^ & * ( ) _ + - = | \ / ? . , : ; ' ";
    for (int i = 0; i < str.length(); ++i) {
        if (!check(str[i], signs)) newstr += str[i];
    }
    
    cout << sorting(newstr) << "\n";
    return sorting(newstr);
}

bool check(char s, string signs) {
    for (int i = 0; i < signs.length(); ++i) if (s == signs[i]) return true;
    return false;
}

string sorting(string newstr) {
    string newstr2 = newstr;
    for (int i = 0; i < newstr2.length(); ++i) {
        for (int j = 0; j < newstr2.length() - i - 1; ++j) {
            if (newstr2[j] < newstr2[j + 1]) continue;
            char box = newstr2[j];
            newstr2[j] = newstr2[j + 1];
            newstr2[j + 1] = box;
        }
    }

    return newstr2;
}

int task2() {
    int* num = new int;
    int* i = new int;
    int* j = new int;
    int* k = new int;

    cout << "Enter the number of lines: ";
    cin >> *num;
    cout << '\n';
    
    for (*i = 0; *i <= *num-1; ++ * i) {
        for (*j = 0; *j < *num - *i; ++ * j) {
            cout << " ";
        }
        for (*k = 0; *k <= *i; ++ * k) {
            cout << hosoya(i, k) << " ";
        }
        cout << "\n";
    }
    delete num, i, j, k;
    return 0;
}

int hosoya(int* j, int* i) {
    return fibNum(*i + 1) * fibNum(*j - *i + 1);
}

int fibNum(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibNum(n - 1) + fibNum(n - 2);
}


//int AddTask() {
//    setlocale(LC_ALL, "rus");
//    int n;
//    cout << "Введите кол-во суммирующихся символы: ";
//    cin >> n;
//    cout << "Введите строку: ";
//
//    std::vector<string> data(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> data[i];
//    }
//
//    summ_all(data, n);
//    return 0;
//}
//
//template <typename T>
//T summ_all(T data[], int n) {
//    T s = data[0];
//    for (int i = 0; i < n; ++i) s += data[i];
//    cout << s;
//    return s;
//}