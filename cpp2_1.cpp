// cpp2_1.cpp
#include <iostream>
using namespace std;

#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
*/
/* -------------------------------------------------------------- */

bool Prime(unsigned int a) {
	for (int i = 2; i < a; i++) {
		if (a%i == 0) {
			return(false);
		}
		return(true);
	}
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int count = 0;
	int number = 0;
	while(number < CPP2_PRIME_UPPER_LIMIT) {
		a = a + number*d;
		number++;
		std::cout << a << std::endl;
		if (Prime(a)) {
			count++;
			
		}
		if (count == n) {
			return (a);
		}
	}return(1);
};



int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	return 0;
}