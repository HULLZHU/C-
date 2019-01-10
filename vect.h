#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>

namespace VECTOR
{
	class Vector
	{
	private:
		//data field
		double x;
		double y;
		double mag;
		double ang;
		char mode;
		//private method
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double n1,double n2, char form ='r');\
		void sett(double n1, double n2, char form = 'r');
		~Vector();
		double xval() const {return (x);};
		double yval() const {return (y);};
		double magval()const {return (mag);};
		double angval()const {return (ang);};
		void polar_mode();
		void rect_mode();
		//operator overloading
		Vector operator+(const Vector &b)const;
		Vector operator-(const Vector &b)const;
		Vector operator-()const;
		Vector operator*(double n);
		//friends
		friend Vector operator*(double n, const Vector &a);
		friend std::ostream &operator<<(std::ostream, const Vector &v);
	};
}

#endif
