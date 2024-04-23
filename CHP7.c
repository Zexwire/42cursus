#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//FIXME: Pon el main al final del archivo para evitar tener que declarar las funciones antes de usarlas
//y los problemas de coherencia que eso puede causar
void semilla(int *);
void operacion(int, int, int *);
void tiempo(int);

int main()
{
	int		sem;
	int		max = 99;
	int		min = 10;
	int		res;
	char	in;
	time_t inicio, fin;

	semilla(&sem);
	srand(sem);
	printf("¿Quieres comenzar? (y/n)\n");
	scanf(" %c", &in);

	switch (in)
	{
	case 'n':
		printf("¡Que tengas buen día!\n");
		return (0);
	case 'y':
		printf("Empieza el test.\n");
		inicio = time(NULL);
		tiempo(5); // Asume que el tiempo es 5 segundos para este ejemplo
		break;
	//FIXME: No se maneja el caso en que el usuario introduzca un valor distinto a 'y' o 'n'
	default:
		printf("Opción no válida.\n");
		return (-1);
	}

	//FIXME: Define el bucle así para que sea más claro
	while (difftime(fin, inicio) <= 200)// Asume que el tiempo es 200 segundos para este ejemplo
	{
		fin = time(NULL);
		operacion(max, min, &res);
		// Espera un segundo antes de verificar de nuevo el tiempo
		sleep(1);
	}
	//FIXME: Porque siempre imprimes esto si el bucle termina por tiempo agotado
	printf("Tiempo agotado.\n");
	return 0;
}

//FIXME: En vez de precompilar la semilla, se puede hacer en la función main
void semilla(int *dir_sem)
{
	printf("Introduce una semilla aleatoria para comenzar.\n");
	scanf("%d", dir_sem);
}

//FIXME: La función operacion no necesita devolver nada en este código
//Solo en caso de que se quiera notificar al usuario si la respuesta es correcta o no
//FIXME: No necesitas pasar todos esos parametros que solo se usan internamente,
//puedes definirlos dentro de la función, ajustando su scope correctamente
void operacion(int max, int min, int *res)
{
	int		rand1 = rand() % (max - min + 1) + min;
	int		rand2 = rand() % (max - min + 1) + min;
	char	sig = rand() % 2 ? '-' : '+';

	switch (sig)
	{
	case '+':
		*res = rand1 + rand2;
		break;
	case '-':
		*res = rand1 - rand2;
		break;
	}

	printf("%d %c %d = ?\n", rand1, sig, rand2);
	scanf("%d", res);

	if (*res != (rand1 + rand2) && *res != (rand1 - rand2))
	{
		printf("Incorrecto. Inténtalo de nuevo.\n");
	}
	else
	{
		printf("Correcto! Vamos a la siguiente operación.\n");
	}
}

void tiempo(int seg)
{
	printf("quedan %d segundos\n", seg);
	//FIXME: No tiene sentio esperar aquí el tiempo dado
	//FIXME: Porque usas un bucle while para esperar el tiempo en vez de usar la función sleep(seg)?
	while (seg > 0)
	{
		sleep(1);
		seg--;
	}
}