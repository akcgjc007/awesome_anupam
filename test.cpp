#include "avl/avl.c"

#include <iostream>
#include <chrono>
#include <set>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
using namespace std::chrono;

#define rn rand()%10000000

int main()
{
	tree *t = new_tree();
	srand(time(0));

	const int INIT_SIZE = 10000000;
	const int OPERATIONS = 1000000;
	clock_t t1, t2;
	double time_used;

	int tmp;

	// my AVL testing
	t1 = clock();
	for (int i = 0; i < INIT_SIZE; i++)
	{
		add_t(t, rn);
	}
	for (int i = 0; i < OPERATIONS; i++)
	{
		tmp = rand() % 3;
		switch (tmp)
		{
		case 0:
			add_t(t, rn);
			break;
		case 1:
			remove_t(t, rn);
			break;
		case 2:
			find_t(t, rn);
			break;

		default:
			break;
		}
	}
	t2 = clock();
	time_used = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
	cout << time_used << endl;

	// std RB tree testing
	set<int> s;
	t1 = clock();
	for (int i = 0; i < INIT_SIZE; i++)
	{
		s.insert(rn);
	}
	for (int i = 0; i < OPERATIONS; i++)
	{
		tmp = rand() % 3;
		switch (tmp)
		{
		case 0:
			s.insert(rn);
			break;
		case 1:
			s.erase(rn);
			break;
		case 2:
			s.find(rn);
			break;

		default:
			break;
		}
	}
	t2 = clock();
	time_used = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
	cout << time_used << endl;



	
	
	
	delete_tree(t);
	printf("Successfully completed.\n");
	return 0;
}