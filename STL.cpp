#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "STL.h"

Cube::Cube(double s) : s(s)
{
	vertax p1;
	p1.m_x = 0+x;
	p1.m_y = 0+y;
	p1.m_z = 0+z;

	vertax p2;
	p2.m_x = 0+x;
	p2.m_y = 0+y;
	p2.m_z = s+z;

	vertax p3;
	p3.m_x = 0+x;
	p3.m_y = s+y;
	p3.m_z = 0+z;

	length = s - 0;
	height = s - 0;
	vertax p4;
	p4.m_x = 0+x;
	p4.m_y = s+y;
	p4.m_z = s+z;

	vertax p5;
	p5.m_x = s+x;
	p5.m_y = 0+y;
	p5.m_z = 0+z;

	vertax p6;
	p6.m_x = s+x;
	p6.m_y = 0+y;
	p6.m_z = s+z;

	vertax p7;
	p7.m_x = s+x;
	p7.m_y = s+y;
	p7.m_z = 0+z;

	vertax p8;
	p8.m_x = s+x;
	p8.m_y = s+y;
	p8.m_z = s+z;


	tri Shapedata;
	Shapedata.m_p1 = p1;
	Shapedata.m_p2 = p2;
	Shapedata.m_p3 = p3;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p2;
	Shapedata.m_p2 = p4;
	Shapedata.m_p3 = p3;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p1;
	Shapedata.m_p2 = p5;
	Shapedata.m_p3 = p2;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p2;
	Shapedata.m_p2 = p5;
	Shapedata.m_p3 = p6;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p1;
	Shapedata.m_p2 = p3;
	Shapedata.m_p3 = p5;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p5;
	Shapedata.m_p2 = p3;
	Shapedata.m_p3 = p7;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);



	Shapedata.m_p1 = p5;
	Shapedata.m_p2 = p7;
	Shapedata.m_p3 = p6;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p6;
	Shapedata.m_p2 = p7;
	Shapedata.m_p3 = p8;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);



	Shapedata.m_p1 = p2;
	Shapedata.m_p2 = p6;
	Shapedata.m_p3 = p4;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p6;
	Shapedata.m_p2 = p8;
	Shapedata.m_p3 = p4;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p3;
	Shapedata.m_p2 = p4;
	Shapedata.m_p3 = p7;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);


	Shapedata.m_p1 = p7;
	Shapedata.m_p2 = p4;
	Shapedata.m_p3 = p8;
	crossproduct(Shapedata);
	triangles.push_back(Shapedata);
	int i = 0;
}

void Cube::crossproduct(tri &data)
{
	
	vertax v1, v2;
		v1.m_x = data.m_p2.m_x - data.m_p1.m_x;
		v1.m_y = data.m_p2.m_y - data.m_p1.m_y;
		v1.m_z = data.m_p2.m_z - data.m_p1.m_z;
		v2.m_x = data.m_p3.m_x - data.m_p1.m_x;
		v2.m_y = data.m_p3.m_y - data.m_p1.m_y;
		v2.m_z = data.m_p3.m_z - data.m_p1.m_z;
		data.m_n.m_x = (v1.m_y*v2.m_z) - (v1.m_z*v2.m_y);
		data.m_n.m_y = (v1.m_z*v2.m_x) - (v1.m_x*v2.m_z);
		data.m_n.m_z = (v1.m_x*v2.m_y) - (v1.m_y*v2.m_x);
}

void Cube::write(std::string filename)
{
	std::string header_info = "solid " + filename;
	char head[80];
	strncpy_s(head, header_info.c_str(), sizeof(head) - 1);
	char attribute[2] = "0";
	unsigned long nTriLong = num_tri;
	std::ofstream myfile;
	myfile.open((filename).c_str(), std::ios::out | std::ios::binary);
	myfile.write(head, sizeof(head));
	myfile.write((char*)&nTriLong, 4);
	for (std::vector<tri>::iterator it = triangles.begin(); it != triangles.end(); it++) {
		myfile.write((char*)&it->m_n.m_x, 4);
		myfile.write((char*)&it->m_n.m_y, 4);
		myfile.write((char*)&it->m_n.m_z, 4);

		myfile.write((char*)&it->m_p1.m_x, 4);
		myfile.write((char*)&it->m_p1.m_y, 4);
		myfile.write((char*)&it->m_p1.m_z, 4);

		myfile.write((char*)&it->m_p2.m_x, 4);
		myfile.write((char*)&it->m_p2.m_y, 4);
		myfile.write((char*)&it->m_p2.m_z, 4);

		myfile.write((char*)&it->m_p3.m_x, 4);
		myfile.write((char*)&it->m_p3.m_y, 4);
		myfile.write((char*)&it->m_p3.m_z, 4);

		myfile.write(attribute, 2);
	}

	myfile.close();
}

void Design::write(std::string filename)
{
	std::string header_info = "solid " + filename;
	char head[80];
	strncpy_s(head, header_info.c_str(), sizeof(head) - 1);
	char attribute[2] = "0";
	unsigned long nTriLong = tri_n;

	std::ofstream myfile1;

	myfile1.open((filename).c_str(), std::ios::out | std::ios::binary);

	myfile1.write(head, sizeof(head));
	myfile1.write((char*)&nTriLong, 4);

	for (std::vector<tri>::iterator it = triangles_d.begin(); it != triangles.end(); it++) {

		myfile1.write((char*)&it->m_n.m_x, 4);
		myfile1.write((char*)&it->m_n.m_y, 4);
		myfile1.write((char*)&it->m_n.m_z, 4);

		myfile1.write((char*)&it->m_p1.m_x, 4);
		myfile1.write((char*)&it->m_p1.m_y, 4);
		myfile1.write((char*)&it->m_p1.m_z, 4);

		myfile1.write((char*)&it->m_p2.m_x, 4);
		myfile1.write((char*)&it->m_p2.m_y, 4);
		myfile1.write((char*)&it->m_p2.m_z, 4);

		myfile1.write((char*)&it->m_p3.m_x, 4);
		myfile1.write((char*)&it->m_p3.m_y, 4);
		myfile1.write((char*)&it->m_p3.m_z, 4);

		myfile1.write(attribute, 2);
	}

	myfile1.close();
}
void Cube::translate(int x, int y, int z)
{

}

double Cube::volume()
{
	double vol=0;
	vol = height * length;
	return  vol;
}

std::ostream &operator <<(std::ostream &os, Cube& dt)
{
	return os;
}

void Design::add(std::vector <tri> &add_item)
{
	
	for (int i = 0; i < tri_n; i++)
	{
		tri a;
		a.m_p1 = add_item.at(i).m_p1;
		a.m_p2 = add_item.at(i).m_p2;
		a.m_p3 = add_item.at(i).m_p3;
		a.m_n = add_item.at(i).m_n;
		triangles_d.push_back(a);
	}
}

int main() {
	Design d;
	double s = 10;
	Cube c(s);	
	int x = 0, y = 0, z = 0;
	c.translate(x, y, z);
	// rotate??
	std::cout << c.volume() << '\n';
	c.write("out.stl"); // how to get all my shapes into the same file
	//d.add(c); 
	d.add(triangles);
	// we found a way to pass the vector in to the add functin. but not the the class cube.
	//please see the code
	double r = 10, height = 20;
	//Cylinder cyl(r, height);
	//d.write("test.stl");
}