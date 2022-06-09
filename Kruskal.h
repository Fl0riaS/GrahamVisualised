#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <string>
#include "LinkedList.h"
#include "TimeStruct.h"

namespace algo
{
	struct UnionFind
	{
		int* parent, * rank;

		void UnionUFByRank(int i, int j)
		{
			int iRoot = FindWithPathCompression(i);
			int jRoot = FindWithPathCompression(j);
			if (rank[i] < rank[j]) parent[i] = jRoot;
			else if (rank[i] > rank[j]) parent[j] = iRoot;
			else
			{
				parent[i] = jRoot;
				rank[j]++;
			}
		}
		void UnionUF(int i, int j)
		{
			parent[i] = j;
		}
		int FindWithPathCompression(int i)
		{
			if (i == parent[i])return i;
			else
			{
				parent[i] = FindWithPathCompression(parent[i]);
				return parent[i];
			}
		}
		int Find(int i)
		{
			if (i == parent[i])return i;
			else Find(parent[i]);
		}
		UnionFind(int n)
		{
			parent = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; i++)
			{
				parent[i] = i;
				rank[i] = 0;
			}
		}
	};

	struct GraphNode
	{
		float x, y;
		GraphNode(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
		GraphNode() {}
	};

	struct GraphEdge
	{
		int node1, node2;
		float cost;
		GraphEdge(int node1, int node2, float cost)
		{
			this->node1 = node1;
			this->node2 = node2;
			this->cost = cost;
		}
		GraphEdge() {}
	};

	struct Graph
	{
		int graphEdgeAmount, graphNodeAmount;
		GraphEdge* graphEdgeArray = nullptr;
		GraphNode* graphNodeArray = nullptr;

		void InitializeGraphEdgeArray(int n)
		{
			graphEdgeArray = new GraphEdge[n];
			graphEdgeAmount = n;
		}
		void InitializeGraphNodeArray(int n)
		{
			graphNodeArray = new GraphNode[n];
			graphNodeAmount = n;
		}
	};

	Graph* ReadGraphFromFile(std::string path);
	int CompareCosts(GraphEdge x, GraphEdge y);
	LL<GraphEdge>* Kruskal(Graph* gr, timeStruct *ts);
}

#endif