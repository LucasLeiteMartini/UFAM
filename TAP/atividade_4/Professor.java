public class Professor {
    String titulacao;
    String nome;
    int matricula;

    
    Professor(){
        this(null,null,0);
    }

    Professor(String tiulacao, String nome, int matricula){
        this.titulacao = tiulacao;
        this.nome = nome;
        this.matricula = matricula;
    }

    String getDescricao(){
        return "Prof. " + this.titulacao + " " + this.nome + " - mat " + this.matricula;
    }


}
