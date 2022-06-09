#include <string>
#include <fstream>
#include "Kruskal.h"
#include "LinkedList.h"
#include "BinaryHeap.h"
#include "TimeStruct.h"
#include <time.h>

namespace algo
{
	Graph* ReadGraphFromFile(std::string path)
	{
		Graph* result = new Graph;

		std::ifstream reader(path);
		std::string word;

		//wierzcholki
		reader >> word;
		int n = stoi(word);//ilosc wierzcholkow
		result->InitializeGraphNodeArray(n);
		for (int i = 0; i < n; i++)
		{
			reader >> word;
			result->graphNodeArray[i].x = std::stof(word);
			reader >> word;
			result->graphNodeArray[i].y = std::stof(word);
		}

		//krawedzie
		reader >> word;
		n = std::stoi(word);//ilosc krawedzi
		result->InitializeGraphEdgeArray(n);
		for (int i = 0; i < n; i++)
		{
			reader >> word;
			result->graphEdgeArray[i].node1 = stoi(word);
			reader >> word;
			result->graphEdgeArray[i].node2 = stoi(word);
			reader >> word;
			result->graphEdgeArray[i].cost = stof(word);
		}
		return result;
	}

	int CompareCosts(GraphEdge x, GraphEdge y)
	{
		if (x.cost - y.cost < 0)return -1;
		else if (x.cost - y.cost > 0)return 1;
		else return 0;
	}

	LL<GraphEdge>* Kruskal(Graph* gr, timeStruct *ts)
	{
		LL<GraphEdge>* MST = new LL<GraphEdge>();

		//1. Inicjalizacja Union Find
		UnionFind* uf = new UnionFind(gr->graphEdgeAmount);

		//2. Sortowanie przez kopocowanie
		clock_t timerBegin = clock();
		BinaryHeap<GraphEdge>* bh = new BinaryHeap<GraphEdge>(gr->graphEdgeArray, gr->graphEdgeAmount);
		bh->Sort(CompareCosts);
		delete bh;
		clock_t timerEnd = clock();
		ts->sortTime = (double(timerEnd - timerBegin) / CLOCKS_PER_SEC) * 1000;

		//3. Tworzenie MST
		timerBegin = clock();
		for (int i = 0; i < gr->graphEdgeAmount; i++)
		{
			//3.1, 3.2 Sprawdzanie czy zbiory sa takie same
			int find1 = uf->FindWithPathCompression(gr->graphEdgeArray[i].node1);
			int find2 = uf->FindWithPathCompression(gr->graphEdgeArray[i].node2);
			if (find1 != find2)
			{
				//Dodawanie do MST
				MST->AddToTail(gr->graphEdgeArray[i]);
				//Laczenie zbiorow
				uf->UnionUFByRank(find1, find2);
				//Sprawdzanie czy ilosc krawedzi odpowiada ilosci wierzolkow-1
				if (MST->GetSize() == gr->graphNodeAmount - 1) break;
			}
		}
		timerEnd = clock();
		ts->mainTime = (double(timerEnd - timerBegin) / CLOCKS_PER_SEC) * 1000;
		ts->fullTime = ts->mainTime + ts->sortTime;

		//4. Zwracanie MST
		return MST;
	}
}