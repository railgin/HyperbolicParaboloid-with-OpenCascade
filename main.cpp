#include "main.h"

int main()
{ 

	Viewer vout(100, 100, 500, 500);

	//creating saddle
	HyperbolicParaboloid Parab(1, 1, 10., 11.);
	TopoDS_Shape A = Parab.GetPolygon().Shape();

	//write data to step file
	STEPControl_Writer writer;
	writer.Transfer(A, STEPControl_AsIs);
	writer.Write("HyperbolicParaboloid.stp");

	//viewer (if needed)
	vout << A;
	vout.StartMessageLoop();

	

	
	

	return 0;
}
