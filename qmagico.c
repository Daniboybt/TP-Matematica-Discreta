#include <stdio.h>
#include <stdlib.h>

void magic_square(int num_lados);
void odd_magic_square(int **array, int n, int sum_factor);
void doubly_even_magic_square(int **array, int n);
void even_magic_square(int **array, int n);

int main(){
	int num_lados;
	scanf("%d", &num_lados);
	
	magic_square(num_lados);
}

void magic_square(int num_lados){
	int magic_const = num_lados * (num_lados * num_lados + 1) / 2;
	int **magic_square = (int**)malloc(sizeof(int *) * num_lados);
	
	for(int i = 0; i < num_lados; i++){
		magic_square[i] = (int*)malloc(sizeof(int) * num_lados); 
		
		for(int j = 0; j < num_lados; j++){
			magic_square[i][j] = 0;
		}
	}

	if(num_lados % 2 == 1){
		odd_magic_square(magic_square, num_lados, 0);

	}else if(num_lados % 4 == 0){
		doubly_even_magic_square(magic_square, num_lados);
	
	}else if(num_lados % 2 == 0){
	//	even_magic_square(magic_square, num_lados);
	}
	
	printf("n = %d, Soma = %d\n", num_lados, magic_const);
	for(int i = 0; i < num_lados; i++){
		for(int j = 0; j < num_lados; j++){
			printf("%d ", magic_square[i][j]);
		}
		printf("\n");
		free(magic_square[i]);
	}
	free(magic_square);
}

void odd_magic_square(int **array, int n, int sum_factor){
	int i = 0;
	int j = (n + 1)/2 - 1;

	for(int num = 1; num <= n*n; num++){
		array[i][j] = num + sum_factor;
		i--;
		j++;

		if(i < 0){ i = n - 1; }
		
		if(j == n){ j = 0; }

		if(array[i][j] != 0){
			i += 2;
			j--;
			if(i >= n){ i = 1; }

			if(j < 0){ j = n - 1; }	
		}
	}
}

void doubly_even_magic_square(int **array, int n){
	int painted_corner = n / 4;
	int  painted_central = n / 2;

	int num_out_painted = 16;
	int num_in_painted = 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			
			if(i < painted_corner && j < painted_corner){ //Canto Superior Esquerdo
				array[i][j] = num_in_painted;

			}else if(i < painted_corner && j + 1 > n - painted_corner){ // Area Superior Direita
				array[i][j] = num_in_painted;
			
			}else if(i + 1 > n - painted_corner && j < painted_corner){	// Area Inferior Esquerda
				array[i][j] = num_in_painted;
				
			}else if(i + 1 > n - painted_corner && j + 1 > n - painted_corner){	// Area Inferior Direita
				array[i][j] = num_in_painted;

			}else if(i + 1 > painted_corner && i < n - painted_corner 
						&& j + 1 > painted_corner && j < n - painted_corner){	// Area Central
				
				array[i][j] = num_in_painted;
			
			}else{ // Fora De uma Area realçada
				array[i][j] = num_out_painted;
			}
			num_out_painted--;
			num_in_painted++;
		}
	}
}

void even_magic_square(int **array, int n){
	int quadrant_size = n / 2;
	
	
}
