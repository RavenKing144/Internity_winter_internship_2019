template <class Iterator>
void build_heap (Iterator start, Iterator stop) {
	unsigned int heapSize = stop - start;
	for (int i = heapSize / 2; i >= 0; i--)
		adjust_heap(start, heapSize, i);
}

template <class Iterator>
void sort_heap (Iterator start, Iterator stop) {
	unsigned int lastPosition = stop - start - 1;
	while (lastPosition > 0) {
		swap(start[0], start[lastPosition]);
		adjust_heap(start, lastPosition, 0);
		lastPosition--;
		}
}

template <class Iterator>
void heap_sort(Iterator start, Iterator stop) {	
	build_heap (start, stop);
	sort_heap (start, stop);
}

