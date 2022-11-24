CC = gcc
LIBLOOP = basicClassification.o advancedClassificationLoop.o 
LIBREC = basicClassification.o advancedClassificationRecursion.o
AR = ar -rcs
FLAGS = -Wall -g
COMP = -shared -fPIC -o
C = -c
O = -o

#make all compiles
all: loops recursived recursives loopd mains maindloop maindrec

#make static library
loops: libclassloops.a

#iterative functions library
libclassloops.a: $(LIBLOOP)
	$(AR) libclassloops.a $(LIBLOOP)

#basic functions
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) $(C) basicClassification.c

#advanced iterative functions
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) $(C) advancedClassificationLoop.c

#make static library
recursives: libclassrec.a

#recursive functions
libclassrec.a: $(LIBREC)
	$(AR) libclassrec.a $(LIBREC)

#advanced recursive functions
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) $(C) advancedClassificationRecursion.c

#make dynamic library
loopd: libclassloops.so

#dynamic library of advanced iterative functions
libclassloops.so: $(LIBLOOP)
	$(CC) $(COMP) libclassloops.so $(LIBLOOP)

#make dynamic library
recursived: libclassrec.so

#dynamic library of advaned recursive functions
libclassrec.so: $(LIBREC)
	$(CC) $(COMP) libclassrec.so $(LIBREC)

#static
mains: main.o libclassrec.a
	$(CC) $(FLAGS) $(O) mains main.o libclassrec.a -lm

#dynamic
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) $(O) maindloop main.o ./libclassloops.so -lm

#dynamic
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) $(O) maindrec main.o ./libclassrec.so -lm

#main file
main.o: main.c NumClass.h
	$(CC) $(FLAGS) $(C) main.c -lm

#phony
.PHONY: clean all

#clean all files
clean: 
	rm -f  *.o *.a *.so mains maindloop maindrec