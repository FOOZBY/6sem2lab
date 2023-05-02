#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct binaryheap
{
private:
	vector<pair<int, int>> heap;

    // вернуть левого потомка `A[i]`
    int LEFT(int i) 
    {
        return (2 * i + 1);
    }

    // вернуть правого потомка `A[i]`
    int RIGHT(int i) 
    {
        return (2 * i + 2);
    }

    int PARENT(int i) 
    {
        return (i - 1) / 2;
    }

    // Рекурсивный алгоритм heapify-down.
    // Узел с индексом `i` и два его прямых потомка
    // нарушает свойство кучи
    void heapify_down(int i)
    {
        // получить левый и правый потомки узла с индексом `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int smallest = i;

        // сравниваем `A[i]` с его левым и правым дочерними элементами
        // и находим наименьшее значение
        if (left < heap.size() && heap[left].first < heap[i].first) 
        {
            smallest = left;
        }

        if (right < heap.size() && heap[right].first < heap[smallest].first) 
        {
            smallest = right;
        }

        // поменяться местами с дочерним элементом с меньшим значением и
        // вызовите heapify-down для дочернего элемента
        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify_down(smallest);
        }
    }

    // Рекурсивный алгоритм heapify-up
    void heapify_up(int i)
    {
        // проверяем, не нарушают ли узел с индексом `i` и его родитель свойство кучи
        if (i && heap[PARENT(i)].first > heap[i].first)
        {
            // поменять их местами, если свойство кучи нарушено
            swap(heap[i], heap[PARENT(i)]);

            // вызываем heapify-up для родителя
            heapify_up(PARENT(i));
        }
    }

public:
    bool empty()
    {
        return heap.empty();
    }

    void push(int key, int ind)
    {
        // вставляем новый элемент в конец вектора
        heap.push_back({key, ind});

        // получаем индекс элемента и вызываем процедуру heapify-up
        int index = heap.size() - 1;
        heapify_up(index);
    }

    //удалаяет корень
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
            cout << "Куча пуста" << endl;
        }
    }
    // возвращает минимальный элемент кучи(вершину)
    pair<int, int> top()
    {
        if (heap.size())
        {
            return heap[0];
        }
        else
        {
            cout << "Куча пуста" << endl;
        }
    }

    void show()
    {
        int i = 0;
        int k = 1;
        while (i < heap.size()) {
            while ((i < k) && (i < heap.size())) {
                cout << heap[i].first << " ";
                i++;
            }
            cout << endl;
            k = k * 2 + 1;
        }
    }
};