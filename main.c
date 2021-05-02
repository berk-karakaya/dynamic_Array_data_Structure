#include <stdio.h>
#include "vector.h"





int main()
{

	HndVector hnd = initVectorCapacity(60);

	printf("%d\n", getcapacity(hnd));
	printf("%d\n", getSize(hnd));

	printf("*********************************\n\n");

	printf("%d \n",isEmpty(hnd));


	printf("*********************************\n\n");

	for (int i = 0; i < 10; ++i)
		pushback(hnd, i);


	displayVector(hnd);

	printf("*********************************\n\n");

	getAt(hnd, 3);
	printf("%d\n", hnd->parray[3]);



	printf("*********************************\n\n");

	printf("%d \n", isEmpty(hnd));

	printf("*********************************\n\n");


	insertAt(hnd, 3, 12);

	displayVector(hnd);

	printf("*********************************\n\n");

	swapVectorIndex(hnd, 3, 1);
	displayVector(hnd);
	displayVector(hnd);

}