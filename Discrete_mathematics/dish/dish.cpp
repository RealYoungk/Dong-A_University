#include <iostream>
#include<fstream>
using namespace std;

class Dish {
private:
	int high;	// 접시의 높이
	int many;	// 접시의 개수
	char *arr = new char[many];	// 접시의 모양
public:
	Dish(int many, char arr[]) {
		this->high = 10;
		this->many = many;
		this->arr = arr;
	}	//	생성자
	int howHigh() {
		for (int i = 1; i < many; i++) {
			if (arr[i] == arr[i-1]) {
				this->high = this->high + 5;
			}
			/*else if(arr[i] =! arr[i-1]){
				this->high = this->high + 10;
			}*/ // 이거 왜 안돼는지 질문
			else {
				this->high = this->high + 10;
			}
		}
		return this->high;
	}	// 높이 구하는 함수
};

int main() {
	ofstream outFile("dish.out");	// 파일 출력하는거
	ifstream inFile("dish.inp");	// 파일 읽는거

	int count;	// 몇번 높이를 확인할건지
	inFile >> count;	// 첫줄의 높이 읽기

	for (int i = 0; i < count; i++) {

		int many;	// 접시의 갯수
		inFile >> many;		// 둘째줄의 접시수 읽기

		char *arr = new char[many];	// 접시모양 배열 동적할당
		for (int i = 0; i < many; i++) {
			inFile >> arr[i];
		}	//	접시모양 입력
		
		Dish d(many, arr);
		outFile << d.howHigh() << '\n';

		delete[] arr;	// 접시배열 동적할당 해제
	}
}