import java.util.Comparator;
import java.util.Collections;
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
	
	public int comparaTurmaEmSala(TurmaEmSala ts1, ArrayList<TurmaEmSala> ensalamento) {
		if(ts1 == null || ensalamento == null) {
			return 0;
		}else {
			for(TurmaEmSala ts2 : ensalamento) {
				if(comparaSala(ts1.sala, ts2.sala) == 1 && comparaTurma(ts1.turma, ts2.turma) == 1) {
					return 1;
				}
			}
			return 0;
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
				ensalamento.add(ts1);
				return true;
			}
		}
		return false;
	}
	
	public void alocarTodas() {
        for (Turma turma : turmas) {
            Sala salaDisponivel = encontrarSalaDisponivel(turma);

            if (salaDisponivel != null) {
                alocar(turma, salaDisponivel);
            }
        }
    }

	private Sala encontrarSalaDisponivel(Turma turma) {
	    for (Sala sala : salas) {
	        if (sala.acessivel && turma.numAlunos <= sala.capacidade && salaDisponivelConsecutivo(sala, turma.horarios)) {
	            return sala;
	        }
	    }
	    return null; // Retorna null se nenhuma sala disponível for encontrada
	}

	private boolean salaDisponivelConsecutivo(Sala sala, ArrayList<Integer> horarios) {
	    for (int horario : horarios) {
	        if (!salaDisponivel(sala, horario)) {
	            return false;
	        }
	    }
	    return true;
	}

//	int getTotalTurmas();
//	int getTotalEspacoLivre();
//	String relatorioResumoEnsalamento();
//	String relatorioTurmasPorSala();
//	String relatorioSalasPorTurma();
}