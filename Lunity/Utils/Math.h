#include <stdexcept>

#ifndef LUNITY_UTILS_MATH
#define LUNITY_UTILS_MATH

template<typename T>
struct Vector1
{
    T X = 0;
    Vector1() = default;
    Vector1(T x) : X(x) { }
    Vector1 operator+(Vector1& other) const { return Vector1(X + other.X); }
    Vector1 operator-(Vector1& other) const { return Vector1(X - other.X); }
    Vector1 operator*(Vector1& other) const { return Vector1(X * other.X); }
    Vector1 operator/(Vector1& other) const { return Vector1(X / other.X); }
    Vector1& operator+=(Vector1& other) { X += other.X; return *this; }
    Vector1& operator-=(Vector1& other) { X -= other.X; return *this; }
    Vector1& operator*=(Vector1& other) { X *= other.X; return *this; }
    Vector1& operator/=(Vector1& other) { X /= other.X; return *this; }
    Vector1 operator+(T other) const { return Vector1(X + other); }
    Vector1 operator-(T other) const { return Vector1(X - other); }
    Vector1 operator*(T other) const { return Vector1(X * other); }
    Vector1 operator/(T other) const { return Vector1(X / other); }
    Vector1& operator+=(T other) { X += other; return *this; }
    Vector1& operator-=(T other) { X -= other; return *this; }
    Vector1& operator*=(T other) { X *= other; return *this; }
    Vector1& operator/=(T other) { X /= other; return *this; }
    T& operator[](int index) { *(this+(index*sizeof(T))); }
};

template<typename T>
struct Vector2 : public Vector1<T>
{
    T Y = 0;
    Vector2() = default;
    Vector2(T x, T y) : Vector1(x), Y(y) { }
    Vector2 operator+(Vector2& other) const { return Vector2(X + other.X, Y + other.Y); }
    Vector2 operator-(Vector2& other) const { return Vector2(X - other.X, Y - other.Y); }
    Vector2 operator*(Vector2& other) const { return Vector2(X * other.X, Y * other.Y); }
    Vector2 operator/(Vector2& other) const { return Vector2(X / other.X, Y / other.Y); }
    Vector2& operator+=(Vector2& other) { X += other.X; Y += other.Y; return *this; }
    Vector2& operator-=(Vector2& other) { X -= other.X; Y -= other.Y; return *this; }
    Vector2& operator*=(Vector2& other) { X *= other.X; Y *= other.Y; return *this; }
    Vector2& operator/=(Vector2& other) { X /= other.X; Y /= other.Y; return *this; }
    Vector2 operator+(T other) const { return Vector2(X + other, Y + other); }
    Vector2 operator-(T other) const { return Vector2(X - other, Y - other); }
    Vector2 operator*(T other) const { return Vector2(X * other, Y * other); }
    Vector2 operator/(T other) const { return Vector2(X / other, Y / other); }
    Vector2& operator+=(T other) { X += other; Y += other; return *this; }
    Vector2& operator-=(T other) { X -= other; Y -= other; return *this; }
    Vector2& operator*=(T other) { X *= other; Y *= other; return *this; }
    Vector2& operator/=(T other) { X /= other; Y /= other; return *this; }
    T& operator[](int index) { *(this+(index*sizeof(T))); }
};

template<typename T>
struct Vector3 : public Vector2<T>
{
    T Z = 0;
    Vector3() = default;
    Vector3(T x, T y, T z) : Vector2(x, y), Z(z) { }
    Vector3 operator+(Vector3& other) const { return Vector3(X + other.X, Y + other.Y, Z + other.Z); }
    Vector3 operator-(Vector3& other) const { return Vector3(X - other.X, Y - other.Y, Z - other.Z); }
    Vector3 operator*(Vector3& other) const { return Vector3(X * other.X, Y * other.Y, Z * other.Z); }
    Vector3 operator/(Vector3& other) const { return Vector3(X / other.X, Y / other.Y, Z / other.Z); }
    Vector3& operator+=(Vector3& other) { X += other.X; Y += other.Y; Z += other.Z; return *this; }
    Vector3& operator-=(Vector3& other) { X -= other.X; Y -= other.Y; Z -= other.Z; return *this; }
    Vector3& operator*=(Vector3& other) { X *= other.X; Y *= other.Y; Z *= other.Z; return *this; }
    Vector3& operator/=(Vector3& other) { X /= other.X; Y /= other.Y; Z /= other.Z; return *this; }
    Vector3 operator+(T other) const { return Vector3(X + other, Y + other, Z + other); }
    Vector3 operator-(T other) const { return Vector3(X - other, Y - other, Z - other); }
    Vector3 operator*(T other) const { return Vector3(X * other, Y * other, Z * other); }
    Vector3 operator/(T other) const { return Vector3(X / other, Y / other, Z / other); }
    Vector3& operator+=(T other) { X += other; Y += other; Z += other; return *this; }
    Vector3& operator-=(T other) { X -= other; Y -= other; Z -= other; return *this; }
    Vector3& operator*=(T other) { X *= other; Y *= other; Z *= other; return *this; }
    Vector3& operator/=(T other) { X /= other; Y /= other; Z /= other; return *this; }
    T& operator[](int index) { *(this+(index*sizeof(T))); }
};

