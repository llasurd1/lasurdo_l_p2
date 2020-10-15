all: submission

p1: submission.cpp
	g++ -g submission.cpp -o submission

clean:
	rm -rf submission

run:
  ./submission input.txt output.txt
