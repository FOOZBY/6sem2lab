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
	auto st = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, micro> duration = end - st;
	double time = 0;

	cout << "binary heap: " << endl;
	int* dist = new int[N];
	int M = 15000;
	for (int i = 0; i < M; i++)
	{
		st = chrono::high_resolution_clock::now();
		my_dij_bin(Graph, N, start_point - 1);
		end = chrono::high_resolution_clock::now();
		duration = end - st;
		time += duration.count();
	}
	cout << "binary heap time: " << time/M << endl;
	dist = my_dij_bin(Graph, N, start_point-1);
	/*for (int i = 0; i < N; i++) if (dist[i] != INT_MAX)
		cout << start_point << " > " << i + 1 << " = " << dist[i] << endl;
	else cout << start_point << " > " << i + 1 << " = " << "маршрут недоступен" << endl;*/

	time = 0;
	cout << endl << "fib heap: " << endl;
	for (int i = 0; i < M; i++)
	{
		st = chrono::high_resolution_clock::now();
		my_dij_fib(Graph, N, start_point - 1);
		end = chrono::high_resolution_clock::now();
		duration = end - st;
		time += duration.count();
	}
	cout << "fib heap time: " << time / M << endl;
	dist = my_dij_fib(Graph, N, start_point - 1);
	/*for (int i = 0; i < N; i++) if (dist[i] != INT_MAX)
		cout << start_point << " > " << i + 1 << " = " << dist[i] << endl;
	else cout << start_point << " > " << i + 1 << " = " << "маршрут недоступен" << endl;*/
	system("pause");
}
