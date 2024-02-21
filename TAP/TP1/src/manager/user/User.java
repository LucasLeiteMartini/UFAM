package manager.user;

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

    public int getNumConta() {
        return this.numConta;
    }
    
    public int getSenha(){
        return this.senha;
    }
    
    public void setRendimento(double rendimento){
        this.rendimento = rendimento;
    }

    public void setSaldo(double saldo){
        this.saldo = saldo;
    }
		
	
    public void setNome(String nome){
        this.nome = nome;
    }

    public void setNumConta(int numConta){
        this.numConta = numConta;
    }

    public void setSenha(int senha){
        this.senha = senha;
    }

}
