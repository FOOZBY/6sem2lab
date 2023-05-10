#include "heap.h"

void Dijkstra(int **GR,int N, int st)
{
	int* distance = new int[N];//������ ��������� �� �����
	int count, index, u, m = st + 1;// count - ���������� �� ���� ��������, ����� ���������, index - ������ ��������, �������� ����������� ���������� �� ��������� �������,
	//m = ��� ��������� ������
	bool *visited = new bool[N];//������ ���������� �� ������������ ������
	for (int i = 0; i < N; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count < N - 1; count++)//N-1 ��� ��� ����� ������� ���� ������������ �������, �� ��� ����� �� �������� ���������� �� ��
	{
		int min = INT_MAX;
		for (int i = 0; i < N; i++)//������� �� ������������ ������ ��, � ������� ����� ��������� ��������� �� ��������� �������
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; u = i;
			}
		//u - �������(������������) � ����������� ����������� �� ��������� �������, ��������� ������� � ������ �������
		visited[u] = true;// �������� ������� ��� ����������
		for (int i = 0; i < N; i++)
			/*���� ������� ������������
			���� ���������� ����� ����� ���������������� ���������
			���������� �� ��������� ����� �� ��������������� �� �������������
			����� ���������� �� ��. ����� � ����� �� ���� ����� �� ���������(i) ������,
			��� ���������� �� ��. ����� �� ����� i,
			�� ������������� ���������� �� ��. ����� �� ����� i*/
			
			if (!visited[i] && GR[u][i] && distance[u] != INT_MAX && distance[u] + GR[u][i] < distance[i])
			{
				distance[i] = distance[u] + GR[u][i];
			}
	}
	cout << "��������� ���� �� ��������� ������� �� ���������:\t\n";
	for (int i = 0; i < N; i++) if (distance[i] != INT_MAX)
		cout << m << " > " << i + 1 << " = " << distance[i] << endl;
	else cout << m << " > " << i + 1 << " = " << "������� ����������" << endl;
}


void my_dij_bin(int** graph, int N, int start)
{
	int* dist = new int[N];
	binaryheap q;
	for (int i = 0; i < N; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[start] = 0;
	q.push(dist[start], start);
	while (!q.empty())
	{
		pair<int, int> u = q.top();
		q.pop();
		for (int i = 0; i < N; i++)
		{
			int temp = graph[u.second][i];
			if (graph[u.second][i] && dist[u.second] + graph[u.second][i] < dist[i])
			{
				{
					dist[i] = dist[u.second] + graph[u.second][i];
					q.push(dist[i], i);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) if (dist[i] != INT_MAX)
		cout << start+1 << " > " << i + 1 << " = " << dist[i] << endl;
	else cout << start + 1 << " > " << i + 1 << " = " << "������� ����������" << endl;
}

void my_dij_fib(int** graph, int N, int start)
{
	int* dist = new int[N];
	FibonacciHeap<int> q;
	for (int i = 0; i < N; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[start] = 0;
	q.insert(dist[start], start);
	while (!q.isEmpty())
	{
		int u_dist = q.getMinimum();
		int u = q.getMinimum_dij_node();
		q.removeMinimum();
		for (int i = 0; i < N; i++)
		{
			if (graph[u][i] && dist[u] + graph[u][i] < dist[i])
			{
				{
					dist[i] = dist[u] + graph[u][i];
					q.insert(dist[i], i);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) if (dist[i] != INT_MAX)
		cout << start + 1 << " > " << i + 1 << " = " << dist[i] << endl;
	else cout << start + 1 << " > " << i + 1 << " = " << "������� ����������" << endl;
}