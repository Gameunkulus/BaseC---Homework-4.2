// Homework-4.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Adress {

private:
    string city;
    string street;
    int dom;
    int room;

public:

    Adress() {
        this->city = "0";
        this->street = "0";
        this->dom = 0;
        this->room = 0;
    }

    string *getCity() {
        return &this->city;
    }

    void setCity(string aCity) {
        this->city = aCity;
    }

    string getStreet() {
        return this->street;
    }

    void setStreet(string aStreet) {
        this->street = aStreet;
    }

    string getDom() {
        string strDom = to_string(dom);
        return strDom;
    }

    void setDom(int dom) {
        this->dom = dom;
    }

    string getRoom() {
        string strRoom = to_string(room);
        return strRoom;
    }

    void setRoom(int room) {
        this->room = room;
    }

    string printAdress() {
        string text = *getCity() + " " + getStreet() + " " + getDom() + " " + getRoom();
        return text;
    };
};



int main()
{
    setlocale(LC_ALL, "Russian");

    int num;
    ifstream in("C:/Users/bugr2/source/repos/Homework-4.2/Homework-4.2/folder/in.txt");
    in >> num;

    Adress* arr = new Adress[num];

    for (int i = 0; i < num; i++) {
        string city;
        in >> city;
        arr[i].setCity(city);
        string street;
        in >> street;
        arr[i].setStreet(street);
        int dom;
        in >> dom;
        arr[i].setDom(dom);
        int room;
        in >> room;
        arr[i].setRoom(room);
    }

    in.close();
    ofstream out("C:/Users/bugr2/source/repos/Homework-4.2/Homework-4.2/folder/out.txt");

    for (int i = 0; i < num - 1; i++) {
        for (int l = 0; l < num - 1; l++) {
            if (arr[l].getCity()[0] < arr[l + 1].getCity()[0]) {
                Adress temp = arr[l];
                arr[l] = arr[l + 1];
                arr[l + 1] = temp;
            } 
        }
    }

    for (int i = num - 1; i >= 0; i--) {
        cout << arr[i].getCity() << endl;
        out << arr[i].printAdress() << endl;
    }
    delete[] arr;
    out.close();

}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
