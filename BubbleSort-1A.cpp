void bubblesort1A(int A[], int n) {
	bool sorted = false;//�Ż�
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < n-1; i++) {
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				sorted = false;
			}
		}
		n--;//�Ż�
	}
}