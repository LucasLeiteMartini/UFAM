import java.util.ArrayList;

public class Turma {
    String disciplina;
    int ano;
    int semestre;
    Professor professor = new Professor();
    ArrayList<Aluno> alunos;

    Turma(String disciplina, int ano, int semestre, Professor professor){
        this.disciplina = disciplina;
        this.ano = ano;
        this.semestre = semestre;
        this.professor = professor;
        this.alunos = new ArrayList<Aluno>();
    }

    

    Aluno getAluno(int matricula){
        for(int i = 0; i < alunos.size(); i++){
            if(matricula == alunos.get(i).matricula){
                return alunos.get(i);
            }
        }
        return null;
    }

    boolean checkAluno(int matricula){
        for(int i = 0; i < this.alunos.size(); i++){
            if(matricula == this.alunos.get(i).matricula){
                return false;
            }
        }
        return true;
    }

    

    void addAluno(Aluno aluno){
        if(this.alunos == null){
            this.alunos.add(aluno);
        }else{
            if(checkAluno(aluno.matricula)){
                this.alunos.add(aluno);
            }else{
            }
        }
    }

    double getMediaIdade(){
        
        double sumAge = 0.0;
        
        for(Aluno a : alunos){
            sumAge += (double) a.getIdade();
        }

        return sumAge / alunos.size();
    }
    
    String getDescricao(){
        String p = "Turma " + this.disciplina + " - " + this.ano + "/" + this.semestre + " (" + this.professor.getDescricao() + "):";
        int n = 1;
        for(Aluno b : alunos){
            p +="\n" + "  - Aluno " + n +": "+ b.getDescricao(); 
            n++;
        }
        return p;
    }


}
