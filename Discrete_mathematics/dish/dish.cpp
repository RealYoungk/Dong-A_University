#include <iostream>
#include<fstream>
using namespace std;

class Dish {
private:
	int high;	// ������ ����
	int many;	// ������ ����
	char *arr = new char[many];	// ������ ���
public:
	Dish(int many, char arr[]) {
		this->high = 10;
		this->many = many;
		this->arr = arr;
	}	//	������
	int howHigh() {
		for (int i = 1; i < many; i++) {
			if (arr[i] == arr[i-1]) {
				this->high = this->high + 5;
			}
			/*else if(arr[i] =! arr[i-1]){
				this->high = this->high + 10;
			}*/ // �̰� �� �ȵŴ��� ����
			else {
				this->high = this->high + 10;
			}
		}
		return this->high;
	}	// ���� ���ϴ� �Լ�
};

int main() {
	ofstream outFile("dish.out");	// ���� ����ϴ°�
	ifstream inFile("dish.inp");	// ���� �д°�

	int count;	// ��� ���̸� Ȯ���Ұ���
	inFile >> count;	// ù���� ���� �б�

	for (int i = 0; i < count; i++) {

		int many;	// ������ ����
		inFile >> many;		// ��°���� ���ü� �б�

		char *arr = new char[many];	// ���ø�� �迭 �����Ҵ�
		for (int i = 0; i < many; i++) {
			inFile >> arr[i];
		}	//	���ø�� �Է�
		
		Dish d(many, arr);
		outFile << d.howHigh() << '\n';

		delete[] arr;	// ���ù迭 �����Ҵ� ����
	}
}