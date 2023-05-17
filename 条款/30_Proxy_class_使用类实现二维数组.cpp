#include <iostream>
#include <string>
#include <ctime>
using namespace std;




template<class T>
class Array2D {
public:

	class Array1D {
	public:
		Array1D(int dim) {
			PD = new T[dim];
		}

		T& operator[](int index) {
			return PD[index];
		}

		Array1D& operator=(Array1D& tt) {
			this->PD = tt.PD;
			return this->PD;
		}

		T* PD;
	};
	//----------------------------------
	Array2D(int dim1, int dim2) :dim1(dim1), dim2(dim2) {
		DP = (Array1D**)malloc(sizeof(Array1D) * dim1);
		for (int i = 0; i < dim1; i++) {
			DP[i] = new Array1D(dim2);
		}
	}
	Array1D operator[](int index) {
		return *(DP[index]);
	}

	int dim1;
	int dim2;
	Array1D** DP;
};


int main(void) {
	Array2D < float>dd(10, 20);
	dd[2][2] = 3;
	dd[3][4] = 5;

	float a = 0;
	a = dd[2][2];

	cout << a << endl;

	a = dd[3][4];
	cout << a << endl;


	cout << "运行时创建二维数组" << endl;
	size_t size1 = 0 , size2 = 0 ;
	cin >> size1 >> size2;
	Array2D<int> siz(size1, size2);
	size_t size3 = size2 * size1;
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < size1; ++i) {
		for (size_t j = 0; j < size2; j++) {
			siz[i][j] = rand() % size3;
		}
	}

	for (size_t i = 0; i < size1; ++i) {
		for (size_t j = 0; j < size2; j++) {
			cout << siz[i][j]  << "  ";
		}
		cout << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}
