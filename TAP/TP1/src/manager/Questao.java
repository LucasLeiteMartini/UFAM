package manager;

public class Questao{
    private String descricao;
    private String resposta;

    public Questao(String descricao, String resposta){
        this.descricao = descricao;
        this.resposta = resposta;
    }
    public static void main(String[] args) {
        Questao q1 = new Questao("ABC", "123");
        Questao q2 = new Questao("ABC", "123");

        if(q1 == q2){
            System.out.println("Q1 == Q2");
        }else {
            System.out.println("Q1 <> Q2");
        }

        if(q1.equals(q2)){
            System.out.println("Q1 == Q2");
        }else{
            System.out.println("Q1 <> Q2");
        }
    }
}