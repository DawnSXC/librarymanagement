#include"borrow_management.h"
#include"book_management.h"
#include"user_management.h"
#include<ctype.h>

BorrowLink borrowList; 
BookArray books; 
UserLink userList;
User nowUser; 
//main menu
void mainView();
//user menu
void userView();
//administrator menu
void adminView();
//user login
void userLogin();
//administrator login
void adminLogin();
//User registration
void createUser();
//add books to the system
void addBook();
//delect books from system
void deleteBook();
//search books by name
void searchByName();
//search books by author
void searchByAuthor();
//search books by year
void searchByYear();
//all books
void searchAll();
//borrow books
void borrowBook();
//return books
void backBook();
//diaplay the list of borrowed books
void borrowLsits();
int main()
{
	//load file
	FILE*file = fopen("user.txt", "r");
	load_user(file);
	file = fopen("book.txt", "r");
	load_books(file);
	file = fopen("borrow_record.txt", "r");
	load_borrow(file);
	mainView();
	file = fopen("user.txt", "w");
	store_user(file);
	fclose(file);
	file = fopen("book.txt", "w");
	store_books(file);
	fclose(file);
	file = fopen("borrow_record.txt", "w");
	store_borrow(file);
	fclose(file);
	return 0;
}
//main menu
void mainView()
{
	int chice;
	while (1)
	{
		system("cls");
		printf("\t****************************\n");
		printf("\t* Welcome to the library! *\n");
		printf("\t***************************\n");
		printf("\t1.User login\n");
		printf("\t2.Administrator login\n");
		printf("\t3.User registration\n");
		printf("\t0.Exit the system\n");
		printf("\n");
		printf("\tPlease enter your choice:");
		scanf("%d", &chice);
		switch (chice)
		{
		case 1:userLogin(); break;
		case 2:adminLogin();break;
		case 3:createUser(); break;
		case 0: return;
		default:
			break;
		}
	}
	

}
//user menu
void userView()
{
	int chice;
	while (1)
	{
		system("cls");
		printf("\t****************************\n");
		printf("\t* Welcome to the library! *\n");
		printf("\t***************************\n");
		printf("\t1.Search books by title\n");
		printf("\t2.Search books by author\n");
		printf("\t3.Search books by published year\n");
		printf("\t4.Display all books\n");
		printf("\t5.Borrow Books\n");
		printf("\t6.Return Books\n");
		printf("\t7.Borrow List\n");
		printf("\t0.Return to the main menu\n");
		printf("\n");
		printf("\tPlease enter your choice:");
		scanf("%d", &chice);
		switch (chice)
		{
		case 1:	searchByName(); break;
		case 2:searchByAuthor(); break;
		case 3:searchByYear();	break;
		case 4:searchAll(); break;
		case 5:	borrowBook(); break;
		case 6:	backBook(); break;
		case 7:borrowLsits(); break;
		case 0: return;
		default:
			break;
		}
	}
}
//user login
void userLogin()
{
	char username[20]; 
	char password[20];
	printf("\tInput User Name:");
	scanf("%s", username);
	printf("\tInput Password:");
	scanf("%s", password);
	User* p = userList.head; 
	while (p)
	{
		if (strcmp(p->usercount, username) == 0)
		{
			if (strcmp(p->password, password) == 0)
			{
				nowUser.usercount = (char*)malloc(sizeof(char)*strlen(username));
				strcpy(nowUser.usercount, username);
				userView();
				return; 
			}
			else
			{
				printf("\tPassword is wrong£¡\n");
				printf("\tPress any key to exit........\n");
				getchar();
				getchar();
				return; 
			}
		}
		p = p->next; 
	}
	if (p == NULL)
	{
		printf("\tThis account does not exist, please sign up to be a member after exiting.\n");
		printf("\tPress any key to exit........\n");
		getchar();
		getchar();
	}
}
//administrator login£¨support only one account ID£ºadmin Password£º123456)
void adminLogin()
{
	char password[20];
	char username[20]; 
	printf("\tEnter administrator account:");
	scanf("%s", username);
	printf("\tEnter administrator password:");
	scanf("%s", password);
	char temp[] = "admin";
	User* p = userList.head;
	while (p)
	{
		if ((strcmp(p->usercount, temp) == 0) && (strcmp(username, temp) == 0))
		{
			if (strcmp(p->password, password) == 0)
			{
				adminView();
				return;
			}
			else
			{
				printf("\tPassword is wrong please check and try again after exiting.\n");
				printf("\tPress any key to exit........\n");
				getchar();
				getchar();
				
				return;
			}
		}
		p = p->next;
	}
	printf("\tWrong ID or this account has no administrative rights.\n");
	printf("\tPress any key to exit........\n");
	getchar();
	getchar();
}
//administrator menu
void adminView()
{
	int chice;
	while (1)
	{
		system("cls");
		printf("\t****************************\n");
		printf("\t* Welcome to the library! *\n");
		printf("\t***************************\n");
		printf("\t1.Add New Books\n");
		printf("\t2.Delect Books\n");
		printf("\t3.All Books List\n");
		printf("\t0.Exit\n");
		printf("\n");
		printf("\tEnter your choice:");
		scanf("%d", &chice);
		switch (chice)
		{
		case 1:	addBook(); break;
		case 2:	deleteBook(); break;
		case 3:	searchAll(); break;
		case 0: return; 
		default:
			break;
		}
	}
}
//add users' information,User registration
void createUser()
{
	char username[20];
	char password[20];
	char againPassword[20];
	printf("\tEnter a username for a new account:");
	scanf("%s", username);
	printf("\tPlease set the password for your account(no more than 15 numbers):");
	scanf("%s", password);
	printf("\tPlease enter the password again to confirm:");
	scanf("%s", againPassword);
	if (strlen(username) == 0 || strlen(password) == 0)
	{
		printf("\tUser name and password cannot be empty!\n");
		printf("\tPress any key to exit........\n");
		getchar();
		getchar();
		return; 
	}
	if (strcmp(password, againPassword) != 0)
	{
		printf("The two passwords are inconsistent!\n");
		printf("Press any key to exit........\n");
		getchar();
		getchar();
		return; 
	}
	User* p = userList.head;
	while (p)
	{
		if (strcmp(p->usercount, username) == 0)
		{
			break; 
		}
		p = p->next;
	}
	if (p == NULL)
	{
		User add;
		add.password = (char*)malloc(sizeof(password));
		add.usercount = (char*)malloc(sizeof(username));
		strcpy(add.password, password); strcpy(add.usercount, username);
		add_user(add);
		printf("Congratulations on your successful registration!\n");
		printf("Press any key to exit and log in to start your reading journey........\n");
		getchar();
		getchar();
	}
	else
	{
		printf("This user name has been registered, please login. Or sign up for a new account.\n");
		printf("Press any key to exit........\n");
		getchar();
		getchar();
	}
}

