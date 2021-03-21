#include"user_management.h"
int store_user(FILE *file)//store users'information "user.txt"
{
	User* p = userList.head; 
	while (p!=NULL)
	{
		fprintf(file, "%s %s", p->usercount, p->password); 
		if (p->next != NULL)
			fprintf(file, "\n");
		p = p->next;
	}
	return 0; 
}
int load_user(FILE *file)//load users'information from file
{
	userList.head = NULL; 
	char username[20], password[20];
	while (!feof(file))
	{
		User* p = (User*)malloc(sizeof(User));
		fscanf(file, "%s %s",username, password);
		p->usercount = (char*)malloc(sizeof(char)*strlen(username));
		p->password = (char*)malloc(sizeof(char)*strlen(password));
		strcpy(p->usercount, username);
		strcpy(p->password, password);
		p->next = NULL; 
		if (userList.head==NULL)
		{ 
			userList.head = p; 
		}
		else
		{
			p->next = userList.head; 
			userList.head = p;
		}
	}
	return 0;
}

int add_user(User user) //user register
{
	User* p = userList.head; 
	User* add = (User*)malloc(sizeof(User)); //creat new node for new user
	add->password = (char*)malloc(sizeof(user.password));
	add->usercount = (char*)malloc(sizeof(user.usercount));
	strcpy(add->usercount, user.usercount);
	strcpy(add->password, user.password);
	add->next = NULL; 
	while (p != NULL)
	{
		//if the user name has exited
		if (strcmp(user.usercount, p->usercount) == 0)
			return 1;
		p = p->next;
	}
	if (userList.head == NULL)
		userList.head = add; 
	else
	{
		add->next = userList.head; 
		userList.head = add; 
	}
	return 0;
}