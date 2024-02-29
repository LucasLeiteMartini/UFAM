package manager;

import java.sql.*;

import javax.swing.JOptionPane;

import java.awt.*;

public class DespesasDAO extends BancoDeDados{


    public void listaDespesas(){

        String nome = 
        JOptionPane.showInputDialog("Digite o nome");
        
        try{
            Statement st = conexao.createStatement();
            ResultSet rs = st.executeQuery("SELECT * FROM usuarios, despesas WHERE usuarios.nome=" + nome + "AND depesas");
            
            }catch (SQLException e){}
    }
}