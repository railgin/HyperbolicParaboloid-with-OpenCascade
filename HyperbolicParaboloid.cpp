#include "HyperbolicParaboloid.h"

void HyperbolicParaboloid::CreateSaddle(double max_x, double max_y)
{
	int i = 0, j = 0;
	for (double x = -max_x; x < max_x; x += 0.1)
	{
		j = 0;
		P.SetX(i);
		for (double y = -max_y; y < max_y && x != y; y += 0.1)
		{
			P.SetY(j);
			P.SetZ(a * x * x - b * y * y);

			W.Add(P);
			j++;
		}
		i++;
	}
}