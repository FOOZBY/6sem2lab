#include "heap.h"

void Dijkstra(int **GR,int N, int st)
{
	int* distance = new int[N];//������ ��������� �� �����
	int count, index, i, u, m = st + 1;// count - , index - , i - , u - , m = 
	bool *visited = new bool[N];//������ ���������� �� ������������ ������
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
	cout << "��������� ���� �� ��������� ������� �� ���������:\t\n";
	for (i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "������� ����������" << endl;
}


void my_dij(int** graph, int N, int start)
{
	//graph - ������� ���������� ����� �������, N - ���-�� ������, start - �����, �� ������� ����� �����
	int* distance = new int[N];//������ ���� ����� �� ���������� �����
	bool* visited = new bool[N];//������ ������������
	for (int i = 0; i < N; i++)
	{
		distance[i] = INT_MAX;//�� ��������� ���������� �� ����� ����� ����� �������, ������������� � ������
		visited[i] = 0;//�� ���� ����� �� ��������
	}
	distance[start] = 0;// ���������� �� ��������� ����� ����� 0, �� ���� � ���
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
		{ // ���� ������� ��� �� ������ � ��� ������ min
			if ((!visited[i]) && (distance[i] < min))
			{ // ��������������� ��������
				min = distance[i];
				minindex = i;
			}
		}
		// ��������� ��������� ����������� ���
		// � �������� ���� �������
		// � ���������� � ������� ����������� ����� �������
		if (minindex != INT_MAX)
		{
			for (int i = 0; i < N; i++)
			{
				if (graph[minindex][i] > 0)//���� ���� �� minindex � i
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

	cout << "��������� ���� �� ��������� ������� �� ���������:\t\n";
	for (int i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << start+1 << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << start+1 << " > " << i + 1 << " = " << "������� ����������" << endl;
}