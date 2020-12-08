CC=clang++
CFLAGS=-fsanitize=address,undefined -O1 -fno-omit-frame-pointer \
		-g -Wall -Wshadow -std=c++17 \
		-Wno-unused-result -Wno-sign-compare -Wno-char-subscripts
TARGET=main.out

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
TEST_DIR = ./test
TEST_FILE =

all: run

${BUILD_DIR}/${TARGET}: 
	@${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${SRC_DIR}/*.cpp

${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	@${CC} ${CFLAGS} -I ${INCLUDE_DIR}/* -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

run: ${BUILD_DIR}/${TARGET}
	@$^

${TEST_DIR}/test.out : ${BUILD_DIR}/Vendedor.o ${BUILD_DIR}/Engenheiro.o ${BUILD_DIR}/Empregado.o
	@${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Empregado/ -c ${TEST_DIR}/${TEST_FILE} -o ${TEST_DIR}/BasicTests.o
	@${CC} ${CFLAGS} ${BUILD_DIR}/*.o ${TEST_DIR}/*.o -o ${TEST_DIR}/test.out

test: ${TEST_DIR}/test.out
	@$^ 
	@echo "If you want to remove the files built for testing, you just need to 'make clean'"

dir:
	@mkdir 'build'
	@touch build/.gitignore
	@mkdir 'src'
	@mkdir 'test'
	@mkdir 'include'
	@touch .gitignore ; echo "*.out\n/build\n.vscode" > .gitignore
	@mv main.cpp src/
	@echo "Basic directory structure created"

debug: ${BUILD_DIR}/${TARGET}
	@gdb ${BUILD_DIR}/${target}
	

clean:
	@rm -f ${BUILD_DIR}/* ${TEST_DIR}/*.out ${TEST_DIR}/*.o
