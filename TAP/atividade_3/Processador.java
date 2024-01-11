public class Processador{
    String marca;
    String modelo;
    double velocidade;
    int numNucleos;

    Processador(){
        this("", "", 0.0, 0);
    }    

    Processador(String marca, String modelo, double velocidade, int numNucleos){
        this.marca = marca;
        this.modelo = modelo;
        this.velocidade = velocidade;
        this.numNucleos = numNucleos;
    }

    public double getVelocidadeParalela(){
        return this.velocidade*this.numNucleos;
    }

    public String getDescricao(){
        return "Processador: marca=" + this.marca + ", modelo=" + this.modelo + ", velocidade=" + this.velocidade + "GHz" + ", numNucleos=" + this.numNucleos + ", velocidadeParalela=" + getVelocidadeParalela() + "GHz.";
    }

}
