package manager.user.despesa;

public class Despesa {
	private int id;
	private double valor;
	private String data;
	private String categoria;
	
	public Despesa() {
		this(0.0, null, null);
	}
	
	public Despesa(double valor, String data, String categoria) {
		setValor(valor);
		setData(data);
		setCategoria(categoria);
	}
	
	public int getId(){
		return this.id;
	}

	public double getValor() {
		return this.valor;
	}
	
	public String getData() {
		return this.data;
	}
	
	public String getCategoria() {
		return this.categoria;
	}
	
	public void setId(int id){
		this.id = id;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}
	
	public void setData(String data) {
		this.data = data;
	}
	
	public void setCategoria(String categoria) {
		this.categoria = categoria;
	}
	
	/*public static void main(String[] args) {
		Despesa d1 = new Despesa();
		
		d1.setCategoria("Macacada");
		d1.setData("21/02/2024");
		d1.setValor(15.96);
		
		System.out.println(d1);
		
	}*/
}