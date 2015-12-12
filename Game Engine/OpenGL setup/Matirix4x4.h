#ifndef MATRIX_4X4
#define MATRIX_4X4

/*******************************************
 *Template class for a col-major 4x4 matrix*
 *******************************************/

template<typename TVal> class Matrix3x3;										//Template class for a 3x3 matrix
template<typename TVal> class Quaterniont;										//Template class for a quaterniot

template<typename TVal>															//Template value( ie: float, double, int,..., ect)
class Matrix4x4
{
public:
	Matrix4x4();																//Default constructor A11-A44 = 0 (float by default)
	Matrix4x4(TVal _11, TVal _21, TVal _31, TVal _41,							//Explicite constructor
			  TVal _12, TVal _22, TVal _32, TVal _42,
			  TVal _13, TVal _23, TVal _33, TVal _43,
			  TVal _14, TVal _24, TVal _34, TVal _44);
				/******Col-Row format******
					| 11  21  31  41 |
					| 12  22  32  42 |
					| 13  23  33  43 |
					| 14  24  34  44 |
				 **************************/
	explicit Matrix3x3(const Matrix3x3<TVal>& m);								//Explicit constructor for 3x3 matrix

	inline Matrix4x4& transform();
	inline Matrix4x4& rotate();
	inline Matrix4x4& inverse();
	inline TVal determinant() const;
	inline Matrix3x3& transpose();
	inline void projection();
private:
	TVal 11, 21, 31, 41;
	TVal 12, 22, 32, 42;
	TVal 13, 23, 33, 43;
	TVal 14, 24, 34, 44;

};

#endif