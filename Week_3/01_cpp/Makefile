## Change the following

# ANTLR4_JAR := /home/kaustuv/build/antlr-4.7.2-complete.jar
# ANTLR4_CFLAGS := -I/usr/include/antlr4-runtime
# ANTLR4_LDFLAGS := -lantlr4-runtime

ANTLR4_JAR := /users/profs/info/kaustuv.chaudhuri/antlr-4.7.2-complete.jar
ANTLR4_CFLAGS := -I/users/profs/info/kaustuv.chaudhuri/build/antlr4/run/usr/local/include/antlr4-runtime
ANTLR4_LDFLAGS := -L/users/profs/info/kaustuv.chaudhuri/build/antlr4/run/usr/local/lib -lantlr4-runtime

## ------------------------------------------------------------

CXX=g++91 -Wno-attributes

CLASSPATH := .:$(ANTLR4_JAR):

DEPS := BX0.g4 BX0Parser.h
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

.PHONY: all
all: BX0Parser.h
	@${MAKE} -j4 bx0.exe

.PHONY: show
show:
	@echo export LD_LIBRARY_PATH=/usr/local/gcc-9.1.0/lib64/:/users/profs/info/kaustuv.chaudhuri/build/antlr4/run/usr/local/lib:

BX0Parser.h: BX0.g4
	java -cp $(CLASSPATH) -jar $(ANTLR4_JAR) -Dlanguage=Cpp -package bx BX0.g4

bx0.exe: $(OBJECTS)
	$(CXX) -o $(@) $(OBJECTS) $(ANTLR4_LDFLAGS)

%.exe: %.bx bx0.exe
	LD_LIBRARY_PATH=/usr/local/gcc-9.1.0/lib64:/users/profs/info/kaustuv.chaudhuri/build/antlr4/run/usr/local/lib: ./bx0.exe $(<)

%.o: %.cpp
	$(CXX) $(ANTLR4_CFLAGS) -c $(<)

.PHONY: clean
clean:
	rm -f *.o *.exe $(filter-out BX0.g4,$(wildcard BX0*))
	rm -f test/*.exe test/*.c

ast.o: ast.h
bx0.o: ast.h
