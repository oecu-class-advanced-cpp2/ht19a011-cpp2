// cpp2_1.cpp
#include <iostream>
using namespace std;

#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */

bool is_prime(unsigned int a) {
	for (unsigned int i = 2; i < a; i++) {
		if (a%i == 0) {
			return true;
			//cout << "cnt" <<i<< endl;
		}
	}return false;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int count = 0;
	int number = 0;
	bool test = 0;
	while (a < CPP2_PRIME_UPPER_LIMIT) {
		//unsigned int ki = a + number*d;
		//number++;

		//素数判定
			if (is_prime(a) == false) {
				//cout << "count" << endl;
				count++;
			}
		
		if (count == n) {
			//cout << "cnt" << count << endl;
			return a;
		}
		a += d;
	}return 0;
};



int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	// 以下、同様に、入出力例通りになるか確認せよ。
	//return 0;
}