script: AdvancedMode.o CleanTags.o Position.o Printer.o SimpleMode.o Style.o Tempo.o main.o
	gcc -Wall -Wextra -pedantic-errors -O2 *.c -lm -o script

AdvancedMode.o:
	gcc -c AdvancedMode.c

CleanTags.o:
	gcc -c CleanTags.c

Position.o:
	gcc -c Position.c

Printer.o:
	gcc -c Printer.c

SimpleMode.o:
	gcc -c SimpleMode.c

Style.o:
	gcc -c Style.c

Tempo.o:
	gcc -c Tempo.c

main.o:
	gcc -c main.c

run:
	./script

clean:
	rm *.o script