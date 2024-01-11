public class Memoria {
    String marca;
    String tipo;
    double tamanho;
    double velocidade;
    int numPentes;


    Memoria(){

    }

    Memoria(String marca, String tipo, double tamanho, double velocidade, int numPentes){
        this.marca = marca;
        this.tipo= tipo;
        this.tamanho = tamanho;
        this.velocidade = velocidade;
        this.numPentes = numPentes;
    }

    double getTamanhoTotal(){
        return this.tamanho * this.numPentes;
    }

    double getVelocidadeParalela(){
        return this.velocidade*this.numPentes;
    }

    String getDescricao(){
        return "Memoria: marca=" + this.marca + ", tipo=" + this.tipo + ", tamanho=" + this.tamanho + "GB" + ", velocidade=" + this.velocidade + "GHz" + ", numPentes=" + this.numPentes + ", tamanhoTotal=" + getTamanhoTotal() + "GB" + ", velocidadeParalela=" + getVelocidadeParalela() + "GHz.";
    }


}
