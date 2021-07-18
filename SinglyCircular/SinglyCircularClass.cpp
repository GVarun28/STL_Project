/*
SinglyCircularClass.cpp
*/
#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	char key;
	struct Node *Next;
};

template <class T>
class tempSinglyC
{
private:
		int iSize;
		struct Node<T> *Head;
		struct Node<T> *Tail;		
		
public:
		tempSinglyC();
		~tempSinglyC();
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
//FUNCTION DEFINITIONS BELOW :

/////////////////////////////////////////////
//Constructor + Destructor 
template <class T>
tempSinglyC<T>::tempSinglyC()
{	
	iSize=0;
	Head=NULL;
	Tail=NULL;
cout<<"\n\t\t### Object Created ###";
}
template <class T>
tempSinglyC<T>::~tempSinglyC()
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
cout<<"\n\t\t### Object Deleted ###";
}

//////////////////////////////////////
//Functions to Display List and get Count of Nodes :
//Date :26-05-2021 
//
template <class T>
bool tempSinglyC<T>::showList()
{
if(iSize==0)
	return false;
struct Node<T>* Temp=Head;
int s=iSize;
while(s!=0)
{
	cout<<(Temp->data)<<"|"<<(Temp->key)<<"|->";
	Temp=Temp->Next;
s--;	
}
cout<<"(back to Head)\n";
return true;
}
template <class T>
int tempSinglyC<T>::Count()
{
	return iSize;
}
/////////////////////////////////////////////////////
// Occurance Functions :
// Date : 26-05-2021

template <class T>
int tempSinglyC<T>::FirstOccurance(int no)
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
int tempSinglyC<T>::LastOccurance(int no)
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
return c;	
}
////////////////////////////////////////////////
//Insert Node Functions:
//Date :26-05-2021 
//
template <class T>
bool tempSinglyC<T>::InsertFirst(T no,char k)
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
iSize++; Tail->Next=Head;
return true;
}
template <class T>
bool tempSinglyC<T>::InsertLast(T no,char k)
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
iSize++; Tail->Next=Head;
return true;
}
template <class T>
int tempSinglyC<T>::InsertAtPosition(T no,char k,int iPos)
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
iSize++; Tail->Next=Head;
}
return 0;
}
//////////////////////////////////////////////////
//Delete Node Functions below :
//Date :26-05-2021 
template <class T>
bool tempSinglyC<T>::DeleteFirst()
{
if(iSize==0)
{ return false; }

Head=(Head->Next);
delete (Tail->Next);
iSize--;
Tail->Next=Head;
return true;
}
template <class T>
bool tempSinglyC<T>::DeleteLast()
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

iSize--; Tail->Next=Head;
return true;	
}
template <class T>
bool tempSinglyC<T>::DeleteAtPosition(int iPos)
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
//Date :26-05-2021 

int main()
{
	
	
return 0;
}


