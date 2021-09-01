#include <iostream>
#include <string.h>
using namespace std;
class node
{
friend class list;
int prnno;
char name[30];
node *next;
public:
node(int d,char s[10])
{
prnno=d;
strcpy(name,s);
next=NULL;
}
};
class list
{
node *start;
public:
list()
{
start=NULL;
}
void disp()
{
node *ptr;
ptr=start;
cout<<"\n Info : \n";
while(ptr!=NULL)
{
cout<<"\n"<<ptr->prnno;
cout<<"\t"<<ptr->name;
ptr=ptr->next;
}
}
void insertmem();
void createmem();
void insertpres();
void insertsec();
void deletemem();
void delete1();
void deletesec();
void deletepres();
void count();
void reverse(node *);
void reverse1()
{
reverse(start);
}
void con(list,list);
};
void list::insertmem()
{
int prnno;
char name[30];
node *ptr,*temp;
cout<<"\n Enter PRN : ";
cin>>prnno;
cout<<"\n Enter Name : ";
cin>>name;
temp=new node(prnno,name);
if(start==NULL)
{
start=temp;
}
else
{
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}
}
void list::insertpres()
{
int prnno;
char name[30];
node *temp;
cout<<"\n Enter PRN : ";
cin>>prnno;
cout<<"\n Enter Name : ";
cin>>name;
temp=new node(prnno,name);
temp->next=start;
start=temp;
}
void list::insertsec()
{
int prnno;
char name[30];
node *ptr,*temp;
cout<<"\n Enter PRN : ";
cin>>prnno;
cout<<"\n Enter Name : ";
cin>>name;
temp=new node(prnno,name);
ptr=start;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
}
void list::createmem()
{
int ch;
char ans;
do
{
cout<<"\n 1)Member\n 2)Secretary\n 3)President";
cout<<"\n Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1: insertmem();
break;
case 2: insertsec();
break;
case 3: insertpres();
break;
default:cout<<"Invalid choice ! ";
break;
}
cout<<"\n Insert more members(y/n)?";
cin>>ans;
}while(ans=='y');
}
void list::delete1()
{
int ch;
char ans;
do
{
cout<<"\n 1)Member\n 2)Secretary\n 3)President";
cout<<"\n Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1:deletemem();
break;
case 2:deletesec();
break;
case 3:deletepres();
break;
default:cout<<"Invalid choice ! ";
break;
}
cout<<"\n Delete more members?(y/n)";
cin>>ans;
}while(ans=='y');
}
void list::deletesec()
{
node *ptr,*prev;
ptr=start;
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
}
prev->next=NULL;
delete ptr;
cout<<"\n Deleted";
}
void list::deletepres()
{
node *ptr;
ptr=start;
start=start->next;
delete ptr;
cout<<"\n Deleted";
}
void list::deletemem()
{
node *ptr,*prev;
int p;
cout<<"\n Enter PRN to delete member : ";
cin>>p;
ptr=start;
while(ptr->next!=NULL)
{
prev=ptr;
ptr=ptr->next;
if(ptr->prnno==p)
break;
}
if(ptr->next==NULL)
{
cout<<"\n Member not found !";
}
else if(ptr->prnno==p)
{
prev->next=ptr->next;
ptr->next=NULL;
delete ptr;
cout<<"\n Deleted";
}
}
void list::count()
{
node *ptr;
int cnt=0;
ptr=start;
while(ptr!=NULL)
{
cnt++;
ptr=ptr->next;
}
cout<<"\n Total no. of nodes : "<<cnt;
}
void list::reverse(node *ptr)
{
if(ptr==NULL)
return;
else
{
reverse(ptr->next);
}
cout<<"\n"<<ptr->prnno;
cout<<"\t"<<ptr->name;
}
void list::con(list s1,list s2)
{
node *ptr;
ptr=s1.start;
while(ptr->next!=NULL)
ptr=ptr->next;
ptr->next=s2.start;
s1.disp();
}
int main()
{
int ch;
char ans;
list sll1,sll2,s1,s2;
do
{
cout<<"\n 1)Create member\n 2)Display\n 3)Delete member\n 4)No. of nodes\n 5)Reverse\n 6)Concatenate";
cout<<"\n Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1: sll1.createmem();
break;
case 2: sll1.disp();
break;
case 3: cout<<"\n Enter the nodes to be deleted in list : ";
sll1.delete1();
break;
case 4: cout<<"\n No. of nodes :";
sll1.count();
break;
case 5: cout<<"\n Reversed :";
sll1.reverse1();
break;
case 6: cout<<"Creating nodes in second list:";
sll2.createmem();
sll1.con(sll1,sll2);
break;
default: cout<<"\n Invalid choice ! ";
break;
}
cout<<"\n Do you want to continue ? ";
cin>>ans;
}while(ans=='y');
return 0;}