template<typename T>
struct Vector4 : public Vector3<T>
{
    T W = 0;
    Vector4() = default;
    Vector4(T x, T y, T z, T w) : Vector3(x, y, z), W(w) { }
    Vector4 operator+(Vector4& other) const { return Vector4(X + other.X, Y + other.Y, Z + other.Z, W + other.W); }
    Vector4 operator-(Vector4& other) const { return Vector4(X - other.X, Y - other.Y, Z - other.Z, W - other.W); }
    Vector4 operator*(Vector4& other) const { return Vector4(X * other.X, Y * other.Y, Z * other.Z, W * other.W); }
    Vector4 operator/(Vector4& other) const { return Vector4(X / other.X, Y / other.Y, Z / other.Z, W / other.W); }
    Vector4& operator+=(Vector4& other) { X += other.X; Y += other.Y; Z += other.Z; W += other.W; return *this; }
    Vector4& operator-=(Vector4& other) { X -= other.X; Y -= other.Y; Z -= other.Z; W -= other.W; return *this; }
    Vector4& operator*=(Vector4& other) { X *= other.X; Y *= other.Y; Z *= other.Z; W *= other.W; return *this; }
    Vector4& operator/=(Vector4& other) { X /= other.X; Y /= other.Y; Z /= other.Z; W /= other.W; return *this; }
    Vector4 operator+(T other) const { return Vector4(X + other, Y + other, Z + other, W + other); }
    Vector4 operator-(T other) const { return Vector4(X - other, Y - other, Z - other, W - other); }
    Vector4 operator*(T other) const { return Vector4(X * other, Y * other, Z * other, W * other); }
    Vector4 operator/(T other) const { return Vector4(X / other, Y / other, Z / other, W / other); }
    Vector4& operator+=(T other) { X += other; Y += other; Z += other; W += other; return *this; }
    Vector4& operator-=(T other) { X -= other; Y -= other; Z -= other; W -= other; return *this; }
    Vector4& operator*=(T other) { X *= other; Y *= other; Z *= other; W *= other; return *this; }
    Vector4& operator/=(T other) { X /= other; Y /= other; Z /= other; W /= other; return *this; }
    T& operator[](int index) { *(this+(index*sizeof(T))); }
};

struct Vector1F : Vector1<float> { };
struct Vector2F : Vector2<float> { };
struct Vector3F : Vector3<float> { };
struct Vector4F : Vector4<float> { };

struct Vector1D : Vector1<double> { };
struct Vector2D : Vector2<double> { };
struct Vector3D : Vector3<double> { };
struct Vector4D : Vector4<double> { };

struct Vector1B : Vector1<char> { };
struct Vector2B : Vector2<char> { };
struct Vector3B : Vector3<char> { };
struct Vector4B : Vector4<char> { };

struct Vector1S : Vector1<short> { };
struct Vector2S : Vector2<short> { };
struct Vector3S : Vector3<short> { };
struct Vector4S : Vector4<short> { };

struct Vector1I : Vector1<int> { };
struct Vector2I : Vector2<int> { };
struct Vector3I : Vector3<int> { };
struct Vector4I : Vector4<int> { };

struct Vector1L : Vector1<long long> { };
struct Vector2L : Vector2<long long> { };
struct Vector3L : Vector3<long long> { };
struct Vector4L : Vector4<long long> { };

/*

template <typename T>
struct Vector2 {
	union {
		struct {
			T x, y;
		};
		T arr[2];
	};

	Vector2<T>() { x = y = 0; };
	Vector2<T>(T x, T y) {
		this->x = x;
		this->y = y;
	}
	Vector2<T> operator+(Vector2<T> toAdd) const {
        T newX = x + toAdd.x;
        T newY = y + toAdd.y;
        return Vector2<T>(newX, newY);
    }
    Vector2<T> operator-(Vector2<T> toSub) const {
        T newX = x - toSub.x;
        T newY = y - toSub.y;
        return Vector2<T>(newX, newY);
    }
};

template <typename T>
struct Vector3 {
	union {
		struct {
			T x, y, z;
		};
		T arr[3];
	};

	Vector3<T>() { x = y = z = 0; };
	Vector3<T>(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3<T> operator+(Vector3<T> toAdd) const {
        T newX = x + toAdd.x;
        T newY = y + toAdd.y;
		T newZ = z + toAdd.z;
        return Vector3<T>(newX, newY, newZ);
    }
    Vector3<T> operator-(Vector3<T> toSub) const {
        T newX = x - toSub.x;
        T newY = y - toSub.y;
		T newZ = z - toSub.z;
        return Vector3<T>(newX, newY, newZ);
    }
};

template <typename T>
struct Vector4 {
	union {
		struct {
			T x, y, z, w;
		};
		T arr[4];
	};

	Vector4<T>() { x = y = z = w = 0; };
	Vector4<T>(T x, T y, T z, T w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	Vector4<T> operator+(Vector4<T> toAdd) const {
        T newX = x + toAdd.x;
        T newY = y + toAdd.y;
		T newZ = z + toAdd.z;
		T newW = w + toAdd.w;
        return Vector4<T>(newX, newY, newZ, newW);
    }
    Vector4<T> operator-(Vector4<T> toSub) const {
        T newX = x - toSub.x;
        T newY = y - toSub.y;
		T newZ = z - toSub.z;
		T newW = w - toSub.w;
        return Vector4<T>(newX, newY, newZ, newW);
    }
};

*/

#endif /* LUNITY_UTILS_MATH */