//Add new books
void addBook()
{
	Book add;
	int i; 
	char titles[20], author[20] ,id[20];
	printf("Book ID(1-1000):");
	scanf("%s", id);
	for (i = 0; i < strlen(id); i++)
	{
		if (!isdigit(id[i]))
			break; 
	}
	if (i < strlen(id))
	{
		printf("Book ID must be numbers\n");
		printf("Press any key to exit........\n");
		getchar();
		getchar();
		return ;
	}
	else
	{
		add.id = atoi(id); 
		printf("Book Title:");
		scanf("%s", titles);
		printf("Author£º");
		scanf("%s", author);
		add.authors = (char*)malloc(sizeof(char)*strlen(author));
		add.title = (char*)malloc(sizeof(char)*strlen(titles));
		strcpy(add.authors, author);
		strcpy(add.title, titles);
		printf("Year of publication:"); scanf("%d", &add.year);
		if (add.year <= 0)
		{
			printf("Publishing time input error, should be greater than 0\n ");
			printf("Press any key to exit........\n");
			getchar();
			getchar();
			return; 
		}
		printf("Enter book inventory(copies):"); scanf("%d", &add.copies);
		if (add.copies < 0)
		{
			printf("Inventory quantity cannot be less than 0.\n ");
			printf("Press any key to exit........\n");
			getchar();
			getchar();
			return;
		}
		if (add_book(add) == -1)
		{
			printf("This book ID already exists.Add books failed.\n");
		}
		else
		{
			printf("Add books successfully!\n"); 
		}
		printf("Press any key to exit........\n");
		getchar();
		getchar();
	}
}
//delect books from library
void deleteBook()
{
	int i , flag; 
	char id[20]; 
	printf("Enter the book ID:");
	scanf("%s", id);
	for (i = 0; i < strlen(id); i++)
	{
		if (!isdigit(id[i]))
			break;
	}
	if (i < strlen(id))
	{
		printf("Book ID is number,please check and try again!\n");
		printf("Press any key to exit........\n");
		getchar();
		getchar();
		return;
	}
	else
	{
		Book book; book.id = atoi(id);
		flag = remove_book(book); 
		if (flag == -1)
		{
			printf("This book has borrowed information and cannot be deleted. Please contact the user to return it as soon as possible.\n");
		}
		else if (flag == 1)
		{
			printf("This book does not exist.\n"); 
		}
		else
		{
			printf("Delect books successfully!\n");
		}
		printf("Press any key to exit........\n");
		getchar();
		getchar();
	}
}

