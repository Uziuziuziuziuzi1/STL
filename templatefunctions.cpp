#include<iostream>
#include<string>
using namespace std;

template<typename T>
void insertionSort(T x[], int n) {
	for (int j = 0; j < n-1; j++) {
		for (int i = 0; i < n-1; i++)
			if (x[i] > x[i+1]) {
				swap(x[i],x[i+1]);
			}
	}
}
template<typename T>
void print(T x[],int n){
	for(int i=0;i<n;i++){
		cout<<x[i]<<' ';
	}
	cout<<"\n";
}
template<typename T>
T sum(T x[],int n){
	T a=0;
	for(int i=0;i<n;i++){
		a+=x[i];
	} 
	return a;
}


int main(){
    int a[]={5,4,3,1,7,8,9,2,1};
    insertionSort(a,sizeof(a)/sizeof(int));
    print(a,sizeof(a)/sizeof(int));
    
	double b[]={5.5,4.5,1.2,2.9,9.2,5.2};
	insertionSort(b, sizeof(b)/sizeof(double));
	print(b,sizeof(b)/sizeof(double));
	
	cout<<sum(a,sizeof(a)/sizeof(int))<<"\n";
	cout<<sum(b,sizeof(b)/sizeof(double))<<"\n";
	
	string c[]={"yo","ho","test","foo","bar"};
	insertionSort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	
}
