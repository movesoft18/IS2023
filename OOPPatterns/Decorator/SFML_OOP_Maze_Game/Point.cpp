#include "Point.h"
bool operator < (const Point& p1, const Point& p2)
{
	return p1.x * 1023 + p1.y < p2.x * 1023 + p2.y;
}