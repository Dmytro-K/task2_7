#include "var7_funcs.h"

#define _CRT_SECURE_NO_WARNINGS
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>

char* StrChr( char* str, char c )
{
	char *ptr;

	if( str == NULL ) {
		return NULL;
	}

	ptr = str;

	while( *ptr ) {
		if( *ptr == c ) {
			return ptr;
		}
		ptr++;
	}
	return NULL;
}

//#define IS_GRAPH( CHR ) ( ( CHR >= 0x21 ) && ( CHR <= 0x7E ) )

_inline bool IsGraph( char chr )
{
	return chr >= 0x21 && chr <= 0x7E;
}

_inline bool IsDigit( char chr )
{
	return chr >= 0x30 && chr <= 0x39;
}

bool ParseLine( char *buffer, BookInfo *book )
{
	char *tmp, *tmp2;
	tmp = buffer;

	tmp2 = StrChr( tmp, ',' );
	if( tmp2 == NULL ) {
		return false;
	}
	*tmp2 = 0;
	while( !IsGraph( *tmp ) ) tmp++;
	memcpy( book->author, tmp, tmp2 - tmp + 1 );

	tmp = tmp2 + 1;
	tmp2 = StrChr( tmp, ',' );
	if( tmp2 == NULL ) {
		return false;
	}
	*tmp2 = 0;
	while( !IsGraph( *tmp ) ) tmp++;
	memcpy( book->name, tmp, tmp2 - tmp + 1 );

	tmp = tmp2 + 1;
	tmp2 = StrChr( tmp, ',' );
	if( tmp2 == NULL ) {
		return false;
	}
	*tmp2 = 0;
	while( !IsGraph( *tmp ) ) tmp++;
	memcpy( book->publisher, tmp, tmp2 - tmp + 1 );

	tmp = tmp2 + 1;
	while( !IsDigit( *tmp ) )
	{
		if( *tmp )
		{
			tmp++;
		}
		else
		{
			return false;
		}
	}
	book->year = atoi( tmp );
	return true;
}

bool InputBooks( BookList *books )
{
	BookList *curBook;
	BookList *tmpBook = 0;
	char buffer[BUF_SIZE];

	puts( "Enter data(comma separator, empty line for end):" );
	puts( "Author:\tName:\tPublisher:\tYear:" );

	curBook = books;

	while( 1 ) {
		fgets( buffer, BUF_SIZE-1, stdin );
		if( buffer[0] ) {
			if( !tmpBook ) {
				tmpBook = (BookList*)malloc( sizeof( BookList ) );
				if( tmpBook == NULL ) {
					return false;
				}
			}

			//sscanf( buffer, "%[a-zA-Z0-9],%*[ \t]%[a-zA-Z0-9],%*[ \t]%[a-zA-Z0-9],%*[ \t]%u", tmpBook->book.author, tmpBook->book.name, tmpBook->book.publisher, &tmpBook->book.year );
			if( !ParseLine( buffer, &tmpBook->book ) ) {
				puts( "Wrong input, try again" );
			} else {
				curBook->next = tmpBook;
				curBook = curBook->next;
				curBook->next = 0;
				tmpBook = 0;
			}
		} else {
			free( tmpBook );
			break;
		}
	}
	return true;
}

void SortBooks( BookList **books )
{
	bool k;
	BookList *curBook, *tmpBook;
	void *root;

	root = books;

	k = *books ? true : false;
	//if( k )
	//{
	//	root = malloc( sizeof( root->next ) );
	//	root->next = books;
	//}
	//else
	//{
	//	return;
	//}

	while( k ) {
		k = 0;
		curBook = root;
		while( curBook->next->next ) {
			if( curBook->next->book.year < curBook->next->next->book.year ) {
				tmpBook = curBook->next;
				curBook->next = curBook->next->next;
				tmpBook->next = curBook->next->next;
				curBook->next->next = tmpBook;
				k = 1;
			}
			curBook = curBook->next;
		}
	}
	//free( root );
}

void PrintBooks( const BookList *books )
{
	const BookList * curBook = books;
	puts( "Author:\tName:\tPublisher:\tYear:" );
	while( curBook )
	{
		printf( "%s\t%s\t%s\t%d\n", curBook->book.author, curBook->book.name, curBook->book.publisher, curBook->book.year );
		curBook = curBook->next;
	}
}

void DeleteBooks( BookList *books )
{
	BookList *curBook;
	curBook = books;
	while( curBook ) {
		BookList *tmpBook;
		tmpBook = curBook;
		curBook = curBook->next;
		free( tmpBook );
	}
}