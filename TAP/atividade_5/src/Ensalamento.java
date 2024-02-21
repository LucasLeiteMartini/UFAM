import java.util.ArrayList;

public class Ensalamento {
	
	ArrayList<Sala> salas;
	ArrayList<Turma> turmas;
	ArrayList<TurmaEmSala> ensalamento;

	Ensalamento(){
		this.salas = new ArrayList<Sala>();
		this.ensalamento = new ArrayList<TurmaEmSala>();
		this.turmas = new ArrayList<Turma>();
	}
	
	public int comparaTurma(Turma t1, Turma t2) {
		if(t1.acessivel && !t2.acessivel || !t1.acessivel && t2.acessivel) {
			return 0;
		}else {
			if(t1.nome.contentEquals(t2.nome) && t1.numAlunos == t2.numAlunos && t1.professor.contentEquals(t2.professor) && t1.horarios.size() == t2.horarios.size()) {
				for(int i = 0; i < t1.horarios.size(); i++) {
					if(t1.horarios.get(i) != t2.horarios.get(i)) {
						return 0;
					}
				}
			}else {
				return 0;
			}
			return 1;
		}
	}
	
	public int comparaSala(Sala s1, Sala s2) {
		if(s1.acessivel && !s2.acessivel || !s1.acessivel && s2.acessivel) {
			return 0;
		}else {
			if(s1.bloco == s2.bloco && s1.capacidade == s2.capacidade && s1.sala == s2.sala) {
				return 1;
			}else {
				return 0;
			}
		}
	}
	
	public Sala getSala(Turma turma) {
		if(turma == null) {
			return null;
		}else {
			for(TurmaEmSala ts : this.ensalamento) {
				if(comparaTurma(ts.turma, turma) == 1) {
					return ts.sala;
				}
			}
			return null;
		}
	}

	public boolean salaDisponivel(Sala sala, int horario) {
	    if (sala == null || horario <= 0) {
	        return false;
	    }

	    for (TurmaEmSala t1 : this.ensalamento) {
	        if (comparaSala(t1.sala, sala) == 1 && t1.turma.horarios.contains(horario)) {
	        	return false;
	        } else {
	            continue;
	        }
	    }
	    return true;
	}

	
	public boolean salaDisponivel(Sala sala, ArrayList<Integer> horarios) {
		for(int a : horarios) {
			if(!salaDisponivel(sala, a)) {
				return false;
			}
		}
		return true;
	}
	
	public void addSala(Sala sala) {
		if(this.salas == null) {
			System.out.println("Lista de Salas inexistente");
		}else {
			this.salas.add(sala);
		}
	}
	
	public void addTurma(Turma turma) {
		if(this.turmas == null) {
			System.out.println("Lista de Turmas inexistente");
		}else {
			this.turmas.add(turma);
		}
	}
	
	public boolean alocar(Turma turma, Sala sala) {
		if(turma == null || sala == null || !turma.acessivel || !sala.acessivel) {
			return false;
		}else {
			if(turma.acessivel && sala.acessivel && turma.numAlunos <= sala.capacidade && salaDisponivel(sala, turma.horarios)) {
				TurmaEmSala ts1 = new TurmaEmSala(turma, sala);
				this.ensalamento.add(ts1);
				return true;
			}
		}
		return false;
	}
	
	public void alocarTodas() {
        for (Turma turma : turmas) {

        }
    }


	public int getTotalTurmasAlocadas() {
		int totalTurmasAlocadas = 0;
		
		for(TurmaEmSala turma : this.ensalamento) {
			if(turma != null) {
				totalTurmasAlocadas ++;
			}
		}
		return totalTurmasAlocadas;
	}
	
	
	public int getTotalEspacoLivre() {
		int totalEspacoLivre = 0;
		
		for(TurmaEmSala turmaEmSala : this.ensalamento) {
			if(turmaEmSala.sala != null) {
				int espacoLivre = turmaEmSala.sala.capacidade - turmaEmSala.turma.numAlunos;
				totalEspacoLivre += espacoLivre;
			}
		}
		return totalEspacoLivre;
	}
	public String relatorioResumoEnsalamento() {
        int totalSalas = salas.size();
        int totalTurmas = turmas.size();
        int turmasAlocadas = getTotalTurmasAlocadas();
        int espacosLivres = getTotalEspacoLivre();

        StringBuilder resumo = new StringBuilder();
        resumo.append("Total de Salas: ").append(totalSalas).append("\n");
        resumo.append("Total de Turmas: ").append(totalTurmas).append("\n");
        resumo.append("Turmas Alocadas: ").append(turmasAlocadas).append("\n");
        resumo.append("Espaços Livres: ").append(espacosLivres).append("\n\n");

        return resumo.toString();
    }

	boolean checaAlocamentoSala(Sala s1) {
		for(TurmaEmSala a : this.ensalamento) {
			if(comparaSala(a.sala, s1) == 1) {
				return false;
			}
		}
		return true;
	}
	
	public String relatorioTurmasPorSala() {
		String str = relatorioResumoEnsalamento();
	
		if (this.ensalamento.size() > 0) {
			for (TurmaEmSala a : this.ensalamento) {
				str += "--- " + a.sala.getDescricao() + "---\n" + a.turma.getDescricao();
			}
		}
		for(Sala s1 : this.salas) {				
			if(checaAlocamentoSala(s1)) {
				str += "--- " + s1.getDescricao() + " ---\n";
			}
		}
		return str;
	}
	
	boolean checaAlocamentoTurma(Turma t1){
		for(TurmaEmSala a : this.ensalamento) {
			if(comparaTurma(a.turma, t1) == 1) {
				return false;
			}
		}
		return true;
	}
	
	public String relatorioSalasPorTurma() {
		String str = relatorioResumoEnsalamento();

		if(this.ensalamento.size() > 0) {			
			for(TurmaEmSala a : this.ensalamento) {
				str += a.turma.getDescricao() + "Sala: " + a.sala.getDescricao() + "\n";
			}
		}else{
			for(Turma t1 : this.turmas){
				if(checaAlocamentoTurma(t1)) {
					str += t1.getDescricao() + "Sala: SEM SALA\n";
				}
			}
		}
		

		return str;
	}

}