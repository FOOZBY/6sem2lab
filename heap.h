#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct binaryheap
{
private:
	vector<int> heap;

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
        if (left < heap.size() && heap[left] < heap[i]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
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
        if (i && heap[PARENT(i)] > heap[i])
        {
            // поменять их местами, если свойство кучи нарушено
            swap(heap[i], heap[PARENT(i)]);

            // вызываем heapify-up для родителя
            heapify_up(PARENT(i));
        }
    }

public:
    void push(int key)
    {
        // вставляем новый элемент в конец вектора
        heap.push_back(key);

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

    int top()
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
};