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

	Matrix(const int& num_rows, const int& num_cols) {
		Reset(num_rows, num_cols);
	}

	void Reset(const int& num_rows, const int& num_cols) {
		int numRows, numCols;

		if (num_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (num_cols < 0) {
			throw out_of_range("num_columns must be >= 0");
		}

		if (num_rows == 0 || num_cols == 0) {
			numRows = numCols = 0;
		}
		else
		{
			numRows = num_rows;
			numCols = num_cols;
		}

		_matrix.assign(numRows, vector<int>(numCols));
	}

	int At(int num_rows, int num_cols) const {
		return _matrix.at(num_rows).at(num_cols);
	}

	int& At(int num_rows, int num_cols) {
		return _matrix.at(num_rows).at(num_cols);
	}

	int GetNumRows() const {
		return _matrix.size();
	}

	int GetNumColumns() const {
		if (GetNumRows() > 0) {
			return _matrix[0].size();
		}

		return 0;
	}
private:
	vector<vector<int>> _matrix;
};

// * оператор ввода для класса Matrix из потока istream
istream& operator >> (istream& stream, Matrix& matrix) {
	int num_rows, num_columns;
	stream >> num_rows >> num_columns;

	matrix.Reset(num_rows, num_columns);
	for (int row = 0; row < num_rows; ++row) {
		for (int column = 0; column < num_columns; ++column) {
			stream >> matrix.At(row, column);
		}
	}

	return stream;
}



// * оператор вывода класса Matrix в поток ostream
ostream& operator << (ostream& stream, const Matrix& matrix) {
	stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

	for (int i = 0; i < matrix.GetNumRows(); i++)
	{
		for (int j = 0; j < matrix.GetNumColumns(); j++)
		{
			stream << matrix.At(i, j) << (j == matrix.GetNumColumns() - 1 ? "" : " ");
		}

		if (i != matrix.GetNumRows() - 1) {
			stream << endl;
		}
	}

	return stream;
}

// * оператор проверки на равенство двух объектов класса Matrix
bool operator == (const Matrix& lhs, const Matrix& rhs)
{
	if ((lhs.GetNumRows() != rhs.GetNumRows()) || (lhs.GetNumColumns() != rhs.GetNumColumns())) {
		return false;
	}

	for (int i = 0; i < lhs.GetNumRows(); i++)
	{
		for (int j = 0; j < lhs.GetNumColumns(); j++)
		{
			if (lhs.At(i, j) != rhs.At(i, j))
			{
				return false;
			}
		}
	}

	return true;
};

// * оператор сложения двух объектов класса Matrix
Matrix operator + (const Matrix& lhs, const Matrix& rhs)
{
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}

	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}

	auto resultingMatix = Matrix(lhs.GetNumRows(), lhs.GetNumColumns());

	for (int i = 0; i < lhs.GetNumRows(); i++)
	{
		for (int j = 0; j < lhs.GetNumColumns(); j++)
		{
			resultingMatix.At(i, j) = lhs.At(i,j) + rhs.At(i, j);
		}
	}

	return resultingMatix;
}


int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
