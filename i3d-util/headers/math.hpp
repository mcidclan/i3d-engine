#ifndef MATH_HPP
#define MATH_HPP

	namespace math
	{
		template <typename T>
		void setIdentityMatrix4x4(T* matrix)
		{
			memset(matrix, (T)0, 16 * sizeof(T));
			matrix[0] = matrix[5] = matrix[10] =
			matrix[15] = (T)1;
		}
	}

#endif
