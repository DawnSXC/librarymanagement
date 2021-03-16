#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "book_management.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 main_menu();
	 

	Book *head1=NULL;
	
	int a,b,z;
	char ch;   //接收 'y'或'n' ，作出判断
   
	printf("☆☆☆☆☆☆☆☆☆☆☆☆☆☆欢迎进入图书馆管理系统☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n\n\n");
   
	do{  z=1;      //当z=0时，跳出当前系统
		printf("*******************************************************************\n\n\
		 1-书籍管理系统    2-读者管理系统     3-借还书系统    4-退出系统\n*******************************************************************");
     printf("\n\n请输入要进入的系统的编号：");
	     scanf("%d",&b);

		 if(b==1)   //进入书籍管理系统
		 {  printf("\n请输入书籍管理系统密码：");
 	         scanf("%s",key3);
			 if(strcmp(key1,key3)==0)

			do{
	              printf("\n**********************************\n");
	              printf("1-录入或添加图书信息\n2-加载图书信息\n3-保存图书信息\n4-查询图书信息\n5-删除图书信息\n6-修改图书信息\n7-浏览图书信息\n8-退出\n");
	              printf("**********************************\n");
	              printf("请按键选择：");
	              scanf("%d",&a);
				  if(a==8)        //退出时提示是否需要对修改进行保存
				  {
					  if(saveflag==1)
					  {
						  printf("\n是否要保存书籍信息？按Y保存，按N不保存\n");
						  getchar();
						  scanf("%c",&ch);
						  if(ch=='y'||ch=='Y')
							  savebok(head1);
						  
					  }
				       printf("\n保存完毕！退出书籍管理系统。\n\n");
						  break;
				  }
	          switch(a)
			  {
	                  case 1:inputbok();break;       //录入或添加图书信息
					  case 2:head1=readbok();break;     //加载图书信息
		              case 3:savebok(head1);break;          //保存图书信息
		              case 4:searchbok(head1);break;        //查询图书信息
		              case 5:deletebok(head1);break;        //删除图书信息
	                  case 6:changebok(head1);break;        //修改图书信息
		              case 7:outbok(head1);break;           //浏览图书信息
                     
	                 default:printf("输入错误，请重新输入！\n");break;
			  }
			}while(z);
			else printf("密码输入错误！！\n");
		 }




		else if(b==2)       //进入读者管理系统
		{
	       printf("请输入读者管理系统密码：");
 	         scanf("%s",key3);
			 if(strcmp(key2,key3)==0)
			do{
	              printf("\n**********************************\n");
	              printf("1-录入或添加读者信息\n2-加载读者信息\n3-保存读者信息\n4-查询读者信息\n5-删除读者信息\n6-浏览读者信息\n7-退出\n");
	              printf("**********************************\n");
	              printf("请按键选择：");
	              scanf("%d",&a);
				  if(a==7)
				  {
					  if(saveflag==1)
					  {
						  printf("是否要保存读者信息？按Y保存，按N不保存\n");
						
						  scanf("%c",&ch);
                          getchar();
						  if(ch=='y'||ch=='Y')
							  savereader(head2);
						  
					  }
				       printf("保存完毕！退出读者管理系统。\n\n");      
						  break;
				  }
	         switch(a)
			 {
	              case 1:inputreader();break;          //录入或添加读者信息
		          case 2:head2=readreader();break;       //加载读者信息
				  case 3:savereader(head2);break;        //保存读者信息
				  case 4:searchreader(head2);break;      //查询读者信息
	              case 5:deletereader(head2);break;      //删除读者信息
	              case 6:outreader(head2);break;          //浏览读者信息
		          default:printf("输入错误，请重新输入！\n");break;
			 }
			}while(z);
				else printf("密码输入错误！！\n");
		}
       else if(b==3)      //进入借还书系统
	   {
	       
		   head1=readbok();
		   head2=readreader();

			do{
	              printf("\n**********************************\n");
	              printf("1-浏览图书信息\n2-查询图书信息\n3-借阅图书\n4-还书\n5-借阅信息查询\n6-退出\n");
	              printf("**********************************\n");
	              printf("请按键选择：");
	              scanf("%d",&a);
			if(a==6)
			{
                   savereader(head2);   //退出系统前将借阅信息保存
				 printf("保存完毕！退出书籍管理系统。\n");
				 break;
			}
	         switch(a)
			 {
			      case 1:outbok(head1);break;         //浏览图书信息
		          case 2:searchbok(head1);break;       //查询图书信息
	              case 3:bor_bok(head2,head1);break;    //借阅图书
	              case 4:ret_bok(head2,head1);break;    //还书
				  case 5:outreader(head2);break;        //借阅信息查询
				  
	              default:printf("输入错误，请重新输入！\n");break;
			 }
			}while(z);
		}
	   else if(b==4)
        exit(0);
	}while(1);
	    
}

	return 0;
}

