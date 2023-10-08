#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int key;
    Node *next;
    Node *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
        data = 0;
        key = 0;
    }
    Node(int data, Node *next, Node *prev, int key)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
        this->key = key;
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
class DoublyLinkedlist
{
public:
    Node *head;
    DoublyLinkedlist()
    {
        head = NULL;
    }
    Node *NodeExists(int key)
    {
        Node *ptr = NULL;
        Node *temp = head;
        if (head == NULL)
        {
            return NULL;
        }
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                ptr = temp;
                return ptr;
            }
            temp = temp->next;
        }
        return ptr;
    }
    void appendNode(int key, int data)
    {
        Node *ptr = new Node(key, data);
        Node *temp = head;
		Node* exists= NodeExists(key);
		if(exists!=NULL){
			cout<<"A node with this key already exists"<<endl;
			return;
		}
        if (head == NULL)
        {
            head = ptr;
            ptr->prev = NULL;
            ptr->next = NULL;
            cout << "Node added as head of the linked list" << endl;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        ptr->next = NULL;
        cout << "Node added sucessfully" << endl;
    }
    void PreAppendNode(int key, int data)
    {
        Node *ptr = new Node(key, data);
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << "A node with this key already exists" << endl;
                delete ptr;
                return;
            }
            temp = temp->next;
        }
        if (head == NULL)
        {
            head = ptr;
            ptr->prev = NULL;
            ptr->next = NULL;
            return;
        }
        ptr->prev = NULL;
        ptr->next = head;
        head->prev = ptr;
        head = ptr;
        cout << "Node added as head sucessfully"<<endl;
    }
    void insertNodeAfter(int key, int data, int key2)
    {
    	Node *ptr = new Node(key, data);
        Node *temp = head;
        Node *after=NodeExists(key2);
        if(after==NULL){
        	cout<<"No node exists with this key "<<endl;
		}
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << "A node with this key already exists" << endl;
                delete ptr;
                return;
            }
            temp = temp->next;
        }
        if(after->next==NULL){
        	after->next=ptr;
        	ptr->prev=after;
        	ptr->next=NULL;
        	return;
		}
		ptr->next=after->next;
		after->next->prev=ptr;
		after->next=ptr;
		ptr->prev=after;
		cout<<"Node added after the given node sucessfully!";
		
    }
    void deleteNode(int key){
    	Node* exists= NodeExists(key);
    	Node* temp=head;
    	if(exists==NULL){
    		cout<<"This node does not exist"<<endl;
    		return;
		}
		while(temp->next->key!=key){
			temp=temp->next;
		}
		temp->next=exists->next;
		exists->next->prev=temp;
		exists=NULL;
		delete exists;
		cout<<"Node deleted successfully";
		
	}
	void print(){
		cout<<"Data of the nodes:";
		for(Node*current=head; current!=NULL;current=current->next){
			cout<<current->data<<" ";
		}
	}
	
};
int main()
{
    Node *one = new Node(1, 1);
    Node *two = new Node(2, 2);
    DoublyLinkedlist d = DoublyLinkedlist();
    d.appendNode(1, 1);
    d.appendNode(2, 2);
    d.appendNode(3,3);
//    d.PreAppendNode(3, 3);
//    d.insertNodeAfter(4,4,2);
    d.deleteNode(5);
    d.print();
}