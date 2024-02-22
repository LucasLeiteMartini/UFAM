package manager.user;

public class User {
	protected String nome;
	private int senha;
	protected double saldo;
	protected double rendimento;
	private int numConta;
	
    public User(){
        this(null, 0, 0.0, 0.0, 0);
    }

    public User(String nome, int senha, double saldo, double rendimento, int numConta){
        setNome(nome);
        setSenha(senha);
        setSaldo(saldo);
        setRendimento(rendimento);
        setNumConta(numConta);
    }

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
