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
	char ch;   //���� 'y'��'n' �������ж�
   
	printf("��������������ӭ����ͼ��ݹ���ϵͳ���������������\n\n\n");
   
	do{  z=1;      //��z=0ʱ��������ǰϵͳ
		printf("*******************************************************************\n\n\
		 1-�鼮����ϵͳ    2-���߹���ϵͳ     3-�軹��ϵͳ    4-�˳�ϵͳ\n*******************************************************************");
     printf("\n\n������Ҫ�����ϵͳ�ı�ţ�");
	     scanf("%d",&b);

		 if(b==1)   //�����鼮����ϵͳ
		 {  printf("\n�������鼮����ϵͳ���룺");
 	         scanf("%s",key3);
			 if(strcmp(key1,key3)==0)

			do{
	              printf("\n**********************************\n");
	              printf("1-¼������ͼ����Ϣ\n2-����ͼ����Ϣ\n3-����ͼ����Ϣ\n4-��ѯͼ����Ϣ\n5-ɾ��ͼ����Ϣ\n6-�޸�ͼ����Ϣ\n7-���ͼ����Ϣ\n8-�˳�\n");
	              printf("**********************************\n");
	              printf("�밴��ѡ��");
	              scanf("%d",&a);
				  if(a==8)        //�˳�ʱ��ʾ�Ƿ���Ҫ���޸Ľ��б���
				  {
					  if(saveflag==1)
					  {
						  printf("\n�Ƿ�Ҫ�����鼮��Ϣ����Y���棬��N������\n");
						  getchar();
						  scanf("%c",&ch);
						  if(ch=='y'||ch=='Y')
							  savebok(head1);
						  
					  }
				       printf("\n������ϣ��˳��鼮����ϵͳ��\n\n");
						  break;
				  }
	          switch(a)
			  {
	                  case 1:inputbok();break;       //¼������ͼ����Ϣ
					  case 2:head1=readbok();break;     //����ͼ����Ϣ
		              case 3:savebok(head1);break;          //����ͼ����Ϣ
		              case 4:searchbok(head1);break;        //��ѯͼ����Ϣ
		              case 5:deletebok(head1);break;        //ɾ��ͼ����Ϣ
	                  case 6:changebok(head1);break;        //�޸�ͼ����Ϣ
		              case 7:outbok(head1);break;           //���ͼ����Ϣ
                     
	                 default:printf("����������������룡\n");break;
			  }
			}while(z);
			else printf("����������󣡣�\n");
		 }




		else if(b==2)       //������߹���ϵͳ
		{
	       printf("��������߹���ϵͳ���룺");
 	         scanf("%s",key3);
			 if(strcmp(key2,key3)==0)
			do{
	              printf("\n**********************************\n");
	              printf("1-¼�����Ӷ�����Ϣ\n2-���ض�����Ϣ\n3-���������Ϣ\n4-��ѯ������Ϣ\n5-ɾ��������Ϣ\n6-���������Ϣ\n7-�˳�\n");
	              printf("**********************************\n");
	              printf("�밴��ѡ��");
	              scanf("%d",&a);
				  if(a==7)
				  {
					  if(saveflag==1)
					  {
						  printf("�Ƿ�Ҫ���������Ϣ����Y���棬��N������\n");
						
						  scanf("%c",&ch);
                          getchar();
						  if(ch=='y'||ch=='Y')
							  savereader(head2);
						  
					  }
				       printf("������ϣ��˳����߹���ϵͳ��\n\n");      
						  break;
				  }
	         switch(a)
			 {
	              case 1:inputreader();break;          //¼�����Ӷ�����Ϣ
		          case 2:head2=readreader();break;       //���ض�����Ϣ
				  case 3:savereader(head2);break;        //���������Ϣ
				  case 4:searchreader(head2);break;      //��ѯ������Ϣ
	              case 5:deletereader(head2);break;      //ɾ��������Ϣ
	              case 6:outreader(head2);break;          //���������Ϣ
		          default:printf("����������������룡\n");break;
			 }
			}while(z);
				else printf("����������󣡣�\n");
		}
       else if(b==3)      //����軹��ϵͳ
	   {
	       
		   head1=readbok();
		   head2=readreader();

			do{
	              printf("\n**********************************\n");
	              printf("1-���ͼ����Ϣ\n2-��ѯͼ����Ϣ\n3-����ͼ��\n4-����\n5-������Ϣ��ѯ\n6-�˳�\n");
	              printf("**********************************\n");
	              printf("�밴��ѡ��");
	              scanf("%d",&a);
			if(a==6)
			{
                   savereader(head2);   //�˳�ϵͳǰ��������Ϣ����
				 printf("������ϣ��˳��鼮����ϵͳ��\n");
				 break;
			}
	         switch(a)
			 {
			      case 1:outbok(head1);break;         //���ͼ����Ϣ
		          case 2:searchbok(head1);break;       //��ѯͼ����Ϣ
	              case 3:bor_bok(head2,head1);break;    //����ͼ��
	              case 4:ret_bok(head2,head1);break;    //����
				  case 5:outreader(head2);break;        //������Ϣ��ѯ
				  
	              default:printf("����������������룡\n");break;
			 }
			}while(z);
		}
	   else if(b==4)
        exit(0);
	}while(1);
	    
}

	return 0;
}

