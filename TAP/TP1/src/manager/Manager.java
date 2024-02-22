package manager;
import java.awt.*;
import java.awt.event.*;
import java.security.SecureRandom;

import javax.swing.*;

import manager.user.User;

public class Manager extends JFrame{

    private JTextField nome;
    private JTextField senha;
    private JTextField saldo;
    private JTextField rendimento;

    public Manager(){
        super("Gestor de Finanças Pessoais");
        this.setLayout(new FlowLayout());
        this.setSize(400, 300);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel(new GridLayout(4,2));
        panel.setVisible(true);

        panel.add(new JLabel("Nome completo:"));
        nome = new JTextField();
        panel.add(nome);

        panel.add(new JLabel("Informe seu saldo atual"));
        saldo = new JTextField();
        panel.add(saldo);

        panel.add(new JLabel("Informe seu rendimento:"));
        rendimento = new JTextField();
        panel.add(rendimento);


        JButton cadastraButton = new JButton("Cadastrar");
        cadastraButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                cadastrar();
            }
        });
        panel.add(cadastraButton);

        this.add(panel);
    }

    public void cadastraUser(){
        

    }

    private int geraConta(int tamanho) {
        SecureRandom random = new SecureRandom();
        StringBuilder senha = new StringBuilder();

        for (int i = 0; i < tamanho; i++) {
            int digito = random.nextInt(10); // Gera um número aleatório de 0 a 9
            senha.append(digito);
        }

        return Integer.parseInt(senha.toString());
    }

    private User cadastrar(){
        User user = new User(this.nome.getText(),
        Integer.parseInt(this.senha.getText()),
        Double.parseDouble(this.saldo.getText()),
        Double.parseDouble(this.rendimento.getText()),
        geraConta(10));

        int confirmacao = JOptionPane.showConfirmDialog(
                this,
                "Confirme seus dados:\n\n" +
                        "Nome: " + user.getNome() + "\n" +
                        "Saldo: " + user.getSaldo() + "\n" +
                        "Rendimetno: " + user.getRendimento()+ "\n" +
                        "Número da conta: " + user.getNumConta(),
                "Confirmação de Cadastro",
                JOptionPane.YES_NO_CANCEL_OPTION
        );

        if(confirmacao == JOptionPane.YES_OPTION){
            return user;
        }else if(confirmacao == JOptionPane.NO_OPTION){
            cadastraUser();
        }
        JOptionPane.showConfirmDialog(this, "Cadastro Cancelado");
        return null;
    }

    public static void main(String[] args) {
        Manager managerWindow = new Manager();

        managerWindow.setVisible(true);
    }

}
