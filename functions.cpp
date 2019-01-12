
#include "Functions.hpp"
#include <iostream>
#include <cmath>

using namespace std;

//Помощна функция, която връща true, ако числото е в пръстена

bool isInRemainderRing(int* set, int size, int num) {
    for (unsigned i = 0; i < size; i++) {
        if (set[i] == num) return true;
    }
    return false;
}

//Генерира остатъчния пръстен и го отпечатва в конзолата

int remainderRing(int * set, int size) {
    for (unsigned i = 0; i < size; i++) {
        set[i] = i;
    }
    
    cout << "Z(" << size << ") = {";
    for (unsigned i = 0; i < size; i++) {
        cout << set[i] << ((i == size - 1) ? "}" : ",");
    }
    cout << endl;
    return 0;
}

//Събиране
int sum(int* set, int size, int num1, int num2) {
    int result = 0;
    
    if (isInRemainderRing(set,size,num1) && isInRemainderRing(set,size,num2)) {
        result = (set[num1] + set[num2]) % size;
    }
    cout <<endl<< num1 <<" + "<<num2 <<" = "<<result;
    return result;
}

//Изваждане
int sub(int* set, int size, int num1, int num2) {
    int result = 0;
    
    if (isInRemainderRing(set, size, num1) && isInRemainderRing(set, size, num2)) {
        result = abs(set[num1] - set[num2]) % size;
    }
    cout << endl << num1 << " - " << num2 << " = " << result;
    return result;
}

//Умножение
int mul(int* set, int size, int num1, int num2) {
    int result = 0;
    
    if (isInRemainderRing(set, size, num1) && isInRemainderRing(set, size, num2)) {
        result = (set[num1] * set[num2]) % size;
    }
    cout << endl << num1 << " * " << num2 << " = " << result;
    return result;
}

//Задача 5. Функция, която намира двойките елементи на пръстена, които при умножение дават 1.
int getReciprocal(int size,int cols, int pos) {
    
    int * remSet = new int[size];
    for (int i = 0; i < size; i++) {
        remSet[i] = i;
    }
    for (int i = 0; i < size; i++) {
        int  a = remSet[i];
        for (int j = 0; j < size; j++) {
            int b = remSet[j];
            if (a * b % size == 1) {
                cols++;
            }
        }
    }
    int ** remSet2D = new int *[2];
    for (int i = 0; i < size; i++) {
        remSet2D[i] = new int[cols];
    }
    for (int i = 0; i < size; i++) {
        int a = remSet[i];
        for (int j = 0; j < size; j++) {
            int b = remSet[j];
            if (a * b % size == 1) {
                remSet2D[0][pos] = a;
                remSet2D[1][pos]= b;
                pos++;
            }
        }
    }
    findReciprocal(remSet2D, cols);
    delete[] remSet2D;
    remSet2D = NULL;
    delete[] remSet;
    remSet = NULL;
    return 0;
}

//  Задача 6. Функция, която намира реципрочната стойност на всеки елемент, ако такъв съществува. Извикваме я във функцията за задача 5., за да използваме двумерния масив.

void findReciprocal(int ** remSet2D, int cols) {
    for (unsigned i = 0; i < cols; i++) {
        cout << remSet2D[0][i] << "\t" << remSet2D[1][i] << endl;
    }
}
//Задача 7. Функция, която намира реципрочен елемент на зададен от потребителя елемент от множеството Z(n), ако такъв съществува.

void getReciprocalUser(int num,int size, int tmp) {
    for (int i = 0; i < size; i++) {
        if (num*i%size == 1) tmp = i;
    }
    if(tmp==0) cout << "Няма реципрочно число" << endl;
    else cout << "Реципрочното число е: " << tmp << endl;
}


// Задача 8. Деление

int div(int a, int b, int size, int tmp) {
    for (int i = 0; i < size; i++) {
        if (b*i%size == 1) {
            tmp = i;
        }
    }
    if (tmp > 0) {
        cout << "Резултат: ";
        return (a*tmp%size);
    }
    else {
        return -1;
    }
}

// Задача 9. Функция, която извършва бързо степенуване

int fastPower(int size, int a, int power, int k, int cnt) {
    for (int k = 1; k < size; k++) {
        cnt++;
        if ((int)pow(a, k) % size == 1) {
            break;
        }
    }
    k = cnt;
    return (int)pow(a, power%k) % size;
}

// Задача 11. Функция, която проверява дали даден остатъчен пръстен е остатъчно поле.


bool findF(unsigned size) {
    unsigned cnt = 0;
    for (unsigned i = 1; i < size; i++) {
        for (unsigned j = 1; j < size; j++) {
            if ((i*j) % size == 1) cnt++;
        }
    }
    if (cnt == size - 1) {
        
        cout << "Z(n) съвпада с F(n). \n";
        return true;
    }
    else
    {
        cout << "Z(n) не съвпада с F(n). \n";
        return false;
    }
}

//Задача 12. Функция, която проверява дали дадено число е примитивен корен във F(n).

bool primitiveRoot(unsigned n, int g)
{
    int tmp;
    int *arr = NULL;
    arr = new int[n];
    
    
    for (int i = 1; i<n; i++)
    {
        tmp = pow(g, i);
        arr[i] = tmp%n;
    }
    for (int i = 1; i<n; i++)
    {
        for (int j = i + 1; j<n; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
                break;
            }
        }
    }
    return true;
}

//Задача 13. Функция, която намира всички примитивни корени във F(n).

void findAllPrimitiveRoots(int n) {
    if (findF(n)) {
        for (int i = 1; i < n; i++) {
            if (primitiveRoot(n, i)) {
                cout << "i=" << i << endl;
            }
        }
    } else
        cout << "Не може да намери примитивни корени. " << endl;
    
    
}

//Задача 14. Функция, която изчислява дисретен логаритъм във F(n) при дадена основа и елемент от F(n) и връща -1, ако това не е допустимо.

int discreteLog(int a, int b,int size) {
    if (findF(size)) {
        do {
            cout << "Моля въведете стойности за a и b, за да се изчисли дискретен логаритъм: " << endl;
            cin >> a >> b;
        } while (!(a >= 0 && a < size) && !(b >= 0 && b < size));
        for (int i = 0; i < size; i++) {
            if (fastPower(size, a, i, 0, 0) == b) {
                cout << "dloga"<<a<<"b"<<b<<"="<<i;
                return i;
            }
            
        }
        
    }
    cout<<"-1";
        return -1;
}
