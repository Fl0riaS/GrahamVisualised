#include <string>
#include <fstream>
#include "LinkedList.h"
#include "Graham.h"
#include "BinaryHeap.h"
#include "TimeStruct.h"
#include <time.h>

namespace algo
{
	PointArray* ReadPointsFromFile(std::string path)
	{
		PointArray* result = new PointArray;

		std::ifstream reader(path);
		std::string word;

		reader >> word;
		int n = std::stoi(word);//ilosc puntkow
		result->length = n;
		result->array = new Point[n];
		for (int i = 0; i < n; i++)
		{
			result->array[i].index = i;
			reader >> word;
			result->array[i].x = std::stof(word);
			reader >> word;
			result->array[i].y = std::stof(word);
		}
		return result;
	}

	float VectorProduct(Point a, Point b)
	{
		return (b.x * a.y - a.x * b.y);
	}

	int CompareAngles(Point x, Point y)
	{
		if (x.angle - y.angle < 0)return -1;
		else if (x.angle - y.angle > 0)return 1;
		else return 0;
	}

	LL<Point>* Graham(PointArray* pointsArray, timeStruct* ts)
	{
		LL<Point> *CH = new LL<Point>();

		Point* lowest = &pointsArray->array[0];

		//szukanie najnizszego punktu
		for (int i = 1; i < pointsArray->length; i++)
		{
			if (pointsArray->array[i].y == lowest->y)
			{
				if (pointsArray->array[i].x < lowest->x)
				{
					lowest = &pointsArray->array[i];
				}
			}
			else if (pointsArray->array[i].y < lowest->y)
			{
				lowest = &pointsArray->array[i];
			}
		}

		float lowestY = lowest->y;
		float lowestX = lowest->x;

		//przesuwanie punktu na srodek ukladu wspolrzednych
		for (int i = 0; i < pointsArray->length; i++)
		{
			pointsArray->array[i].y -= lowestY;
			pointsArray->array[i].x -= lowestX;
		}

		//obliczanie katow miedzy punktami a osia OX
		for (int i = 0; i < pointsArray->length; i++)
		{
			pointsArray->array[i].angle = atan2(pointsArray->array[i].y, pointsArray->array[i].x);
		}

		//powrot punktow na ich oryginalne miejsca
		for (int i = 0; i < pointsArray->length; i++)
		{
			pointsArray->array[i].y += lowestY;
			pointsArray->array[i].x += lowestX;
		}


		//sortowanie po wartosciach katow
		clock_t timerBegin = clock();
		BinaryHeap<Point>* BH = new BinaryHeap<Point>(pointsArray->array, pointsArray->length);
		BH->Sort(CompareAngles);
		delete BH;
		clock_t timerEnd = clock();
		ts->sortTime = (double(timerEnd - timerBegin) / CLOCKS_PER_SEC) * 1000;

		//tworzenie powloki
		timerBegin = clock();
		CH->AddToTail(pointsArray->array[0]);
		CH->AddToTail(pointsArray->array[1]);
		for (int i = 2; i < pointsArray->length; i++)
		{
			CH->AddToTail(pointsArray->array[i]);
			int chSize = CH->GetSize();
			while (VectorProduct((CH->Get(chSize - 2)) - (CH->Get(chSize - 3)), (CH->Get(chSize - 1)) - (CH->Get(chSize - 2))) > 0)
			{
				CH->DeletePenultimate();
				chSize = CH->GetSize();
				if (chSize < 3)break;
			}
		}
		timerEnd = clock();
		ts->mainTime = (double(timerEnd - timerBegin) / CLOCKS_PER_SEC) * 1000;
		ts->fullTime = ts->mainTime + ts->sortTime;
		return CH;
	}
}