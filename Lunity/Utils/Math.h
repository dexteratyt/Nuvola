#include <stdexcept>

#ifndef LUNITY_UTILS_MATH
#define LUNITY_UTILS_MATH

/*
template<typename T>
struct Vector1
{
    T X = 0;
    Vector1() = default;
    Vector1(T x) : X(x) { }
    Vector1<T> operator+(Vector1<T>& other) const { return Vector1<T>(this->X + other.X); }
    Vector1<T> operator-(Vector1<T>& other) const { return Vector1<T>(this->X - other.X); }
    Vector1<T> operator*(Vector1<T>& other) const { return Vector1<T>(this->X * other.X); }
    Vector1<T> operator/(Vector1<T>& other) const { return Vector1<T>(this->X / other.X); }
    Vector1<T>& operator+=(Vector1<T>& other) { this->X += other.X; return *this; }
    Vector1<T>& operator-=(Vector1<T>& other) { this->X -= other.X; return *this; }
    Vector1<T>& operator*=(Vector1<T>& other) { this->X *= other.X; return *this; }
    Vector1<T>& operator/=(Vector1<T>& other) { this->X /= other.X; return *this; }
    Vector1<T> operator+(T other) const { return Vector1<T>(this->X + other); }
    Vector1<T> operator-(T other) const { return Vector1<T>(this->X - other); }
    Vector1<T> operator*(T other) const { return Vector1<T>(this->X * other); }
    Vector1<T> operator/(T other) const { return Vector1<T>(this->X / other); }
    Vector1<T>& operator+=(T other) { this->X += other; return *this; }
    Vector1<T>& operator-=(T other) { this->X -= other; return *this; }
    Vector1<T>& operator*=(T other) { this->X *= other; return *this; }
    Vector1<T>& operator/=(T other) { this->X /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

template<typename T>
struct Vector2 : public Vector1<T>
{
    T Y = 0;
    Vector2() = default;
    Vector2(T x, T y) : Vector1<T>(x), Y(y) { }
    Vector2<T> operator+(Vector2<T>& other) const { return Vector2<T>(this->X + other.X, this->Y + other.Y); }
    Vector2<T> operator-(Vector2<T>& other) const { return Vector2<T>(this->X - other.X, this->Y - other.Y); }
    Vector2<T> operator*(Vector2<T>& other) const { return Vector2<T>(this->X * other.X, this->Y * other.Y); }
    Vector2<T> operator/(Vector2<T>& other) const { return Vector2<T>(this->X / other.X, this->Y / other.Y); }
    Vector2<T>& operator+=(Vector2<T>& other) { this->X += other.X; this->Y += other.Y; return *this; }
    Vector2<T>& operator-=(Vector2<T>& other) { this->X -= other.X; this->Y -= other.Y; return *this; }
    Vector2<T>& operator*=(Vector2<T>& other) { this->X *= other.X; this->Y *= other.Y; return *this; }
    Vector2<T>& operator/=(Vector2<T>& other) { this->X /= other.X; this->Y /= other.Y; return *this; }
    Vector2<T> operator+(T other) const { return Vector2<T>(this->X + other, this->Y + other); }
    Vector2<T> operator-(T other) const { return Vector2<T>(this->X - other, this->Y - other); }
    Vector2<T> operator*(T other) const { return Vector2<T>(this->X * other, this->Y * other); }
    Vector2<T> operator/(T other) const { return Vector2<T>(this->X / other, this->Y / other); }
    Vector2<T>& operator+=(T other) { this->X += other; this->Y += other; return *this; }
    Vector2<T>& operator-=(T other) { this->X -= other; this->Y -= other; return *this; }
    Vector2<T>& operator*=(T other) { this->X *= other; this->Y *= other; return *this; }
    Vector2<T>& operator/=(T other) { this->X /= other; this->Y /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

template<typename T>
struct Vector3 : public Vector2<T>
{
    T Z = 0;
    Vector3() = default;
    Vector3(T x, T y, T z) : Vector2<T>(x, y), Z(z) { }
    Vector3<T> operator+(Vector3<T>& other) const { return Vector3<T>(this->X + other.X, this->Y + other.Y, this->Z + other.Z); }
    Vector3<T> operator-(Vector3<T>& other) const { return Vector3<T>(this->X - other.X, this->Y - other.Y, this->Z - other.Z); }
    Vector3<T> operator*(Vector3<T>& other) const { return Vector3<T>(this->X * other.X, this->Y * other.Y, this->Z * other.Z); }
    Vector3<T> operator/(Vector3<T>& other) const { return Vector3<T>(this->X / other.X, this->Y / other.Y, this->Z / other.Z); }
    Vector3<T>& operator+=(Vector3<T>& other) { this->X += other.X; this->Y += other.Y; this->Z += other.Z; return *this; }
    Vector3<T>& operator-=(Vector3<T>& other) { this->X -= other.X; this->Y -= other.Y; this->Z -= other.Z; return *this; }
    Vector3<T>& operator*=(Vector3<T>& other) { this->X *= other.X; this->Y *= other.Y; this->Z *= other.Z; return *this; }
    Vector3<T>& operator/=(Vector3<T>& other) { this->X /= other.X; this->Y /= other.Y; this->Z /= other.Z; return *this; }
    Vector3<T> operator+(T other) const { return Vector3<T>(this->X + other, this->Y + other, this->Z + other); }
    Vector3<T> operator-(T other) const { return Vector3<T>(this->X - other, this->Y - other, this->Z - other); }
    Vector3<T> operator*(T other) const { return Vector3<T>(this->X * other, this->Y * other, this->Z * other); }
    Vector3<T> operator/(T other) const { return Vector3<T>(this->X / other, this->Y / other, this->Z / other); }
    Vector3<T>& operator+=(T other) { this->X += other; this->Y += other; this->Z += other; return *this; }
    Vector3<T>& operator-=(T other) { this->X -= other; this->Y -= other; this->Z -= other; return *this; }
    Vector3<T>& operator*=(T other) { this->X *= other; this->Y *= other; this->Z *= other; return *this; }
    Vector3<T>& operator/=(T other) { this->X /= other; this->Y /= other; this->Z /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

template<typename T>
struct Vector4 : public Vector3<T>
{
    T W = 0;
    Vector4() = default;
    Vector4(T x, T y, T z, T w) : Vector3<T>(x, y, z), W(w) { }
    Vector4<T> operator+(Vector4<T>& other) const { return Vector4(this->X + other.X, this->Y + other.Y, this->Z + other.Z, this->W + other.W); }
    Vector4<T> operator-(Vector4<T>& other) const { return Vector4(this->X - other.X, this->Y - other.Y, this->Z - other.Z, this->W - other.W); }
    Vector4<T> operator*(Vector4<T>& other) const { return Vector4(this->X * other.X, this->Y * other.Y, this->Z * other.Z, this->W * other.W); }
    Vector4<T> operator/(Vector4<T>& other) const { return Vector4(this->X / other.X, this->Y / other.Y, this->Z / other.Z, this->W / other.W); }
    Vector4<T>& operator+=(Vector4<T>& other) { this->X += other.X; this->Y += other.Y; this->Z += other.Z; this->W += other.W; return *this; }
    Vector4<T>& operator-=(Vector4<T>& other) { this->X -= other.X; this->Y -= other.Y; this->Z -= other.Z; this->W -= other.W; return *this; }
    Vector4<T>& operator*=(Vector4<T>& other) { this->X *= other.X; this->Y *= other.Y; this->Z *= other.Z; this->W *= other.W; return *this; }
    Vector4<T>& operator/=(Vector4<T>& other) { this->X /= other.X; this->Y /= other.Y; this->Z /= other.Z; this->W /= other.W; return *this; }
    Vector4<T> operator+(T other) const { return Vector4<T>(this->X + other, this->Y + other, this->Z + other, this->W + other); }
    Vector4<T> operator-(T other) const { return Vector4<T>(this->X - other, this->Y - other, this->Z - other, this->W - other); }
    Vector4<T> operator*(T other) const { return Vector4<T>(this->X * other, this->Y * other, this->Z * other, this->W * other); }
    Vector4<T> operator/(T other) const { return Vector4<T>(this->X / other, this->Y / other, this->Z / other, this->W / other); }
    Vector4<T>& operator+=(T other) { this->X += other; this->Y += other; this->Z += other; this->W += other; return *this; }
    Vector4<T>& operator-=(T other) { this->X -= other; this->Y -= other; this->Z -= other; this->W -= other; return *this; }
    Vector4<T>& operator*=(T other) { this->X *= other; this->Y *= other; this->Z *= other; this->W *= other; return *this; }
    Vector4<T>& operator/=(T other) { this->X /= other; this->Y /= other; this->Z /= other; this->W /= other; return *this; }
    T& operator[](int index) { *(this + (index * sizeof(T))); }
};

struct Vector1F : public Vector1<float> { using Vector1<float>::Vector1; };
struct Vector2F : public Vector2<float> { using Vector2<float>::Vector2; };
struct Vector3F : public Vector3<float> { using Vector3<float>::Vector3; };
struct Vector4F : public Vector4<float> { using Vector4<float>::Vector4; };

struct Vector1D : public Vector1<double> { using Vector1<double>::Vector1; };
struct Vector2D : public Vector2<double> { using Vector2<double>::Vector2; };
struct Vector3D : public Vector3<double> { using Vector3<double>::Vector3; };
struct Vector4D : public Vector4<double> { using Vector4<double>::Vector4; };

struct Vector1B : public Vector1<char> { using Vector1<char>::Vector1; };
struct Vector2B : public Vector2<char> { using Vector2<char>::Vector2; };
struct Vector3B : public Vector3<char> { using Vector3<char>::Vector3; };
struct Vector4B : public Vector4<char> { using Vector4<char>::Vector4; };

struct Vector1S : public Vector1<short> { using Vector1<short>::Vector1; };
struct Vector2S : public Vector2<short> { using Vector2<short>::Vector2; };
struct Vector3S : public Vector3<short> { using Vector3<short>::Vector3; };
struct Vector4S : public Vector4<short> { using Vector4<short>::Vector4; };

struct Vector1I : public Vector1<int> { using Vector1<int>::Vector1; };
struct Vector2I : public Vector2<int> { using Vector2<int>::Vector2; };
struct Vector3I : public Vector3<int> { using Vector3<int>::Vector3; };
struct Vector4I : public Vector4<int> { using Vector4<int>::Vector4; };

struct Vector1L : public Vector1<long long> { using Vector1<long long>::Vector1; };
struct Vector2L : public Vector2<long long> { using Vector2<long long>::Vector2; };
struct Vector3L : public Vector3<long long> { using Vector3<long long>::Vector3; };
struct Vector4L : public Vector4<long long> { using Vector4<long long>::Vector4; };

*/

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

