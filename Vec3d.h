#pragma once

#include<iostream>

template<typename T>
class Vec3d {
private:
	T x, y, z;
public:
	Vec3d(T x, T y, T z) {}
	friend Vec3d<T> operator +(const Vec3d<T>& a, const Vec3d<T>& b)
	{
		return Vec3d<T>(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	friend std::ostream& operator<<(std::ostream& out, const Vec3d<T>& c)
	{
		return out << "( " << c.x << ", " << c.y << ", " << c.z << ")" << "\n";
	}
};

