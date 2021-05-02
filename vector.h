#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef int valuetype;

#define INITAL_CAPACITY 8;

typedef struct Vector {

	valuetype* parray;
	int  capacity;
	int  size;


}Vector, *HndVector;

HndVector initVector();
HndVector initVectorCapacity(int cap);
int getSize(HndVector hnd);
int getcapacity(HndVector hnd);
static int SetCapacity(HndVector hnd);
int pushback(HndVector hnd, valuetype val);
int getAt(const HndVector hnd, int index);
int isEmpty(const HndVector hnd);
void destroyVector(HndVector hnd);
void displayVector(const HndVector hnd);
int insertAt(HndVector hnd, int index, valuetype value);
void  swapVectorIndex(HndVector hnd, valuetype idx1, valuetype idx2);

#endif
