.PHOYY: all
all:
	mkdir build -p && \
		cd build && \
		cmake .. && \
		make -j4

.PHONY: clean
clean:
	rm build -rf

.PHONY: setup
setup:
	apt-get update && \
		apt-get -y install libssl-dev && \
		wget http://downloads.cpp-netlib.org/0.11.2/cpp-netlib-0.11.2-final.tar.gz && \
		tar -zxvf cpp-netlib-0.11.2-final.tar.gz && \
		rm cpp-netlib-0.11.2-final.tar.gz && \
		cd cpp-netlib-0.11.2-final && \
		mkdir build -p && \
		cd build && \
		cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_CXX_FLAGS=-std=c++11 .. && \
		make -j4 && \
		make install && \
		cd ../.. && \
		rm -rf cpp-netlib-0.11.2-final
