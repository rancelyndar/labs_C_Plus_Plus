#pragma once
#include <iostream>
#include <stdexcept>

class MatrixBase {
public:
	MatrixBase() = delete;
	unsigned int size() const { return m_size; }
	void operator *= (int iMult);
	void operator += (MatrixBase& iAdd);
	virtual int element(unsigned int i, unsigned int j) const = 0;
	virtual int& element(unsigned int i, unsigned int j) = 0;
	friend std::ostream& operator<< (std::ostream &out, const MatrixBase &iMatrix);
protected:
	explicit MatrixBase(unsigned int iSize) : m_size(iSize) {}
private:
	const unsigned int m_size;
};


