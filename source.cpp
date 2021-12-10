#include<iostream>
#include"singlylist.h"
using namespace std;

template<class T>
sList<T> :: sList()
{
	(*this).head=NULL;
	(*this).n=0;	
}

template<class T>
bool sList<T> :: isEmpty()
{
	return(((*this).head == NULL));
}

template<class T>
int sList<T> :: sizE(){return(*this).n;}

template<class T>
node<T>* sList<T> :: findItem(const T &item)
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	node<T> *p=(*this).head;
	while((p != NULL) && (p->data != item))p=p->Next;
	if(p==NULL)cout<<"Not found item \n";
	return p;
}

template<class T>
node<T>* sList<T> :: getH()const
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	return (*this).head;
}

template<class T>
T& node<T> :: getD()const
{
	//if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	return this->data;
}

template<class T>
node<T>*  node<T> :: getN()const
{
	//if(this->isEmpty()){cout<<"Error : Empty List \n"; return NULL;}
	return this->Next;
}

template<class T>
void sList<T> :: insert(T const & item)
{
	node<T> *p=new node<T>;
	p->data=item;
	p->Next=NULL;
	(*this).n++;
	if( (*this).isEmpty() )
	{
		(*this).head=p;
		return;
	}
	
	node<T> *pre=NULL;
	node<T>*cur=(*this).head;
	while((cur != NULL) && (cur->data < item))
	{
		pre=cur;
		cur=cur->Next;
	}
	if(pre == NULL)
	{
		p->Next=(*this).head;
		(*this).head=p;
		return;
	}
	if(cur == NULL)
	{
		pre->Next=p;
		return;
	}
	if(cur && pre)
	{
		p->Next=cur;
		pre->Next=p;
		return;
	}
	//cout<<" f \n";
	return;
}

template<class T>
T sList<T> :: getFront()
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return '\0';}
	return (*this).head->data;
}

template<class T>
bool sList<T> :: removeF()
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return false;}
	node<T> *p=(*this).head;
	(*this).head=p->Next;
	p->Next=NULL;
	delete p;
	p=NULL;
	(*this).n--;
	return true;
}

template<class T>
bool sList<T> :: remove(T const &item)
{
	if(this->isEmpty()){cout<<"Error : Empty List \n"; return false;}
	node<T> *p=(*this).findItem(item);
	if(p==NULL){return false;}
	if(p == (*this).head){return (*this).removeF(); }
	node<T> *w=(*this).head;
	while((w->Next != p)){w=w->Next;}
	w->Next=p->Next;
	p->Next=NULL;
	delete p;
	p=NULL;
	(*this).n--;
	//cout<<"YAZAN\n";
	return true;
}

template<class T>
sList<T> :: ~sList()
{
	while(!(*this).isEmpty())(*this).removeF();
	(*this).head=NULL;
	(*this).n=0;
	//cout<<"thi\n";
}

template<class T>
void sList<T> :: print()
{
	node<nodeN> *p=(*this).head;
	while(p!=NULL)
	{
		(*p).data.printNode();
		cout<<"********************\n";
		p=p->Next;
	}
	//cout<<" yazan \n";

}

