package manager;

import javax.swing.JFrame;

public class ConsultarUsuarioWindow extends JFrame{
    public ConsultarUsuarioWindow(){
        super("Consulta de Usuários por Nome Completo");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400,300);
        setLocationRelativeTo(null);

        UserDAO userDAO = new UserDAO();
    }
}
