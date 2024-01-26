public class Sala{
    int bloco;
    int sala;
    int capacidade;
    boolean acessivel;


    Sala(){
        this(0, 0, 0, false);
    }

    Sala(int bloco, int sala, int capacidade, boolean acessivel){
        this.bloco = bloco;
        this.sala = sala;
        this.capacidade = capacidade;
        this.acessivel = acessivel;
    }

    String getDescricao(){
        if(this.acessivel){
            return "Bloco " + this.bloco + ", Sala " + this.sala + " (" + this.capacidade + " lugares, acessível)";
        }
        return "Bloco " + this.bloco + ", Sala " + this.sala + " (" + this.capacidade + " lugares, não acessível)";
    }

    int getCapacidade() {
    	return this.capacidade;
    }
    
}