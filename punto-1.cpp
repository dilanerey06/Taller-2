//punto-1
#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

void llenarMatrix(int a);
void imp(int a);
bool rectifier(int n);
void rectifierDiagonals(bool &flag, int n);
int **ptrMatrix;

int main(){
	int n;
	bool var=false;
	cout<<"Digite orden de la matriz cuadrada"<<'\n';
	cin>>n;
	ptrMatrix=new int *[n];
	for(int i=0; i<n; ++i){
		ptrMatrix[i]=new int[n];
	}	
	llenarMatrix(n);
	cout<<"Imprimiendo matriz"<<'\n';
	imp(n);
	var=rectifier(n);
	if(var==true){
		cout<<"La matriz es un cuadrado magico"<<'\n';
	}
	else{
		cout<<"La matriz no es un cuadrado magico"<<'\n';
	}
	delete[]ptrMatrix;
	return 0;
}

bool rectifier(int n){
	bool flag;
	int aux=0, auxRows, auxCols;
	int sumRows[n]={};
	int sumCols[n]={}; 	
	for(int i=0; i<n; ++i){
		auxRows=0;
		auxCols=0;
		for(int j=0; j<n; ++j){
			auxRows+=ptrMatrix[i][j];
			auxCols+=ptrMatrix[j][i];
		}
		sumRows[i]=auxRows;
		sumCols[i]=auxCols;
	}
	while(aux<=n-1){
		if(sumRows[aux]!=sumCols[aux]){
			return flag=false;	
		}
		else{
			++aux;
		}
	}
	rectifierDiagonals(flag, n);
	return flag;
}

void rectifierDiagonals(bool &flag, int n){
	int auxMain=0, auxSecond=0;
	for(int i=0; i<n; ++i){
		auxMain+=ptrMatrix[i][i];	
		auxSecond+=ptrMatrix[i][n-i-1];
	}
	if(auxMain==auxSecond){
		flag=true;
	}
	else{
		flag=false;
	}
}

void llenarMatrix(int a){
	cout<<"Ingrese valores de la matriz"<<'\n';
	for(int i=0; i<a; ++i){
		for(int j=0; j<a; ++j){
			cout<<"matriz["<<i<<"]["<<j<<"]=";
			cin>>ptrMatrix[i][j];
		}
	}
}

void imp(int a){
	for(int i=0; i<a; ++i){
		for(int j=0; j<a; ++j){
			cout<<ptrMatrix[i][j]<<'\t';
		}
		cout<<'\n';	
	}
}
