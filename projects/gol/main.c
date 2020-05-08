/*
	Student name :Mehmet Can KAHRAMAN
	Student ID   :200008645
*/

#include <stdlib.h>
#include <stdio.h>
#include "gol.h"
#include "gol.c"

int count_alive_neighbors(char *b, int x, int y)
{
	FILE *f = fopen(INITIAL_FILE, "r");
	int count = 0;
if((b[10*y+x-1])== '1'){
	count++;
}
if((b[10*y+x+1])== '1'){ 
// Burada if koşullarını teker teker yazmamak için string oluşturup for döngüsünde bitirecektim
//fakat stringler de pointer ile bir sorunla karşılaştım bu ifadeleri bir değişkene eşitleyemedim.(Tahminim iç içe pointerlardan dolayı olabilir.)
	count++;
}
if((b[10*y+x-11])== '1'){
	count++;
}
if((b[10*y+x+11])== '1'){
	count++;
}
if((b[10*y+x-9])== '1'){
	count++;
}
if((b[10*y+x+9])== '1'){
	count++;
}
if((b[10*y+x-10])== '1'){
	count++;
}
if((b[10*y+x+10])== '1'){
	count++;
}
	

	/* do stuff with b, x and y */ 

	return count;
}

char* evaluate(char *b)
{
	char *n = create_board();

	/* do stuff with b and n */ 
	int i,j,neighbors,matrix;

	for(i=0;i<N;i++){
	// Matriks yapısını for ile değil while ile yapmaya çalıştım fakat uyum sağlayamadı. Nedenini çözememekle beraber
	//neden matriks oluştururken for döngüsünün kullanıldığını daha net anlamış oldum 
	//fakat hala neden while döngüsünde sorun çıkardı bilmiyorum.
		for(j=0;j<M;j++){
			matrix = ((i*M) + j);
				neighbors = count_alive_neighbors(b, j, i);
			 if(b[matrix] == '0'){
				if(neighbors == 3){
					//NEW BORN!!
					n[matrix] = '1';
					}
				else{     
				//if else yerine switch kullandığımda aynı başarıyı alamadım switch kullanmak istemiştim doğru çalışmadığından ve
				//  if kadar  kullanışlı olmadığından switch yerine if kullanmak zorunda kaldım.
					//AS THE SAME
					n[matrix] = '0';
					}
									
									}
			 if (b[matrix] == '1'){
				
				if(neighbors == 2) {
					// GO LIVE
						n[matrix] = '1';
						}
				else if(neighbors == 3){
					n[matrix] = '1';
					   }
				else{
					//DEAD
					n[matrix] = '0';
					}
				
			
								 }

				}
			}

	return n;
}
//https://github.com/cankahramanm sizin projeyi forklayarak devamını getirdim.
int main()
{
	int i = 0;
	char *b = NULL;
	char *next_generation = NULL;

	b = create_board();
	read_initial(b);
	
	printf("Welcome to game of life, please type 'q' to quit\n\n");

	do
	{
		printf("Generation %d\n", ++i);
		
		print_board(b);
		next_generation = evaluate(b);
		destroy_board(b);
		b = next_generation;

		printf("\n\n");

	}while(getchar() != 'q');

	destroy_board(b);
	
	return EXIT_SUCCESS;
}