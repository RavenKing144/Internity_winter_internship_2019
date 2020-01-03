#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename Iterator> 
void merge(Iterator begin, Iterator middle, Iterator end, Iterator res) {
	Iterator a = begin, b = middle, r = res;

	while (a < middle && b < end)
		if (*a < *b) *r++ = *a++;
		else *r++ = *b++;

	while (a < middle) *r++ = *a++;
	while (b < end) *r++ = *b++;
	while (begin < end) *begin++ = *res++;
}

template<typename Iterator> 
void mergesort(Iterator begin, Iterator end, Iterator res)
{
	int s = end-begin;
	if (s > 1)
	{
		Iterator middle = begin+s/2;
		mergesort(begin, middle, res);
		mergesort(middle, end, res);
		merge(begin, middle, end, res);
	}
}

int main() {
    int liist[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10};
    int sorted[10];
    mergesort(liist, liist + 10, sorted);

    for (int i = 0; i < 10; i++)
	cout << sorted[i] << " ";
	cout << endl;
	return 0;
}
