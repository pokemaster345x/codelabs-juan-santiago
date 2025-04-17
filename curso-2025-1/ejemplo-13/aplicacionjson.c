#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>



cJSON * procesarJSON(cJSON* entrada){
	cJSON * respuesta=cJSON_CreateObject();//crea un objeto  cJSON vacio

	cJSON * mensaje = cJSON_GetObjectItem(entrada, "mensaje");
	if(mensaje != null){
		cJSON_AddItemToObject(respuesta,"mensaje_original",cJSON_Duplicate(mensaje));
	}
	return respuesta;
}

int main(int numArgs, char ** args){
	char * json_string = "{\mensaje:\"Este es el mensaje original\"}";

	cJSON* objJsonEntrada=  cJSON_Parse(json_string);

	if(objJsonEntrada == null){
		printf("Error en la decodificacion del JSON\r\n");
	return -1;
	}
	cJSON * respuesta= procesarJSON(objJsonEntrada);

	char * cadena =cJSON_Print(respuesta);

	printf("El Json es: %s \r\n",cadena);

	cJSON_Delete(respuesta);
	cJSON_Delete(objJsonEntrada);

	free(cadena);

	exit(EXIT_SUCCESS);
}
