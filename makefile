# if needed, change to your ow compiler that supports omp
CXX=g++

all:
	${CXX}          axpy.cpp -o axpy_s
	${CXX} -fopenmp axpy.cpp -o axpy_p

clean:
	rm -rf axpy_s axpy_p
