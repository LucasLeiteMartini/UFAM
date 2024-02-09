package br.edu.ufam.icomp.lab_excecoes;

public class Caminho {

	private Coordenada[] caminho;
	private int tamanho;
	
	public Caminho(int maxTam) {
		this.caminho = new Coordenada[maxTam];
		this.tamanho = 0;
	}
	
	public int tamanho() {
		return this.tamanho;
	}
	
	public void reset() {
		
		for(Coordenada coord : caminho) {
			coord = null;
		}
		
		this.tamanho = 0;
	
	}
	
	
	Coordenada getUltima() {
		int i = 0;
		while(this.caminho[i] != null) {
			i++;
		}
		if(i > 0)return this.caminho[i-1];
		else return this.caminho[i];
	}
	
	public void addCoordenada(Coordenada coordenada) throws TamanhoMaximoExcedidoException, DistanciaEntrePontosExcedidaException{
		Coordenada ult = getUltima();
		
		if(this.tamanho >= this.caminho.length - 1) throw new TamanhoMaximoExcedidoException();
		else {
			if(coordenada.distancia(ult) > 15) throw new DistanciaEntrePontosExcedidaException();
			else {
				this.caminho[this.tamanho] = coordenada; 
				this.tamanho++;
			}
		}
	}
	
	public String toString() {
		int cont = 0, i = 0;
		String str = "Dados do caminho:\n" + "  - Quantidade de pontos: " + cont + "\n" + "  - Pontos:\n";
		if(this.caminho.length > 0) {
			while(cont < this.caminho.length && this.caminho[cont] != null) {
				cont++;
			}
			
			str = "Dados do caminho:\n" + "  - Quantidade de pontos: " + cont + "\n" + "  - Pontos:\n";

			while(i < this.caminho.length && this.caminho[i] != null) {
				str += "    -> " + this.caminho[i].toString() + "\n";
				i++;
			}
			
		}
		return str;
	}
}