void main_menu()  //���˵�
{
	load();
	head1=readbok();
	Book *head1=NULL;
	while (1)
	{
	
		printf("+----------------------Welcome to the library!-----------------------+\n");
		printf("\n");
		printf("Please choose by entering the number before the option��\n");
		printf("1��Users registe\n");
		printf("2��Users log in\n");
		printf("3��Administrators log in\n");
		printf("0��Exit the system\n");
		printf("+---------------------------------------------+\n");
		int op; scanf("%d", &op); system("cls");
		switch (op)
		{
		case 1: user_register(); break;
		case 2: user_login();  break;
		case 3: admin_login();  break;
		case 0:printf("Exiting system......\n");
		       break;
	        
		default: printf("Wrong number,please enter again��\n"); system("pause"); system("cls"); break;
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
			printf("Loading fail��\n"); exit(0);
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
void loadbook()  //���ļ��м�������
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


void creat_user_list(char* userid, char* password, char* username)  //�����û�����
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

void user_register()  //�û�ע��
{
	char userid[20];
	printf("Please input your ID(1-15 number)��\n");
	scanf("%s", userid);
	User* account;
	if (account = serch_username(userid), account != NULL)
	{
		printf("The user ID already exists, please re-enter��\n");
		system("pause"); system("cls"); return;
	}
	printf("Please enter your password(1-20 letter or number)��\n");
	char password[30];
	scanf("%s", password);
	printf("Please input your username(1-25 letter)��\n");
	char username[30];
	scanf("%s", username);
	creat_user_list(userid, password, username);
	printf("Congratulations on your successful registration��\n");

	system("pause"); system("cls");
}

User* serch_username(char* userid)  //�����û���
{
	User* p = user_head->next;
	while (p)
	{
		if (!strcmp(p->user_id, userid)) return p;
		p = p->next;
	}
	return NULL;
}

void user_login()  //�û���¼
{
	char uid[30];
	printf("Please input your user ID��\n");
	scanf("%s", uid);
	User* account;
	if (account = serch_username(uid), account == NULL)
	{
		printf("The user name does not exist, please register!\n");
		system("pause"); system("cls"); return;
	}
	char key[30];
	printf("Please enter your password��\n");
	scanf("%s",key);
	if (strcmp(account->password, key))
	{
		printf("Password is wrong,please check and login again��\n");
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

void save()  //�������ݵ��ļ�
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
void admin_initi()  //����Ա�˺ų�ʼ��
{
	FILE* fp = fopen("user.bin", "wb");
	if (fp == NULL)
	{
		printf("Fail��\n"); exit(0);
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
void admin_login()  //����Ա��½
{
	char name[30];
	
	printf("Please input system ID��\n");
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
	printf("Please input system password��\n");
	scanf("%s", name);
	if (strcmp(account->password, name))
	{
		printf("Password is wrong,please check and login again��\n");
		system("pause"); system("cls"); return;
	}
	printf("Congratulations on your successful login\n");
	system("pause"); system("cls");
	admmain();
	
}

void admin_menu(Book *head1)  //����Ա�˵�
{   int a;
	while (1)
	{
		printf("\n**********************************\n");
	              printf("1-¼������ͼ����Ϣ\n2-����ͼ����Ϣ\n3-����ͼ����Ϣ\n4-��ѯͼ����Ϣ\n5-ɾ��ͼ����Ϣ\n6-�޸�ͼ����Ϣ\n7-���ͼ����Ϣ\n8-�˳�\n");
	              printf("**********************************\n");
	              printf("�밴��ѡ��");
	              scanf("%d",&a);
				  if(a==8)        //�˳�ʱ��ʾ�Ƿ���Ҫ���޸Ľ��б���
				  {
					  if(flag==1)
					  {
						  printf("\n�Ƿ�Ҫ�����鼮��Ϣ����Y���棬��N������\n");
						  getchar();
						  scanf("%c",&ch);
						  if(ch=='y'||ch=='Y')
							  store_book(head1);
						  
					  }
				       printf("\n������ϣ��˳��鼮����ϵͳ��\n\n");
						  break;
				  }
	          switch(a)
			  {
	                  case 1:add_book();break;       //¼������ͼ����Ϣ
					  case 2:searchbook(head1);break;        //��ѯͼ����Ϣ
		              case 3:deletebook(head1);break;        //ɾ��ͼ����Ϣ
	                       //�޸�ͼ����Ϣ
		              case 4:outbok(head1);break;           //���ͼ����Ϣ
		              case 5:store_book(head1);break;          //����ͼ����Ϣ
		              
	                 default:printf("����������������룡\n");break;
		printf("*************************************************\n");
	          }
}


void add_book()     
{FILE*fp;
Book s;

	if((fp=fopen("book.txt","ab+"))==NULL)
	{
		printf("�ļ��򿪴���\n");
	
		return ;
	}

	do{
		printf("�������鼮���,������0ʱֹͣ����\n");
			scanf("%d",&s.id);
			if(s.id!=0)
			{printf("����������������\n");
	           scanf("%s",s.title);
	         printf("������������������\n");
	           scanf("%s",s.authors);
	         printf("���������ĳ���ʱ�䣺\n");
	           scanf("%s",s.year);
	         printf("���������Ŀ��������\n");
	           scanf("%d",&s.copies);
	        
			   s.next=NULL;
			fwrite(&s,sizeof(Book),1,fp);     //���鼮��Ϣһ��һ���д���ļ�����
			}
			else
			{	printf("���������\n");
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
	{printf("���ļ�ʧ�ܣ�\n");
	return;
	}
	p=head->next;        //��ǰ�б�����������д���ڴ�
	while(p)
	{fwrite(p,sizeof(Book),1,fp);      //ÿ��дһ���ڵ����Ϣ���ļ�
	p=p->next;
	}
	printf("�ļ�����ɹ���\n");
	fclose(fp);
}


struct book* readbook()
{
	FILE*fp;
    Book*bh;   //ָ����е�һ���ָ��
    Book*bl;    // ָ�����һ����ָ��
    Book*p;     //����ָ��
    char filename[20];
	bh=(Book*)malloc(sizeof(Book));
	bh->next=NULL;
	bl=bh;
	fp=fopen("book.txt","rb");
	if(fp==NULL)     //�Զ��ķ�ʽ���ļ�
	{
		printf("�ļ��򿪴���\n");
		
		return NULL;
	}
	while(!feof(fp))           //���ļ��ж�ȡ�鼮��Ϣ���ŵ������д��
	{
		p=(Book*)malloc(sizeof(Book));
		if(fread(p,sizeof(Book),1,fp)==1)
		{
			p->next=NULL;
			bl->next=p;
			bl=p;
		}
	
	}
	printf("�ļ����سɹ���\n");
	fclose(fp);
	return bh;       //���ض��������ݿ��ļ���ָ��
}

struct Book*searchbook(struct Book*head)
{
	int a;
	Book*p,*r=NULL;
	char str[20];
	if(!head->next)
	{
		printf("û���鼮��Ϣ��\n");
        getchar();
		return NULL;
	}

	printf("��ѡ���ѯ��ʽ��1-������    2-������   3-�����浥λ    4-������ʱ��\n");
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
		printf("��������浥λ��\n");
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
		printf("������������\n");
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
 	printf("���������ߣ�\n");
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
 		printf("���������ʱ�䣺\n");
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
		
	printf("û���鼮��Ϣ��");
	return NULL;
	}
	
	printf("�밴��ѡ��1-���鼮���ɾ����Ϣ   2-������ɾ����Ϣ\n");
	scanf("%d",&a);
	if(a==1)
	{
		printf("�������鼮��ţ�\n");
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
			   r->next=p->next;       //��p��ָ����������ɾȥ
			   flag=1;
			   free(p);                 //�ͷ��ڴ�ռ�
			   printf("\n�鼮ɾ���ɹ���\n");
			}
		}
		else
			printf("\nδ�ҵ����飡\n");
	}
	else if(a==2)
	{
		printf("������������\n");
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
			r->next=p->next;        //��p��ָ����������ɾȥ
			flag=1;
			free(p);          //�ͷ��ڴ�ռ�
			printf("\n�鼮ɾ���ɹ���\n");
			}
		}
		else
			printf("\nδ�ҵ����飡\n");
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
	printf("\n��������Ľ��ĺ�,����0ʱֹͣ����\n");
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
		printf("\n��������Ҫ����鼮���,����0ʱֹͣ����\n");
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
			     	printf("�����ѱ����꣡\n");
			    if(p->hav_bou>4)
				{	  printf("���ѽ����ı��飬�����ٽ裡\n");
	                  return ;	
				}
		   }
	     	
		
	  }

		}
	  
	}
	p=head1->next;
	if((fp=fopen("borrow.dat","wb"))==NULL)
	{printf("���ļ�ʧ�ܣ�\n");
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
	printf("��������Ľ��ĺţ�\n");
	scanf("%d",&num);   
	p=head1->next;
	while(p&&p->user_id!=num)
		p=p->next;
	if(p)
	{
		while(p->hav_bou)
		{
			printf("������Ҫ�����鼮��ţ�\n");
			scanf("%d",&num); 
			getchar();   //���ջس���
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
				printf("�Ƿ�Ҫ�������飿��Y��������N����\n");
	                c=getchar();   
	                    if(c=='n')
	                   	break;
		}
	}
	printf("��������\n");
	return;
}

void outbok(struct Book* head)
{
	Book*p;
	if(head==NULL)
	{
		printf("�鼮�ѱ����꣬û���鼮��Ϣ��");
	    return;
	}
	p=head->next;
	if(!p)
	{
       printf("û���鼮��Ϣ��");   
	}
	printf("\n�鼮���      ����     ������   �����  ���浥λ   ����ʱ��   �������   �۸�\n");
	  do
		{
			printf("%-10d%-14s%-10s%-6s%-14s%-10s%-8d%-5.2f\n",p->id,p->title,p->authors,p->year,p->copies);
			p=p->next;
		}while(p!=NULL);
		return;

}

