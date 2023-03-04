#include<cstddef>
#include<array>
#include "vector.h"

template <typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator*=(T numb) {
    for (auto it = this->arr_.begin(); it < this->arr_.end(); it++) 
        *it *= numb;
    return *this;
}

template <typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator*(T numb) const {
    Vector<T, N> res;
    for (std::size_t i = 0; i < N; i++) 
        res[i] = this->arr_[i] * numb;
    return res;
}

template <typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator/=(T numb) {
    return ((*this) *= (static_cast<T>(1) / numb));
}

template <typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator/(T numb) const {
    return *this * (static_cast<T>(1) / numb);
}

template <typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator+=(const Vector<T, N>& arr) {
    for (auto i = 0; i < N; i++)
        this->arr_[i] += arr.arr_[i];
    return *this;
}

template <typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& arr) const {
    Vector<T, N> res;
    for (auto i = 0; i < N; i++) 
        res[i] = arr.arr_[i] + this->arr_[i];
    return res;
}

template <typename T, std::size_t N>
Vector<T, N>& Vector<T, N>::operator-=(const Vector<T, N>& arr) {
    return *this += arr * static_cast<T>(-1);
}

template <typename T, std::size_t N>
Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& arr) const {
    return *this + arr * static_cast<T>(-1);
}

template <typename T, std::size_t N>
[[nodiscard]] std::size_t Vector<T, N>::size() const {
    return N;
}

template <typename T, std::size_t N>
[[nodiscard]] std::size_t Vector<T, N>::scalar(const Vector<T, N> arr){
    std::size_t res = 0;
    for(size_t i = 0; i < N; i++) {
        arr_[i] *= arr[i];
        res += arr_[i];
    }
    return res;
}

template <typename T, std::size_t N>
[[nodiscard]] Vector<T, N> Vector<T, N>::addVector(const Vector<T, N> arr){
    for(std::size_t i = 0; i < N; i++)
        arr_[i] += arr[i];
    return arr_;
}

template <typename T, std::size_t N>
const T& Vector<T, N>::operator[](std::size_t i) const { 
    return arr_[i]; 
}

template <typename T, std::size_t N>
bool Vector<T, N>::operator==(const Vector<T, N>& arr) {
    for (auto i = 0; i < N; i++) 
        if (this->arr_[i] != arr.arr_[i]) 
            return false;
    return true;
}