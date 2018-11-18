#include<iostream>
#include<fstream>
using namespace std; 

class Design{
public:
	Design(){
	};
	template<typename T>
	void add(T a){
	}
	void write(const char* a){
	}
};

class Cube{
private:
	double x,y,z,a;
public:
	Cube(double a):a(a){
	};
	void translate(double xx,double yy,double zz){
		x=xx;
		y=yy;
		z=zz;
	}
	double volume(){
		return a*a*a;
	}
	void write(const char* a){
		ofstream out;
		out.open(a);
		out<<"Center:"<<x<<","<<y<<","<<z<<"edge:"<<a<<endl;
		out.close();
	}
};

class Cylinder{
private:
	double r,h;
public:
	Cylinder(double r,double h):r(r),h(h){
	}
};
int main() {
	Design d;
	double s = 10;
	Cube c(s);
	c.translate(0,0,0);
	// rotate??
	cout << c.volume() << '\n';
	c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
	double r = 10, height  = 20;
	Cylinder cyl(r, height);
	d.add(c);
	d.write("test.stl");
}
