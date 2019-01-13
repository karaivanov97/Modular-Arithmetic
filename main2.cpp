#include <iostream>
#include <cmath>
#include "Functions.hpp"
using namespace std;
int main() {
        setlocale(LC_ALL, "Russian");
    int size = 0;
    char input = ' ';
    int pos = 0;
    unsigned int operation;
    int tmp = 0;
    cout<<"За сигурен достъп въведете името си: ";
    char name[100];
    cin.getline(name,99);
    
    cout<< "Здравейте " << name <<"! Въведете число за остатъчния пръстен: ";
    
  
    cin >> size;
    int *set = NULL;
    set = new int[size];
    int num1, num2;


    cout << "Задача 1. Елементите на остатъчния пръстен са: " << endl;
    remainderRing(set, size);

Label1: cout << "Каква операция ще извършите?" << endl << "1. Събиране" <<endl << "2. Изваждане" <<endl << "3. Умножение" << endl << "4. Намиране на двойките елементи на остатъчния пръстен, които при умножение дават 1 и намиране на реципрочната стойност на всеки един елемент, ако съществува " << endl << "5. Намиране на реципрочен елемент" << endl <<"6. Деление" << endl <<"7. Бързо степенуване" << endl <<"8. Проверка дале даден остатъчен пръстен е остатъчно поле "<<endl <<"9. Проверка дали дадено число е примитивен корен в остатъчно поле"<< endl <<"10. Намиране на всички примитивти корени в остътчното поле"<<endl <<"11. Изчисляване на дискретен логаритъм"<<endl;
    cin >> operation;
    switch (operation){
        case 1:
    
    cout << "Задача 2. Събиране" << endl;
    cout << "Моля въведете 2 числа от остатъчния пръстен, които желаете да съберете" << endl;
    cin >> num1 >> num2;
    sum(set, size, num1, num2);
    cout << endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;
    
        case 2:
    cout << "Задача 3. Изваждане" << endl;
    cout << "Моля въведете 2 числа от остатъчния пръстен, които желаете да извадите" << endl;
    cin >> num1 >> num2;
    sub(set, size, num1, num2);
    cout << endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

    
        case 3:
    cout << "Задача 4. Умножение" << endl;
    cout << "Моля въведете 2 числа от остатъчния пръстен, които желаете да умножите" << endl;
    cin >> num1 >> num2;
    mul(set, size, num1, num2);
    cout << endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        case 4: cout <<endl<< "Задача 5. и Задача 6. - Намира двойките елементи, които при умножение дават 1. Във втората колона са реципрочните елементи."<<endl;
            getReciprocal(size,0, pos);
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        case 5:  cout << endl << "Задача 7. Намиране на реципрочен елемент." << endl;
    do {
        cout << "Моля въведете число, за да се намери реципрочният елемент, ако съществува." << endl;
        cin >> num1;
    } while (!(isInRemainderRing(set, size, num1)));

            getReciprocalUser(num1,size,tmp);
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        case 6:  cout << endl << "Задача 8. Деление" << endl;
    do {
        cout << "Моля въведете числата, които искате да делите." << endl;
        cin >> num1 >> num2;
    } while (!(isInRemainderRing(set, size, num1)) || !(isInRemainderRing(set, size, num2)));
    cout << div(num1, num2, size, tmp)<<endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        

        case 7:  {cout << "Задача 9. Бързо степенуване" << endl;
    int sz1, a1, m, k = 1, cnt = 0;
    cout << "Моля въведете остатъчен пръстен, основа и степен:"<<endl;
    cin >> sz1 >> a1 >> m;
    cout << fastPower(sz1, a1, m, k, cnt) << endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        }
        case 8:{ cout << "Задача 11. Проверка дали даден остатъчен пръстен е остатъчно поле." << endl;
    cout << "Дали Z(n) е F(n)?"<<endl;
            findF(size);
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        }


        case 9: {cout << "Задача 12. Проверка дали дадено число е примитивен корен във F(n)." << endl;
    int n, num;
    cout << "Моля въведете n и число: " << endl;
    cin >> n >> num;
    cout << ((primitiveRoot(n, num)) ? "Числото е примитивен корен." : "Числото не е примитивен корен.");
            cout << endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        }


        case 10:{ int n2;
    cout << "Задача 13. Всички примитивни корени във F(n)." << endl;
    cout << "Моля въведете n: " << endl;
    cin >> n2;
    findAllPrimitiveRoots(n2);
            cout << endl;
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        }

    
        case 11:{ cout << "Задача 14. Изчисляване на дискретен логаритъм." << endl;
    discreteLog(0,0,size);
            cout << "Желаете ли да продължите? (y/n)" << endl;
            cin >> input;
            if (input == 'y') {
                goto Label1;
            }
            else if (input == 'n') {
                return 0;
            }
            break;

        }
    delete[] set;
        set = NULL;
}//za switch operation
    return 0;
}
