#include "Matrix.h"
#include "OutOfRange.h"
#include "IncompatibleDimException.h"
#include <memory>


CSRMatrix::CSRMatrix() : amount_of_rows(0), amount_of_values(0), capacity(0), values(nullptr), rows(nullptr), cols(nullptr) {};

CSRMatrix::CSRMatrix(double** matrix, int size) : capacity(size) {
	double* tvalues = new double[size * size];
	int* trows = new int[size];
	int* tcols = new int[size * size];
	amount_of_rows = 0;
	amount_of_values = 0;
	bool first_element;
	for (int i = 0; i < size; ++i) {
		first_element = true;
		for (int j = 0; j < size; ++j) {
			if (matrix[i][j] != 0) {
				tvalues[amount_of_values] = matrix[i][j];
				tcols[amount_of_values] = j;
				amount_of_values++;
				if (first_element) {
					trows[amount_of_rows] = i;
					amount_of_rows++;
					first_element = false;
				}
			}
		}
	}

	values = new double[amount_of_values];
	std::copy(tvalues, tvalues + amount_of_values, values);
	rows = new int[amount_of_rows];
	std::copy(trows, trows + amount_of_rows, rows);
	cols = new int[amount_of_values];
	std::copy(tcols, tcols + amount_of_values, cols);
	delete[] tvalues;
	delete[] tcols;
	delete[] trows;
}

CSRMatrix::CSRMatrix(const CSRMatrix& matr) : amount_of_rows(matr.amount_of_rows), amount_of_values(matr.amount_of_values), capacity(matr.capacity) {
	values = new double[amount_of_values];
	std::copy(matr.values, matr.values + amount_of_values, values);
	rows = new int[amount_of_rows];
	std::copy(matr.rows, matr.rows + amount_of_rows, rows);
	cols = new int[amount_of_values];
	std::copy(matr.cols, matr.cols + amount_of_values, cols);
}

CSRMatrix::~CSRMatrix() {
	delete[] values;
	delete[] cols;
	delete[] rows;
	amount_of_rows = NULL;
	amount_of_values = NULL;
	capacity = NULL;
}

CSRMatrix& CSRMatrix::operator=(const CSRMatrix& matr) {
	delete[] values;
	delete[] cols;
	delete[] rows;
	amount_of_rows = matr.amount_of_rows;
	amount_of_values = matr.amount_of_values;
	capacity = matr.capacity;
	values = new double[amount_of_values];
	std::copy(matr.values, matr.values + amount_of_values, values);
	rows = new int[amount_of_rows];
	std::copy(matr.rows, matr.rows + amount_of_rows, rows);
	cols = new int[amount_of_values];
	std::copy(matr.cols, matr.cols + amount_of_values, cols);
	return *this;
}



CSRMatrix CSRMatrix::operator*(double number) {
	for (int i = 0; i < amount_of_values; ++i) {
		values[i] *= number;
	}
	return *this;
}



CSRMatrix operator*(double number, CSRMatrix& matr) {
	for (int i = 0; i < matr.amount_of_values; ++i) {
		matr.values[i] *= number;
	}
	return matr;
}


Vector CSRMatrix::operator*(const Vector& v) const {
	Vector tmp_v(v.capacity());
	if (v.capacity() == capacity) {
		int index = 0, rindex = 0;
		for (int i = 0; i < capacity; ++i) {
			for (int j = 0; j < capacity; ++j) {
				if (cols[index] == j and index <= rows[rindex]) {
					tmp_v[i] += values[index] * v[j];
					index++;
				}
			}
			if (rindex + 1 < amount_of_rows) {
				rindex++;
			}
		}
	}
	else {
		throw IncompatibleDimException("Dimensions are not equal");
	}
	return tmp_v;
}


std::ostream& operator<<(std::ostream& os, CSRMatrix& matr) {
	os << "array of values\n";
	for (int i = 0; i < matr.amount_of_values; ++i) {
		os << matr.values[i];
		os << " ";
	}
	os << "\n";

	os << "array of cols\n";
	for (int i = 0; i < matr.amount_of_values; ++i) {
		os << matr.cols[i];
		os << " ";
	}
	os << "\n";

	os << "array of rows\n";

	for (int i = 0; i < matr.amount_of_rows; ++i) {
		os << matr.rows[i];
		os << " ";
	}
	std::cout << "\n";
	os << "\nregained matrix\n";
	int index = 0, rindex = 0;
	for (int i = 0; i < matr.capacity; ++i) {
		for (int j = 0; j < matr.capacity; ++j) {
			if (matr.cols[index] == j and index <= matr.rows[rindex]) {
				os << matr.values[index] << " ";
				index++;
			}
			else {
				os << "0 ";
			}
		}
		if (rindex + 1 < matr.amount_of_rows) {
			rindex++;
		}
		os << "\n";
	}

	return os;
}

std::istream& operator>>(std::istream& is, CSRMatrix& matr) {
	int capacity;
	std::cout << "enter capacity\n";
	is >> capacity;
	double** tmp = new double* [capacity];
	for (int i = 0; i < capacity; ++i) {
		tmp[i] = new double[capacity];
		for (int j = 0; j < capacity; ++j) {
			std::cout << "enter " << i << ", " << j << " element\n";
			is >> tmp[i][j];
		}
	}
	matr = CSRMatrix(tmp, capacity);
	return is;
}

int CSRMatrix::get_amount_of_values() const {
	return amount_of_values;
}
int CSRMatrix::get_amount_of_rows() const {
	return amount_of_rows;
}
int CSRMatrix::get_capacity() const {
	return capacity;
}
