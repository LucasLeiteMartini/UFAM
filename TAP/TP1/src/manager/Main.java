package manager;
import java.sql.*;


public class Main {
    public static void main(String[] args) {
        try {
            Connection conexao = DriverManager.getConnection("jdbc:mysql://localhost:3306/gfp", "gfp_admin", "MasterManager");
            System.out.println("ESTA MERDA FUNCIONA");
            conexao.close();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }    
}
