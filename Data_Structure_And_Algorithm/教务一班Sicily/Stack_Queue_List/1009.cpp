void List::remove(int pos) {
	ListNode *T = head;
	for (int i = 0; i < pos - 1; i++) {
		T = T->next;
	}
	ListNode *K = T->next;
	T->next = T->next->next;
	delete K;
}