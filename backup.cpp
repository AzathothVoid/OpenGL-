//#include <iostream>
//#include <stack>
//#include <vector>
//
//#define N 15
//
//char map[N + (N + 1)][N + (N + 1)];
//int graph[N * N][4];
//std::vector<int> data;
//
//std::vector<int> direction(int k, bool* visited)
//{
//	int index = -1;
//	std::vector<int> pair(2);
//
//	pair[0] = -1;
//	pair[1] = -1;
//
//	for (int temp = 0; temp < data.size(); temp++)
//	{
//		if (data[temp] == k)
//		{
//			index = temp;
//			break;
//		}
//	}
//
//	int prev = index - 1;
//	int next = index + 1;
//
//	std::cout << "Node: " << k << " Next: " << next << " Prev: " << prev << std::endl;
//
//	if (index == -1 || visited[index + 1] || visited[index - 1])
//	{
//		return pair;
//	}
//
//	visited[index] = true;
//
//
//
//	if (prev != -1)
//	{
//		if (data[index - 1] = k + 1)
//		{
//			pair[1] = 2;
//		}
//		else if (data[index - 1] = k - 1)
//		{
//			pair[1] = 3;
//		}
//		else if (data[index - 1] = k + N)
//		{
//			pair[1] = 0;
//		}
//		else if (data[index - 1] = k - N)
//		{
//			pair[1] = 1;
//		}
//	}
//
//	if (data[index + 1] == k + 1)
//		pair[0] = 3;
//	else if (data[index + 1] == k - 1)
//		pair[0] = 2;
//	else if (data[index + 1] == k + N)
//		pair[0] = 1;
//	else if (data[index + 1] == k - N)
//		pair[0] = 0;
//
//
//	return pair;
//}
//
//void board()
//{
//
//	for (int i = 0; i < data.size(); i++)
//	{
//		int row = data[i] / N;
//		int column = data[i] % N;
//
//		int diff = data[i] / N;
//		row += diff + 1;
//
//		column += (column % N) + 1;
//
//
//		if (map[row][column] == '.')
//			continue;
//		else
//		{
//			int wallRow = -1;
//			int wallColumn = -1;
//			int prev = -1;
//			char character = ' ';
//
//			if (i != 0)
//				prev = data[i - 1];
//			if (prev != -1)
//			{
//				if (prev + 1 == data[i])
//				{
//					wallRow = row;
//					wallColumn = column - 1;
//				}
//				else if (prev - 1 == data[i])
//				{
//					wallRow = row;
//					wallColumn = column + 1;
//				}
//				else if (prev + N == data[i])
//				{
//					wallRow = row - 1;
//					wallColumn = column;
//				}
//				else if (prev - N == data[i])
//				{
//					wallRow = row + 1;
//					wallColumn = column;
//				}
//			}
//			if (row == 1 && column == 1)
//			{
//				map[row][column] = 'S';
//				continue;
//			}
//			if (row == (N + N) - 1 && column == (N + N) - 1)
//			{
//				map[row][column] = 'E';
//				continue;
//			}
//
//			map[row][column] = character;
//			map[wallRow][wallColumn] = character;
//		}
//	}
//
//	for (int i = 0; i < N + (N + 1); i++)
//	{
//		for (int j = 0; j < N + (N + 1); j++)
//			std::cout << map[i][j];
//		std::cout << std::endl;
//	}
//}
//
////void board()
////{
////
////	bool* visited = new bool[data.size()];
////	std::vector<int> pair(2);
////
////	for (int i = 0; i < data.size(); i++)
////		visited[i] = false;
////
////	int multiple = 0;
////
////	for (int i = 0; i < N * 2; i++)
////	{
////		std::cout << "|";
////		
////
////		for (int j = multiple; j < N + multiple; j++)
////		{
////			if (i == 0)
////			{
////				std::cout << "----";
////				continue;
////			}
////
////			pair = direction(j, visited);
////
////			if (pair[0] == 0 || pair[0] == 1 || pair[1] == 0 || pair[1] == 1)
////			{
////				std::cout << "    ";
////				continue;
////			}
////			if (pair[0] == 2 || pair[0] == 3 || pair[1] == 2 || pair[1] == 3)
////			{
////				std::cout << "    ";
////				continue;
////			}
////
////		//	if ((direction(j, visited) == 0) || (direction(j, visited) == 1))
////		//	{
////		///*		std::cout << "DIRECTION: " << direction(j, visited);
////		//		std::cout << "UP AND DOWN" << std::endl;*/
////		//		std::cout << "    ";
////		//		continue;
////		//	}
////
////		//	if ((direction(j, visited) == 2) || (direction(j, visited) == 3))
//////		//	{/*
////		//		std::cout << "DIRECTION: " << direction(j, visited);
////		//		std::cout << "LEFT AND RIGHT" << std::endl;*/
////		//		std::cout << "    ";
////		//		continue;
////		//	}
////
////			if (i % 2 == 0)
////			{				
////				std::cout << "----";
////			}
////			else
////			{				
////				std::cout << "  | ";
////			}
////			
////		}
////
////		if(i != 0)
////			multiple += N;
////		std::cout << " |" << "\n";
////	}
////}
//
//void settingArray(bool visited[N * N])
//{
//	for (int i = 0; i < N * N; i++)
//		visited[i] = false;
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			map[i][j] = 1;
//	for (int i = 0; i < N + (N - 1); i++)
//		for (int j = 0; j < N + (N - 1); j++)
//			map[i][j] = '#';
//
//}
//
//void settingGraph()
//{
//	bool visited[N * N];
//
//	settingArray(visited);
//
//	std::srand(time(0));
//
//	for (int i = 0; i < N * N; i++)
//		for (int j = 0; j < 4; j++)
//			graph[i][j] = -1;
//
//	for (int i = 0; i < N * N; i++)
//	{
//		visited[i] = true;
//
//		if ((i - 1) / N < i / N)
//		{
//			if (visited[i - 1] == false)
//			{
//				graph[i][2] = i - 1;
//				graph[i - 1][3] = i;
//			}
//		}
//		if ((i + 1) / N <= i / N)
//		{
//			if (visited[i + 1] == false)
//			{
//				graph[i][3] = i + 1;
//				graph[i + 1][2] = i;
//			}
//		}
//		if ((i - N) > 0)
//		{
//			if (visited[i - N] == false)
//			{
//				graph[i][0] = i - N;
//				graph[i - N][1] = i;
//			}
//		}
//		if ((i + N) < N * N)
//		{
//			if (visited[i + N] == false)
//			{
//				graph[i][1] = i + N;
//				graph[i + N][0] = i;
//			}
//		}
//	}
//
//	int index = 0;
//
//	std::cout << graph[index][3] << std::endl;
//	std::cout << graph[index][1] << std::endl;
//
//	if (graph[index][0] != -1)
//		std::cout << "UP" << std::endl;
//	if (graph[index][1] != -1)
//		std::cout << "DOWN" << std::endl;
//	if (graph[index][2] != -1)
//		std::cout << "LEFT" << std::endl;
//	if (graph[index][3] != -1)
//		std::cout << "RIGHT" << std::endl;
//}
//
//void DFS(int source)
//{
//	bool visited[N * N];
//
//	for (int i = 0; i < N * N; i++)
//		visited[i] = false;
//
//	std::stack<int> s;
//	std::srand(time(0));
//
//	s.push(source);
//
//	while (!s.empty())
//	{
//
//		int vertex = s.top();
//		visited[vertex] = true;
//
//		int row = vertex / N;
//		int column = vertex % N;
//
//		map[row][column] = 0;
//
//		data.push_back(vertex);
//
//		int neighbour = std::rand() % 4;
//
//		int count = 0;
//
//		for (int i = 0; i < 4; i++)
//		{
//			if (visited[graph[vertex][i]])
//				count++;
//		}
//
//		if (count == 4)
//		{
//			s.pop();
//			continue;
//		}
//
//		if (graph[vertex][neighbour] != -1 && !visited[graph[vertex][neighbour]])
//			s.push(graph[vertex][neighbour]);
//		else
//		{
//			while (graph[vertex][neighbour] == -1 || visited[graph[vertex][neighbour]])
//				neighbour = std::rand() % 4;
//			s.push(graph[vertex][neighbour]);
//		}
//
//		/*	if (graph[vertex][neighbour] != -1)
//			{
//				if (!visited[graph[vertex][neighbour]])
//					s.push(graph[vertex][neighbour]);
//			}
//			else
//			{
//
//			}*/
//
//
//
//			//while (true)
//			//{
//			//	neighbour = std::rand() % 4;
//
//			//	if (graph[vertex][neighbour] != -1)
//			//		if (visited[graph[vertex][neighbour]] == false)
//			//		{
//			//			s.push(graph[vertex][neighbour]);
//			//			break;
//			//		}
//			//	
//			//}		
//
//	}
//
//	std::cout << std::endl;
//}
//
//void display()
//{
//	for (int i = 0; i < N * N; i++)
//	{
//		if (graph[i][0] == 1)
//			std::cout << "UP ";
//		else if (graph[i][1] == 1)
//			std::cout << "DOWN ";
//		else if (graph[i][2] == 2)
//			std::cout << "LEFT ";
//		else
//			std::cout << "RIGHT ";
//	}
//}
//
////void generatingPath()
////{
////	bool visited[N * N];
////
////	DFS(graph, 0, visited);
////
////	display();
////}
//
//void creatingMap()
//{
//
//	std::srand(time(0));
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			map[i][j] = std::rand() % 2;
//		}
//	}
//
//	map[0][0] = 0;
//	map[N - 1][N - 1] = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			std::cout << map[i][j] << " ";
//		}
//
//		std::cout << std::endl;
//	}
//}
//
//int main()
//{
//	//creatingMap();
//	settingGraph();
//	DFS(0);
//	for (int i = 0; i < N + (N + 1); i++)
//		for (int j = 0; j < N + (N + 1); j++)
//		{
//			if (i == 0 || i == N + N)
//			{
//				map[i][j] = '-';
//				continue;
//			}
//			if (j == 0 || j == N + N)
//			{
//				map[i][j] = '|';
//				continue;
//			}
//
//			map[i][j] = '*';
//		}
//
//	//for (int i = 0; i < N + (N - 1); i++)
//	//{
//	//	for (int j = 0; j < N + (N - 1); j++)
//	//		std::cout << map[i][j];
//	//	std::cout << std::endl;
//	//}
//	board();
//
//
//	return 0;
//}
//
