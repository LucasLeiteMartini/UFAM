import java.util.ArrayList;

public class Turma {
    String nome;
    String professor;
    int numAlunos;// quantidade total de alunos matriculados.
    boolean acessivel;
    ArrayList<Integer> horarios;
       
    static int[][] matrix = {
            {8 , 1,  8, 15, 22, 29},
            {10, 2,  9, 16, 23, 30},
            {12, 3, 10, 17, 24, 31},
            {14, 4, 11, 18, 25, 32},
            {16, 5, 12, 19, 26, 33},
            {18, 6, 13, 20, 27, 34},
            {20, 7, 14, 21, 28, 35}
        };
    
    Turma(){
    	this(null, null, 0, false);
    }

    Turma(String nome, String professor, int numAlunos, boolean acessivel){
        this.nome = nome;
        this.professor = professor;
        this.numAlunos = numAlunos;
        this.acessivel = acessivel;
        this.horarios = new ArrayList<>();
    }

    void addHorario(int horario) {
    	this.horarios.add(horario);
    }
    
    String getHorario(ArrayList<Integer> horarios) {
        StringBuilder str = new StringBuilder();

        for (int horario : horarios) {
            if (horario >= 1 && horario <= 7) {
                for (int i = 0; i < 7; i++) {
                    if (horario == matrix[i][1]) {
                        if (str.length() > 0) {
                            str.append(", ");
                        }
                        str.append("segunda ").append(matrix[i][0]).append("hs");
                    }
                }
            } else if (horario >= 8 && horario <= 14) {
                for (int i = 0; i < 7; i++) {
                    if (horario == matrix[i][2]) {
                        if (str.length() > 0) {
                            str.append(", ");
                        }
                        str.append("terça ").append(matrix[i][0]).append("hs");
                    }
                }
            } else if (horario >= 15 && horario <= 21) {
                for (int i = 0; i < 7; i++) {
                    if (horario == matrix[i][3]) {
                        if (str.length() > 0) {
                            str.append(", ");
                        }
                        str.append("quarta ").append(matrix[i][0]).append("hs");
                    }
                }
            } else if (horario >= 22 && horario <= 28) {
                for (int i = 0; i < 7; i++) {
                    if (horario == matrix[i][4]) {
                        if (str.length() > 0) {
                            str.append(", ");
                        }
                        str.append("quinta ").append(matrix[i][0]).append("hs");
                    }
                }
            } else if (horario >= 29 && horario <= 35) {
                for (int i = 0; i < 7; i++) {
                    if (horario == matrix[i][5]) {
                        if (str.length() > 0) {
                            str.append(", ");
                        }
                        str.append("sexta ").append(matrix[i][0]).append("hs");
                    }
                }
            }
        }

        return str.toString();
    }


    	int getNumAlunos() {
    		return this.numAlunos;
    	}
    
    	String getHorariosString() {
    		return getHorario(this.horarios);
    	}
    
    	String getDescricao() {
    		if(this.acessivel) {
    			return "Turma: " + this.nome + "\n" + "Professor: " + this.professor + "\n" + "Número de Alunos: " + this.numAlunos + "\n" + "Horário: " + getHorariosString() + "\n" + "Acessível: sim";

    		}else {
        		return "Turma: " + this.nome + "\n" + "Professor: " + this.professor + "\n" + "Número de Alunos: " + this.numAlunos + "\n" + "Horário: " + getHorariosString() + "\n" + "Acessível: não";

    		}
    	}
    	
    }