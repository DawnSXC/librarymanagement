#ifndef BOOK_MANAGEMENT_GUARD__H 
#define BOOK_MANAGEMENT_GUARD__H

#include <stdio.h>

/*You can extend the structs (Book and BookArray) defined in this head file;
  However, you may not change the function prototypes. 
  You are also free to add additional head files and data structures as needed. 
*/


typedef struct _Book {
	    unsigned int id; //Book ID
		char *title; //book title
		char *authors; //comma separated list of authors
		unsigned int year; // year of publication
		unsigned int copies; //number of copies the library has
}Book;

typedef struct _BookArray {
	 Book* array; // pointer to array (or linked list) of struct Book.
	 unsigned int length; // number of elements in the (Book*) array 
}BookArray;

typedef struct user //�û�
{
	char user_id[30];  //�û���
	char password[30];  //����
	char username[30]; //��Ч֤������
	int admin;  //�Ƿ����Ա
	//struct node user_book;  //�û������鼮
	struct user* next;  //��һλ�û�
}User;
User* user_head;  //�û�ͷָ��
User* adm1;  //��������Ա�˺�



//saves the database of books in the specified file
//returns 0 if books were stored correctly, or an error code otherwise
int store_books(FILE *file);

//loads the database of books from the specified file
//the file must have been generated by a previous call to store_books()
//returns 0 if books were loaded correctly, or an error code otherwise
int load_books(FILE *file);

//adds a book to the ones available to the library
//returns 0 if the book could be added, or an error code otherwise
int add_book(Book book);

//removes a book from the library
//returns 0 if the book could be successfully removed, or an error code otherwise.
int remove_book(Book book);

//finds books with a given title.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_title (const char *title);

//finds books with the given authors.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_author (const char *author);

//finds books published in the given year.
//returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
//provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
//array is the null pointer.
BookArray find_book_by_year (unsigned int year);



void user_register();  //�û�ע��
void user_login();  //�û���¼
void admin_login();  //����Ա��½
//���Ĺ�����
void creat_user_list(char*, char*, char*);  //�����û�����


void load();  //���ļ��м�������
void save();  //�������ݵ��ļ�

//�û�������
void user_menu(User*);  //�û��˵�

void borrow_book(User*);  //���Ĺ���
void return_book(User*);  //�������


//����Ա������
void admin_initi();  //��������Ա�˺ų�ʼ��
User* serch_username(char*);  //�����û���



#endif