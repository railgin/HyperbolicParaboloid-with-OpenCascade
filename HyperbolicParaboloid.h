#ifndef SADDLE_H
#define SADDLE_H

#include <BRepBuilderAPI_MakePolygon.hxx>

class HyperbolicParaboloid
{
private:
	double a, b;
	gp_Pnt P;
	BRepBuilderAPI_MakePolygon W;
public:
	HyperbolicParaboloid(double e_a, double e_b, double e_x, double e_y) : a(e_a), b(e_b) 
	{ 
		CreateSaddle(e_x, e_y);
	};

	void CreateSaddle(double e_x, double e_y);

	BRepBuilderAPI_MakePolygon GetPolygon() const
	{
		return W;
	}
	
};

#endif