package manager;
import manager.user.User;

import java.sql.*;

import javax.swing.*;
public class UserDAO extends BancoDeDados{
    public void listarUsers(){
        try {
            Statement st = conexao.createStatement();
            ResultSet rs = st.executeQuery("select * from user");
            while(rs.next()){
            }
        } catch (SQLException e) {}
    }    

    public boolean addUser(User user){
        try {
            Statement st = conexao.createStatement();
            st.executeQuery("INSERT INTO usuarios VALUES ( NULL, '" + user.getNome() + "', " +
                                                                                user.getSaldo() + ", " + 
                                                                                user.getRendimento() + ", " + 
                                                                                user.getNumConta() + ");");
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
            return false;
        }
    }

    public boolean deleteUser(User user){
        try{
            Statement st = conexao.createStatement();

            int confirmacao = JOptionPane.showConfirmDialog(
                null,
                "Confirme seus dados:\n\n" +
                        "Nome: " + user.getNome() + "\n" +
                        "Saldo: " + user.getSaldo() + "\n" +
                        "Rendimento: " + user.getRendimento() + "\n" +
                        "Número da Conta: " + user.getNumConta(),
                "Confirmação de Usuário a ser Excluído",
                JOptionPane.YES_NO_OPTION
        );

            if(confirmacao == JOptionPane.YES_OPTION){
            st.executeQuery("DELETE FROM usuarios WHERE nome='" +user.getNome() + 
                                                "' AND saldo=" + user.getSaldo() +
                                                " AND rendimento=" + user.getRendimento() +
                                                    " AND numConta=" + user.getNumConta());
        return true;
        }else{
            JOptionPane.showMessageDialog(null, "Exclusão cancelada!");
            return false;
        }
        }catch(SQLException e){e.printStackTrace(); return false;}
    }

    public static void main(String[] args) {
        UserDAO userDAO = new UserDAO();
        User user = new User("lucas leite", 12345, 12.34, 2952722);
        userDAO.deleteUser(user);
        if(userDAO.deleteUser(user) == true){
            System.out.println("deu certo");
        }else{
            System.out.println("deu errado");
        }
    }

} 
