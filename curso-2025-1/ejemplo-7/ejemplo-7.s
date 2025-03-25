

.text
.global suma_float


# para los floats se utilizan los registro xmm (son de 128 bits)
# segun system V:
# xmm0 funcion (xmm0,xmm1,xmm2, ....)

suma_float:
	addss %xmm1, %xmm0 # xmm0=xmm0+xmm1
	ret
# addss significa Add Scalar Single Precision (sumar un escadar de presicion simple, osea un float)

