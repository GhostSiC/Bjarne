#pragma once

// abstract class
class Container
{
public:
	virtual double& operator[](int) = 0; // pure virtual function
	virtual int size() const = 0;
	virtual ~Container() {}
};

// A class that provides the interface to a variety of other classes is often called a polymorphic type