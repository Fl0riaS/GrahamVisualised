#ifndef GRAHAM_H
#define GRAHAM_H

#include <string>
#include "TimeStruct.h"

namespace algo
{
	struct Point
	{
		float x, y;
		float angle = 0.0;
		int index;
		Point() {}
		Point(int index, float x, float y)
		{
			this->index = index;
			this->x = x;
			this->y = y;
		}
		Point operator -(Point a)
		{
			Point result;
			result.x = this->x - a.x;
			result.y = this->y - a.y;
			return result;
		}
	};

	struct PointArray
	{
		Point* array;
		int length;
	};

	PointArray* ReadPointsFromFile(std::string path);
	float VectorProduct(Point a, Point b);
	int CompareAngles(Point x, Point y);
	LL<Point> *Graham(PointArray* pointsArray, timeStruct* ts);
}

#endif