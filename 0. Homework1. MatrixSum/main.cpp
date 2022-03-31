#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
class Matrix {
public:
	Matrix() {
		Reset(0, 0);
	}

	Matrix(int num_rows, int num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(int num_rows, int num_cols) {
		if (num_rows < 0 || num_cols < 0) {
			throw out_of_range("");
		}
	}

	int At(int num_rows, int num_cols) const {
		try
		{
			return _matrix.at(num_rows).at(num_cols);
		}
		catch (const std::out_of_range& oor)
		{
			throw out_of_range("");
		}
	}

	int& At(int num_rows, int num_cols) {
		try
		{
			return _matrix.at(num_rows).at(num_cols);
		}
		catch (const std::out_of_range& oor)
		{
			throw out_of_range("");
		}
	}

	int GetNumRows() const {
		return _matrix.size();
	}

	int GetNumColumns() const {
		if (GetNumRows() > 0) {
			_matrix[0].size();
		}

		return 0;
	}
private:
	vector<vector<int>> _matrix;
};

// * оператор ввода для класса Matrix из потока istream
istream& operator >> (istream& stream, Matrix& matrix) {

	return stream;
}



// * оператор вывода класса Matrix в поток ostream
ostream& operator << (ostream& stream, const Matrix& duration) {


	return stream;
}

// * оператор проверки на равенство двух объектов класса Matrix
bool operator == (const Matrix& lhs, const Matrix& rhs)
{
	return true;
};

// * оператор сложения двух объектов класса Matrix
Matrix operator + (const Matrix& lhs, const Matrix& rhs)
{

}


int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
