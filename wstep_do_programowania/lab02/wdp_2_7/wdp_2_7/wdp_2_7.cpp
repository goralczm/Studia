#include <iostream>

using namespace std;

int main()
{
    float a;
    float b;
    float c;
    cout << "Zadanie nr. 2\n";
    cout << "------";
    cout << "Podaj wspolczynniki wielomianu drugiego stopnia:\na=";
    cin >> a;

    cout << "b=";
    cin >> b;

    cout << "c="; 
    cin >> c;

    float deltaResult = b * b - 4 * a * c;
    double rootDelta = sqrt(deltaResult);
    
    cout << "Wynik delty: " << deltaResult << endl;

    if (deltaResult < 0)
    {
        cout << "Brak rozwiazan tego wielomianu!";
    }
    else if (deltaResult == 0)
    {
        double element = (-b + rootDelta) / (2 * a);

        cout << "Odpowiedzia jest: x1=" << element << endl;
    }
    else {
        double element = (-b + rootDelta) / (2 * a);
        double element2 = (-b - rootDelta) / (2 * a);

        cout << "Odpowiedzia jest: x1=" << element << endl;
        cout << "Odpowiedzia jest: x2=" << element2 << endl;
    }
}