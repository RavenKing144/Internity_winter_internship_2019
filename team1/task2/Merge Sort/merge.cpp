template<class t>
class sort {
	t *list;
	public:
		sort(t *data, int size) {
			list = data;
			mergesort(0,size-1);
		}

		void mergesort(int low, int high) {
			int mid;
			if(low < high) {
				mid = (low + high) /2;
				mergesort(low, mid);
				mergesort(mid + 1, high);
				merge(low, high, mid);
			}
		}

		void merge(int low, int high, int mid) {
			t temp[10];
			int i = low, j, l = low, m = mid + 1;
			while(l <= mid && m <= high) {
				if(list[l] <= list[m]) {
					temp[i] = list[l];
					l++;
				}
				else {
					temp[i] = list[m];
					m++;
				}
				i++;
			}
			if(l > mid) {
				for(j = m; j <= high; j++) {
					temp[i] = list[j];
					i++;
				}
			}
			else {
				for(j = l; j <= mid; j++) {
					temp[i] = list[j];
					i++;
				}
			}
			for(j = low; j <= high; j++)
				list[j] = temp[j];
		}
};
