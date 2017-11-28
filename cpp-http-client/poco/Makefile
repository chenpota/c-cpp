.PHONY: all
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
		apt-get -y install libpoco-dev
