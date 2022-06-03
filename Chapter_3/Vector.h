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

	Vector(const Vector& a);			// copy constr uctor
	Vector& operator=(const Vector& a);	// copy assignment

	double& operator[](int i);
	double& operator[](int i) const;
	int size() const;
	void push_back(double);
};

Vector operator + (const Vector& a, const Vector& b);
