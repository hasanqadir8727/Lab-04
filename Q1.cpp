#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int key;
    Node *next;
    Node()
    {
        next = NULL;
        data = 0;
        key = 0;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
    }
    ~Node()
    {
        delete next;
    }
};
class CircularLinkedlist
{
public:
    Node *head;
    CircularLinkedlist()
    {
    	head=NULL;
    }
    CircularLinkedlist(Node *head)
    {
        this->head = head;
    }
    Node *nodeExists(int key)
    {
        Node *ptr= NULL;
        Node *temp = head->next;
        if (head == NULL)
        {
            return NULL;
        }
        while (temp != head)
        {
            if (temp->key == key)
            {
                ptr = temp;
                break;
            }
            temp = temp->next;
        }
        if(head->key==key){
            return head;
        }
        return ptr;
    }
    void append(int key, int data)
    {
        Node *ptr = new Node(key, data);
        Node *temp = head;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            cout<<"Node added as the head of the list"<<endl;
            return;
        }
        temp=head->next;
        while (temp->next!= head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head;
        cout << "Node added in the list" << endl;
    }
	void preAppend(int data, int key){
		Node* temp=head;
		Node*ptr=new Node(data,key);
		if(nodeExists(ptr->key)!=NULL){
			cout<<"Node already exists"<<endl;
			return;
		}
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			return;
		}
		while(temp->next!=head){
			temp=temp->next;
		}
		ptr->next=head;
		temp->next=ptr;
		cout<<"Node added as head"<<endl;

	}
	void insertNodeAfter(int key,int data, int key1){
	Node* ptr= nodeExists(key1);
	Node* newNode= new Node(key, data);
	Node* temp=head;
	if(ptr==NULL){
		cout<<"No node exists with this key";
		delete newNode;
		return;
	}
	if (nodeExists(key)!=NULL){
		cout<<"This key already exists";
		return;
	}
	if(ptr->next==head){
		ptr->next=newNode;
		newNode->next=head;
		return;
	}
	newNode=ptr->next;
	ptr->next=newNode;
}
	void deleteNodeByKey(int key){
		Node*temp=head->next;
		Node* ptr= nodeExists(key);
		while(temp->next->key!=key){
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr=NULL;
		delete ptr;
		cout<<"Node deleted sucessfully";
	}
	void print(){
		cout<<"Data of the nodes: ";
		cout<<head->data<<" ";
		for(Node*current= head->next;current!=head;current=current->next)
		{
			cout<<current->data<<endl;
		}
	}
	
};
int main()
{
    Node *one = new Node(1, 1);
    Node *two = new Node(2, 2);
    CircularLinkedlist l = CircularLinkedlist();
//    cout<<"Before";
    l.append(1, 1);
    l.append(2, 2);
    l.preAppend(3,3);
    l.nodeExists(2);
    l.deleteNodeByKey(2);
}