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
		void debug();
	};
	mcxi::mcxi(std::string s) :value_(0) {
		int count = 0;
		while (count<s.length())
		{
			int num = 0;
			if ('0' <= s[count] && s[count] <= '9') {
				num += int(s[count] - '0');
				//std::cout << s[count] << "aa" << num << std::endl;
				count++;
				switch (s[count])
				{
				case 'm':
					num *= 1000;
				case 'c':
					num *= 100;
				case 'x':
					num *= 10;
				case 'i':
					num *= 1;
				}count++;
				value_ += num;
			}
			else {
				switch (s[count])
				{
				case 'm':
					num = 1000;
					break;
				case 'c':
					num = 100;
					break;
				case 'x':
					num = 10;
					break;
				case 'i':
					num = 1;
					break;
				}
				count++;
				value_ += num;
				std::cout << "value" << value_ << std::endl;
			}
		}
	}
	void mcxi::debug() {
		std::cout << "kkk" << value_ << std::endl;
	}

	std::string mcxi::to_string() {
		std::string str = "";
		int num = value_;
		int temp = 0;
		if (num > 999) {
			if (num / 1000 != 1) {
				str += num / 1000;
				num = num % 1000;
			}
			str += 'm';
		}
		return(str);
	}

	mcxi operator+  (mcxi a, mcxi b) {
		mcxi temp("");
		return temp;
	}

} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	a0.debug();
	cpp2::mcxi b0("x9i");
	b0.debug();
	cpp2::mcxi result0 = a0 + b0;
	result0.debug();
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::mcxi a1("i");
	a1.debug();
	cpp2::mcxi b1("9i");
	b1.debug();
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}