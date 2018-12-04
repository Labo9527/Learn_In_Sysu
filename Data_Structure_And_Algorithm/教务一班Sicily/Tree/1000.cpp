#include <iostream>
#include <string>

using namespace std;

int Count = 1;
//https://blog.csdn.net/huangjq36SYSU/article/details/49980671?locationNum=3&fps=1
//参考BLOG如上，已看懂
void Find(string pre,string post) {
	if(pre.length() == 1)
		return;
	if(pre[1] == post[post.length() - 2]) {
		Count *= 2;
		pre = pre.substr(1);
		post = post.substr(0,post.length() - 1);
		Find(pre, post);
		return;
	}
	int indexl = 1, indexr = 0;
	string lpre, lpost, rpre, rpost;
	while (1) {
		lpre += pre[indexl++];
		lpost += post[indexr++];
		if (pre[1] == post[indexr - 1])
			break;
	}
	while (indexl != pre.length()) {
		rpre += pre[indexl++];
		rpost += post[indexr++];
	}
	Find(lpre, lpost);
	Find(rpre, rpost);
}

int main() {
	string pre, post;
	cin >> pre >> post;
	Find(pre, post);
	cout << Count;
	return 0;
}