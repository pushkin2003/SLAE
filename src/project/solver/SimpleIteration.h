#include "../vector/Norm.h"
#include "../matrix/CSR.h"

template<typename T>
std::vector<T>SimpleIteration(const matrix::CSR<T> &a, const std::vector<T> &b, const std::vector<T> X_0, const T &taor,const T &tolerance){
    auto r = a * x -b;
    std::vector<T> x = X_0
    while (norm(r) > tolerance) {
        x = x - taor*r;
        r = a * x -b;
    }
    return x;

}
template<typename T>
std::vector<T> SimpleIteration(const matrix::CSR<T> &a, const std::vector<T> &b, const std::vector<T> X_0, const T &taor,const T &tolerance){
    std::vector<std::vector<T>> steps{}; steps.reserve(100);

    std::vector<T> x = X_0;
    std::vector<T> r = A* x -b;
    x = x - tao*r;
    r = a * x - b;
   steps.push_back(x);
   
   return{x, steps}; 
   
}

