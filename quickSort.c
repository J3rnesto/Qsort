#include <stdio.h>
#include <stdlib.h>
#include <time.h> 



void qSort ( int lista[], int inf, int sup )
{
	int di = lista[ sup ];
	int i = inf-1;
	int j = sup;
	int cont = 1;
	int temp;

	if ( inf >= sup )
		return;
	while ( cont )
	{
		while( lista[ ++i ] < di );
		while( lista[ --j ] > di );
		if ( i < j )
		{
			temp = lista[ i ];
			lista[ i ] = lista[ j ];
			lista[ j ] = temp;
		}
		else
				cont = 0;

	}
	temp = lista[ i ];
	lista[ i ] = lista[ sup ];
	lista[ sup ] = temp;

	qSort(lista, inf, i-1);
	qSort(lista, i+1, sup);

};

void fillArray (int lista[], int ARRAY_SIZE)
{
	int i;
	for (i=0;i<ARRAY_SIZE+1;i++)
	{
		lista[i]=rand()% 23459;	
	}
 

};

int main (int argc, const char * argv [])
{
	int i;
//	Define the size of the b array.	
	int ARRAY_SIZE = 50 ;
	int b[ARRAY_SIZE];
	fillArray( b, ARRAY_SIZE );

	//a is the test array
	int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};
	int ap[9];

	printf("\n\nUnsorted array is:  ");
		for(i = 0; i < ARRAY_SIZE; ++i)
			printf(" %d ", b[i]);
		

	//testing
	qSort( b, 0, 9);


	printf("\n\nSorted array is:  ");
		for(i = 0; i < ARRAY_SIZE; ++i)
			printf(" %d ", b[i]);
		printf("\n");
}