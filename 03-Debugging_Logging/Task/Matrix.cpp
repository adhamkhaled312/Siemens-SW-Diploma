#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    void setData(const std::vector<std::vector<int>>& newData) {
        if (newData.size() == rows && newData[0].size() == cols) {
            data = newData;
        } else {
            std::cout << "Invalid matrix dimensions." << std::endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix multiply(const Matrix& other) {
        if (cols != other.rows) {
            std::cout << "Matrix dimensions are incompatible for multiplication." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] = data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }
};

int main() {
    Matrix matrix1(2, 3);
    Matrix matrix2(3, 2);

    matrix1.setData({{1, 2, 3}, {4, 5, 6}});
    matrix2.setData({{7, 8}, {9, 10}, {11, 12}});

    std::cout << "Matrix 1:" << std::endl;
    matrix1.display();

    std::cout << "Matrix 2:" << std::endl;
    matrix2.display();

    Matrix result = matrix1.multiply(matrix2);

    std::cout << "Result of multiplication:" << std::endl;
    result.display();

    return 0;
}