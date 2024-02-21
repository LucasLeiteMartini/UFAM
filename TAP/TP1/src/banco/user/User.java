package banco.user;

public class User {
	protected String nome;
	protected int senha;
	protected double saldo;
	protected double rendimento;
	protected int numConta;
	
	public double getSaldo() {
		return this.saldo;
	}
		
	public double getRendimento() {
		return this.rendimento;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	protected int getNumConta() {
		return this.numConta;
	}
	
}