struct RectangleArea : public Vector4<float> {
    RectangleArea(){
        this->x = 0;
        this->z = 0;
        this->y = 100;
        this->w = 100;
    };
    RectangleArea(float x, float y){
        this->x = x;
        this->z = y;
        this->y = this->x + 100;
        this->w = this->z + 100;
    };
    RectangleArea(Vector2<float> vec2){
        this->x = vec2.x;
        this->z = vec2.y;
        this->y = this->x + 100;
        this->w = this->z + 100;
    };
	RectangleArea(Vector2<float> position, Vector2<float> size) {
		this->x = position.x;
		this->y = this->x + size.x; //width
		this->z = position.y;
		this->w = this->z + size.y; //Height
	}
    RectangleArea(float x, float y, float w, float h){
        this->x = x;
        this->z = y;
        this->y = this->x + z;
        this->w = this->z + w;
    };
};

struct Color : public Vector4<float> {
	bool test;

	/* Constructor overloads */
	Color() : Color(1.0f, 1.0f, 1.0f) {}
	Color(float r, float g, float b) : Color(r, g, b, 1.0f) {}
	Color(float r, float g, float b, float a) : Color(r, g, b, a, false) {}

	//Constructor
	Color(float r, float g, float b, float a, bool test) {
		this->x = r;
		this->y = g;
		this->z = b;
		this->w = a;
		this->test = test;
	}
};

struct TextMeasureData {
    float scale;

    TextMeasureData() {
        this->scale = 1.0f;
    }
    TextMeasureData(float scale) {
        this->scale = scale;
    }
};

struct CaretMeasureData {
    int a;
    bool b;

    CaretMeasureData() {
        CaretMeasureData(0xFFFFFFFF, false);
    };
    CaretMeasureData(int param_1, bool param_2) {
        this->a = param_1;
        this->b = param_2;
    };
};

#endif /* LUNITY_UTILS_MATH */
