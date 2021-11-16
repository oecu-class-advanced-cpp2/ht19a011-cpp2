// cpp2_1.cpp
#include <iostream>

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

//�f������
//�^����ꂽ���l�����̐��Ŋ���A���܂���m�F����
bool is_prime(unsigned int a) {
	for (unsigned int i = 2; i < sqrt(a); i++) {
		if (a%i == 0) {
			return false;
		}
	}
	if (a == 1) {
		return false;
	}return true;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int count = 0;
	while (a < CPP2_PRIME_UPPER_LIMIT) {
		//�f������
			if (is_prime(a) == true) {
				if (--n == 0) {
					return a;
				}
			}
		//�����̑����Z
		a += d;
	}return 0;
};



int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177)<< std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;
	//return 0;
}