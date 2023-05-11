#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <chrono>
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

template <class V> class FibonacciHeap;

template <class V> struct node {
private:
	node<V>* prev;
	node<V>* next;
	node<V>* child;
	node<V>* parent;
	V value, dij_node;
	int degree;
	bool marked;
public:
	friend class FibonacciHeap<V>;
	node<V>* getPrev() { return prev; }
	node<V>* getNext() { return next; }
	node<V>* getChild() { return child; }
	node<V>* getParent() { return parent; }
	V getValue() { return value; }
	bool isMarked() { return marked; }

	bool hasChildren() { return child; }
	bool hasParent() { return parent; }
};

template <class V> class FibonacciHeap {
protected:
	node<V>* heap;
public:

	FibonacciHeap() {
		heap = _empty();
	}
	virtual ~FibonacciHeap() {
		if (heap) {
			_deleteAll(heap);
		}
	}
	node<V>* insert(V value, V dij_node) {
		node<V>* ret = _singleton(value, dij_node);
		heap = _merge(heap, ret);
		return ret;
	}
	void merge(FibonacciHeap& other) {
		heap = _merge(heap, other.heap);
		other.heap = _empty();
	}

	bool isEmpty() {
		return heap == NULL;
	}

	V getMinimum() {
		return heap->value;
	}
	V getMinimum_dij_node()
	{
		return heap->dij_node;
	}

	V removeMinimum() {
		node<V>* old = heap;
		heap = _removeMinimum(heap);
		V ret = old->value;
		delete old;
		return ret;
	}

	void decreaseKey(node<V>* n, V value) {
		heap = _decreaseKey(heap, n, value);
	}

	node<V>* find(V value) {
		return _find(heap, value);
	}
private:
	node<V>* _empty() {
		return NULL;
	}

	node<V>* _singleton(V value,V dij_node) {
		node<V>* n = new node<V>;
		n->value = value;
		n->prev = n->next = n;
		n->degree = 0;
		n->marked = false;
		n->child = NULL;
		n->parent = NULL;
		n->dij_node = dij_node;
		return n;
	}

	node<V>* _merge(node<V>* a, node<V>* b) {
		if (a == NULL)return b;
		if (b == NULL)return a;
		if (a->value > b->value) {
			node<V>* temp = a;
			a = b;
			b = temp;
		}
		node<V>* an = a->next;
		node<V>* bp = b->prev;
		a->next = b;
		b->prev = a;
		an->prev = bp;
		bp->next = an;
		return a;
	}

	void _deleteAll(node<V>* n) {
		if (n != NULL) {
			node<V>* c = n;
			do {
				node<V>* d = c;
				c = c->next;
				_deleteAll(d->child);
				delete d;
			} while (c != n);
		}
	}

	void _addChild(node<V>* parent, node<V>* child) {
		child->prev = child->next = child;
		child->parent = parent;
		parent->degree++;
		parent->child = _merge(parent->child, child);
	}

	void _unMarkAndUnParentAll(node<V>* n) {
		if (n == NULL)return;
		node<V>* c = n;
		do {
			c->marked = false;
			c->parent = NULL;
			c = c->next;
		} while (c != n);
	}

	node<V>* _removeMinimum(node<V>* n) {
		_unMarkAndUnParentAll(n->child);
		if (n->next == n) {
			n = n->child;
		}
		else {
			n->next->prev = n->prev;
			n->prev->next = n->next;
			n = _merge(n->next, n->child);
		}
		if (n == NULL)return n;
		node<V>* trees[64] = { NULL };

		while (true) {
			if (trees[n->degree] != NULL) {
				node<V>* t = trees[n->degree];
				if (t == n)break;
				trees[n->degree] = NULL;
				if (n->value < t->value) {
					t->prev->next = t->next;
					t->next->prev = t->prev;
					_addChild(n, t);
				}
				else {
					t->prev->next = t->next;
					t->next->prev = t->prev;
					if (n->next == n) {
						t->next = t->prev = t;
						_addChild(t, n);
						n = t;
					}
					else {
						n->prev->next = t;
						n->next->prev = t;
						t->next = n->next;
						t->prev = n->prev;
						_addChild(t, n);
						n = t;
					}
				}
				continue;
			}
			else {
				trees[n->degree] = n;
			}
			n = n->next;
		}
		node<V>* min = n;
		node<V>* start = n;
		do {
			if (n->value < min->value)min = n;
			n = n->next;
		} while (n != start);
		return min;
	}

	node<V>* _cut(node<V>* heap, node<V>* n) {
		if (n->next == n) {
			n->parent->child = NULL;
		}
		else {
			n->next->prev = n->prev;
			n->prev->next = n->next;
			n->parent->child = n->next;
		}
		n->next = n->prev = n;
		n->marked = false;
		return _merge(heap, n);
	}

	node<V>* _decreaseKey(node<V>* heap, node<V>* n, V value) {
		if (n->value < value)return heap;
		n->value = value;
		if (n->parent) {
			if (n->value < n->parent->value) {
				heap = _cut(heap, n);
				node<V>* parent = n->parent;
				n->parent = NULL;
				while (parent != NULL && parent->marked) {
					heap = _cut(heap, parent);
					n = parent;
					parent = n->parent;
					n->parent = NULL;
				}
				if (parent != NULL && parent->parent != NULL)parent->marked = true;
			}
		}
		else {
			if (n->value < heap->value) {
				heap = n;
			}
		}
		return heap;
	}

	node<V>* _find(node<V>* heap, V value) {
		node<V>* n = heap;
		if (n == NULL)return NULL;
		do {
			if (n->value == value)return n;
			node<V>* ret = _find(n->child, value);
			if (ret)return ret;
			n = n->next;
		} while (n != heap);
		return NULL;
	}
};