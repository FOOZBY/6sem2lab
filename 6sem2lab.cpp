#include "Dijkstra.h"

int main()
{
	setlocale(0, "");
	int start_point = 0, end_point, N = 0;
	cout << "Введите кол-во вершин: ";
	cin >> N;
	int** Graph = new int*[N];
	for (int i = 0; i < N; i++)
	{
		Graph[i] = new int[N];
	}
	cout << "введите вершину из которой хотите найти путь: ";
	cin >> start_point;
	cout << "Введите длины путей между вершинами." << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "из вершины " << i+1;
		for (int j = 0; j < N; j++)
		{
			cout << " в вершину " << j+1 << ": ";
			cin >> Graph[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Graph[i][j] << " ";
		cout << endl;
	}

	cout << "binary heap: " << endl;
	my_dij_bin(Graph, N, start_point-1);
	cout << endl << "fib heap: " << endl;
	my_dij_fib(Graph, N, start_point - 1);
	
	system("pause");
}
