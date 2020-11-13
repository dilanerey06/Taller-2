//punto-4
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<time.h>

using namespace std;

void generator();
void imp();
void rectifier(int &cont, int ite, int x);
void histogram(int cont, int x);

int *ptrArray;
const int a=4000;

int main(){
	srand(time(NULL));
	int cont;
	ptrArray=new int [a];
	generator();
	cout<<"\n ======Histograma: numero de veces que se repite numero generado aleatoriamente=====\n"<<'\n';
	for(int i=1; i<=100; ++i){
		cont=0;
		rectifier(cont,0,i);
		//cout<<"el número "<<i<<" se repite "<<cont<<" veces"<<'\n';
		histogram(cont, i);
	}	
	delete[]ptrArray;
	return 0;
}

void histogram(int cont, int x){
	int i=0;
	while(i<cont){
		if(i==0){
			if(x<=9){
				cout<<x<<"   | * ";
				++i;
			}
			if(10<=x&&x<=99){
				cout<<x<<"  | * ";
				++i;
			}
			if(x==100){
				cout<<x<<" | * ";
				++i;
			}		
		}
		cout<<"* ";
		if(i==cont-1){
			cout<<" ["<<cont<<"]";
		}
		++i;
	}
	cout<<'\n';
}

void rectifier(int &cont, int ite, int x){
	if(ptrArray[ite]==x){
		cont+=1;
	}
	ite+=1;
	if(ite<a){
		rectifier(cont,ite,x);
	}
}

void generator(){
	for(int i=0; i<a; ++i){
		ptrArray[i]=(rand()%100)+1;
	}
}

void imp(){
	for(int i=0; i<a; ++i){
		cout<<ptrArray[i]<<'\n';
	}
}
