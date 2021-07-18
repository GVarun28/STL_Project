/*
SinglyLinearClass.cpp
*/
#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	char key;
	struct Node* Next;	
};

template <class T>
class templateSLinear
{
private:
	int iSize;
	struct Node<T>* Head;
	struct Node<T>* Tail;

public:
	templateSLinear();
	~templateSLinear();
	bool showList();
	int Count();
	int FirstOccurance(int);
	int LastOccurance(int);	
	
	bool InsertFirst(T,char);
	bool InsertLast(T,char);	
	int InsertAtPosition(T,char,int);
	
	bool DeleteFirst();
	bool DeleteLast();	
	bool DeleteAtPosition(int);	
};
///////////////////////////////////
//Constructor and Destructor below :
//Date :26-052021
//
template <class T>
templateSLinear<T>::templateSLinear()
{
cout<<"\nInside Constructor";	
	Head=NULL; Tail=NULL; iSize=0;
}
template <class T>
templateSLinear<T>::~templateSLinear()
{
int c=iSize;
struct Node<T> *Temp=NULL;	
while(c>0)
{
Temp=Head;
Head=Head->Next;	
delete Temp;
c--;	
}
//code
}
//////////////////////////////////////
//Functions to Display List and get Count of Nodes :
//Date :25-05-2021 
//
template <class T>
bool templateSLinear<T>::showList()
{
if(iSize==0)
	return false;
struct Node<T>* Temp=Head;
while(Temp!=NULL)
{
	cout<<(Temp->data)<<"|"<<(Temp->key)<<"|->";
	Temp=Temp->Next;
}
cout<<"->NULL\n";
return true;
}
template <class T>
int templateSLinear<T>::Count()
{
	return iSize;
}
/////////////////////////////////////////////////////
// Occurance Functions :
// Date : 26-05-2021

template <class T>
int templateSLinear<T>::FirstOccurance(int no)
{
if(iSize==0)
{ return -1; }	
struct Node<T> *Temp=Head;
int c=-2;
while(c<=iSize)
{
if((Temp->data)==no)
{ break; }
Temp=Temp->Next;	
c++;	
}
return c;
}

template <class T>
int templateSLinear<T>::LastOccurance(int no)
{
if(iSize==0)
{ return -1; }
int i=1;
int c=-2;
struct Node<T> *Temp=Head;
while(i<=iSize)
{
if((Temp->data)==no)
{ c=i; }
Temp=Temp->Next;	
i++;	
}
return -2;	
}

////////////////////////////////////////////////
//Insert Node Functions:
//Date :25-05-2021 
//
template <class T>
bool templateSLinear<T>::InsertFirst(T no,char k)
{
struct Node<T> *newn=new struct Node<T>;
if(newn==NULL)
{ return false; }
newn->data=no;
newn->key=k; newn->Next=NULL;
if(iSize==0)
{
	Head=newn;	Tail=newn;
}else{
newn->Next=Head;
Head=newn;
}
iSize++;
return true;
}
template <class T>
bool templateSLinear<T>::InsertLast(T no,char k)
{
struct Node<T>* newn=new struct Node<T>;
if(newn==NULL)
{ return false; }
newn->data=no;
newn->key=k; newn->Next=NULL;
if(iSize==0)
{
	Tail=newn; Head=newn;	
}else{
Tail->Next=newn;
Tail=newn;
}
iSize++;
return true;
}
template <class T>
int templateSLinear<T>::InsertAtPosition(T no,char k,int iPos)
{
if(iPos<1 || iPos>(iSize+1))
{ return -1; }
	
if(iPos==1)
{
	InsertFirst(no,k);
}else if(iPos==iSize)
{
	InsertLast(no,k);
}else{
struct Node<T>* newn=new struct Node<T>;
if(newn==NULL)
{ return 1; }
newn->data=no;
newn->key=k;
newn->Next=NULL;
struct Node<T>* Temp=Head;
for(int i=1;i<iPos-1;i++)
{ Temp=Temp->Next; }
newn->Next=(Temp->Next);
Temp->Next=newn;
iSize++;
}
return 0;
}
//////////////////////////////////////////////////
//Delete Node Functions below :
//Date :25-05-2021 
template <class T>
bool templateSLinear<T>::DeleteFirst()
{
if(iSize==0)
{ return false; }
struct Node<T>* Temp=Head;
Head=(Head->Next);
delete Temp;
iSize--;
return true;
}
template <class T>
bool templateSLinear<T>::DeleteLast()
{
if(iSize==0)
{ return false; }
struct Node<T>* Temp=Head;
while((Temp->Next)!=Tail)
{
	Temp=Temp->Next;
}
delete Tail;
Tail=Temp;
Temp->Next=NULL;
iSize--;
return true;	
}
template <class T>
bool templateSLinear<T>::DeleteAtPosition(int iPos)
{
bool r=true;
if(iPos<1 || iPos>iSize)
{ return false; }
if(iPos==1)
{
	r=DeleteFirst();
}else if(iPos==iSize)
{
	r=DeleteLast();
}else{
struct Node<T> *Temp=Head;
for(int i=1;i<iPos-1;i++)
{ Temp=Temp->Next; }
struct Node<T> *Target=(Temp->Next);
(Temp->Next)=Target->Next;
delete Target;
iSize--;	
}
return r;
}

