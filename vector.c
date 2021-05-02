#include "vector.h"

HndVector initVector()
{

	return initVectorCapacity(8);

}

HndVector initVectorCapacity(int cap)
{

	HndVector pVector= (HndVector)malloc(sizeof(HndVector));
	if (!pVector)
	{
		printf("pVector error");
		exit(EXIT_FAILURE);

	}

	pVector->parray = (valuetype*)malloc(cap * sizeof(valuetype));
	if (pVector->parray == NULL)
	{
		printf("Not enough capacity");
		return NULL;

	}

	pVector->capacity = cap;
	pVector->size = 0;

	return pVector;

}

int getSize(HndVector hnd)
{

	return hnd->size;

}
int getcapacity(HndVector hnd)
{
	return hnd->capacity;
}

static int SetCapacity(HndVector hnd)
{

	size_t memorySizeBytes = hnd->capacity * 2 * sizeof(int);   //2 is default value

	valuetype* pnewarray = (valuetype*)realloc(hnd->parray, memorySizeBytes);
	if (pnewarray == NULL)
	{
		printf("not enough capacity");
		return -1;
	}

	hnd->capacity = 2 * hnd->capacity;

	hnd->parray = pnewarray;

	return hnd->capacity;

}

int pushback(HndVector hnd, valuetype val)
{

	if (hnd->size >= hnd->capacity)
	{
		if (SetCapacity(hnd) == -1)
		{
			return -2;
		}
		else
			SetCapacity(hnd);
	}

	hnd->parray[hnd->size] = val;   // first value: hnd->size = 0
	hnd->size++;

}


int getAt(const HndVector hnd, int index)
{

	if (index<0 || index > hnd->size)
		return -3;

	return hnd->parray[index];

}

int isEmpty(const HndVector hnd)
{

	return !hnd->size == 0;      // 0 or 1 

}

void displayVector(const HndVector hnd)
{

	for (int i = 0; i < getSize(hnd); ++i)
		printf("%d\n", hnd->parray[i]);

}

int insertAt(HndVector hnd, int index, valuetype value)
{

	if (index< 0 || index>hnd->size)
		return -4;

	if (hnd->size >= hnd->capacity)
	{
		if (SetCapacity(hnd) == -1)
		{
			return -2;
		}
		else
			SetCapacity(hnd);
	}


	memmove(&hnd->parray[index + 1], &hnd->parray[index], (hnd->size - index) * sizeof(valuetype));

	hnd->parray[index] = value;
	++hnd->size;


}


void  swapVectorIndex(HndVector hnd, valuetype idx1, valuetype idx2)
{

	valuetype tempValue;

	tempValue = hnd->parray[idx1];
	hnd->parray[idx1] = hnd->parray[idx2];
	hnd->parray[idx2] = tempValue;


}


void destroyVector(HndVector hnd)
{

	free(hnd->parray);
//	free(hnd);
}