// ex2_main.cpp
#include <iostream>
#include <string>
#include<string.h>
#include<vector>
namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		//int num;
		int value_;
		mcxi(std::string);
		std::string to_string();
		int unit(char);
		void debug();
	};
	mcxi::mcxi(std::string s) :value_(0) {
		int count = 0;
		while (count<s.length())
		{
			int num = 0;
			if ('0' <= s[count] && s[count] <= '9') {
				num += int(s[count] - '0');
				count++;
				num *= unit(s[count]);
				count++;
				value_ += num;
			}
			else if (s[count] == 'm' || s[count] == 'c' || s[count] == 'x' || s[count] == 'i') {
				num = unit(s[count]);
				count++;
				value_ += num;
			}
			else {

			}
		}
	}
	int mcxi::unit(char s) {
		switch (s)
		{
		case 'm':
			return 1000;
			break;
		case 'c':
			return  100;
			break;
		case 'x':
			return  10;
			break;
		case 'i':
			return  1;
			break;
		}
	}

	void mcxi::debug() {
		std::cout << "value_" << value_ << std::endl;
	}

	std::string st(int& num, int div, std::string mcxi) {
		std::string str;
		if (num > div - 1) {
			if (num / div != 1) {
				str += std::to_string(num / div);
			}num = num % div;
			str += mcxi;
		}
		return str;
	}

	std::string mcxi::to_string() {
		std::string str = "";
		int num = value_;
		str += st(num, 1000, "m");
		str += st(num, 100, "c");
		str += st(num, 10, "x");
		str += st(num, 1, "i");


		return(str);
	}

	mcxi operator+  (mcxi a, mcxi b) {
		int value_ = a.value_ + b.value_;

		mcxi temp("");
		temp.value_ = value_;
		return temp;
	}

} // namespace cpp2

void test(std::string mcxi_a, std::string mcxi_b, std::string result) {
	cpp2::mcxi a0(mcxi_a);
	cpp2::mcxi b0(mcxi_b);
	cpp2::mcxi result0 = a0 + b0;
	//check(result0.to_string(), result);
	if (result0.to_string() == result) {
		std::cout << "ok" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
}

void check(std::string a, std::string b) {
	if (a == b) {
		std::cout << "ok" << std::endl;
	}
}

int main() {
	test("xi", "x9i", "3x");
	test("i", "9i", "x");
	test("c2x2i", "4c8x8i", "6cx");
	test("m2ci", "4m7c9x8i", "5m9c9x9i");
	test("9c9x9i", "i", "m");
	test("i", "9m9c9x8i", "9m9c9x9i");
	test("m", "i", "mi");
	test("i", "m", "mi");
	test("m9i", "i", "mx");
	test("9m8c7xi", "c2x8i", "9m9c9x9i");
}