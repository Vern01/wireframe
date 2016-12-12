#include "fdf.h"

void      set_line_info(line_t *line, cor_t cor)
{
    line->dx = cor.x2 - cor.x1;
    line->dy = cor.y2 - cor.y1;
    line->eps = 0;
}