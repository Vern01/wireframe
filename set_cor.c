#include "fdf.h"

cor_t	set_cor(double x1, double y1, double x2, double y2)
{
	cor_t cor;

	cor.x1 = round(x1);
	cor.y1 = round(y1);
	cor.x2 = round(x2);
	cor.y2 = round(y2);
	return (cor);
}