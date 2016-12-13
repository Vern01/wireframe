#include "fdf.h"

cor_t	set_cor(double x1, double y1, double x2, double y2)
{
	cor_t cor;

	cor.x1 = round(x1 + HALF_WIDTH);
	cor.y1 = round(y1 + HALF_HEIGHT);
	cor.x2 = round(x2 + HALF_WIDTH);
	cor.y2 = round(y2 + HALF_HEIGHT);
	return (cor);
}