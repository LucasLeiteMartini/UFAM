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
	
	void addCoordenada(Coordenada coordenada) throws TamanhoMaximoExcedidoException, DistanciaEntrePontosExcedidaException{
		if(this.tamanho > this.caminho.length) throw new TamanhoMaximoExcedidoException();
		else {
			
		}
	}
	
	public String toString() {
		int cont = 0;
		if(this.caminho.length > 0) {
			for(Coordenada coord : this.caminho) {			
				cont++;
			}
			
			String str = "Dados do caminho: \n" + "  - Quantidade de pontos: " + cont + "\n" + "  - Pontos:\n";
			
			for(Coordenada coord : this.caminho) {			
				str += "	-> " + coord.toString();
			}
			
			return str;
		}else {
			return null;
		}
	}
}
