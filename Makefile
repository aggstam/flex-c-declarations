INPUT = flex_c_declarations.l
OUTPUT = flex_c_declarations.c
GCC_OUTPUT = flex_c_declarations
TEST0 = test_file_0.c
TEST1 = test_file_1.c

all:
	flex -o $(OUTPUT) $(INPUT)
	gcc $(OUTPUT) -o $(GCC_OUTPUT) -lfl
	./$(GCC_OUTPUT) $(TEST0)
	./$(GCC_OUTPUT) $(TEST1)

clean:
	rm -f $(OUTPUT) $(GCC_OUTPUT)

.PHONY: all clean
