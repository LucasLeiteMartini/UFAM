package br.edu.icomp.ufam.lab_heranca;
import java.util.ArrayList;
public class FormasMain {

	public static void main(String[] args) {
		Circulo c1 = new Circulo(1, 2, 5);
		Retangulo r1 = new Retangulo(10, 12, 7, 8);
		Quadrado q1 = new Quadrado(12, 14, 7);

		FormaGeometrica[] lista= new FormaGeometrica[3];
		
		lista[0] = c1;
		lista[1] = r1;
		lista[2] = q1;
		
		for(FormaGeometrica a : lista) {
			System.out.println(a);
		}
		
	}

}
