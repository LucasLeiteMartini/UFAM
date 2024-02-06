package br.edu.ufam.icomp.lab_excecoes;

public class Coordenada {

	private int posX;
	private int posY;
	private int digito;
	
	public Coordenada(int posX, int posY, int digito) throws CoordenadaNegativaException, CoordenadaForaDosLimitesException, DigitoInvalidoException{
		
		if(posX < 0 || posY < 0 || digito < 0) throw new CoordenadaNegativaException();
		else if(posX > 30000 || posY > 30000) throw new CoordenadaForaDosLimitesException();
		else if(((posX + posY) % 10) != digito) throw new DigitoInvalidoException();
		else {			
			this.posX = posX;
			this.posY = posY;
			this.digito = digito;
		}
	}
	
	public int getPosX() {
		return this.posX;
	}
	
	public int getPosY() {
		return this.posY;
	}
	
	public double distancia(Coordenada coordenada){
		double dist;
		
		dist = Math.sqrt(Math.pow((this.posX - coordenada.getPosX()), 2) + Math.pow((this.posY - coordenada.getPosY()), 2));  
		
		return dist;
	}
	
	public String toString() {
		return getPosX() + ", " + getPosY();
	}
	
}
