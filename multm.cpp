#include<iostream>
using namespace std;

int** mult_matrix(int** m1,int f1, int c1,int** m2,int f2,int c2){
	int **m3=new int* [f1];
	for(int i=0;i<c1;i++){
		*(m3+i)=new int [c2];
	}
	for(int i=0;i<f1;i++){
		for(int j=0;j<c2;j++){
			int acc=0;
			for(int k=0;k<c1;k++){
				acc=acc+(*(*(m1+i)+k))*(*(*(m2+k)+j));
			}
			*(*(m3+i)+j)=acc;
		}
	}
	return m3;
}

int main(){
	int f1,c1,f2,c2;
	cout<<"Ingrese filas y columnas de la matriz 1:";cin>>f1>>c1;
	cout<<"Ingrese filas y columnas de la matriz 2:";cin>>f2>>c2;
	int **m1=new int* [f1];
	for(int i=0;i<f1;i++){
		*(m1+i)=new int [c1];
	}
	int **m2=new int* [f2];
	for(int i=0;i<f2;i++){
		*(m2+i)=new int [c2];
	}
	for(int i=0;i<f1;i++){
		for(int j=0;j<c1;j++){
			cout<<i<<" y " <<j<<": ";cin>>*(*(m1+i)+j);
		}
	}
	for(int i=0;i<f2;i++){
		for(int j=0;j<c2;j++){
			cout<<i<<" y " <<j<<": ";cin>>*(*(m2+i)+j);
		}
	}
	if(c1==f2){
		int **m3=mult_matrix(m1,f1,c1,m2,f2,c2);
		for(int i=0;i<f1;i++){
			for(int j=0;j<c2;j++){
				cout<<*(*(m3+i)+j)<<" ";
			}
			cout<<endl;
		}
		for(int i=0;i<f1;i++){
			delete [] *(m3+i);
		}
		delete [] m3;
	}
	for(int i=0;i<f1;i++){
		delete [] *(m1+i);
	}
	delete [] m1;
	for(int i=0;i<f1;i++){
		delete [] *(m2+i);
	}
	delete [] m2;
	return 0;
}
