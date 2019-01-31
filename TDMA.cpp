#include "math.h"
#include "stdio.h"
#include "iostream"
using namespace std;
int main()
{
double a[4],b[4],c[4],d[4],B[4],D[4],phi[4]; //change the array size as per length of d.

a[0]=2; a[1]=2; a[2]=1; a[3]=2; //diagonal
b[0]=3; b[1]=3; b[2]=2; b[3]=0; //superdiagonal
c[1]=1; c[2]=3; c[3]=1; c[0]=0; //subdiagonal
d[0]=8;d[1]=14; d[2]=17; d[3]=11; //RHS(d)

B[0]=b[0]/a[0];
D[0]=d[0]/a[0];

// A * phi = D
for (int n=1; n<4; n++){
	D[n]=(d[n]-c[n]*D[n-1])/(a[n]-c[n]*B[n-1]);
	B[n]=b[n]/(a[n]-c[n]*B[n-1]);
	//cout<<D[n]<<' ';
}

for(int i=3; i>=0; i--){
	phi[3]=D[3];
	phi[i]=D[i]-B[i]*phi[i+1];
	cout<<phi[i]<<' ';
}
}
