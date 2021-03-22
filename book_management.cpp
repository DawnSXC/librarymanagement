#include"book_management.h"
#include"borrow_management.h"
//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file)
{
	if (file == NULL||books.length>books.max)
		return -1;
	int i; 
	//all books
	for (i = 0; i < books.length;i++)
	{
		//stor books
		fprintf(file, "%d %s %s %d %d", books.array[i].id, books.array[i].title, books.array[i].authors, books.array[i].year, books.array[i].copies);
		if (i!=books.length-1)
			fprintf(file, "\n"); 
	}
	return 0; 
}

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file)
{
	if (file == NULL)
		return -1;
	//for start the sysytem
	books.max = 100;
	books.length = 0;
	books.array = (Book*)malloc(sizeof(Book)*books.max);
	if (books.array == NULL)
		return -1;
	while (!feof(file))
	{
		Book* p = (Book*)malloc(sizeof(Book));
		char titles[20], authors[20];
		fscanf(file, "%d %s %s %d %d",&p->id, titles, authors,&p->year,&p->copies);
		p->authors = (char*)malloc(sizeof(char)*strlen(authors));
		p->title = (char*)malloc(sizeof(char)*strlen(titles));
		strcpy(p->authors, authors); strcpy(p->title, titles);
		if (p->id < 0 || p->id>3000)
			break; 
		if (books.length == books.max)//allow to store more books if there are too many
		{
			
			int new_max = books.max + 20; 
			books.array = (Book*)realloc(books.array, new_max*sizeof(Book)); 
			if (books.array == NULL)
				return -2;
			books.max = new_max;
			books.array[books.length++] = *p;
		}
		else
		{
			books.array[books.length++] = *p; 
		}
	}
	return 0;
}

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(Book book)
{
	int i; 
	for (i = 0; i < books.length; i++)
	{
		if ((books.array[i].id == book.id)&&strcmp(book.authors, books.array[i].authors) == 0 && (strcmp(book.title, books.array[i].title) == 0) && (books.array[i].year == book.year))
		{
			books.array[i].copies++; 
			return 0;
		}
		else if ((books.array[i].id == book.id))
		{
			return -1; 
		}
	}
	if (i >= books.length)
	{
		if (books.length == books.max)
		{
			//���ݴ���
			int new_max = books.max + 20;
			books.array = (Book*)realloc(books.array, new_max*sizeof(Book));
			if (books.array == NULL)
				return -2;
			books.max = new_max;
			books.array[i].authors = (char*)malloc(sizeof(char)*strlen(book.authors));
			books.array[i].title = (char*)malloc(sizeof(char)*strlen(book.title));
			books.array[i].copies = book.copies;
			books.array[i].id = book.id;
			books.array[i].year = book.year;
			strcpy(books.array[i].authors, book.authors);
			strcpy(books.array[i].title, book.title);
			books.length++;
		}
		else
		{
			books.array[i].authors = (char*)malloc(sizeof(char)*strlen(book.authors)); 
			books.array[i].title = (char*)malloc(sizeof(char)*strlen(book.title)); 
			books.array[i].copies = book.copies; 
			books.array[i].id = book.id;
			books.array[i].year = book.year;
			strcpy(books.array[i].authors, book.authors);
			strcpy(books.array[i].title, book.title);
			books.length++; 
		}
	}
	return 0;
}

//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(Book book)
{
	int i , j ;
	Borrow* p = borrowList.head;
	while (p)
	{
		//���ڽ����޷�ɾ��
		if (p->id == book.id)
			return -1; 
		p = p->next;
	}
	for (i = 0; i < books.length; i++)
	{
		if (books.array[i].id == book.id)
		{
			for (j = i; j < books.length-1; j++)
			{
				books.array[j] = books.array[j + 1];
			}
			books.length--;
			return 0;
		}
	}
	return 1;
}

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_title(const char *title)
{
	BookArray p; 
	int i = 0;
	p.max = 100;
	p.length = 0;
	p.array = (Book*)malloc(sizeof(Book)*books.max);
	if (p.array == NULL)
		return p;
	for (i = 0; i < books.length; i++)
	{
		if (strcmp(books.array[i].title, title) == 0)
		{
			p.array[p.length].authors = (char*)malloc(sizeof(char)*strlen(books.array[i].authors));
			p.array[p.length].title = (char*)malloc(sizeof(char)*strlen(books.array[i].title));
			p.array[p.length].id = books.array[i].id; 
			p.array[p.length].copies = books.array[i].copies;
			p.array[p.length].year = books.array[i].year;
			strcpy(p.array[p.length].title, title);
			strcpy(p.array[p.length].authors, books.array[i].authors);
			p.length++;
		}
	}
	return p;

}

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_author(const char *author){
	BookArray p;
	int i = 0;
	p.max = 100;
	p.length = 0;
	p.array = (Book*)malloc(sizeof(Book)*books.max);
	if (p.array == NULL)
		return p;
	for (i = 0; i < books.length; i++)
	{
		if (strcmp(books.array[i].authors, author) == 0)
		{
			p.array[p.length].authors = (char*)malloc(sizeof(char)*strlen(books.array[i].authors));
			p.array[p.length].title = (char*)malloc(sizeof(char)*strlen(books.array[i].title));
			p.array[p.length].id = books.array[i].id;
			p.array[p.length].copies = books.array[i].copies;
			p.array[p.length].year = books.array[i].year;
			strcpy(p.array[p.length].authors, author);
			strcpy(p.array[p.length].title, books.array[i].title);
			p.length++;
		}
	}
	return p;
}

//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_year(unsigned int year)
{
	BookArray p;
	int i = 0;
	p.max = 100;
	p.length = 0;
	p.array = (Book*)malloc(sizeof(Book)*books.max);
	if (p.array == NULL)
		return p;
	for (i = 0; i < books.length; i++)
	{
		if (books.array[i].year==year)
		{
			p.array[p.length].authors = (char*)malloc(sizeof(char)*strlen(books.array[i].authors));
			p.array[p.length].title = (char*)malloc(sizeof(char)*strlen(books.array[i].title));
			p.array[p.length].id = books.array[i].id;
			p.array[p.length].copies = books.array[i].copies;
			p.array[p.length].year = year;
			strcpy(p.array[p.length].authors, books.array[i].authors);
			strcpy(p.array[p.length].title, books.array[i].title);
			p.length++;
		}
	}
	return p;
}