void main_menu()  //主菜单
{
	load();
	head1=readbok();
	Book *head1=NULL;
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
/*
int load_books(FILE *file){
	FILE* fp2;
	fp2 = fopen("book.bin", "rb");
	if (fp2 == NULL)
	{
		fp2 = fopen("book.bin", "wb");
		if (fp2 == NULL)
		{
			printf("Loading fail！\n"); exit(0);
		}
		fclose(fp2);
		return 0;
	}
	else loadbook();
}
int store_books(FILE *file){
	FILE* fp = fopen("book.bin","wb");
	void savebook();
	return 1;
	
}
void loadbook()  //从文件中加载数据
{   array = (Book*)malloc(sizeof(Book));
	array->next = NULL;
	int length = 0;

	
		Book* bp = (Book*)malloc(sizeof(Book));
		bp = array;
		Book* tp = (Book*)malloc(sizeof(Book));
		FILE* fp2;
	    fp2 = fopen("book.bin", "rb");
		while (fread(tp, sizeof(Book), 1, fp2))
		{
			bp->next = tp;
			++length;
			tp = tp->next;
			tp = (Book*)malloc(sizeof(Book));
			bp = bp->next;
		}
		fclose(fp2);
	

}*/


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


void load(){

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
}


/*void savebook(){
	FILE* fp = fopen("book.bin", "wb");
	Book* tb = array->next;
	while (tb)
	{
		fwrite(tb, sizeof(Book), 1, fp);
		tb = tb->next;
	}
	fclose(fp);
	
}*/
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
	admmain();
	
}