////////////////////////////////////////////////////
//main() below :
//Date :25-05-2021 
//
int main()
{

int iOpt=1,iListType=0,iFlag=0,iPos=0;
bool bFlag=true;
double no;
char key;
cout<<"\nInside main() :";

templateSLinear<int> L1;
delete L1;
templateSLinear<float> L1;

while(iOpt!=0)
{
       printf("\n********************************\n");
       printf("Please select the option\n");
        printf("1 : Insert the node at First position\n");
        printf("2 : Insert the node at Last position\n");
        printf("3 : Insert the node at given position\n");
        printf("4 : Delete the First node\n");
        printf("5 : Delete the Last node\n");
        printf("6 : Delete the node at given position \n");
        printf("7 : Display the contents of linked list \n");
        printf("8 : Count the nodes of linked list \n");
		printf("9 : Count the nodes of linked list \n");
		printf("10 : Count the nodes of linked list \n");
        printf("0 : Exit the application\n	");
        scanf("%d",&iOpt);
        printf("********************************\n");	
		
switch(iOpt)
{

case 1:
	cout<<"\nEnter data to Insert :";
	cin>>no;
	cout<<"\nEnter key for Node :";
	cin>>key;
	bFlag=L1.InsertFirst(no,key);
	if(bFlag==false)
		cout<<"\nFailed to Insert ";
	break;

case 2:
		cout<<"\nEnter data to Insert :";
		cin>>no;
		cout<<"\nEnter key for Node :";
		cin>>key;
		bFlag=L1.InsertLast(no,key);
		if(bFlag==false)
			cout<<"\nFailed to Insert ";
		break;

case 3:
		cout<<"\nEnter Position :";
		cin>>iPos;
		cout<<"\nEnter data to Insert :";
		cin>>no;
		cout<<"\nEnter key for Node :";
		cin>>key;
		iFlag=L1.InsertAtPosition(no,key,iPos);
		if(iFlag==-1)
			cout<<"\nInvalid Position ";
		if(iFlag==1)
			cout<<"\nFailed to Enter. ";		
		break;
case 4:
		bFlag=L1.DeleteFirst();
		if(bFlag==false)
			cout<<"\nList Already Empty. ";		
		break;
case 5:
		bFlag=L1.DeleteLast();
		if(bFlag==false)
			cout<<"\nList Already Empty. ";		
		break;
		
case 6:
		cout<<"\nEnter Position :";
		cin>>iPos;
		bFlag=L1.DeleteAtPosition(iPos);
		if(bFlag==false)
			cout<<"\nList Already Empty. ";	
		break;
case 7:
		bFlag=L1.showList();
		if(bFlag==false)
			cout<<"\nList Already Empty. ";	
		break;

case 8:
		iFlag=L1.Count();
		cout<<"\nCount of Nodes in LL :"<<iFlag;	
		break;	

case 9:
		cout<<"\nEnter No to search 1st Occurance :";
		cin>>no;
		iFlag=L1.FirstOccurance(no);
		if(iFlag==-1)
			cout<<"\nList Empty .";
		
		if(iFlag==-2)
			cout<<"\nNumber Not Present";		
		else
			cout<<"\n Number :"<<no<<"1st Occured at Position :"<<iFlag;
		break;
case 10:
		cout<<"\nEnter No to search Last Occurance :";
		cin>>no;
		iFlag=L1.LastOccurance(no);
		if(iFlag==-1)
			cout<<"\nList Empty .";
		
		if(iFlag==-2)
			cout<<"\nNumber Not Present";
		else
			cout<<"\n Number :"<<no<<"Last Occured at Position :"<<iFlag;
		break;		
		
case 0:
	cout<<"\nThank You For Using our Generic Linked List Application ";
	exit(0);
	break;

default:
		cout<<"\nInvalid Input\nTry again";
		break;

}//switch
}//while
return 0;
}

