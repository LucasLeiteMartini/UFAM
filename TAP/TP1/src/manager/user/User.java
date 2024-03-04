package manager.user;

public class User {
	private String nome;
	private double saldo;
	private double rendimento;
	private int numConta;

    public User(){
        this(null, 0.0, 0.0, 0);
    }

    public User(String nome, double saldo, double rendimento, int numConta){
        setNome(nome);
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

}
