#ifndef ASSIGNMENT7_H
#define ASSIGNMENT7_H

#include <vector>
using namespace std;

void build_heap(vector <int> & v, int heap_size, bool (*compar) (int, int));
void heapify(vector <int> & v, int heap_size, int r, bool (*compar) (int, int));
bool less_than(int e1, int e2);
bool greater_than(int e1, int e2);
void heap_sort(vector <int> & v, int heap_size, bool (*compar) (int, int));
int extract_heap(vector <int> & v, int& heap_size, bool (*compar) (int, int));
void print_vector(vector <int> & v, int pos, int size);

#endif
