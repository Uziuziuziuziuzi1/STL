/*
HW templates Li Jiang
*/
#include <iostream>
#include <string>
using namespace std;

template<typename T>
void sort(T x[], int n) {
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

int main() {
	int a[]={4,3,9,6};
	double b[]={4.0,3.1,9.2,6.3};
	string c[]={"dog","cat","boy","apple"};
	
	sort(a,sizeof(a)/sizeof(int));
    print(a,sizeof(a)/sizeof(int));
	sort(b, sizeof(b)/sizeof(double));
	print(b,sizeof(b)/sizeof(double));
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
}
