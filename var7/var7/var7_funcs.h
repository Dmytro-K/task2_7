#ifndef VAR7_FUNCS_H
#define VAR7_FUNCS_H

#ifndef __cplusplus
typedef unsigned char bool;
#define true ((bool)1)
#define false ((bool)0)
#endif /* __cplusplus */

#ifndef NULL
#define NULL (void*)0
#endif /* NULL */

#define FIELD_SIZE 256
#define BUF_SIZE (FIELD_SIZE*4)

typedef struct _BookInfo
{
	char author[FIELD_SIZE];
	char name[FIELD_SIZE];
	char publisher[FIELD_SIZE];
	int year;
} BookInfo;

typedef struct _BookList BookList;

struct _BookList
{
	BookList *next;
	BookInfo book;
};

bool InputBooks( BookList *books );

void SortBooks( BookList **books );

void PrintBooks( const BookList *books );

void DeleteBooks( BookList *books );

#endif /* VAR7_FUNCS_H */