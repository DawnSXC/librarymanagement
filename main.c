#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "book_management.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 main_menu();
	return 0;
}
void load()  //从文件中加载数据
{
/*	book_head = (Book*)malloc(sizeof(Book));
	book_head->next = NULL;
	book_amount = 0;

	FILE* fp2;
	fp2 = fopen("book.bin", "rb");
	if (fp2 == NULL)
	{
		fp2 = fopen("book.bin", "wb");
		if (fp2 == NULL)
		{
			printf("图书存储失败！\n"); exit(0);
		}
		fclose(fp2);
	}
	else
	{
		Book* bp = (Book*)malloc(sizeof(Book));
		bp = book_head;
		Book* tp = (Book*)malloc(sizeof(Book));
		while (fread(tp, sizeof(Book), 1, fp2))
		{
			bp->next = tp;
			++book_amount;
			tp = tp->next;
			tp = (Book*)malloc(sizeof(Book));
			bp = bp->next;
		}
		fclose(fp2);
	}
*/
	user_head = (User*)malloc(sizeof(User));
	user_head->next = NULL;
	FILE* fp1;
	fp1 = fopen("user.bin", "rb");
	if (fp1 == NULL)
	{
		admin_initi(); return;
	}
	User* p = (User*)malloc(sizeof(User));
	p = user_head;
	User* temp = (User*)malloc(sizeof(User));
	while (fread(temp, sizeof(User), 1, fp1))
	{
		p->next = temp;
		temp = temp->next;
		temp = (User*)malloc(sizeof(User));
		p = p->next;
	}
	adm1 = user_head->next;
	fclose(fp1);
}

void save()  //保存数据到文件
{
	FILE* fp = fopen("user.bin", "wb");
	User* temp = user_head->next;
	while (temp)
	{
		fwrite(temp, sizeof(User), 1, fp);
		temp = temp->next;
	}
	fclose(fp);

	/*fp = fopen("book.bin", "wb");
	Book* tb = book_head->next;
	while (tb)
	{
		fwrite(tb, sizeof(Book), 1, fp);
		tb = tb->next;
	}
	fclose(fp);
	*/
}
void admin_initi()  //管理员账号初始化
{
	FILE* fp = fopen("user.bin", "wb");
	if (fp == NULL)
	{
		printf("Fail！\n"); exit(0);
	}
	adm1 = (User*)malloc(sizeof(User));
	strcpy(adm1->user_id, "2019110031");
	strcpy(adm1->password, "12345678");
	strcpy(adm1->username, "adm1");
	adm1->admin = 1;
	adm1->next = NULL;
	//user_initi(adm1);
	user_head->next = adm1;
	//user_amount = 1;
	save();
	fclose(fp);
}
void admin_login()  //管理员登陆
{
	char name[30];
	
	printf("Please input system ID：\n");
	scanf("%s", name);
	User* account;
	if (account = serch_username(name), account == NULL)
	{
		printf("The user name does not exist, please register!\n");
		system("pause"); system("cls"); return;
	}
	if (!account->admin)
	{
		printf("This account has no administrative rights.\n");
		system("pause"); system("cls"); return;
	}
	printf("Please input system password：\n");
	scanf("%s", name);
	if (strcmp(account->password, name))
	{
		printf("Password is wrong,please check and login again！\n");
		system("pause"); system("cls"); return;
	}
	printf("Congratulations on your successful login\n");
	system("pause"); system("cls");
	//admin_menu(account);
}


void creat_user_list(char* userid, char* password, char* username)  //创建用户链表
{
	User* p = (User*)malloc(sizeof(User));
	p = user_head;
	while (p->next) p = p->next;
	User* tp = (User*)malloc(sizeof(User));
	strcpy(tp->user_id, userid);
	strcpy(tp->password, password);
	strcpy(tp->username, username);
	tp->admin = 0;
	tp->next = NULL;
	//user_initi(tp);
	p->next = tp;
	save();
}

void user_register()  //用户注册
{
	char userid[20];
	printf("Please input your ID(1-15 number)：\n");
	scanf("%s", userid);
	User* account;
	if (account = serch_username(userid), account != NULL)
	{
		printf("The user ID already exists, please re-enter！\n");
		system("pause"); system("cls"); return;
	}
	printf("Please enter your password(1-20 letter or number)：\n");
	char password[30];
	scanf("%s", password);
	printf("Please input your username(1-25 letter)：\n");
	char username[30];
	scanf("%s", username);
	creat_user_list(userid, password, username);
	printf("Congratulations on your successful registration！\n");

	system("pause"); system("cls");
}

User* serch_username(char* userid)  //查找用户名
{
	User* p = user_head->next;
	while (p)
	{
		if (!strcmp(p->user_id, userid)) return p;
		p = p->next;
	}
	return NULL;
}

void user_login()  //用户登录
{
	char uid[30];
	printf("Please input your user ID：\n");
	scanf("%s", uid);
	User* account;
	if (account = serch_username(uid), account == NULL)
	{
		printf("The user name does not exist, please register!\n");
		system("pause"); system("cls"); return;
	}
	char key[30];
	printf("Please enter your password：\n");
	scanf("%s",key);
	if (strcmp(account->password, key))
	{
		printf("Password is wrong,please check and login again！\n");
		system("pause"); system("cls"); return;
	}
	printf("Congratulations on your successful login\n");
	system("pause"); system("cls");
	//user_menu(account);
}
//user and administrators
void main_menu()  //主菜单
{
	load();
	while (1)
	{
	
		printf("+----------------------Welcome to the library!-----------------------+\n");
		printf("\n");
		printf("Please choose by entering the number before the option！\n");
		printf("1、Users registe\n");
		printf("2、Users log in\n");
		printf("3、Administrators log in\n");
		printf("0、Exit the system\n");
		printf("+---------------------------------------------+\n");
		int op; scanf("%d", &op); system("cls");
		switch (op)
		{
		case 1: user_register(); break;
		case 2: user_login();  break;
		case 3: admin_login();  break;
		case 0:printf("Exiting system......\n");
		       break;
	        
		default: printf("Wrong number,please enter again！\n"); system("pause"); system("cls"); break;
		}
	}
	
}







