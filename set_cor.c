#include "fdf.h"

cor_t	set_cor(int x1, int y1, int x2, int y2)
{
	cor_t cor;

	cor.x1 = x1 + 7;
	cor.y1 = y1 + 7;
	cor.x2 = x2 + 7;
	cor.y2 = y2 + 7;
	return (cor);
}