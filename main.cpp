#include <iostream>
#include <cmath>
#include "Functions.hpp"
using namespace std;
int main() {
    int size = 0;
    int pos = 0;
    int tmp = 0;
    cout << "Въведете число: " << endl;
    cin >> size;
    int *set = NULL;
    set = new int[size];
    int num1, num2;

    cout << "Задача 1." << endl;
    remainderRing(set, size);



    {
    cout << "Задача 2. Събиране" << endl;
    cout << "Моля въведете 2 числа от остатъчния пръстен, които желаете да съберете" << endl;
    cin >> num1 >> num2;
    sum(set, size, num1, num2);
    cout << endl;
    }
    {
    cout << "Задача 3. Изваждане" << endl;
    cout << "Моля въведете 2 числа от остатъчния пръстен, които желаете да извадите" << endl;
    cin >> num1 >> num2;
    sub(set, size, num1, num2);
    cout << endl;
    }
    {
    cout << "Задача 4. Умножение" << endl;
    cout << "Моля въведете 2 числа от остатъчния пръстен, които желаете да умножите" << endl;
    cin >> num1 >> num2;
    mul(set, size, num1, num2);
    cout << endl;
    }


    cout <<endl<< "Задача 5. и Задача 6. - Намира двойките елементи, които при умножение дават 1. Във втората колона са реципрочните елементи."<<endl;
    getReciprocal(size,0, pos);


    cout << endl << "Задача 7. Намиране на реципрочен елемент." << endl;

    do {
        cout << "Моля въведете число, за да се намери реципрочният елемент, ако съществува." << endl;
        cin >> num1;
    } while (!(isInRemainderRing(set, size, num1)));

    getReciprocalUser(num1,size,tmp);



    cout << endl << "Задача 8. Деление" << endl;
    do {
        cout << "Моля въведете числата, които искате да делите." << endl;
        cin >> num1 >> num2;
    } while (!(isInRemainderRing(set, size, num1)) || !(isInRemainderRing(set, size, num2)));
    cout << div(num1, num2, size, tmp)<<endl;


    cout << "Задача 9. Бързо степенуване" << endl;
    int sz1, a1, m, k = 1, cnt = 0;
    cout << "Моля въведете остатъчен пръстен, основа и степен:"<<endl;
    cin >> sz1 >> a1 >> m;
    cout << fastPower(sz1, a1, m, k, cnt) << endl;


    cout << "Задача 11. Проверка дали даден остатъчен пръстен е остатъчно поле." << endl;
    cout << "Дали Z(n) е F(n)?"<<endl;
    findF(size);


    cout << "Задача 12. Проверка дали дадено число е примитивен корен във F(n)." << endl;
    int n, num;
    cout << "Моля въведете n и число: " << endl;
    cin >> n >> num;
    cout << ((primitiveRoot(n, num)) ? "Числото е примитивен корен." : "Числото не е примитивен корен.");
    cout << endl;


    int n2;
    cout << "Задача 13. Всички примитивни корени във F(n)." << endl;
    cout << "Моля въведете n: " << endl;
    cin >> n2;
    findAllPrimitiveRoots(n2);
    cout << endl;

    
    cout << "Задача 14. Изчисляване на дискретен логаритъм." << endl;
    discreteLog(0,0,size);

    delete[] set;
    set = NULL;
    return 0;
}
