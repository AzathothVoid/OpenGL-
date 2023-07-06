#include <iostream>
#include <stack>
#include <vector>

#define N 15

void creatingMap(int source, int destination);
void display();
void pathToNode(int node);
void settingArray();
void settingGraph();
void DFS(int source);
void settingBoard();
void pathDisplay();

char map[N + (N + 1)][N + (N + 1)];
int graph[N*N][4];
std::vector<int> data;


int main()
{		
	int choice = 0;	
	int source = 0;
	int destination = 0;

	std::cout << "Enter Source Node: " << std::endl;
	std::cin >> source;
	std::cout << "Enter Destination Node: " << std::endl;
	std::cin >> destination;
	int node = -1;

	while (true)
	{
		settingArray();
		settingGraph();
		DFS(source);
		settingBoard();
		creatingMap(source, destination);
		
		std::cout << "Press 1 for New Map" << std::endl;
		std::cout << "Press 2 for Path to a Specific Node" << std::endl;
		std::cout << "Press 0 to Exit" << std::endl;
		std::cin >> choice;
	
		if (choice == 0)
			break;		
		if (choice == 2)
		{
			std::cout << "Enter Node: " << std::endl;			
			std::cin >> node;
			pathToNode(node);
		}
	}
	
	return 0;
}

void creatingMap(int source, int destination)
{
	int sourceRow = source / N;
	int sourceColumn = source % N;

	int diffSource = source / N;
	sourceRow += diffSource + 1;

	sourceColumn += (sourceColumn % N) + 1;

	int destinationRow = destination / N;
	int destinationColumn = destination % N;

	int diffdestination = destination / N;
	destinationRow += diffdestination + 1;

	destinationColumn += (destinationColumn % N) + 1;

	for (int node = 0; node < data.size(); node++)
	{
		int row = data[node] / N;
		int column = data[node] % N;

		int diff = data[node] / N;
		row += diff + 1;

		column += (column % N) + 1;


		if (map[row][column] == '.')
			continue;
		else
		{
			int wallRow = -1;
			int wallColumn = -1;
			int prev = -1;
			char character = ' ';

			if (node != 0)
				prev = data[node - 1];
			if (prev != -1)
			{
				if (prev + 1 == data[node])
				{
					wallRow = row;
					wallColumn = column - 1;
				}
				else if (prev - 1 == data[node])
				{
					wallRow = row;
					wallColumn = column + 1;
				}
				else if (prev + N == data[node])
				{
					wallRow = row - 1;
					wallColumn = column;
				}
				else if (prev - N == data[node])
				{
					wallRow = row + 1;
					wallColumn = column;
				}
			}
			if (row == sourceRow && column == sourceColumn)
			{			
				map[row][column] = 'S';
				continue;
			}
			if (row == destinationRow && column == destinationColumn)
			{
				map[row][column] = 'E';
				continue;
			}

			map[row][column] = character;
			map[wallRow][wallColumn] = character;
		}
	}
	display();
}


void display()
{
	for (int row = 0; row < N + (N + 1); row++)
	{
		for (int column = 0; column< N + (N + 1); column++)
			std::cout << map[row][column];
		std::cout << std::endl;
	}
}

void settingArray()
{
	data.clear();
}

void settingGraph()
{
	bool visited[N * N];

	for (int node = 0; node < N * N; node++)
		visited[node] = false;

	std::srand(time(0));

	for (int node = 0; node < N * N; node++)
		for (int neigh = 0; neigh < 4; neigh++)
			graph[node][neigh] = -1;

	for (int node = 0; node< N * N; node++)
	{
		visited[node] = true;

		if ((node - 1) / N < node / N)
		{
			if (visited[node - 1] == false)
			{
				graph[node][2] = node - 1;
				graph[node - 1][3] = node;
			}
		}
		if ((node + 1) / N <= node / N)
		{
			if (visited[node + 1] == false)
			{
				graph[node][3] = node + 1;
				graph[node + 1][2] = node;
			}
		}
		if ((node - N) > 0)
		{
			if (visited[node - N] == false)
			{
				graph[node][0] = node - N;
				graph[node - N][1] = node;
			}
		}
		if ((node + N) < N * N)
		{
			if (visited[node + N] == false)
			{
				graph[node][1] = node + N;
				graph[node + N][0] = node;
			}
		}
	}
}

void DFS(int source)
{
	bool visited[N * N];

	for (int node = 0; node < N * N; node++)
		visited[node] = false;

	std::stack<int> s;
	std::srand(time(0));

	s.push(source);

	while (!s.empty())
	{

		int vertex = s.top();
		visited[vertex] = true;

		data.push_back(vertex);

		int neighbour = std::rand() % 4;

		int count = 0;

		for (int neigh = 0; neigh < 4; neigh++)
		{
			if (visited[graph[vertex][neigh]])
				count++;
		}

		if (count == 4)
		{
			s.pop();
			continue;
		}

		if (graph[vertex][neighbour] != -1 && !visited[graph[vertex][neighbour]])
			s.push(graph[vertex][neighbour]);
		else
		{
			while (graph[vertex][neighbour] == -1 || visited[graph[vertex][neighbour]])
				neighbour = std::rand() % 4;
			s.push(graph[vertex][neighbour]);
		}
	}

	std::cout << std::endl;
}


void settingBoard()
{
	for (int row = 0; row < N + (N + 1); row++)
		for (int column = 0; column< N + (N + 1); column++)
		{
			if (row == 0 || row == N + N)
			{
				map[row][column] = '-';
				continue;
			}
			if (column == 0 || column == N + N)
			{
				map[row][column] = '|';
				continue;
			}

			map[row][column] = '*';
		}

}

void pathToNode(int node)
{	
	for (int i = 1; i < data.size(); i++)
	{
		int curr = data[i];

		int currRow = data[i] / N;
		int currColumn = data[i] % N;

		int currDiff = data[i] / N;
		currRow += currDiff + 1;

		currColumn += (currColumn % N) + 1;

		map[currRow][currColumn] = '!';

		if (curr == node)
		{
			map[currRow][currColumn] = 'P';
			break;
		}

	}
	                                                                                                                                                                                                                                                                           display();
}



  