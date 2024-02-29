package manager;

import java.awt.*;
import javax.swing.*;

public class Manager extends JFrame{

    

    public Manager() {
        // Configurações básicas do JFrame
        super("Gestor de Finanças");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);
        setLocationRelativeTo(null);

        // Criação do JPanel para os componentes
        JPanel panel = new JPanel(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5); // Espaçamento entre os componentes

        // Adiciona o JPanel ao JFrame
        add(panel);

        // Adiciona botões para operações
        JButton consultarUsuarioButton = new JButton("Consultar Usuário por ID");
        consultarUsuarioButton.addActionListener(e -> consultarUsuario());
        addField(panel, gbc, "", consultarUsuarioButton);

        JButton cadastrarUsuarioButton = new JButton("Cadastrar Usuário");
        cadastrarUsuarioButton.addActionListener(e -> new CadastrarWindow());
        addField(panel, gbc, "", cadastrarUsuarioButton);

        JButton consultarDespesasButton = new JButton("Consultar Despesas por ID de Usuário");
        consultarDespesasButton.addActionListener(e -> consultarDespesas());
        addField(panel, gbc, "", consultarDespesasButton);

        JButton gerirDespesasButton = new JButton("Gerir Despesas");
        gerirDespesasButton.addActionListener(e -> gerirDespesas());
        addField(panel, gbc, "", gerirDespesasButton);

        // Torna o JFrame visível
        setVisible(true);
    }

    // Método auxiliar para adicionar rótulo e campo ao painel
    public void addField(JPanel panel, GridBagConstraints gbc, String label, JComponent component) {
        gbc.gridx = 0;
        gbc.gridy++;
        panel.add(new JLabel(label), gbc);

        gbc.gridx = 1;
        panel.add(component, gbc);
    }

    private void consultarUsuario() {
        // Adicione o código para consultar usuário por ID aqui
        JOptionPane.showMessageDialog(this, "Consulta de Usuário por ID");
    }

    private void consultarDespesas() {
        // Adicione o código para consultar despesas por ID de usuário aqui
        JOptionPane.showMessageDialog(this, "Consulta de Despesas por ID de Usuário");
    }

    private void gerirDespesas() {
        // Adicione o código para gerir despesas aqui
        JOptionPane.showMessageDialog(this, "Gerenciamento de Despesas");
    }    

    public static void main(String[] args) {
        Manager managerWindow = new Manager();
    }
}
