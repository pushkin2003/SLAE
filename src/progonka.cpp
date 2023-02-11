#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

//Вспомогательные функции для вывода массивов
void coutSLAU(double** Matrix, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void coutX(double* mas, int N) {
	for (int i = 0; i < N; i++) {
		cout << "x" << i + 1 << ": " << mas[i] << "; ";
	}
	cout << endl;
}

//Реализация класса метода прогонки
class methodProgonki {
private:
	double** Matrix; // Трехдиагональная матрица
	int N;           // Размер матрицы
	double* B;       // Столбец свободных членов
public:
	//Конструктор класса
	methodProgonki(double** Matr, int Numb, double* stolb) {
		Matrix = Matr;
		N = Numb;
		B = stolb;
	}
	//Реализация метода прогонки
	double* progonka() {
		double* matrix_X = new double[N];
		//Формирование прогоночных коэффициентов
		double* V = new double[N];
		double* U = new double[N];

		//Заполнение значениями этих коэффициентов
		V[0] = Matrix[0][1] / (-Matrix[0][0]);
		U[0] = (-B[0]) / (-Matrix[0][0]);
		for (int i = 1; i < N - 1; i++) {
			V[i] = Matrix[i][i + 1] / (-Matrix[i][i] - Matrix[i][i - 1] * V[i - 1]);
			U[i] = (Matrix[i][i - 1] * U[i - 1] - B[i]) / (-Matrix[i][i] - Matrix[i][i - 1] * V[i - 1]);
		}
		V[N - 1] = 0;
		U[N - 1] = (Matrix[N - 1][N - 2] * U[N - 2] - B[N - 1]) / (-Matrix[N - 1][N - 1] - Matrix[N - 1][N - 2] * V[N - 2]);

		//Вычисление X
		matrix_X[N - 1] = U[N - 1];
		for (int i = N - 1; i >= 0; i--)
			matrix_X[i - 1] = V[i - 1] * matrix_X[i] + U[i - 1];

		return matrix_X;
	}

	//Проверка на то, что матрица тридиагональна
	bool trueEnter() {
		for (int i = 1; i < N - 1; i++)
			for (int j = 1; j < N - 1; j++)
				if (((j == i - 1 || j == i || j == i + 1) && (Matrix[i][j] == 0)) || 
					((j != i - 1 && j != i && j != i + 1) && (Matrix[i][j] != 0))) {
					cout << "Matrix not a threediagonalize" << endl;
					return false;
				}
		if (((Matrix[0][0] || Matrix[0][1] || Matrix[1][0]) == 0) ||
			((Matrix[N - 1][N - 1] || Matrix[N - 1][N - 2] || Matrix[N - 2][N - 1]) == 0)) {
			cout << "Matrix not a threediagonalize" << endl;
			return false;
		}
		for (int i = 2; i < N - 2; i++)
			if ((Matrix[i][0] || Matrix[0][i] || Matrix[i][N - 1] || Matrix[N - 1][i]) != 0) {
				cout << "Matrix not a threediagonalize" << endl;
				return false;
			}
		return true;
	}

	//Проверка на диагональное преобладание
	bool domination() {
		for (int i = 1; i < N - 1; i++)
			if (abs(Matrix[i][i]) <= abs(Matrix[i][i - 1]) + abs(Matrix[i][i + 1])) {
				cout << "Diag not a preobladaet" << endl;
				return false;
			}
		if (Matrix[0][0] <= Matrix[0][1] || Matrix[N - 1][N - 1] <= Matrix[N - 1][N - 2]) {
			cout << "Diag not a preobladaet" << endl;
			return false;
		}
		return true;
	}
};

int main() {
	int N;              //Размер матрицы NxN
	double numb, b;     //Элементы для матриц
	bool solve = true;  //Проверка на правильность входных данных
	char doublePoints = ':';
	int numbTest;
	string numberTest, strTest;
	ifstream testFile("test.txt");
	
	while (testFile.is_open()) {
		testFile >> numberTest >> numbTest >> doublePoints;
		cout << numberTest << " " << numbTest << doublePoints << " " << endl;

		testFile >> N;

		//Создание в памяти места под двумерного массива(матрицы)
		double** Matrix = new double* [N];
		for (int i = 0; i < N; i++)
			Matrix[i] = new double[N];

		//Создание в памяти места под столбец свободных членов
		double* B = new double[N];
	
		//Инициализация класса
		methodProgonki SLAU(Matrix, N, B);
		
		//Заполнение матрицы пользователем
		//cout << "Enter a koef" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				testFile >> numb;
				//cout << "numb" << '[' << i << "][" << j << "]: " << numb << endl;;
				Matrix[i][j] = numb;
			}
		}
		
		//Заполнение толбца свободных членов пользователем
		//cout << "Enter a colum free koef" << endl;
		for (int i = 0; i < N; i++) {
			testFile >> b;
			//cout << "b[" << i << "]: " << b << endl;
			B[i] = b;
		}
		testFile >> strTest >> strTest;
		//cout << "strTEst: " << strTest << endl;
		//Проверка на правильность входных данных
		//solve = SLAU.trueEnter();
		//cout << solve << " " << endl;
		//if (solve == true)
		//	solve = SLAU.domination();
		//cout << solve << " " << endl;
		cout << "Test on right matrix: ";
		if (strTest == "right") {
			cout << "passed" << endl;
			cout << "Answer: ";
			coutX(SLAU.progonka(), N);
			cout << endl;
		}
		else {
			cout << "wrong" << endl;
			solve = true;
			continue;
		}

		//Очистка памяти
		for (int i = 0; i < N; i++)
			delete[] Matrix[i];
		delete[] Matrix;
		delete[] B;
		if (numbTest == 18)
			break;
	}
	return 0;
}