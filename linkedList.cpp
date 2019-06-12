#include<iostream>
using namespace std;


template<class T>
class Node{
	T data;
	Node* next;
	public:
		Node(){this->data=NULL;this->next=NULL;}
		Node(T data){this->data=data;this->next=NULL;}
		Node(T data, Node<T>* next){this->data=data;this->next=next;}
		Node(Node<T> &aux){
			this->data=aux.getData();
			this->next=aux.getNext();
		}
		~Node(){cout<<"node destructor\n";}
		Node* getNext(){return next;}
		void setNext(Node* next){this->next=next;}
		T getData(){return data;}
		void setData(T data){this->data=data;}
		Node<T> operator=(Node<T> aux){
			this->data=aux.getData();
			this->next=aux.getNext();
			return this;
		}
};

template<class T>
class linkedList{
	Node<T>* head;
	int size;
	public:
		linkedList(Node<T>& head){
			this->head=new Node<T>(head);
			this->head->setNext(NULL);
			this->size=1;
		}
		Node<T>* getNodeByIndex(int index){
			if(index>size){
				cout<<"Indice inválido.\n";
				return NULL;
			}
			Node<T>* aux=head;
			for(int i=0;i<index;i++){
				aux=aux->getNext();
			}
			return aux;
		}
		void insertNodeByIndex(Node<T>& aux,int index){
			if(index>0){
				Node<T>* aux1=this->getNodeByIndex(index-1);
				Node<T>* newNode=new Node<T>(aux);
				newNode->setNext(aux1->getNext());
				aux1->setNext(newNode);
				(this->size)++;
			}
			else{
				Node<T>* newNode=new Node<T>(aux);
				newNode->setNext(head);
				this->head=newNode;
				(this->size)++;
			}
		}
		void deleteNodeByIndex(int index){
			if(index>0){
				Node<T>* aux=this->getNodeByIndex(index-1);
				Node<T>* aux1=aux->getNext();
				aux->setNext(aux->getNext()->getNext());
				delete aux1;
				(this->size)--;
			}
			else{
				Node<T>* aux=(this->head)->getNext();
				delete head;
				head=aux;
				(this->size)--;
			}
		}
		void printLinkedList(){
			Node<T>* aux=this->head;
			for(int i=0;i<size;i++){
				cout<<aux->getData()<<" ";
				aux=aux->getNext();
			}
			cout<<endl;
		}
		~linkedList(){
			cout<<"linked list destructor\n";
			Node<T>* aux1=this->head;
			for(int i=0;i<size;i++){
				Node<T>* aux=aux1->getNext();
				delete aux1;
				aux1=aux;
			}
			cout<<"end linked list destructor\n";
		}
};

int main(){
	Node<int> a(10);
	Node<int> b(20);
	Node<int> c(30);
	linkedList<int> list(a);
	list.printLinkedList();
	list.insertNodeByIndex(b,1);
	list.printLinkedList();
	list.insertNodeByIndex(c,0);
	list.printLinkedList();
	list.deleteNodeByIndex(0);
	list.printLinkedList();
	list.deleteNodeByIndex(0);
	list.printLinkedList();
	list.deleteNodeByIndex(0);
	return 0;
}
