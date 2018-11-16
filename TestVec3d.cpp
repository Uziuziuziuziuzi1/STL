#include"Vec3d.h"

int main(){
	Vec3d<float>a(1,2,3);
	Vec3d<double>b(1.5,2.2,3.5);
	std::cout<<a<<b<<"\n";
	Vec3d<double>c(1.9,1.1,4.1);
	std::cout<<b+c<<'\n';
}
