#include<iostream>
#include<string>
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

class Champion{
	private:
		string name;
		double attack;
		int price;
	public:
		Champion(const string& name,const double& attack,int price):name(name),attack(attack),price(price){
		}
		friend bool operator >(const Champion& a,const Champion& b){
			return a.name>b.name;
		}
		friend ostream& operator<<(ostream& s,const Champion& c){
			return s<<"name:"<<c.name<<' '<<"attack:"<<c.attack<<' '<<"price:"<<c.price; 
		}
};

int main(){
    int a[]={4,3,9,6};
	double b[]={4.0,3.1,9.2,6.3};
	string c[]={"dog","cat","boy","apple"};
	
	sort(a,sizeof(a)/sizeof(int));
    print(a,sizeof(a)/sizeof(int));
	sort(b, sizeof(b)/sizeof(double));
	print(b,sizeof(b)/sizeof(double));
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	
	Champion d[]={Champion("Yi",70.3,450),Champion("Zed",67.8,4800),Champion("Yasuo",68.4,6300)};
	sort(d,3);
	print(d,3);
}
