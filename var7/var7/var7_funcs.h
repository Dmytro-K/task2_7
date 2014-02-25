#ifndef VAR7_FUNCS_H
#define VAR7_FUNCS_H

#ifndef __cplusplus
typedef unsigned char bool;
#endif

#define BUF_SIZE 256

typedef struct _BookInfo{
	char author[BUF_SIZE];
	char name[BUF_SIZE];
	char publisher[BUF_SIZE];
	unsigned year;
} BookInfo;

typedef struct _BookList{
	BookInfo book;
	struct _BookList *next;
} BookList;


bool Input( BookList *books );

#endif /* VAR7_FUNCS_H */