#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
using namespace std;

struct user
{
    int id;
    char name[255];
};

int main()
{
    user a;
    a.id = 1;
    strcpy(a.name, "Максим");
    user b;
    b.id = 2;
    strcpy(b.name, "Алекс");
    ofstream fo;
    ifstream fi;
    fo.open("output.dat", ios::ate);
    fo.write((char*)&a, sizeof(a));
    fo.write((char*)&b, sizeof(b));
    fo.close();
    user c;
    fi.open("output.dat", ios::in);
    while (fi.read((char*)&c, sizeof(c)))
        cout << c.id << " " << c.name << endl;
    fi.close();
    return 0;
}