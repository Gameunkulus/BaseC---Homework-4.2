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

    string getCity() {
        return city;
    }

    void setCity(string aCity) {
        city = aCity;
    }

    string getStreet() {
        return street;
    }

    void setStreet(string aStreet) {
        street = aStreet;
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
        string text = getCity() + " " + getStreet() + " " + getDom() + " " + getRoom();
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
        Adress adr;
        string city;
        in >> city;
        adr.setCity(city);
        string street;
        in >> street;
        adr.setStreet(street);
        int dom;
        in >> dom;
        adr.setDom(dom);
        int room;
        in >> room;
        adr.setRoom(room);
        arr[i] = adr;

    }

    in.close();
    ofstream out("C:/Users/bugr2/source/repos/Homework-4.2/Homework-4.2/folder/out.txt");

    for (int i = num - 1; num >= 0; num--) {
        Adress fullAdress = arr[i];
        out << fullAdress.printAdress() << endl;
    }
    
    delete arr;
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
