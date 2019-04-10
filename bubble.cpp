#include<iostream>
using namespace std;

int pow(int x,int y){
	int rpta=1;
	for(;y>0;y--){
		rpta*=x;
	}
	return rpta;
}

//array y longitud
void bubble_sort(int *arr,int n){
	bool sorted=false;
	while(!sorted){
		sorted=true;
		for(int i=0;i<n-1;i++){
			if(arr[i]>arr[i+1]){
				sorted=false;
				int aux=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=aux;
			}
		}
	}
}

//array y longitud
void insert_sort(int *arr,int n){
	for(int i=1,j=0;i<n;i++,j=i-1){
		while(arr[j]>arr[j+1]){
			int aux=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=aux;
			j--;
		}
	}
}

//array, indice del primero y ultimo elemento
void quick_sort(int *arr,int start,int end){
	int i=start,j=end;
	int pivot=arr[j];j--;
	//ordena en el arreglo los elementos menores al pivote a la izquierda,
	//y los mayores a la derecha
	while(i<j){
		if(arr[i]>pivot && arr[j]<=pivot){
			int aux=arr[i];
			arr[i]=arr[j];
			arr[j]=aux;
			i++;j--;
		}
		while(arr[i]<=pivot&&i<j){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
	}
	//inserta al pivote en su posición ideal.
	if(arr[i]>pivot){
		int aux=arr[i];
		arr[i]=arr[end];
		arr[end]=aux;
	}
	//llama a quick_sort recursivamente para el arreglo a la izquierda del pivote
	if(j>0){
		quick_sort(arr,0,j);
	}
	//lo mismo que antes, solo que para la parte derecha
	if(i+1<end){
		quick_sort(arr,i+1,end);
	}
}

//array, numero de elementos y maximo numero de digitos (solo funciona para numeros decimales)
void radix_sort(int *arr,int n,int digits){
	for(int d=1;d<=digits;d++){
		int *arrx=new int [n];
		int count[10] = {0};
		//counting sort
		for(int i=0;i<n;i++){
			count[(arr[i]/pow(10,d-1))%10]++;
		}
		for(int i=1;i<10;i++){
			count[i]=count[i-1]+count[i];
		}
		for(int i=9;i>0;i--){
			count[i]=count[i-1];
		}
		count[0]=0;
		for(int i=0;i<n;i++){
		        arrx[count[(arr[i]/pow(10,d-1))%10]]=arr[i];count[(arr[i]/pow(10,d-1))%10]++;
			
		}
		for(int i=0;i<n;i++){
			arr[i]=arrx[i];
		}
		delete [] arrx;
	}
	
}

void merge(int *left,int nL,int *right,int nR,int *arr){
	int i=0,j=0,k=0;
	while(i<nL && j<nR){
		if(left[i]<=right[j]){
			arr[k]=left[i];
			k++;i++;
		}
		else{
			arr[k]=right[j];
			k++;j++;
		}
	}
	while(i<nL){
		arr[k]=left[i];k++;i++;
	}
	while(j<nR){
		arr[k]=right[j];k++;j++;
	}
}

void merge_sort(int *arr,int n){
	if(n<2){return;}
	int *left=new int [n/2];
	int *right=new int [n-(n/2)];
	for(int i=0;i<n/2;i++){
		left[i]=arr[i];
	}
	for(int i=n/2;i<n;i++){
		right[i-(n/2)]=arr[i];
	}
	merge_sort(left,n/2);
	merge_sort(right,n-(n/2));
	merge(left,n/2,right,n-(n/2),arr);
	delete [] left;
	delete [] right;
}



int main(){
	int n;cout<<"Ingrese el número de elementos: ";cin>>n;
	int *arr=new int [n];cout<<"Ingrese los elementos del array;\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	radix_sort(arr,n,3);
	cout<<"ordenado:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	delete [] arr;
}
