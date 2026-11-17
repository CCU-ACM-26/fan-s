#include <iostream>
#include"random"
using namespace std;
#include"random"


int getrandom(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

int main(){

	int num = getrandom(1, 100);
	int guess_num;
	cout << "请第一次猜一下数字: ";
	cin >> guess_num;
	int guess_count = 1;
	while (guess_num != num) {

		guess_count++;
		cout << "不好意思，你猜错了。" << endl;
		if (guess_num < num) {
			cout << "猜小了，请再试一次: ";
			cin >> guess_num;
		}
		else {
			cout << "猜大了，请再试一次: ";
			cin >> guess_num;
		}
		
	}
	cout << "恭喜你，猜对了！" << endl;

	return 0;
}

