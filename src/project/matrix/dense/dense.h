#ifndef SLAU_DENSE_H
#define SLAU_DENSE_H

class dense {
private:
	std::vector<std::vector<double>> matrix;
public:
	dense(std::vector<std::vector<double>> a);

    const std::vector<double>& operator[](std::size_t i) const {return matrix[i];}

    [[nodiscard]] std::vector<double> multi(std::vector<double> vec);
	[[nodiscard]] std::vector<std::vector<double>> returnMatrix();

    std::pair<std::vector<std::vector<double>>, std::vector<std::vector<double>>> DrHouse();
};

#endif