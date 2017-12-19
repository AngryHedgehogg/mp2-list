#include "list.h"



List::List(const List& list2)
{
	if (list2.head != NULL)
	{
		head = new Node(list2.head->data, list2.head->next);
		Node* tmp = head;
		while (tmp->next != NULL)
		{
			tmp->next = new Node(tmp->data, tmp->next);
			tmp = tmp->next;
		}
	}
};

Node::Node(const Node& node2)
{
	data = node2.data;
	next = node2.next;
}


List::~List()
{
	Node *tmp = head;
	Node *tmp2 = head;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
		delete tmp;
	}
}


List& List::operator=(const List& list2)
{
	if (this != &list2)
	{
		Clean();
		if (list2.head != NULL)
		{
			head = new Node(list2.head->data);
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
	tmp->next = head;
	tmp = head;
};


void List::InsertToTail(const DataType& d) // вставить элемент d последним
{
	Node *tmp;
	tmp = head;
	if (head == NULL)
		head = new Node(d, NULL);
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
	tmp = new Node(d, node->next);
	node->next = tmp;
};



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
	Node*prev, *tmp;
	tmp = head;
	prev = NULL;
	while ((tmp != NULL) && (tmp->data != d))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev != NULL)
		prev->next = tmp->next;
	else
		head = tmp->next;
	delete tmp;
};


void List::Clean() // удалить все звенья
{
	Node*tmp = head, *n;
	while (tmp->next != NULL)
	{
		n = tmp->next->next;
		delete tmp->next;
		tmp->next = n;
	}
	delete tmp;
};


int List::GetSize() // узнать число звеньев в списке
{
	Node* tmp = head;
	int k = 0;
	if (tmp = NULL)
	{
		return 0;
	}
	else
	{
		while (tmp!= NULL)
		{
			k = k + 1;
			tmp = tmp->next;
		}
		return k;
	}
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
	newtmp.head = head;
	Node *tmp1, *tmp2;
	tmp1 = node->next;
	node->next = list2.head;
	tmp2 = list2.head;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp1;
	return newtmp;
}


List List::Merge(const List& list2) // создать список3, добавив в конец текущего списка список2
{
	List newtmp;
	newtmp.head = head;
	Node *tmp;
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = list2.head;
	return newtmp;

}