void admin_menu(Book *head1)  //管理员菜单
{   int a;
	while (1)
	{
		printf("\n**********************************\n");
	              printf("1-录入或添加图书信息\n2-加载图书信息\n3-保存图书信息\n4-查询图书信息\n5-删除图书信息\n6-修改图书信息\n7-浏览图书信息\n8-退出\n");
	              printf("**********************************\n");
	              printf("请按键选择：");
	              scanf("%d",&a);
				  if(a==8)        //退出时提示是否需要对修改进行保存
				  {
					  if(flag==1)
					  {
						  printf("\n是否要保存书籍信息？按Y保存，按N不保存\n");
						  getchar();
						  scanf("%c",&ch);
						  if(ch=='y'||ch=='Y')
							  store_book(head1);
						  
					  }
				       printf("\n保存完毕！退出书籍管理系统。\n\n");
						  break;
				  }
	          switch(a)
			  {
	                  case 1:add_book();break;       //录入或添加图书信息
					  case 2:searchbook(head1);break;        //查询图书信息
		              case 3:deletebook(head1);break;        //删除图书信息
	                       //修改图书信息
		              case 4:outbok(head1);break;           //浏览图书信息
		              case 5:store_book(head1);break;          //保存图书信息
		              
	                 default:printf("输入错误，请重新输入！\n");break;
		printf("*************************************************\n");
	          }
}


void add_book()     
{FILE*fp;
Book s;

	if((fp=fopen("book.txt","ab+"))==NULL)
	{
		printf("文件打开错误！\n");
	
		return ;
	}

	do{
		printf("请输入书籍编号,当输入0时停止输入\n");
			scanf("%d",&s.id);
			if(s.id!=0)
			{printf("请输入该书的书名：\n");
	           scanf("%s",s.title);
	         printf("请输入该书的作者名：\n");
	           scanf("%s",s.authors);
	         printf("请输入该书的出版时间：\n");
	           scanf("%s",s.year);
	         printf("请输入该书的库存数量：\n");
	           scanf("%d",&s.copies);
	        
			   s.next=NULL;
			fwrite(&s,sizeof(Book),1,fp);     //将书籍信息一组一组地写入文件当中
			}
			else
			{	printf("输入结束！\n");
			         break;}
	}while(1);
	flag=1;
	fclose(fp);

}


void store_book(struct Book*head)
{	FILE*fp;
	Book*p;
	fp=fopen("book.txt","wb");
	if(fp==NULL)
	{printf("打开文件失败！\n");
	return;
	}
	p=head->next;        //当前列表中所有数据写入内存
	while(p)
	{fwrite(p,sizeof(Book),1,fp);      //每次写一个节点的信息至文件
	p=p->next;
	}
	printf("文件保存成功！\n");
	fclose(fp);
}


struct book* readbook()
{
	FILE*fp;
    Book*bh;   //指向表中第一项的指针
    Book*bl;    // 指向最后一个的指针
    Book*p;     //工作指针
    char filename[20];
	bh=(Book*)malloc(sizeof(Book));
	bh->next=NULL;
	bl=bh;
	fp=fopen("book.txt","rb");
	if(fp==NULL)     //以读的方式打开文件
	{
		printf("文件打开错误！\n");
		
		return NULL;
	}
	while(!feof(fp))           //从文件中读取书籍信息，放到链表中存放
	{
		p=(Book*)malloc(sizeof(Book));
		if(fread(p,sizeof(Book),1,fp)==1)
		{
			p->next=NULL;
			bl->next=p;
			bl=p;
		}
	
	}
	printf("文件加载成功！\n");
	fclose(fp);
	return bh;       //返回读出的数据库文件的指针
}

struct Book*searchbook(struct Book*head)
{
	int a;
	Book*p,*r=NULL;
	char str[20];
	if(!head->next)
	{
		printf("没有书籍信息！\n");
        getchar();
		return NULL;
	}

	printf("请选择查询方式：1-按书名    2-按作者   3-按出版单位    4-按出版时间\n");
	scanf("%d",&a);
	if(a==1)
	{
		find_book_by_title ();
	}

	else if(a==2)
	{
		find_book_by_author ();
	}

	else if(a==3)
	{
		printf("请输入出版单位：\n");
		scanf("%s",str);
		p=head->next;
		while(p)
		{
			if(strcmp(p->off_name,str)==0)
			{
				if(r==NULL)
					r=p;
					printf("%-10d%-14s%-10s%-6s%-14s%-10s%-8d%-5.2f\n",
					p->num1,p->bok_name,p->wrt_name,p->num2,p->off_name,p->time,p->count,p->price);
				
			}
			p=p->next;
		}
		getchar();
		return r;
	}

	else if(a==4)
	{
		find_book_by_year ();
	}
	getchar();
	return NULL;
}

Book find_book_by_title (){
		printf("请输入书名：\n");
		scanf("%s",str);
		p=head->next;
		while(p)
		{
			if(strcmp(p->title,str)==0)
			{
				if(r==NULL)
					r=p;
					printf("%-10d%-14s%-10s%-6d%-6d%\n",p->id,p->title,p->authors,p->year,p->copies);
				
			}
			p=p->next;
		}
		getchar();
		return r;
}
Book find_book_by_author (){
 	printf("请输入作者：\n");
		scanf("%s",str);
		p=head->next;
		while(p)
		{
			if(strcmp(p->authors,str)==0)
			{
				if(r==NULL)
					r=p;
					printf("%-10d%-14s%-10s%-6d%-10d%\n",p->id,p->titlle,p->authors,p->year,p->copies);
				
			}
			p=p->next;
		}
		getchar();
		return r;
 	
 }
 Book find_book_by_year (){ 
 		printf("请输入出版时间：\n");
		scanf("%s",str);
		p=head->next;
		while(p)
		{
			if(strcmp(p->year,str)==0)
			{
				if(r==NULL)
					r=p;
					printf("%-10d%-14s%-10s%-6d%-14d%\n", p->id,p->title,p->authors,p->year,p->copies);
				
			}
			p=p->next;
		}
		getchar();
		return r;
 }

 struct Book*deletebook(struct Book*head)
{
	int a;
	int num;
	Book*p,*r;
	char bname[20];
    if(!head->next)
	{
		
	printf("没有书籍信息！");
	return NULL;
	}
	
	printf("请按键选择：1-按书籍编号删除信息   2-按书名删除信息\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("请输入书籍编号：\n");
		scanf("%d",&num);
		p=head->next;
		while(p&&p->id!=num)
		{r=p;
		p=p->next;
		}
		if(p->id==num)
		{
			if(p==head)
			head=p->next;
	        else
			{
			   r->next=p->next;       //将p所指结点从链表中删去
			   flag=1;
			   free(p);                 //释放内存空间
			   printf("\n书籍删除成功！\n");
			}
		}
		else
			printf("\n未找到此书！\n");
	}
	else if(a==2)
	{
		printf("请输入书名：\n");
		scanf("%s",bname);
		p=head->next;
		while(p&&strcmp(p->title,bname)!=0)
		{r=p;
		p=p->next;
		}
		if(strcmp(p->title,bname)==0)
		{
			if(p==head)
			head=p->next;
	        else
			{
			r->next=p->next;        //将p所指结点从链表中删去
			flag=1;
			free(p);          //释放内存空间
			printf("\n书籍删除成功！\n");
			}
		}
		else
			printf("\n未找到此书！\n");
	}
	getchar();
	flag=1;
	return head;
}

void borrowbook(struct Student*head1,struct Book*head)
{
	FILE *fp;
	User *p;
	Book *q;
	int n1,n2;
	//char fn[20];
	printf("\n请输入你的借阅号,输入0时停止借书\n");
	scanf("%d",&n1);
	while(n1!=0)
	{   int times;
		p=head1->next;
	while(p&&p->user_id!=n1)
		p=p->next;
	  if(p)
	  { printf("How many books will you borrow?\n");
	    scanf("%d",&times);
	    for(int i= 0,i<times;i++){	
		printf("\n请输入你要借的书籍编号,输入0时停止借书\n");
		scanf("%d",&n2);
	
			q=head->next;
		while(q&&q->id!=n2)
			q=q->next;
		
	       if(q)
		   {
			    if(q->copies!=0)
				{
				  p->lend[p->hav_bou++]=*q;
				    q->copies--;
				    printf("Borrow book successfully!")
				}
			    else
			     	printf("此书已被借完！\n");
			    if(p->hav_bou>4)
				{	  printf("你已借满四本书，不可再借！\n");
	                  return ;	
				}
		   }
	     	
		
	  }

		}
	  
	}
	p=head1->next;
	if((fp=fopen("borrow.dat","wb"))==NULL)
	{printf("打开文件失败！\n");
	return;
	}
	while(p)
	{
		fwrite(p,sizeof(User),1,fp);
			p=p->next;
	}
	fclose(fp);*/
}



void returnbook(struct Student*head1,struct Book*head2)
{
	User*p;
	Book*q;
	int num,i;
	char c;
	printf("请输入你的借阅号：\n");
	scanf("%d",&num);   
	p=head1->next;
	while(p&&p->user_id!=num)
		p=p->next;
	if(p)
	{
		while(p->hav_bou)
		{
			printf("请输入要还的书籍编号：\n");
			scanf("%d",&num); 
			getchar();   //接收回车符
			q=head2->next;
			while(q&&q->id!=num)
				q=q->next;
			q->copies++;
			p->hav_bou--;
			for(i=0;i<4;i++)
				if(q->id==p->lend[i].num1)
				{
					p->lend[i]=p->lend[i+1];
			
				}
				printf("是否要继续还书？按Y继续，按N返回\n");
	                c=getchar();   
	                    if(c=='n')
	                   	break;
		}
	}
	printf("结束还书\n");
	return;
}

void outbok(struct Book* head)
{
	Book*p;
	if(head==NULL)
	{
		printf("书籍已被借完，没有书籍信息！");
	    return;
	}
	p=head->next;
	if(!p)
	{
       printf("没有书籍信息！");   
	}
	printf("\n书籍编号      书名     作者名   分类号  出版单位   出版时间   库存数量   价格\n");
	  do
		{
			printf("%-10d%-14s%-10s%-6s%-14s%-10s%-8d%-5.2f\n",p->id,p->title,p->authors,p->year,p->copies);
			p=p->next;
		}while(p!=NULL);
		return;

}

