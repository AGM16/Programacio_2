#ifndef POINT2D
#define POINT2D

using namespace std;

class Point2D{
public:

	float f_px, f_py;


	//OPERATORS
	Point2D operator-(const Point2D& b)const;

	Point2D operator+(const Point2D& b)const;

	const Point2D& operator+=(const Point2D& b);

	const Point2D& operator-=(const Point2D& b);


	//Comparison
	bool operator==(const Point2D& b)const;

	bool operator!=(const Point2D& b)const;

	//Changes
	bool IsZero()const;

	Point2D& SetZero();


	//Distance to 
	float DistanceTo(const Point2D& b) const;

};

#endif