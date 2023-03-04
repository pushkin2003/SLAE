/*#include "../vectors/Norm.h"

template<typename T> 
std::vector<T>Jacobi(const matrix::CSR<T> &a, const std::vector<T> &b, const std::vector<T> &X_0, const T &tolerance) {
    vector<T> r(b.size());
    vector<T> x= X_0;
    vector<T> x_next(b.size());

    r = (A*x)-b;
    while(norm(r) > tolerance) {
        for(size_t i = 0; i <b.size(); i++) {
            auto sum = static_cast<T>(0);
            for(int j = a[i]; j <a[i+1]; j++)
            if( i !=a)
        }
    }
}
*/