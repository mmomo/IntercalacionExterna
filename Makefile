all: generar_archivo intercalacion

generar_archivo: generar_archivo.c
	gcc -o generar_archivo generar_archivo.c -std=c99

intercalacion: intercalacion.c tokens.c
	gcc -o intercalacion intercalacion.c tokens.c -std=c99

clean:
	rm -rf *.o core generar_archivo intercalacion