void searchByName()
{
	int i = 0;
	char bookName[20]; 
	printf("Please input book title:");
	scanf("%s", bookName);
	BookArray p = find_book_by_title(bookName);
	for (i = 0; i < p.length; i++)
	{
		printf("Book ID:%d\tBook Title:%s\tAuthor:%s\tYear of publication:%d\tCopies:%d\n", p.array[i].id, p.array[i].title, p.array[i].authors, p.array[i].year, p.array[i].copies);
	}
	if (p.length == 0)
		printf("Sorry, we can't find the information of this book.\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();
	
}

void searchByAuthor()
{
	int i; 
	char bookAuthor[20];
	printf("Please input author's name:");
	scanf("%s", bookAuthor);
	BookArray p = find_book_by_author(bookAuthor);
	for (i = 0; i < p.length; i++)
	{
		printf("Book ID:%d\tBook Title:%s\tAuthor:%s\tYear of publication:%d\tCopies:%d\n", p.array[i].id, p.array[i].title, p.array[i].authors, p.array[i].year, p.array[i].copies);
	}
	if (p.length == 0)
		printf("Sorry, we can't find the information of this book.\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();

}

void searchByYear(){
	int year , i ; 
	printf("Please input the year of publication:");
	scanf("%d", &year);
	BookArray p = find_book_by_year(year);
	for (i = 0; i < p.length; i++)
	{
		printf("Book ID:%d\tBook Title:%s\tAuthor:%s\tYear of publication:%d\tCopies:%d\n", p.array[i].id, p.array[i].title, p.array[i].authors, p.array[i].year, p.array[i].copies);
	}
	if (p.length == 0)
		printf("Sorry, we can't find the information of this book.\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();
}
//search all books
void searchAll()
{
	int i; 
	BookArray p = books; 
	for (i = 0; i < p.length; i++)
	{
		printf("Book ID:%d\tBook ID:%s\tAuthor:%s\tYear of publication:%d\tCopies:%d\n", p.array[i].id, p.array[i].title, p.array[i].authors, p.array[i].year, p.array[i].copies);
	}
	if (p.length == 0)
		printf("Sorry, we can't find the information of this book.\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();
}

void borrowBook()
{
	Borrow add;
	int flag; 
	char temp[20]; 
	printf("Enter the borrowing book ID:");
	scanf("%d", &add.id);
	printf("Enter the date of borrowing(Year Month Day:");
	scanf("%d %d %d", &add.year, &add.mounth, &add.day);
	add.username = (char*)malloc(sizeof(char)*strlen(nowUser.usercount));
	strcpy(add.username, nowUser.usercount);
	flag = add_borrow(add);
	if (flag == -1)
		printf("There is no corresponding book.\n");
	else if (flag == -2)
		printf("You have borrowed this book.\n");
	else
		printf("Borrow book successfully!\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();
}
//return books
void backBook()
{
	Borrow add;
	int flag;
	char temp[20];
	printf("Enter the returned book ID:");
	scanf("%d", &add.id);
	add.username = (char*)malloc(sizeof(char)*strlen(nowUser.usercount));
	strcpy(add.username, nowUser.usercount);
	flag = remove_borrow(add);
	if (flag == -1)
		printf("There is no corresponding book.\n");
	else
		printf("Success in returning books!\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();
}
//list of borrowed books
void borrowLsits()
{
	int flag = 0 , i ;
	Borrow* p = borrowList.head;
	while (p)
	{
		if (strcmp(p->username, nowUser.usercount) == 0)
		{
			for (i = 0; i < books.length; i++)//search all book borrowed information
				if (books.array[i].id == p->id)
					break; 
			printf("Borrowing book ID:%d Book Title:%s Borrow Date£º%d %d %d\n", p->id,books.array[i].title, p->year, p->mounth, p->day);
			flag = 1; 
		}
		p = p->next;
	}
	if (flag == 0)
		printf("No borrow record.\n");
	printf("Press any key to exit........\n");
	getchar();
	getchar();
	return ;
}