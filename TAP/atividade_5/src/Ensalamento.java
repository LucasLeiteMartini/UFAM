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
	
	int comparaTurma(Turma t1, Turma t2) {
		if(t1.acessivel && !t2.acessivel || !t1.acessivel && t2.acessivel) {
			return 0;
		}else {
			if(t1.nome.contentEquals(t2.nome)) {
				if(t1.numAlunos == t2.numAlunos) {
					if(t1.professor.contentEquals(t2.professor)) {
						if(t1.horarios.size() == t2.horarios.size()) {
							for(int i = 0; i < t1.horarios.size(); i++) {
								if(t1.horarios.get(i) != t2.horarios.get(i)) {
									return 0;
								}
							}
						}else {							
							return 0;
						}
					}else {
						return 0;						
					}
				}else {
					return 0;
				}
			}
			return 1;
		}
	}
	int comparaSala(Sala s1, Sala s2) {
		if(s1.acessivel && !s2.acessivel || !s1.acessivel && s2.acessivel) {
			return 0;
		}else {
			if(s1.bloco == s2.bloco) {
				if(s1.sala == s2.sala) {
					if(s1.capacidade == s1.capacidade) {
						return 1;
					}
				}else {
					return 0;
				}
			}else {
				return 0;
			}
		}
		return 0;
	}
	
	Sala getSala(Turma turma) {
		for(TurmaEmSala ts : this.ensalamento) {
			if(comparaTurma(ts.turma, turma) == 1) {
				return ts.sala;
			}
		}
		return null;
	}

	boolean salaDisponivel(Sala sala, int horario) {
		for(TurmaEmSala t1 : this.ensalamento) {
			if(comparaSala(t1.sala, sala) == 1) {
				for(int i = 0; i < this.ensalamento.size(); i++) {
					if(this.ensalamento.get(i).turma.horarios.get(i) == horario) {
						return false;
					}
				}
			}else {
				return false;
			}
		}
		return true;
	}
	
	void addSala(Sala sala) {
		if(this.salas == null) {
			System.out.println("Lista de Salas inexistente");
		}else {
			this.salas.add(sala);
		}
	}
	
	void addTurma(Turma turma) {
		if(this.turmas == null) {
			System.out.println("Lista de Turmas inexistente");
		}else {
			this.turmas.add(turma);
		}
	}

	
	
	boolean alocar(Turma turma, Sala sala) {
		if(turma.acessivel && sala.acessivel) {
			if(turma.numAlunos <= sala.capacidade) {
				if()
			}
		}
	}
	
}