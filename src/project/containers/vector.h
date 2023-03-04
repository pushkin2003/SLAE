#ifndef PROJECT_VECTOR_H
#define PROJECT_VECTOR_H

#include<cstddef>
#include<array>

template<typename T, std::size_t N>
class Vector {
private:
    std::array<T, N> arr_;
public:
    Vector() {}
    
    bool operator==(const Vector<T, N>& arr);

    Vector<T, N>& operator*=(T number);
    Vector<T, N> operator*(T number) const;

    Vector<T, N>& operator/=(T number);
    Vector<T, N> operator/(T number) const;
    
    Vector<T, N>& operator+=(const Vector<T, N>& arr);
    Vector<T, N> operator+(const Vector<T, N>& arr) const;
    
    Vector<T, N>& operator-=(const Vector<T, N>& arr);
    Vector<T, N> operator-(const Vector<T, N>& arr) const;

    [[nodiscard]] std::size_t scalar(const Vector<T, N> arr);
    [[nodiscard]] Vector<T, N> addVector(const Vector<T, N> arr);
    [[nodiscard]] std::size_t size() const;

    const T& operator[](std::size_t i) const;

    ~Vector() {}
};
#endif