#ifndef SLAU_THREEDIAG_H
#define SLAU_THREEDIAG_H

class ThreeDiagonalMatrix {
private:
	std::vector<std::vector<double>> matrix;
public:
	ThreeDiagonalMatrix(std::vector<double> a, std::vector<double> b, std::vector<double> c);
	[[nodiscard]]std::vector<std::vector<double>> returnMatrix();
};

#endif