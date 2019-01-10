#include <cmath>
#include "vect.h"
using namespace std;

namespace VECTOR
{
	const double Rad_to_deg = 57.2957795130823;

	//private methods
	//calculates magnitude from x and y
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y*y);
	}

	void Vector::set_ang()
	{
		if ( x == 0.0 && y ==0.0 )
			ang = 0.0;
		else
			ang = atan2(y,x);
	}

	//set x from polar coordinate
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag *sin(ang);
	}

	//public methods
	Vector::Vector() //default constructor
	{
		x = y = mag = ang = 0;
		mode ='r';
	}

	Vector::Vector(double n1, double n2, char form)
	{
		mode = form;
		if ( form == 'r')
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}

		else if ( form == 'p')
		{
			mag = n1;
			ang = n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout<<"Incorrect 3rd argument tp Vector()--";
			cout<<"vector set to 0\n";
			x = y = mag = ang = 0;
			mode = 'r';
		}
	}

	void Vector::set(double n1, double n2, char form)
	{
		mode = form;
		if ( form == 'r')
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if(form == 'p')
		{
			mag = n1;
			ang = n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout<<"Incorrect 3rd argument to vector\n";
			cout<<"Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = 'r';
		}
	}

	Vector::~Vector() //destructor
	{
	}

	void Vector::polar_mode()
	{
		mode = 'p';
	}

	void Vector::rect_mode()
	{
		mode = 'r';
	}

	//operator overloading
	//add two vectors
	Vector Vector::operator +(const Vector &b) const
	{
		Vector sum;
		sum.x = x + b.xval();
		sum.y = y + b.yval();
		sum.set_ang();
		sum.set_mag();
		return (sum);
	}

	Vector Vector::operator -(const Vector &b)const
	{
		return (Vector(x-b.xval(),y-b.yval()));
	}

	//reverse sign of vector
	Vector Vector::operator-() const
	{
		return (Vector(-x,-y));
	}

	Vector Vector::operator *(double n)const
	{
		return (Vector(n*x,n*y));
	}

	//friend methods
	Vector operator*(double n, const Vector &a)
	{
		return  (a*n);
	}

	//display rectangular coordinates if mode is r
	//else diplay polar coordinate if mode is p
	std::ostream &operator<<(std::ostream &os, const Vector &v)
	{
		if ( v.modeval() == 'r')
			os<<"(x,y) = "<<v.xval()<<", "<<v.yval()<<endl;
		else if (v.modeval() == 'p')
		{
			os <<"(m,a)= "<<v.magval()<<","<<v.angval()*Rad_to_deg<<endl;
		}
		return (os);

	}

}
