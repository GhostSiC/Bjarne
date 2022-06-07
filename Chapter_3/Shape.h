#pragma once

class Shape
{
};

/*
public:

	Shape(const Shape&) = delete;		// no copy operations
	Shape& operator=(Shape&) = delete;
	
	Shape(const Shape&&) = delete;		// no move operations
	Shape& operator=(Shape&&) = delete;

	virtual Point center() const = 0;
	virtual void move(Point to) = 0;

	virtual void draw() const = 0;
	virtual void rotate(int angel) = 0;

	virtual ~Shape(){}
};

class Circle : public Shape {
public:
	Circle(Point p, int rr);

	Point center() const { return x; }
	void move(Point to) { x = to; }

	void draw() const;
	void rotate(int angel) {}
private:
	Point x;
	int r;
};

class Smiley : public Circle {
public:
	Smiley(Point p, int r) : Circle{ p,r }, mounth{ nullptr }{}

	~Smiley() 
	{
		delete mounth;
		for (auto& p : eyes) delete p;
	}

	void move(Point to);
	void draw() const;
	void roatet(int);

	void add_eye(Shape* s) { eyes.push_back(s); }
	void set_mouth(Shape* s);
	virtual void wink(int i);

private:
	vector<Shape* p> eyes;
	Shape* mouth;
};
*/