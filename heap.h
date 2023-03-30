#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct binaryheap
{
private:
	vector<int> heap;

    // ������� ������ ������� `A[i]`
    int LEFT(int i) 
    {
        return (2 * i + 1);
    }

    // ������� ������� ������� `A[i]`
    int RIGHT(int i) 
    {
        return (2 * i + 2);
    }

    int PARENT(int i) 
    {
        return (i - 1) / 2;
    }

    // ����������� �������� heapify-down.
    // ���� � �������� `i` � ��� ��� ������ �������
    // �������� �������� ����
    void heapify_down(int i)
    {
        // �������� ����� � ������ ������� ���� � �������� `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int smallest = i;

        // ���������� `A[i]` � ��� ����� � ������ ��������� ����������
        // � ������� ���������� ��������
        if (left < heap.size() && heap[left] < heap[i]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // ���������� ������� � �������� ��������� � ������� ��������� �
        // �������� heapify-down ��� ��������� ��������
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }

    // ����������� �������� heapify-up
    void heapify_up(int i)
    {
        // ���������, �� �������� �� ���� � �������� `i` � ��� �������� �������� ����
        if (i && heap[PARENT(i)] > heap[i])
        {
            // �������� �� �������, ���� �������� ���� ��������
            swap(heap[i], heap[PARENT(i)]);

            // �������� heapify-up ��� ��������
            heapify_up(PARENT(i));
        }
    }

public:
    void push(int key)
    {
        // ��������� ����� ������� � ����� �������
        heap.push_back(key);

        // �������� ������ �������� � �������� ��������� heapify-up
        int index = heap.size() - 1;
        heapify_up(index);
    }

    //�������� ������
    void pop()
    {
        if (heap.size())
        {
            heap[0] = heap.back();
            heap.pop_back();
            heapify_down(0);
        }
        else
        {
            cout << "���� �����" << endl;
        }
    }

    int top()
    {
        if (heap.size())
        {
            return heap[0];
        }
        else
        {
            cout << "���� �����" << endl;
        }
    }
};