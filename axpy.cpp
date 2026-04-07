#include<stdio.h>
#include<stdlib.h>
#include <chrono>

int main()
{
    // vector length
    const int n = 1e8;

    // scalar 'a'
    float a = -0.76;

    // allocate memory for x, y
    float *x = new float[n];
    float *y = new float[n];

    // init vectors
    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        x[i] = 1.33 * (float)(i) / (float)(n);
        y[i] = 0.79 * (float)(i) / (float)(n);
    }

    // start timer
    auto start = std::chrono::steady_clock::now();

    // perform axpy
    #pragma omp parallel for
    for(int i = 0; i < n; i++) {
        y[i] = a * x[i] + y[i];
    }

    // stop timer
    auto end = std::chrono::steady_clock::now();

    // compute elapsed time
    std::chrono::duration<double> elapsed = end - start;

    // print results
    printf("\nvector length   = %d\n", n);
    printf("elapsed time (ms) = %.2f ms\n\n", elapsed.count()*1e3);

    // free memory for x, y
    delete[] x;
    delete[] y;
    return 0;
}