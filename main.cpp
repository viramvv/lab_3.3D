#include <iostream>
#include "RealPublic.h"
#include "RealPrivate.h"

#pragma pack(push, 1)
struct PackedReal {
    double v;
};
#pragma pack(pop)

int main() {
    using namespace std;

    cout << "=== ВІДКРИТЕ УСПАДКУВАННЯ (RealPublic) ===" << endl;
    RealPublic r1(9.0);
    RealPublic r2(2.0);

    cout << "r1: " << r1 << " | r2: " << r2 << endl;
    cout << "Множення (r1 * r2): " << (r1 * r2) << endl;
    cout << "Віднімання (r1 - r2): " << (r1 - r2) << endl;
    cout << "Корінь квадратний з r1: " << r1.Root(2) << endl;
    cout << "Число Pi в степені r2 (Pi^2): " << r2.PowerOfPi() << endl;

    cout << "r1++: " << r1++ << " | Після інкременту: " << r1 << endl;

    cout << "\n=== ЗАКРИТЕ УСПАДКУВАННЯ (RealPrivate) ===" << endl;
    RealPrivate p1(27.0);
    cout << "p1 (кубічний корінь): " << p1.Root(3) << endl;

    RealPrivate p2;
    cout << "Введіть значення для p2: ";
    cin >> p2;
    cout << "++p2: " << ++p2 << endl;

    cout << "\n=== ДЕМОНСТРАЦІЯ МАСИВІВ ===" << endl;
    const int size = 2;
    RealPublic* arr = new RealPublic[size]{ RealPublic(4.0), RealPublic(16.0) };
    cout << "Корінь з першого елемента масиву: " << arr[0].Root(2) << endl;
    delete[] arr;

    cout << "\n=== РОЗМІР ПАМ'ЯТІ ===" << endl;
    cout << "sizeof(RealPublic) без пакування: " << sizeof(RealPublic) << " байт" << endl;
    cout << "sizeof(PackedReal) з #pragma pack(1): " << sizeof(PackedReal) << " байт" << endl;

    return 0;
}