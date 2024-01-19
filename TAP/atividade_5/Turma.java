import java.util.ArrayList;

public class Turma {
    String nome;
    String professor;
    int numAlunos;// quantidade total de alunos matriculados.
    boolean acessivel;
    ArrayList<Integer> horarios;

    Turma(String nome, String professor, int numAlunos, boolean acessivel){
        this.nome = nome;
        this.professor = professor;
        this.numAlunos = numAlunos;
        this.acessivel = acessivel;
        this.horarios = new ArrayList<>();
    }



}
