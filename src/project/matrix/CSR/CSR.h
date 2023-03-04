#ifndef SLAU_CSR_H
#define SLAU_CSR_H

class CSR {
private:
	std::vector<std::vector<double>> matrix;
public:
	CSR(std::vector<std::vector<double>> a);
	[[nodiscard]]std::vector<std::vector<double>> returnMatrix();
};

#endif