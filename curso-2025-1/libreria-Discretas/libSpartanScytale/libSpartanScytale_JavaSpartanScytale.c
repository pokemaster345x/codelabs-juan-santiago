#include <jni.h>
#include "libSpartanScytale_JavaSpartanScytale.h"
#include <stdlib.h> 

/*
 * Class:     libSpartanScytale_JavaSpartanScytale
 * Method:    codificar
 * Signature: (ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libSpartanScytale_JavaSpartanScytale_codificar
  (JNIEnv *env, jobject obj, jint diametro, jstring mensaje) {

    const char *str = (*env)->GetStringUTFChars(env, mensaje, 0);

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    int filas = diametro;
    int columnas = (length + filas - 1) / filas;

    char *tabla = (char *)malloc(filas * columnas);
    for (int i = 0; i < filas * columnas; i++) {
        tabla[i] = ' ';
    }

    int idx = 0;
    for (int c = 0; c < columnas; c++) {
        for (int f = 0; f < filas; f++) {
            if (idx < length) {
                tabla[f * columnas + c] = str[idx++];
            }
        }
    }

    char *cifrado = (char *)malloc(length + 1);
    idx = 0;
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            if (tabla[f * columnas + c] != ' ') {
                cifrado[idx++] = tabla[f * columnas + c];
            }
        }
    }
    cifrado[idx] = '\0';

    (*env)->ReleaseStringUTFChars(env, mensaje, str);
    free(tabla);

    jstring resultado = (*env)->NewStringUTF(env, cifrado);
    free(cifrado);

    return resultado;
}

/*
 * Class:     libSpartanScytale_JavaSpartanScytale
 * Method:    decodificar
 * Signature: (ILjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_libSpartanScytale_JavaSpartanScytale_decodificar
  (JNIEnv *env, jobject obj, jint diametro, jstring mensaje) {

    const char *str = (*env)->GetStringUTFChars(env, mensaje, 0);

    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    int filas = diametro;
    int columnas = (length + filas - 1) / filas;

    char *tabla = (char *)malloc(filas * columnas);
    for (int i = 0; i < filas * columnas; i++) {
        tabla[i] = ' ';
    }

    int idx = 0;
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            if (idx < length) {
                tabla[f * columnas + c] = str[idx++];
            }
        }
    }

    char *decifrado = (char *)malloc(length + 1);
    idx = 0;
    for (int c = 0; c < columnas; c++) {
        for (int f = 0; f < filas; f++) {
            if (tabla[f * columnas + c] != ' ') {
                decifrado[idx++] = tabla[f * columnas + c];
            }
        }
    }
    decifrado[idx] = '\0';

    (*env)->ReleaseStringUTFChars(env, mensaje, str);
    free(tabla);

    jstring resultado = (*env)->NewStringUTF(env, decifrado);
    free(decifrado);

    return resultado;
}

