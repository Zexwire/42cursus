#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void operacion(int max, int min, int *res)
{
	int rand1 = rand() % (max - min + 1) + min;
	int rand2 = rand() % (max - min + 1) + min;
	char sig = rand() % 2 ? '-' : '+';

	if (sig == '+')
		*res = rand1 + rand2;
	else if (sig == '-')
		*res = rand1 - rand2;

	printf("%d %c %d = ?\n", rand1, sig, rand2);
	scanf("%d", res);

	if (*res != (rand1 + rand2) && *res != (rand1 - rand2))
		printf("Incorrecto. Inténtalo de nuevo.\n");
	else
		printf("Correcto! Vamos a la siguiente operación.\n");
}

int main()
{
	int sem;
	int max = 99;
	int min = 10;
	int res;
	char in;
	time_t inicio, fin;

	// FIXME: Para ques la semilla si no la usas en ningún lado?
	printf("Introduce una semilla aleatoria para comenzar.\n");
	scanf("%d", &sem);
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
		printf("quedan %d segundos\n", 15); // Asume que el tiempo es 5 segundos para este ejemplo
		break;
	default:
		printf("Opción no válida.\n");
		return (-1);
	}
	do
	{
		fin = time(NULL);
		operacion(max, min, &res);
	} while (difftime(fin, inicio) <= 15); // Asume que el tiempo es 5 segundos para este ejemplo
	printf("Tiempo agotado.\n");
	return 0;
}