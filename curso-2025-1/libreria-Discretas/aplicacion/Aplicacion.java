package aplicacion;

import libSpartanScytale.JavaSpartanScytale;
import java.util.Scanner;

public class Aplicacion {

    JavaSpartanScytale scytale = null;

    static {
        System.loadLibrary("scytale");
    }

    public Aplicacion() {
        this.scytale = new JavaSpartanScytale();
    }

    public void iniciar() {
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("\n===== ESCITALA ESPARTANA =====");
            System.out.println("1. Codificar mensaje");
            System.out.println("2. Decodificar mensaje");
            System.out.println("3. Salir");
            System.out.print("Seleccione una opcion: ");
            opcion = scanner.nextInt();
            scanner.nextLine(); // Limpiar buffer

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese el mensaje a codificar: ");
                    String mensajeCodificar = scanner.nextLine();
                    System.out.print("Ingrese el diametro (numero de filas): ");
                    int diametroCodificar = scanner.nextInt();
                    scanner.nextLine();

                    String codificado = scytale.codificar(diametroCodificar, mensajeCodificar);
                    System.out.println("Mensaje codificado: " + codificado);
                    break;

                case 2:
                    System.out.print("Ingrese el mensaje a decodificar: ");
                    String mensajeDecodificar = scanner.nextLine();
                    System.out.print("Ingrese el diametro (numero de filas): ");
                    int diametroDecodificar = scanner.nextInt();
                    scanner.nextLine();

                    String decodificado = scytale.decodificar(diametroDecodificar, mensajeDecodificar);
                    System.out.println("Mensaje decodificado: " + decodificado);
                    break;

                case 3:
                    System.out.println("¡Hasta luego!");
                    break;

                default:
                    System.out.println("Opción invalida.");
            }

        } while (opcion != 3);

        scanner.close();
    }

    public static void main(String[] args) {
        Aplicacion app = new Aplicacion();
        app.iniciar();
    }
}

