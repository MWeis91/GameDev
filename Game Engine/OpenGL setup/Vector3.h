#ifndef VECTOR_3D
#define VECTOR_3D


template <typename TVal>			//Template value to use multiple data types within the vector
class Vector3
{
public:
	Vector3();
	Vector3(TVal, TVal, TVal);

	void setX(const TVal _x){ x = _x;};
	void setY(const TVal _y){ y = _y;};
	void setZ(const TVal _z){ z = _z;};

	TVal getX(){return x;};
	TVal getY(){return y;};
	TVal getZ(){return z;};

private:
	TVal x;
	TVal y;
	TVal z;
};

#endif // !VECTOR_3D

