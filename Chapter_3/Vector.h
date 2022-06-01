#pragma once
#include <stdexcept>

class Vector
{
private:
	double* elem;
	int sz;
public:
	Vector(int s);
	Vector(std::initializer_list<double> lst);
	~Vector() { delete[] elem; }
	
	double& operator[](int i);
	int size() const;
	void push_back(double);
};

