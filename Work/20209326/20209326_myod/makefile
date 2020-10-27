#变量定义
TARGET=myod
CC=gcc
#把不同的路径赋给相应的变量
DIR_BIN=./bin
DIR_SRC=./src
DIR_INC=./include 
DIR_LIB=./lib
#把./src中的所有.c文件拿出来赋给变量SRC_PATH，包括.c文件的路径
SRC_PATH=$(wildcard ${DIR_SRC}/*.c)

#去掉SRC的路径，然后把所有.c文件后缀名，改为.o，最后把这些.o文件赋给变量
OBJ = $(patsubst %.c,%.o,$(notdir ${SRC_PATH}))

#把bin文件夹下的所有.o文件赋给变量
OBJ_PATH=$(wildcard ${DIR_BIN}/*.o)

${TARGET}:${OBJ}
	${CC} -o ${TARGET} ${OBJ_PATH}
	mv ${TARGET} ${DIR_BIN}/

${OBJ}:
	${CC} -c ${SRC_PATH} -I ${DIR_INC}
	mv  ${OBJ} ${DIR_BIN}/
	ar rcvs libmyod.a ${DIR_BIN}/*.o
	${CC} -shared -o libmyod.so ${DIR_BIN}/*.o
	mv libmyod.a ${DIR_LIB}/
	mv libmyod.so ${DIR_LIB}/
