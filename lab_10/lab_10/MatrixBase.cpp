#include "MatrixBase.h"
#include "MatrixBase.h"
#include <string>
#include <cassert>

void MatrixBase::operator*=(int iMult) 
{
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			element(i, j) *= iMult;
		}
	}
}

void MatrixBase::operator+=(MatrixBase& iAdd) 
{
	assert(iAdd.size() == m_size);
	for (int i = 0; i < iAdd.m_size; ++i) {
		for (int j = 0; j < iAdd.m_size; ++j) {
			element(i, j) += iAdd.element(i, j);
		}
	}
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
	for (int i = 0; i < iMatrix.size(); i++)
	{
		for (int j = 0; j < iMatrix.size(); j++)
			stream << " " << iMatrix.element(i, j);
		stream << std::endl;
	}
	return stream;
}