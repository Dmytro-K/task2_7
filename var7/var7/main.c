#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var7_funcs.h"

int main()
{
	BookList books = { 0 };
	
	if( InputBooks( &books ) ) {
		SortBooks( &books.next );

		PrintBooks( books.next );
	}
	else
	{
		puts( "Not enough memory" );
	}
	
	DeleteBooks( books.next );

	return 0;
}