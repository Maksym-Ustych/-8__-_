#include <iostream>
using namespace std;

class Vect
{
public:
    Vect(int n) : size(n), p(nullptr)
    {
        try
        {
            if (size <= 0 || size > 256)
                throw "Невірний розмір масиву!";

            p = new int[size];

            for (int i = 0; i < size; ++i)
                p[i] = 0;
        }
        catch (...)
        {
            cout << "Помилка у конструкторі Vect" << endl;
            throw;
        }
    }

    ~Vect()
    {
        try
        {
            delete[] p;
        }
        catch (...)
        {
            cout << "Помилка у деструкторі Vect" << endl;
        }
    }

    int& operator[](int i)
    {
        if (i < 0 || i >= size)
            throw "Індекс поза межами масиву!";
        return p[i];
    }

    void Print()
    {
        for (int i = 0; i < size; ++i)
            cout << p[i] << " ";
        cout << endl;
    }

private:
    int* p;
    int size;
};

int main()
{
    try
    {
        Vect a(3);
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        a.Print();

        Vect a1(200);
        a1[10] = 5;
        a1.Print();
    }
    catch (const char* s)
    {
        cout << "Помилка: " << s << endl;
    }
    catch (...)
    {
        cout << "Невідома помилка!" << endl;
    }

    return 0;
}