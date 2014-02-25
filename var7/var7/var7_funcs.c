#include "var7_funcs.h"

bool Input()
{
		while( 1 )
	{
		gets( buffer );
		if( buffer[0] )
		{
			inputErrors = 0;
			tmpBook = (BookList*)malloc( sizeof( BookList ) );
			tmp = buffer;
			tmp2 = strchr(tmp, ',');
			*tmp2 = 0;
			if( sscanf( tmp, "%[a-zA-Z0-9]", tmpBook->book.author ) == 0 )
			{
				inputErrors++;
			}
			tmp = tmp2+1;
			tmp2 = strchr(tmp, ',');
			*tmp2 = 0;
			if( sscanf( tmp, "%*[ \t]%[a-zA-Z0-9]", tmpBook->book.name ) == 0 )
			{
				inputErrors++;
			}
			tmp = tmp2+1;
			tmp2 = strchr(tmp, ',');
			*tmp2 = 0;
			if( sscanf( tmp, "%*[ \t]%[a-zA-Z0-9]", tmpBook->book.publisher ) == 0 )
			{
				inputErrors++;
			}
			tmp = tmp2+1;
			if( sscanf( tmp, "%*[ \t]%u", &tmpBook->book.year ) == 0 )
			{
				inputErrors++;
			}
			//sscanf( buffer, "%[a-zA-Z0-9],%*[ \t]%[a-zA-Z0-9],%*[ \t]%[a-zA-Z0-9],%*[ \t]%u", tmpBook->book.author, tmpBook->book.name, tmpBook->book.publisher, &tmpBook->book.year );
			if( inputErrors ) {
				puts("Wrong input, try again");
				free( tmpBook );
			}	
			else
			{
				curBook->next = tmpBook;
				curBook = curBook->next;
				curBook->next = 0;
			}
		}
		else
		{
			//k = 0;
			//free( tmpBook );
			break;
		}
	}
	return 1;
}