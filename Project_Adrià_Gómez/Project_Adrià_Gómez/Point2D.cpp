#include "math.h"
#include "Point2D.h"

//---------------------------------
//OPERATORS
//---------------------------------
Point2D Point2D::operator-(const Point2D& b)const
{
	Point2D res;

	res.f_px = f_px - b.f_px;
	res.f_py = f_py - b.f_py;

	return(res);
}


Point2D Point2D::operator+(const Point2D& b) const
{
	Point2D res;

	res.f_px = f_px + b.f_px;
	res.f_py = f_py + b.f_py;

	return(res);
}


const Point2D& Point2D::operator+=(const Point2D& b)
{
	f_px += b.f_px;
	f_py += b.f_py;

	return(*this);
}


const Point2D& Point2D::operator-=(const Point2D& b)
{
	f_px -= b.f_px;
	f_py -= b.f_py;

	return(*this);

}


//-------------------------------------
//COMPARISONS
//------------------------------------
bool Point2D::operator==(const Point2D& b)const
{

	return(f_px == b.f_px && f_py == b.f_py);

}

bool Point2D::operator!=(const Point2D& b)const
{

	return(f_px != b.f_px || f_py != b.f_py);

}



//-------------------------------------
//CHANGES
//-------------------------------------
Point2D& Point2D::SetZero()
{
	f_px = f_py = 0.0f;
	return(*this);
}

bool Point2D::IsZero()const
{
	return (f_px == 0.0f && f_py == 0.0f);

}



//-------------------------------------
//DISTANCES TO 
//-------------------------------------
float Point2D::DistanceTo(const Point2D& b)const
{
	float f_px2 = f_px - b.f_px;
	float f_py2 = f_py - b.f_py;

	return (sqrtf((f_px2 * f_px2) + (f_py2 * f_py2)));
}




