#include "Dijkstra.h"

int main()
{
	setlocale(0, "");
	int start_point = 0, N = 0;
	cout << "Введите кол-во граней: ";
	cin >> N;
	int** Graph = new int*[N];
	for (int i = 0; i < N; i++)
	{
		Graph[i] = new int[N];
	}
	cout << "введите грань из которой хотите найти пути до остальных граней: ";
	cin >> start_point;
	cout << "Введите длины путей между гранями." << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "из грани " << i+1;
		for (int j = 0; j < N; j++)
		{
			cout << " в грань " << j+1 << ": ";
			cin >> Graph[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Graph[i][j];
		cout << endl;
	}
	my_dij(Graph, N, start_point-1);
	system("pause");
}
