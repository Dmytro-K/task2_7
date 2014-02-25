#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "var7_funcs.h"

int main()
{
//	size_t n;
//	size_t i;
	BookList books = { 0 };
	BookList *curBook;
	BookList *tmpBook;
	//BookInfo bookTmp;
	int k, inputErrors;
	char buffer[BUF_SIZE * 4];
	char *tmp, *tmp2;
	
	/*puts("Enter count of books: ");
	scanf("%d", &n);*/
	
	//books = (BookInfo*)malloc( n * sizeof(BookInfo));

	curBook = &books;
	//k=1;
	puts( "Enter data(comma separator, empty line for end):" );
	puts( "Author:\tName:\tPublisher:\tYear:" );

	//while( 1 )
	//{
	//	gets( buffer );
	//	if( buffer[0] )
	//	{
	//		inputErrors = 0;
	//		tmpBook = (BookList*)malloc( sizeof( BookList ) );
	//		tmp = buffer;
	//		tmp2 = strchr(tmp, ',');
	//		*tmp2 = 0;
	//		if( sscanf( tmp, "%[a-zA-Z0-9]", tmpBook->book.author ) == 0 )
	//		{
	//			inputErrors++;
	//		}
	//		tmp = tmp2+1;
	//		tmp2 = strchr(tmp, ',');
	//		*tmp2 = 0;
	//		if( sscanf( tmp, "%*[ \t]%[a-zA-Z0-9]", tmpBook->book.name ) == 0 )
	//		{
	//			inputErrors++;
	//		}
	//		tmp = tmp2+1;
	//		tmp2 = strchr(tmp, ',');
	//		*tmp2 = 0;
	//		if( sscanf( tmp, "%*[ \t]%[a-zA-Z0-9]", tmpBook->book.publisher ) == 0 )
	//		{
	//			inputErrors++;
	//		}
	//		tmp = tmp2+1;
	//		if( sscanf( tmp, "%*[ \t]%u", &tmpBook->book.year ) == 0 )
	//		{
	//			inputErrors++;
	//		}
	//		//sscanf( buffer, "%[a-zA-Z0-9],%*[ \t]%[a-zA-Z0-9],%*[ \t]%[a-zA-Z0-9],%*[ \t]%u", tmpBook->book.author, tmpBook->book.name, tmpBook->book.publisher, &tmpBook->book.year );
	//		if( inputErrors ) {
	//			puts("Wrong input, try again");
	//			free( tmpBook );
	//		}	
	//		else
	//		{
	//			curBook->next = tmpBook;
	//			curBook = curBook->next;
	//			curBook->next = 0;
	//		}
	//	}
	//	else
	//	{
	//		//k = 0;
	//		//free( tmpBook );
	//		break;
	//	}
	//}

	k = books.next ? 1 : 0;

	while( k )
	{
		k = 0;
		curBook = &books;
		while( curBook->next->next )
		{
			if( curBook->next->book.year < curBook->next->next->book.year )
			{
				tmpBook = curBook->next;
				curBook->next = curBook->next->next;
				tmpBook->next = curBook->next->next;
				curBook->next->next = tmpBook;
				k=1;
			}
			curBook = curBook ->next;
		}
	}

	curBook = books.next;

	puts( "Author:\tName:\tPublisher:\tYear:" );
	while( curBook )
	{
		printf( "%s\t%s\t%s\t%u\n", curBook->book.author, curBook->book.name, curBook->book.publisher, curBook->book.year );
		curBook = curBook->next;
	}
	
	curBook = books.next;
	while( curBook )
	{
		tmpBook = curBook;
		curBook = curBook->next;
		free( tmpBook );
	}

	return 0;
}