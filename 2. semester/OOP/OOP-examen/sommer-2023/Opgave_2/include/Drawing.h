#pragma once
#include <vector>
#include "Shape.h"

class Drawing : public Shape
{
public:
	Drawing(int id);
	~Drawing() override;
	void print() const override;
	double area() const override;
	double circumference() const override;
	void add(Shape* shape);

private:
	int id; //den har åbenbart en attribut id selvom den ikke er angivet i diagrammet
	std::vector<Shape*> shapes;
};
