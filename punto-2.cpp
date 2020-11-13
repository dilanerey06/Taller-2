//punto-2
#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;
int maxCol(int a, int b, int c);
void typeData(int a,int b,int c);
void impData(int a,int b,int c);
void rectifier(int a,int b,int c);

int ***ptr3D;

int main(){
	srand(time(NULL));
	int n, m, k;
	cout<<"numero de caras: ";cin>>k;
	cout<<"numero de filas: ";cin>>m;
	cout<<"numero de columnas: ";cin>>n;
	ptr3D=new int**[k];
	for(int i=0; i<k; ++i){
		ptr3D[i]=new int *[m];
		for(int j=0; j<m; ++j){
			ptr3D[i][j]=new int [n];
		}
	}
	typeData(k,m,n);
	impData(k,m,n);
	cout<<"Imprimiendo valores maximos y minimos "<<'\n';
	rectifier(k,m,n);
	return 0;
}

void rectifier(int a,int b,int c){
	int max_rows, max_cols, max_matrix, max_cube, min_cube, min_rows, min_matrix;
	max_cube=ptr3D[0][0][0];
	min_cube=ptr3D[0][0][0];
	for(int i=0; i<a; ++i){
		min_matrix=ptr3D[i][0][0];
		max_matrix=ptr3D[i][0][0];
		cout<<"===================================="<<'\n';
		cout<<"Cara "<<i+1<<": "<<'\n';
		for(int j=0; j<b; ++j){
			max_rows=ptr3D[i][j][0];
			min_rows=ptr3D[i][j][0];
			for(int h=0; h<c; ++h){
				if(ptr3D[i][j][h]>max_rows){
					max_rows=ptr3D[i][j][h];	
				}
				if(ptr3D[i][j][h]<min_rows){
					min_rows=ptr3D[i][j][h];	
				}
				if(j==b-1){
					max_cols=maxCol(i,b,h);
					cout<<"max_columna "<<h+1<<" = "<<max_cols<<'\n';
				}	
			}
			cout<<"max_fila "<<j+1<<" = "<<max_rows<<'\n';
			if(max_rows>max_matrix){
				max_matrix=max_rows;
			}
			if(min_rows<min_matrix){
				min_matrix=min_rows;
			}
		}
		cout<<"max_cara = "<<max_matrix<<'\n';
		if(max_matrix>max_cube){
			max_cube=max_matrix;
		}
		if(min_matrix<min_cube){
			min_cube=min_matrix;
		}
	}
	cout<<"===================================="<<'\n';
	cout<<"Maximo del cubo: "<<max_cube<<'\n';
	cout<<"Minimo del cubo: "<<min_cube<<'\n';
}

int maxCol(int a, int b, int c){
	int max_col;
	max_col=ptr3D[a][0][c];
	for(int i=0;i<b;++i){
		if(ptr3D[a][i][c]>max_col){
			max_col=ptr3D[a][i][c];
		}
	}
	return max_col;
}

void impData(int a,int b,int c){
	cout<<"Imprimiendo el cubo"<<'\n';
	for(int i=0; i<a; ++i){
		cout<<"Cara: "<<i+1<<'\n';
		for(int j=0; j<b; ++j){
			for(int h=0; h<c; ++h){
				cout<<ptr3D[i][j][h]<<'\t';
			}
			cout<<'\n';
		}
		cout<<"===================================="<<'\n';
	}
}

void typeData(int a,int b,int c){
	for(int i=0; i<a; ++i){
		for(int j=0; j<b; ++j){
			for(int h=0; h<c; ++h){
				ptr3D[i][j][h]=rand()%101;
			}
		}
	}
}
