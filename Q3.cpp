#include<iostream>
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
class DoublyCircularLinkedlist{
	public:
		Node* head;
	DoublyCircularLinkedlist(){
		head=NULL;
	}
	Node* NodeExists(int key){
		if(head==NULL){
			return NULL;
		}
		Node* temp=head->next;
		Node*ptr =NULL;
		if(head->key==key){
			return head;
		}
		while(temp!=head){
			if(temp->key==key){
				ptr=temp;
				return ptr;
			}
			temp=temp->next;
		}
		return ptr;
	}
	void appendNode(int key, int data){
		Node* ptr= new Node(key,data);
		Node* exists= NodeExists(key);
		if(exists!=NULL){
			cout<< "A node with this key already exists"<<endl;
			delete ptr;
			return;
		}
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
			cout<<"Node added as head"<<endl;
			return;
		}
		Node* temp= head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		ptr->next=head;
		head->prev=ptr;
		cout<<"Node added in the end of the list"<<endl;
	}
	void PreAppend(int key, int data){
		Node*ptr= new Node(key,data);
		Node* exists= NodeExists(key);
		if(exists!=NULL){
			cout<< "A node with this key already exists"<<endl;
			delete ptr;
			return;
		}
		if(head==NULL){
			head=ptr;
			ptr->next=head;
			ptr->prev=head;
			cout<<"Node added in the start of the list"<<endl;
			return;
		}
		Node* temp=head->next;
		while(temp->next!=head){
			temp=temp->next;
		}
		ptr->next=head;
		head->prev=ptr;
		temp->next=ptr;
		ptr->prev=temp;
		head=ptr;
		cout<<"Node added in the start of the list"<<endl;
		
		
	}
	void insertNodeAfter(int key, int data, int key2 ){
		Node*ptr= new Node(key,data);
		Node* exists= NodeExists(key);
		Node* after= NodeExists(key2);
		if(after==NULL){
			cout<<"No node exits with this key";
		}
		if(exists!=NULL){
			cout<< "A node with this key already exists"<<endl;
			delete ptr;
			return;
		}
		Node*temp= head->next;
		while(temp->next!=head){
			if(temp->key==key2){
				temp->next->prev=ptr;
				ptr->next=temp->next;
				temp->next=ptr;
				ptr->prev=temp;
				cout<<"Node added successfully!"<<endl;
				return;
			}
			temp=temp->next;
		}
		
	}
	void deleteNode(int key){
		Node* exists= NodeExists(key);
		if(exists==NULL){
			cout<< "A node with this key does not exist"<<endl;
			delete exists;
			return;
		}
		Node*temp=head->next;
		if(exists==head){
			head->prev->next=head->next;
			head->next->prev=head->prev;
			delete exists;
			return;
		}
		while(temp->next->key!=key){
			
			temp=temp->next;
		}
		temp->next=exists->next;
		exists->next->prev=temp;
		exists=NULL;
		delete exists;
		cout<<"Node deleted sucessfully!"<<endl;
		
	}
	void print(){
		cout<<"Data of the nodes: ";
		cout<<head->data<<" ";
		for(Node* current=head->next;current!=head;current=current->next){
			cout<< current->data<<" ";
		}
	}
};

int main(){
	Node* one= new Node(1,1);
	Node* two= new Node(2,2);
	Node* three= new Node(3,3);
	DoublyCircularLinkedlist d= DoublyCircularLinkedlist();
	d.appendNode(1,1);
	d.appendNode(2,2);
	d.appendNode(3,3);
	d.PreAppend(4,4);
	d.insertNodeAfter(5,5,2);
	d.deleteNode(4);
	d.print();
}