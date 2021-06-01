/*					ASSIGNMENT NO.:8
Roll NO.:								Batch No.:
Title:Represent a given graph using adjacency matrix /adjacency list and find the shortest path using
Dijkstra's algorithm (single source all destination).
------------------------------------------------------------------------------------------------------*/
#include<iostream>
#define INFINITY 999

using namespace std;

class Dijkstra
{
	private:
		int adjMatrix[15][15];
		int predecessor[15],distance[15];
		bool mark[15]; 
		int source;
		int numOfVertices;
	public:
		void read();
		void initialize();
		int getClosestUnmarkedNode();
		void calculateDistance();
		void output();
		void printPath(int);
};

void Dijkstra::read()
{
	cout<<"Enter the number of vertices of the graph(should be > 0)\n";
	cin>>numOfVertices;
	while(numOfVertices <= 0) 
	{
		cout<<"Enter the number of vertices of the graph(should be > 0)\n";
		cin>>numOfVertices;
	}
		cout<<"Enter the adjacency matrix for the graph\n";
		cout<<"To enter infinity enter "<<INFINITY<<endl;
		for(int i=0;i<numOfVertices;i++) 
		{
			cout<<"Enter the (+ve)weights for the row "<<i<<endl;
			for(int j=0;j<numOfVertices;j++) 
			{	
				cout<<"\n"<<i<<","<<j<<":";
				cin>>adjMatrix[i][j];
				while(adjMatrix[i][j]<0) 
				{
					cout<<"Weights should be +ve. Enter the weight again\n";
					cin>>adjMatrix[i][j];
				}
			}	
		}

		cout<<"\nAdjacency matrix:\n";
		for(int i=0;i<numOfVertices;i++) 
		{
			for(int j=0;j<numOfVertices;j++) 
			{	
					cout<<"\t";
					cout<<adjMatrix[i][j];
			}
			cout<<"\n";	
		}
		cout<<"Enter the source vertex\n";
		cin>>source;
		while((source<0) && (source>numOfVertices-1))
		{
			cout<<"Source vertex should be between 0 and"<<numOfVertices-1<<endl;
			cout<<"Enter the source vertex again\n";
			cin>>source;
		}
}


void Dijkstra::initialize()
{
	for(int i=0;i<numOfVertices;i++) 
	{
		mark[i] = false;
		predecessor[i] = -1;
		distance[i] = INFINITY;
	}
	distance[source]= 0;
}

int Dijkstra::getClosestUnmarkedNode()
{
	int minDistance = INFINITY;
	int closestUnmarkedNode;
	for(int i=0;i<numOfVertices;i++) 
	{
		if((!mark[i]) && ( minDistance >= distance[i])) 
		{
			minDistance = distance[i];
			closestUnmarkedNode = i;
		}
	}
	return closestUnmarkedNode;
}


void Dijkstra::calculateDistance()
{
	initialize();
	int minDistance = INFINITY;
	int closestUnmarkedNode;
	int count = 0;
	while(count < numOfVertices) 
	{
		closestUnmarkedNode = getClosestUnmarkedNode();
		mark[closestUnmarkedNode] = true;
		for(int i=0;i<numOfVertices;i++) 
		{
			if((!mark[i]) && (adjMatrix[closestUnmarkedNode][i]>0) ) 
			{
				if(distance[i] > distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i])
				{
					distance[i] = distance[closestUnmarkedNode]+adjMatrix[closestUnmarkedNode][i];
					predecessor[i] = closestUnmarkedNode;
				}
			}
		}
		count++;
	}
}


void Dijkstra::printPath(int node)
{
	if(node == source)
		cout<<(char)(node + 97)<<"..";
	else if(predecessor[node] == -1)
		cout<<"No path from "<<source<<"to "<<(char)(node + 97);
	else 
	{
		printPath(predecessor[node]);
		cout<<(char) (node + 97)<<"..";
	}
}


void Dijkstra::output()
{
	for(int i=0;i<numOfVertices;i++) 
	{
		if(i == source)
			cout<<(char)(source + 97)<<".."<<source;
		else
			printPath(i);
		cout<<"->"<<distance[i]<<endl;
	}
}


int main()
{
	Dijkstra G;
	G.read();
	G.calculateDistance();
	G.output();
	return 0;
}
/*OUTPUT:
it@IT-PL-17:~/Desktop$ g++ adjmatr.cpp
it@IT-PL-17:~/Desktop$ ./a.out
Enter the number of vertices of the graph(should be > 0)
5
Enter the adjacency matrix for the graph
To enter infinity enter 999
Enter the (+ve)weights for the row 0

0,0:999

0,1:2

0,2:7

0,3:999

0,4:999
Enter the (+ve)weights for the row 1

1,0:999

1,1:999

1,2:3

1,3:8

1,4:5
Enter the (+ve)weights for the row 2

2,0:999

2,1:2

2,2:999

2,3:1

2,4:999
Enter the (+ve)weights for the row 3

3,0:999

3,1:999

3,2:999

3,3:999

3,4:4
Enter the (+ve)weights for the row 4

4,0:999

4,1:999

4,2:999

4,3:5

4,4:999

Adjacency matrix:
	999	2	7	999	999
	999	999	3	8	5
	999	2	999	1	999
	999	999	999	999	4
	999	999	999	5	999
Enter the source vertex
s
a..0->0
a..b..->2
a..b..c..->5
a..b..c..d..->6
a..b..e..->7*/
