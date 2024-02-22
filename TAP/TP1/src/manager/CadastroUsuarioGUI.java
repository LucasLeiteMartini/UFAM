
package manager;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CadastroUsuarioGUI extends JFrame {
    private JTextField nomeField;
    private JTextField emailField;
    private JTextField enderecoField;

    public CadastroUsuarioGUI() {
        // Configurações básicas do JFrame
        super("Cadastro de Usuário");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);
        setLocationRelativeTo(null);

        // Criação do JPanel para os componentes
        JPanel panel = new JPanel(new GridLayout(4, 2));

        // Adiciona componentes ao JPanel
        panel.add(new JLabel("Nome Completo:"));
        nomeField = new JTextField();
        panel.add(nomeField);

        panel.add(new JLabel("Email:"));
        emailField = new JTextField();
        panel.add(emailField);

        panel.add(new JLabel("Endereço:"));
        enderecoField = new JTextField();
        panel.add(enderecoField);

        JButton cadastrarButton = new JButton("Cadastrar");
        cadastrarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                cadastrar();
            }
        });
        panel.add(cadastrarButton);

        JButton cancelarButton = new JButton("Cancelar");
        cancelarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                cancelar();
            }
        });
        panel.add(cancelarButton);

        // Adiciona o JPanel ao JFrame
        add(panel);

        // Torna o JFrame visível
        setVisible(true);
    }

    private void cadastrar() {
        String nome = nomeField.getText();
        String email = emailField.getText();
        String endereco = enderecoField.getText();

        int confirmacao = JOptionPane.showConfirmDialog(
                this,
                "Confirme seus dados:\n\n" +
                        "Nome: " + nome + "\n" +
                        "Email: " + email + "\n" +
                        "Endereço: " + endereco,
                "Confirmação de Cadastro",
                JOptionPane.YES_NO_OPTION
        );

        if (confirmacao == JOptionPane.YES_OPTION) {
            JOptionPane.showMessageDialog(this, "Cadastro confirmado!");
            // Adicione o código para processar o cadastro confirmado aqui

            dispose();
        } else {
            JOptionPane.showMessageDialog(this, "Cadastro cancelado.");
            // Adicione o código para lidar com o cancelamento do cadastro aqui
        }
    }

    private void cancelar() {
        JOptionPane.showMessageDialog(this, "Cadastro cancelado.");
        // Adicione o código para lidar com o cancelamento do cadastro aqui
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new CadastroUsuarioGUI();
            }
        });
    }
}
