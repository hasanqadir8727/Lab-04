#include<iostream>
using namespace std;

class Node
{
	public: 
		int value,key;
		Node* next;
		Node* previous;
		
		Node()		//Default Constructor
		{
			value = 0;
			key = 0;
			next = NULL;
			previous = NULL;
		}
		Node(int data,int key)		//Parametrized Constructor
		{
			this->value = data;
			this->key = key;
		}
		~Node()					//Destructor
		{
			cout<<"Destructor Called!!!"<<endl;
			if(next != NULL)
				delete next;
		}
};
class DoubleCircularLinkedList
{
	public:
		Node* head;
		Node* tail;
		DoubleCircularLinkedList()		//Default Constructor
		{
			head = NULL;
			tail = NULL;
		}
		DoubleCircularLinkedList(Node* h,Node* t)		//Parametrized Constructor
		{
			head = h;
			tail = t;
		}
		~DoubleCircularLinkedList()		//Destructor
		{
			cout<<"\nLinked List Destructor Called!!!"<<endl;
			tail->next = NULL;
			delete head;
		}
		Node* nodeExists(int key)
		{
			Node* temp = NULL;
			if(head == NULL)	return NULL;
			if(head->key == key)
			{
				return head;
			}
			for(Node* traverse = head->next; traverse != head; traverse = traverse->next)
			{
				if(traverse->key == key)
				{
					temp = traverse;
					return traverse;
				}
			}
			return NULL;
		}
		void appendNode(int key,int value)
		{
			Node* newNode = new Node(value,key);
			if(nodeExists(key) != NULL)
			{
				cout<<"Node With The Passd Key "<<key<<" Already Exists !!\n\n";
				delete newNode;
	        	return;
			}
			if(head == NULL)
			{
				head = newNode;
				tail = newNode;
				head->next = head;
				head->previous = head;
			}
			else if(head  != NULL)
			{
				newNode->previous = tail;
				tail->next = newNode;
				tail = newNode;
				newNode->next = head;
				head->previous = tail;
			}
		}
		void shift(int toShift,int withShift)
		{
			if(toShift == withShift)	return;
			Node* current = head;
			Node* prev1 = NULL; 
			Node* prev2 = NULL;
			Node* n1 = NULL;
			Node* n2 = NULL;
			int count = 0;
			
			do
			{
				if(count == toShift)
				{
					prev1 = current->previous;
					n1 = current;
				}
				if(count == withShift)
				{
					prev2 = current->previous;
					n2 = current;
				}
				current = current->previous;
				count++;
			}while(current != head && (n1 == NULL || n2 == NULL));
			
			if (n1 == nullptr || n2 == nullptr) 
			{
		        cout << "Invalid indexes." << endl;
		        return;
			}
			if(prev1 != NULL)
			{
				prev1->next = n2;
			}
			else
			{
				head = n2;
			}
			if(prev2 != NULL)
			{
				prev2->next = n1;
			}
			else
			{
				head = n1;
			}
			Node* temp = n1->next;
			n1->next = n2->next;
			n2->next = temp;
			
			temp = n1->previous;
			n1->previous = n2->previous;
			n2->previous = temp;
		}
		void print()
		{
			cout<<"\n\n==============Printing LinkList==============\n\n";
			cout<<"Value Of LinkList Is : "<<head->value<<" & Key Is :"<<head->key<<"\n";
			for(Node* temp = head->next; temp != head; temp = temp->next)
			{
				cout<<"Value Of LinkList Is : "<<temp->value<<" & Key Is :"<<temp->key<<"\n";
			}
		}
};

int main()
{
	DoubleCircularLinkedList l1 = DoubleCircularLinkedList();
	l1.appendNode(0,1);
	l1.appendNode(1,7);
	l1.appendNode(2,4);
	l1.appendNode(3,2);
	l1.appendNode(4,6);
	l1.appendNode(5,4);
	l1.appendNode(6,5);
	l1.appendNode(7,3);
	l1.appendNode(8,9);
	l1.appendNode(9,8);
	l1.print();
	
	int toShift, withShift;
	cout<<"Enter Key To Shift : ";
	cin>>toShift;
	cout<<"Enter Key With Shift : ";
	cin>>withShift;
	l1.shift(toShift-1,withShift-1);
	cout<<"\n\n==============After Swap==============";
	l1.print();
}