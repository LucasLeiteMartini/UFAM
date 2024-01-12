import java.util.Calendar;


public class Aluno {
    String nome;
    int matricula;
    int anoNascimento;
    
    Aluno(){
        this(null, 0, 0);
    }

    Aluno(String nome, int matricula, int anoNascimento){
        this.nome = nome;
        this.matricula = matricula;
        this.anoNascimento = anoNascimento;
    }

    int getIdade(){
        int ano = Calendar.getInstance().get(Calendar.YEAR);
        return ano - this.anoNascimento;
    }

    String getDescricao(){
        return this.nome + " (mat=" + this.matricula + ", idade=" + getIdade() + ")";
    }

}