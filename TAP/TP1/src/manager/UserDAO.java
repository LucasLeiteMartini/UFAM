package manager;
import java.sql.*;
public class UserDAO extends BancoDeDados{
    public void listarUsers(){
        try {
            Statement st = conexao.createStatement();
            ResultSet rs = st.executeQuery("select * from user");
            while(rs.next()){
            }
        } catch (SQLException e) {}
    }    
}
