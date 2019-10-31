#include <stdio.h>
struct{
	int soma_max;
	int left;
	int right;
}result;

void somamax(int* array, int size){
	int soma_max = 0;
	int soma_aux = 0;
	int left = 0;
	int left_aux = 0;
	int right = 0;

	for(int i = 0; i < size; i++){
		soma_aux += array[i];
		if(soma_aux > soma_max){
			soma_max = soma_aux;
			left = left_aux;
			right = i;

		}else if(soma_aux < 0){
			soma_aux = 0;
			left_aux = i + 1;
		}
	}
	printf("Soma: %d\n", soma_max);
	printf("Índices: %d a %d\n", left + 1, right + 1);
}

int main(){
	int size;
	int array[20];
	
	scanf("%d", &size);
	for(int i = 0; i < size; i++){
		scanf("%d", &array[i]);
	}	
	somamax(array, size);
}
