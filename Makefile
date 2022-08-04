CC = gcc
CFLAGS = -Wall -Wextra -pedantic-errors -O2
LIBS = -lm
OBJS = main.o AdvancedMode.o CleanTags.o Position.o Printer.o SimpleMode.o Style.o Tempo.o
TARGET = script
DOC_FILE = Doxyfile


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

run:
	./$(TARGET)

doc:
	doxygen $(DOC_FILE)

clean_object:
	rm *.o

clean_doc:
	rm -r latex/ html/