test:test.cc
	g++ -std=c++17 -o $@ $^ -L/usr/local/lib/ -lpthread -lredis++ -lhiredis

.PHONY:clean
clean:
	rm -f test