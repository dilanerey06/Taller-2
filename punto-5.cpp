//punto-5
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct Vector{
	int x;
	int y;
	int z;
}vector[2],productVec;

void productoPunto(int &r);
void productoCruz();

int main(){
	int resultadoPunto;
	for(int i=0; i<2; i++){
		cout<<"Coordenadas del vector "<<i+1<<" ="<<'\n';
		cout<<"X: ";cin>>vector[i].x;
		cout<<"Y: ";cin>>vector[i].y;
		cout<<"Z: ";cin>>vector[i].z;
	}
	cout<<"Los vectores ingresados son:"<<'\n';
	for(int j=0;j<2;++j){
		cout<<"Vector "<<j+1<<" = ["<<vector[j].x<<"  "<<vector[j].y<<"  "<<vector[j].z<<"]"<<'\n';
	}
	productoPunto(resultadoPunto);
	cout<<"Resultado del producto punto: "<<resultadoPunto<<'\n';	
	productoCruz();
	cout<<"Resultado del producto cruz: "<<'\n';
	cout<<"productVec= ["<<productVec.x<<"  "<<productVec.y<<"  "<<productVec.z<<"]"<<'\n';
	return 0;
}

void productoCruz(){
	productVec.x=(vector[0].y*vector[1].z)-(vector[0].z*vector[1].y);
	productVec.y=(vector[0].x*vector[1].z)-(vector[0].z*vector[1].x);
	productVec.z=(vector[0].x*vector[1].y)-(vector[0].y*vector[1].x);
}

void productoPunto(int &r){
	r+=vector[0].x*vector[1].x;
	r+=vector[0].y*vector[1].y;
	r+=vector[0].z*vector[1].z;
}
