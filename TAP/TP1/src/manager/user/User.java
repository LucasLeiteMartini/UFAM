package manager.user;

import manager.user.despesa.Despesa;

public class User {
    private int id;
	private String nome;
	private int senha;
	private double saldo;
	private double rendimento;
	private int numConta;
	private Despesa[] despesas;

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

    public int getID(){
        return this.id;
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
    
    public void setId(int id){
        this.id = id;
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
