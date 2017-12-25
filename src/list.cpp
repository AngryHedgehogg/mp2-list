#include "list.h"

List::List(const List& list2)
{
	if (list2.head != NULL)
	{
		Node*tmp= new Node(list2.head->data);
		head = tmp;
		Node* tmp2 = list2.head;
		head = tmp;
		while (tmp2->next != NULL)
		{
			tmp2 = tmp2->next;
			tmp->next = new Node(tmp2->data);
			tmp = tmp->next;
		}
	}
	else
		head = NULL;
};

Node::Node(const Node& node2)
{
	data = node2.data;
	next = NULL;
}

bool Node::operator==(const Node& node2) const
{
	return data == node2.data;
	return next == node2.next;
}




List::~List()
{
	Clean();
}


List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head != NULL)
		{
			head = new Node(list2.head->data,list2.head);
			Node *temp = head;
			Node*temp2 = list2.head->next;
			while (temp2 != NULL)
			{
				temp->next = new Node(temp2->data);
				temp = temp->next;
				temp2 = temp2->next;
			}
		}
	}
	return *this;
};



void List::InsertToHead(const DataType& d) // вставить элемент d первым
{
	Node *tmp;
	tmp = new Node(d, head);
	head = tmp;
};


void List::InsertToTail(const DataType& d) // вставить элемент d последним
{
	if (head == NULL)
		head = new Node(d, NULL);
	else
	{
		Node *tmp;
		tmp = head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new Node(d, NULL);
	}
};


void List::InsertAfter(Node* node, const DataType& d) // вставить элемент d после звена node
{
	if ((node && head)!=NULL)
	{
		Node* tmp = node->next;
		node->next = new Node(d, tmp);
	}
	else
		if (head == NULL)
			throw "error";
}



Node* List::Search(const DataType& d) // найти указатель на звено со значением data = d
{
	Node*tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == d)
			return tmp;
		else
		{
			tmp = tmp->next;
		}
	}
	return tmp;
};


void List::Delete(const DataType& d) // удалить звено со значением data = d
{	
	Node*tmp, *tmp2;
	tmp = head;
	tmp2 = head;
	if (tmp != NULL) {
		while ((tmp->next != NULL) && (tmp->data != d))
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		if (tmp->data == d)
		{
			tmp2->next = tmp->next;
			if (tmp == head)
				head = head->next;
			delete tmp;
		}
	}
};


void List::Clean() // удалить все звенья
{
	Node*tmp = head;
	Node* n;
	if (head != NULL)
	{
		while (tmp != NULL)
		{
			n = tmp->next;
			delete tmp;
			tmp = n;
		}
		head = NULL;
	}
};  


int List::GetSize() // узнать число звеньев в списке
{
	Node* tmp = head;
	int k = 0;
		while (tmp!= NULL)
		{
			k = k + 1;
			tmp = tmp->next;
		}
		return k;
};


void List::Inverse() // инвертировать список, т.е. звенья должны идти в обратном порядке
{
	if (head!=NULL)
	{
		Node* tmp = head->next;
		head->next = NULL;
		Node* tmp2 = head;
		Node* rt;
		while (tmp)
		{
			rt = tmp->next;
			tmp->next = tmp2;
			tmp2 = tmp;
			tmp = rt;
		}
		head = tmp2;
	}
};


bool List::operator==(const List& list2)const
{
	Node *tmp = head;
	Node *tmp2 = list2.head;
	bool f = true;
	while ((tmp != NULL) && (tmp2 != NULL) && (f))
	{
		if (tmp->data != tmp2->data)
			f = false;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if ((tmp != NULL) || (tmp2 != NULL))
		f = false;
	return f;
};



List List::Merge(Node* node, const List& list2) // создать список3, добавив список2 в текущий список после указателя node  
{	
	List newtmp;
	Node* tmp = head;
	if (head!=NULL)
	{
		newtmp.head = new Node(head->data);
		Node* tmp2 = newtmp.head;
		while ((tmp->next) && (tmp != node))
		{
			tmp2->next = new Node(tmp->next->data);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		if (tmp == node)
		{
			if (list2.head)
			{
				Node* tmp3 = list2.head;
				while (tmp3!=NULL)
				{
					tmp2->next = new Node(tmp3->data);
					tmp3 = tmp3->next;
					tmp2 = tmp2->next;
				}
			}
			while (tmp->next)
			{
				tmp2->next = new Node(tmp->next->data);
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
		tmp2->next = NULL;
	}

	return newtmp;
}


List List::Merge(const List& list2) // создать список3, добавив в конец текущего списка список2
{
	List newtmp(*this);
	if (newtmp.head && list2.head)
	{
		Node* tmp = newtmp.head;
		while (tmp->next)
			tmp = tmp->next;
		Node* tmp2 = list2.head;
		while (tmp2!=NULL)
		{
			tmp->next = new Node(tmp2->data, tmp2->next);
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		tmp->next = NULL;
	}
	else
		if (newtmp.head == NULL)
			newtmp = List(list2);
	return newtmp;
}