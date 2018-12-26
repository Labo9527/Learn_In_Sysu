void List::insert(int toadd, int pos) {
	ListNode *T = head;
	for (int i = 0; i < pos - 1; i++) {
		T = T->next;
	}
	ListNode *N = new ListNode();
	N->data = toadd;
	N->next = T->next;
	T->next = N;
}