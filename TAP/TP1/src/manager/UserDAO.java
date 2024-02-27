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

    public void addUser(User user){
        try {
            Statement st = conexao.createStatement();
            ResultSet rs = st.executeQuery("INSERT INTO usuariso VALUES ( NULL, " + user.getNome() + ", " +
                                                                                user.getSaldo() + ", " + 
                                                                                user.getRendimento() + ", " + 
                                                                                user.getNumConta());
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
