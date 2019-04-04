#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
void copiar(char *p,char *q){
	while(*q){
		*p=*q;p++;q++;
	}
}
int len(string a){
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	return i;
}

int leng(char *a){
	int i=0;
	while(*a){a++;i++;}
	return i;
}

void quicksort(int *lista,int izq,int der){
	int pivot=lista[izq];
	int n=der+1;
	int i=izq;
	int j=der;
	while(i<j){
		while(lista[i]<=pivot&&i<j){
			i++;
		}
		while(lista[j]>pivot){
			j--;
		}
		if(i<j){
			int aux=lista[i];
			lista[i]=lista[j];
			lista[j]=aux;
		}
	}
	lista[izq]=lista[j];
	lista[j]=pivot;
	if(izq<j-1){
		quicksort(lista,izq,j-1);
	}
	if(j+1<der){
		quicksort(lista,j+1,der);
	}
}
int nameCmp(string a,string b){
	if(a[0]>='A'&&a[0]<='Z'){
		a[0]=a[0]+32;
	}
	if(b[0]>='A'&&b[0]<='Z'){
		b[0]=b[0]+32;
	}
	int menor;
	if(len(a)<len(b)){
		menor=len(a);
	}
	else{
		menor=len(b);
	}
	for(int i=0;i<menor;i++){
		if(a[i]<b[i]){
			return -1;
		}
		else if(a[i]>b[i]){
			return 1;
		}
		else if(a[i+1]=='\0'||b[i+1]=='\0'){
			return 0;
		}
	}
}
void quicksorts(string *lista,int izq,int der){
	string pivot=lista[izq];
	int n=der+1;
	int i=izq;
	int j=der;
	while(i<j){
		while(nameCmp(lista[i],pivot)<=0&&i<j){
			i++;
		}
		while(nameCmp(lista[j],pivot)==1){
			j--;
		}
		if(i<j){
			string aux=lista[i];
			lista[i]=lista[j];
			lista[j]=aux;
		}
	}
	lista[izq]=lista[j];
	lista[j]=pivot;
	if(izq<j-1){
		quicksorts(lista,izq,j-1);
	}
	if(j+1<der){
		quicksorts(lista,j+1,der);
	}
}

class Serial{
	protected:
		int a;
		int b;
		char *cad;
	public:
		Serial(int,int,char*);
		~Serial();
		void mostrar();
		void asignar(Serial*);
		virtual void resultado(){cout<<a+b<<endl;};
};

Serial::Serial(int x,int y,char *cadena){
	a=x;b=y;
	cad = new char [leng(cadena)+1];
	copiar(cad,cadena);
}
Serial::~Serial(){
	cout<<"Fui eliminado."<<endl;
	delete [] cad;cout<<"contenido: "<<cad<<endl;
}
void Serial::mostrar(){
	cout<<a<<endl<<b<<endl<<cad<<endl;
}
void Serial::asignar(Serial *aux){
	a=aux->a;
	b=aux->b;
	delete [] cad;
	cad = new char [leng(aux->cad)+1];
	copiar(cad,aux->cad);
}

class Cereal : public Serial{
	private:
		int asd;
	public:
		Cereal(int a,int b,char* c,int d):Serial(a,b,c){asd=d;}
		void resultado(){
			cout<<a*b<<endl;
		}
};

bool iguales(char *a,char *b){
	if(leng(a)==leng(b)){
		while(*a){
			if(*a!=*b){
				return false;
			}
			a++;b++;
		}
		return true;
	}
	return false;
}

template <class T>
int abss(T n){
	if(n>0){return n;}
	return (n*-1);
}

int main(){
}
