package aplicacion;

import libcalculadora.JavaCalculadora;

public class Aplicacion{

	//Declaramos un objeto que represente a la biblioteca
	JavaCalculadora calculadora =null;

	static{
		System.loadLibrary("cal");
	}

	public Aplicacion(){
		this.calculadora=new JavaCalculadora();
		System.out.println("la suma de 3  y 5 es: "+ calculadora.sumar(3,5));
	}

	public static void main(String[]  args){
		new Aplicacion();
	}
}
