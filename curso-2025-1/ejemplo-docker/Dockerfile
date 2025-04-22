# Imagen base para complilar y ejecutar un programa de lenguaje C
FROM gcc:latest

# Creamos el directorio de trabajo del contenedor 

WORKDIR /app

# Copiamos el codigo fuente al directorio de trabajo
COPY main.c .

# Copilamos la aplicacion
RUN gcc main.c -o app

# Ejecutamos la aplicacion 

CMD ["./app"]


