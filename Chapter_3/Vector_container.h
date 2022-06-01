#pragma once
#include "Vector.h"
#include "Container.h"
#include <list>

class Vector_container : public Container
{
	Vector v;
public:
	Vector_container(int s) : v(s) {}
	~Vector_container() {}

	double& operator[](int i) { return v[i]; }
	int size() const { return v.size(); }
};

class List_container : public Container 
{
	std::list<double> ld;
public:
	List_container() {}
	List_container(std::initializer_list<double> il) : ld{ il } {}
	~List_container() {}
	double& operator[](int i) {
		for (auto& x : ld)
		{
			if (i == 0) return x;
			--i;
		}
		throw std::out_of_range("List container");
	}
	int size() const { return ld.size(); }

};
