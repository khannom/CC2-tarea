#include<iostream>
using namespace std;

template<class T>
class Iterador{
	public:
		virtual T* begin() = 0;
		virtual T* end() = 0;
		virtual bool hasNext() = 0;
		virtual T* goNext() = 0;
		virtual T* operator++() = 0;//Prefijo
		virtual T* operator++(int) = 0;//Postfijo
		virtual T& operator*() = 0;//Dereferenciar
};

template<class T>
class Node{
	T data;
	Node* next;
	Node* previous;
	public:
		Node(){this->data='\0';this->next=NULL;this->previous=NULL;}
		Node(T data){this->data=data;this->next=NULL;this->previous=NULL;}
		Node(Node<T> &aux){
			this->data=aux.getData();
			this->next=aux.getNext();
			this->previous=aux.getPrevious();
		}
		~Node(){}
		Node* getNext(){return next;}
		void setNext(Node* next){this->next=next;}
		T getData(){return data;}
		void setData(T data){this->data=data;}
		Node<T> operator=(Node<T> aux){
			this->data=aux.getData();
			this->next=aux.getNext();
			return this;
		}
		Node* getPrevious(){return previous;}
		void setPrevious(Node* previous){this->previous=previous;}
};

template<class T>//Solo recorre hacia adelante.
class IteradorLinkedList : public Iterador<T>{
	private:
		T* it;
		T* head;
		int index;
		int size;
	public:
		IteradorLinkedList(T* head,int size){
			it=head;
			this->head=head;
			index=0;
			this->size=size;
		}
		T* begin(){
			it=head;
			return it;
		}
		T* end(){
			return NULL;
		}
		bool hasNext(){
			return it;
		}
		T* goNext(){
			if(this->hasNext()){
				T* aux=it;
				it=it->getNext();
				return aux;
				index++;
			}
			return NULL;
		}
		T* operator++(){
			if(index<size){
				it=it->getNext();
				index++;
				return it;
			}
			return NULL;
		}
		T* operator++(int){
			if(index<size){
				T* aux=it;
				operator++();
				return aux;
			}
		}
		T& operator*(){
			return *(this->it);
		}
		T& operator=(IteradorLinkedList<T> aux){
			this->it=aux->it;
			this->head=aux->head;
			this->index=aux->index;
			this->size=aux->size;
		}
		T& operator=(T* aux){
			(this->it)->setData(aux->getData());
			return it;
		}
		T& operator!=(IteradorLinkedList<T> aux){
			if((this->it)->getData()!=(aux->it)->getData()){
				return true;
			}
			return false;
		}
};

template<class T>
class linkedList{
	Node<T>* head;
	Node<T>* last;
	int size;
	public:
		linkedList(){
			this->head=new Node<T>();
			this->last=head;
			this->size=0;
		}
		linkedList(Node<T>& head){
			this->head=new Node<T>(head);
			this->last=this->head;
			(this->head)->setNext(NULL);
			(this->head)->setPrevious(NULL);
			this->size=1;
		}
		Node<T>& getHead(){
			return *head;
		}
		Node<T>& getLast(){
			return *last;
		}
		int getSize(){
			return size;
		}
		Node<T>* getNodeByIndex(int index){
			if(index<0 || index>=size){
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
			if(index<0 || index>=size){
				cout<<"No se inserto nodo, indice invalido.\n";
				return;
			}
			else if(index==0){
				Node<T>* newNode=new Node<T>(aux);
				newNode->setNext(this->head);
				newNode->setPrevious(NULL);
				
				(this->head)->setPrevious(newNode);
				this->head=newNode;
				this->last->setPrevious(this->head);
				(this->size)++;
			}
			else{
				Node<T>* auxPrevious=this->getNodeByIndex(index-1);
				Node<T>* auxNext=auxPrevious->getNext();
				Node<T>* newNode=new Node<T>(aux);
				
				newNode->setNext(auxNext);
				newNode->setPrevious(auxPrevious);
				
				auxNext->setPrevious(newNode);
				auxPrevious->setNext(newNode);
				(this->size)++;
			}
		}
		void pushBackNode(Node<T>& aux){
			if(size>0){
				Node<T>* newNode=new Node<T>(aux);
				newNode->setNext(NULL);
				newNode->setPrevious(this->last);
				(this->last)->setNext(newNode);
				this->last=newNode;
				(this->size)++;
			}
			else{
				delete this->head;
				Node<T>* newNode=new Node<T>(aux);
				newNode->setNext(NULL);
				newNode->setPrevious(NULL);
				this->head=newNode;
				this->last=newNode;
				(this->size)++;
			}
		}
		void popLastNode(){
			if(size>1){
				Node<T>* aux=this->last->getPrevious();
				delete last;
				this->last=aux;
				this->last->setNext(NULL);
				(this->size)--;
			}
			else{
				delete this->head;
				this->head=new Node<T>();
				this->last=head;
				this->size=0;
			}
		}
		void deleteNodeByIndex(int index){
			if(index<0 || index>size){
				cout<<"No se elimino nodo, indice invalido.\n";
				return;
			}
			else if(index>0){
				Node<T>* aux=this->getNodeByIndex(index);
				(aux->getPrevious())->setNext(aux->getNext());
				(aux->getNext())->setPrevious(aux->getPrevious());
				delete aux;
				(this->size)--;
			}
			else{
				if(size>1){
					Node<T>* aux=(this->head)->getNext();
					delete head;
					this->head=aux;
					this->head->setPrevious(NULL);
					(this->size)--;
				}
				else{
					delete head;
					this->head=new Node<T>();
					this->last=head;
					this->size=0;
				}
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
			
			Node<T>* aux1=this->head;
			for(int i=0;i<size;i++){
				Node<T>* aux=aux1->getNext();
				delete aux1;
				aux1=aux;
			}
			
			if(size==0){
				delete this->head;
			}
		}
		IteradorLinkedList<Node<T>> getIterator(){
			IteradorLinkedList<Node<T>> aux(this->head,this->size);
			return aux;
		}
};

template<class T>
class Stack{
	linkedList<T> stack;
	public:
		Stack(Node<T>& aux){stack.pushBackNode(aux);}
		T getContent(){
			return stack.getLast().getData();
		}
		void pushBack(Node<T>& aux){stack.pushBackNode(aux);}
		T pop(){
			T aux=this->getContent();
			stack.popLastNode();
			return aux;
		}
		~Stack(){}
};

template<class T>
class Queue{
	linkedList<T> queue;
	public:
		Queue(Node<T>& aux){queue.pushBackNode(aux);}
		T getContent(){
			return queue.getHead().getData();
		}
		void enqueue(Node<T>& aux){queue.pushBackNode(aux);}
		T dequeue(){
			T aux=this->getContent();
			queue.deleteNodeByIndex(0);
			return aux;
		}
};
int main(){
	cout<<"PRUEBA DE LA COLA\n";
	Node<int> a(10);
	Node<int> b(20);
	Node<int> c(30);
	Queue<int> st(a);
	st.enqueue(b);
	st.enqueue(c);
	cout<<st.dequeue()<<endl;
	cout<<st.dequeue()<<endl;
	cout<<st.dequeue()<<endl;
	cout<<"PRUEBA DE LA PILA\n";
	Stack<int> st1(a);
	st1.pushBack(b);
	st1.pushBack(c);
	cout<<st1.pop()<<endl;
	cout<<st1.pop()<<endl;
	cout<<st1.pop()<<endl;	
	return 0;
}
