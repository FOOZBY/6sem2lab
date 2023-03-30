#include "heap.h"

void Dijkstra(int **GR,int N, int st)
{
	int* distance = new int[N];//массив дистанций до грани
	int count, index, i, u, m = st + 1;// count - , index - , i - , u - , m = 
	bool *visited = new bool[N];//массив отвечающий за посещённость граней
	for (i = 0; i < N; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < N - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i < N; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i < N; i++)
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
				distance[i] = distance[u] + GR[u][i];
	}
	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}


void my_dij(int** graph, int N, int start)
{
	//graph - матрица расстояний между гранями, N - кол-во граней, start - грань, от которой ведут отчёт
	int* distance = new int[N];//массив длин путей до конкретной грани
	bool* visited = new bool[N];//массив посещаемости
	for (int i = 0; i < N; i++)
	{
		distance[i] = INT_MAX;//по умолчанию расстояние до любой грани очень большое, бесконечность в идеале
		visited[i] = 0;//ни одна грань не посещена
	}
	distance[start] = 0;// расстояние из стартовой грани равно 0, мы итак в ней
	int minindex, min, temp;
	do 
	{
		for (int  i = 0; i < N; i++)
		{
			cout << "d: " << i << " = " << distance[i] << endl;
		}
		for (int i = 0; i < N; i++)
		{
			cout << "v: " << i << " = " << visited[i] << endl;
		}
		cout << endl;
		minindex = INT_MAX;
		min = INT_MAX;
		for (int i = 0; i < N; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((!visited[i]) && (distance[i] < min))
			{ // Переприсваиваем значения
				min = distance[i];
				minindex = i;
			}
		}
		// Добавляем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minindex != INT_MAX)
		{
			for (int i = 0; i < N; i++)
			{
				if (graph[minindex][i] > 0)//есть путь из minindex в i
				{
					temp = min + graph[minindex][i];
					if (temp < distance[i])
					{
						distance[i] = temp;
					}
				}
			}
			visited[minindex] = 1;
		}
	} while (minindex < INT_MAX);

	cout << "Стоимость пути из начальной вершины до остальных:\t\n";
	for (int i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << start+1 << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << start+1 << " > " << i + 1 << " = " << "маршрут недоступен" << endl;
}