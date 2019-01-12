#ifndef Functions_hpp
#define Functions_hpp

#include <stdio.h>

bool isInRemainderRing(int*, int, int);
int remainderRing(int *, int);
int sum(int*, int, int, int);
int sub(int*, int, int, int);
int mul(int*, int, int, int);
int getReciprocal(int,int, int);
void findReciprocal(int ** remSet2D, int cols);
void getReciprocalUser(int,int,int);
int div(int,int,int,int);
int fastPower(int, int, int, int, int);
bool findF(unsigned);
bool primitiveRoot(unsigned, int);
void findAllPrimitiveRoots(int);
int discreteLog(int,int,int);


#endif /* Functions_hpp */
