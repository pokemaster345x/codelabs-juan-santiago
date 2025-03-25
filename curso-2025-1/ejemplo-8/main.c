#include <stdio.h>
#include <stdlib.h>

float comparar_float(float, float);

int main(int numArgs, char** args){
        printf("Casos de prueba(1: verdadero, 0: falso)\r\n");
        float casos[][2] = {{-0.5F, -0.4F},{-0.5F, 0.4F},{0.5F, -0.4F},{0.5F, 0.4F},{-0.4F, -0.5F},{-0.4F, 0.5F},{0.4F, -0.5F},{0.4F, 0.5F}};
        float resultado;
        for(int i = 0; i < sizeof(casos)/sizeof(casos[0]); i++){
                resultado = comparar_float(casos[i][0], casos[i][1]);
                printf("\r\n%f > %f = %f \r\n", casos[i][0], casos[i][1], resultado);
        }
	return 0;
}
