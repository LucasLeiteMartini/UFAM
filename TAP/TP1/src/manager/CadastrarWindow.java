package manager;

import java.awt.*;
import java.security.SecureRandom;

import javax.swing.*;

import manager.user.User;

public class CadastrarWindow extends JFrame{
    private JTextField nome;
    private JTextField saldo;
    private JTextField rendimento;

    public CadastrarWindow(){
        super("Cadastrar Usuários");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400,300);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);

        addField(panel, gbc, "Nome Completo:", nome = new JTextField(20));
        addField(panel, gbc, "Saldo atual:", saldo = new JTextField(20));
        addField(panel, gbc, "Rendimento atual:", rendimento = new JTextField(20));

        JButton cadastrarUsuarioButton = new JButton("Cadastrar Usuário");
        cadastrarUsuarioButton.addActionListener(e -> cadastrar());
        addField(panel, gbc, "", cadastrarUsuarioButton);

        JButton cancelaCadastrButton = new JButton("Cancelar cadastro");
        cancelaCadastrButton.addActionListener(e -> dispose());
        addField(panel, gbc, "", cancelaCadastrButton);

        add(panel);

        setVisible(true);
    }

    private void cadastrar() {
        String nome = this.nome.getText();
        double saldo = Double.parseDouble(this.saldo.getText());
        double rendimento = Double.parseDouble(this.rendimento.getText());
        int conta = geraConta(8);

        int confirmacao = JOptionPane.showConfirmDialog(
                this,
                "Confirme seus dados:\n\n" +
                        "Nome: " + nome + "\n" +
                        "Saldo: " + saldo + "\n" +
                        "Rendimento: " + rendimento + "\n" +
                        "Número da Conta: " + conta,
                "Confirmação de Cadastro",
                JOptionPane.YES_NO_OPTION
        );

        if (confirmacao == JOptionPane.YES_OPTION) {
            JOptionPane.showMessageDialog(this, "Cadastro confirmado!");
            // Adicione o código para processar o cadastro confirmado aqui
            User user = new User(nome, saldo, rendimento, conta);
            UserDAO userDAO = new UserDAO();
            userDAO.addUser(user);
            dispose();
        } else {
            JOptionPane.showMessageDialog(this, "Cadastro cancelado.");
            dispose();
            // Adicione o código para lidar com o cancelamento do cadastro aqui
        }
    } 

    public void addField(JPanel panel, GridBagConstraints gbc, String label, JComponent component) {
        gbc.gridx = 0;
        gbc.gridy++;
        panel.add(new JLabel(label), gbc);

        gbc.gridx = 1;
        panel.add(component, gbc);
    }
    
    private int geraConta(int tamanho) {
        SecureRandom random = new SecureRandom();
        StringBuilder conta = new StringBuilder();

        for (int i = 0; i < tamanho; i++) {
            int digito = random.nextInt(10); // Gera um número aleatório de 0 a 9
            conta.append(digito);
        }

        return Integer.parseInt(conta.toString());
    }

}
