package manager;
import java.awt.*;
import javax.swing.*;

public class Manager extends JFrame{
    public Manager(){
        super("Gestor de Finanças Pessoais");
        this.setLayout(new FlowLayout());
        this.setSize(540, 540);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        Manager managerWindow = new Manager();

        managerWindow.setVisible(true);
        String nome = 
      JOptionPane.showInputDialog("Digite seu nome:");

      int confirm =
        JOptionPane.showConfirmDialog(managerWindow, "Este é seu nome: " + nome + "?");
       
    JOptionPane.showMessageDialog(null, nome + ", tamo junto krai", "Selecione uma opção", JOptionPane.INFORMATION_MESSAGE);

    }

}
