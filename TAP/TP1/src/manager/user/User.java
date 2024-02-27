package manager.user;

public class User {
    private int id;
	private String nome;
	private String saldo;
	private String rendimento;
	private String numConta;

    public User(){
        this(null, null, null, null);
    }

    public User(String nome, String saldo, String rendimento, String numConta){
        setNome(nome);
        setSaldo(saldo);
        setRendimento(rendimento);
        setNumConta(numConta);
    }

    public int getID(){
        return this.id;
    }

	public String getSaldo() {
		return this.saldo;
	}
    
    public String getRendimento() {
        return this.rendimento;
    }
    
    public String getNome() {
        return this.nome;
    }

    public String getNumConta() {
        return this.numConta;
    }
      
    public void setId(int id){
        this.id = id;
    }

    public void setRendimento(String rendimento){
        this.rendimento = rendimento;
    }

    public void setSaldo(String saldo){
        this.saldo = saldo;
    }
	
    public void setNome(String nome){
        this.nome = nome;
    }

    public void setNumConta(String numConta){
        this.numConta = numConta;
    }

}
