#pragma once

// определение точки
struct Point
{
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

bool operator < (const Point& p1, const Point& p2);


