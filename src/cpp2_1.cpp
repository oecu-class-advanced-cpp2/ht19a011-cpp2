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

		//�f������
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
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
	//return 0;
}