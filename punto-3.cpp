//ejercicio-3
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

using namespace std; 

struct complejo{
	int partEntera;
	int partComplex;
	float modulo;
	float argumento;
}array[3], array2[3];;

void imp(complejo arreglo[3]);
void sumOrRest(int id);
void multOrDiv(int id);
void modulo(int id);
void arg();

const int n=3;

int main(){
	srand(time(NULL));
	for(int i=0; i<n; ++i){
		array[i].partEntera=(rand()%10)+1;
		array[i].partComplex=(rand()%10)+1;
		array2[i].partEntera=(rand()%10)+1;
		array2[i].partComplex=(rand()%10)+1;
	}
	cout<<"[1] = ";
	imp(array);
	cout<<"[2] = ";
	imp(array2);
	cout<<"[S] = ";
	sumOrRest(1);
	cout<<"[R] = ";
	sumOrRest(2);
	cout<<"[M] = ";
	multOrDiv(1);
	cout<<"[D] = ";
	multOrDiv(2);
	cout<<"\n================================================================"<<'\n';
	cout<<"[MOD-1]= ";
	modulo(1);
	cout<<"[MOD-2]= ";
	modulo(2);
	arg();
	return 0;
}

void arg(){
	cout<<"[ARG-1]= ";
	for(int i=0; i<n; ++i){
		array[i].argumento=atan(float(array[i].partComplex)/float(array[i].partEntera));
		cout<<array[i].argumento<<"  ";
	}
	cout<<'\n';
	cout<<"[ARG-2]= ";
	for(int j=0; j<n; ++j){
		array2[j].argumento=atan(float(array2[j].partComplex)/float(array2[j].partEntera));
		cout<<array2[j].argumento<<"  ";
	}
	cout<<'\n';
}

void modulo(int id){
	switch(id){
		case 1:	
			for(int i=0; i<n; ++i){
				array[i].modulo=sqrt(pow(array[i].partEntera,2)+pow(array[i].partComplex,2));
				cout<<array[i].modulo<<"  ";
			}
			cout<<'\n';
			break;
		case 2:
			for(int i=0; i<n; ++i){
				array2[i].modulo=sqrt(pow(array2[i].partEntera,2)+pow(array2[i].partComplex,2));
				cout<<array2[i].modulo<<" ";
			}
			cout<<'\n';
			break;
	}
}

void multOrDiv(int id){
	complejo r[n];
	switch(id){
		case 1:
			for(int i=0; i<n; ++i){
				r[i].partEntera=((array[i].partEntera*array2[i].partEntera)-(array[i].partComplex*array2[i].partComplex));
				r[i].partComplex=((array[i].partEntera*array2[i].partComplex)+(array[i].partComplex*array2[i].partEntera));
			}
			imp(r);
			break;
		case 2:
			int aux[n]={};
			for(int i=0; i<n; ++i){
				aux[i]=(pow(array2[i].partEntera,2)+pow(array2[i].partComplex,2));
				r[i].partEntera=((array[i].partEntera*array2[i].partEntera)+(array[i].partComplex*array2[i].partComplex));
				r[i].partComplex=((array[i].partComplex*array2[i].partEntera)-(array[i].partEntera*array2[i].partComplex));
			}
			for(int j=0; j<n; ++j){
				if(r[j].partComplex>=0){
					cout<<"("<<r[j].partEntera<<"/"<<aux[j]<<")+("<<r[j].partComplex<<"/"<<aux[j]<<")i"<<'\t';
				}
				else{
					r[j].partComplex=r[j].partComplex*(-1);
					cout<<"("<<r[j].partEntera<<"/"<<aux[j]<<")-("<<r[j].partComplex<<"/"<<aux[j]<<")i"<<'\t';
				}
			}
			break;
	}	
}

void sumOrRest(int id){
	complejo r[n];
	switch(id){		
		case 1:	
			for(int i=0; i<n; ++i){
				r[i].partEntera=array[i].partEntera+array2[i].partEntera;
				r[i].partComplex=array[i].partComplex+array2[i].partComplex;
			}break;	
		case 2:
			for(int i=0; i<n; ++i){
				r[i].partEntera=array[i].partEntera-array2[i].partEntera;
				r[i].partComplex=array[i].partComplex-array2[i].partComplex;
			}break;	
	}
	imp(r);
}

void imp(complejo arreglo[3]){
	for(int i=0; i<n; ++i){
		if(arreglo[i].partComplex>=0){
			cout<<arreglo[i].partEntera<<"+"<<arreglo[i].partComplex<<"i"<<'\t';
		}
		else{
			cout<<arreglo[i].partEntera<<arreglo[i].partComplex<<"i"<<'\t';
		}
	}
	cout<<'\n';
}

