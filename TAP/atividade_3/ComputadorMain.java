public class ComputadorMain {
    public static void main(String[] args) {
        Processador processador = new Processador();
        Memoria memoria = new Memoria();
        Disco disco = new Disco();
        Computador computador = new Computador(null, processador, memoria, disco);
    }
}
