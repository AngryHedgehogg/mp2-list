#include "list.h"


List::List(const List& list2)
{
	if(list2.head!=NULL)
	{
		head= new Node(list2.head->data,list2.head->next);
		Node* tmp=head;
		while(tmp->next!=NULL)
		{
			tmp->next= new Node(tmp->data, tmp->next);
			tmp=tmp->next;
		}
	}
};



List& List::operator=(const List& list2)
{
	if (list2.head != NULL)
	   head = list2.head;
	else throw "error";
	return*this;
};



 void List::InserToHead(const DataType& d) // вставить элемент d первым
 {
 Node *tmp;
 tmp=new Node(d,head->next);
 head = tmp;
 };


void List::InserToTail(const DataType& d) // вставить элемент d последним
{
  Node *tmp;
  tmp=head;
  if(tmp==NULL)
	head=new Node(d,NULL);
  else
  {
	  while (tmp->next != NULL)
	  {
		  tmp = tmp->next;
	  }
	  tmp->next = new Node(d, NULL);
  }
};


void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
{
Node* tmp;
tmp=new Node(d,node->next);
node->next=tmp;
};



 Node* List::Search(const DataType& d) // найти указатель на звено со значением data = d
 {
 Node*tmp=head;
 while(tmp!=NULL)
 {
	 if(tmp->data==d)
		 return tmp;
	 else
	 {
		 tmp=tmp->next;
	 }
 }
 return tmp;
 };


  void List::Delete(const DataType& d) // удалить звено со значением data = d
  {
  Node*prev,*tmp;
  tmp=head;
  prev=NULL;
  while((tmp!=NULL)&&(tmp->data!=d))
  {
	  prev=tmp;
	  tmp=tmp->next;
  }
  if(prev!=NULL)
	  prev->next=tmp->next;
  else
	  head=tmp->next;
  delete tmp;
  };


void List::Clean() // удалить все звенья
{
  Node*tmp=head,*n;
  while(tmp->next!=NULL)
  {
	  n=tmp->next->next;
	  delete tmp->next;
	  tmp->next=n;
  }
  delete tmp;
};


int List::GetSize() // узнать число звеньев в списке
{
Node* tmp=head;
int k=0;
  if (tmp=NULL)
  {
	return 0;
  }
  else
  {
	while(tmp->next!=NULL)
		{
		  k=k+1;
		  tmp = tmp->next;
        }
	return k;
  }
};

Node* List::GetHead() // получить указатель на первое звено списка
{
	Node*tmp;
	tmp=head;
	return tmp;
};

void List::Inverse() // инвертировать список, т.е. звенья должны идти в обратном порядке
{
	Node *tmp1, *tmp2, *tmp3;
	tmp1 = head;
	tmp2 = head->next;
	tmp1->next = NULL;
	while (tmp2 != NULL)
	{
		tmp3 = tmp2->next;
		tmp2->next = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp3;
	}
};


