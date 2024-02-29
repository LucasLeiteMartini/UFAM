package manager;
import java.sql.*;
import manager.user.User;

public class UserDAO extends BancoDeDados{
    public void listarUsers(){
        try {
            Statement st = conexao.createStatement();
            ResultSet rs = st.executeQuery("select * from user");
            while(rs.next()){
            }
        } catch (SQLException e) {}
    }    

    public void addUser(User user) {
        try {
            String query = "INSERT INTO usuarios (nome, saldo, rendimento, num_conta) VALUES (?, ?, ?, ?)";
            
            try (PreparedStatement pst = conexao.prepareStatement(query)) {
                pst.setString(2, user.getNome());
                pst.setDouble(3, user.getSaldo());
                pst.setDouble(4, user.getRendimento());
                pst.setInt(5, user.getNumConta());
                
                int rowsAffected = pst.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Usuário adicionado com sucesso!");
                } else {
                    System.out.println("Falha ao adicionar usuário.");
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
