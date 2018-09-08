int countOnes(unsigned int n) {
	int ones = 0;
	while (n > 0) {
		ones += (1 & n);//1:0000 0001
		n >>= 1;//ÓÒÒÆ
	}
	return ones;
}