import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class JediAcademy extends JFrame {

	public JediAcademy() {
		super("Jedi Academy v1.0");
		this.setLayout(null);
		this.setSize(260, 180);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		JLabel lTitulo = new JLabel("Jedi Academy v1.0");
		lTitulo.setBounds(0, 10, 260, 20);
		lTitulo.setHorizontalAlignment(SwingConstants.CENTER);
		this.add(lTitulo);
		
		JLabel lDesc = new JLabel("Sistema de Controle e Gerenciamento");
		lDesc.setBounds(0, 25, 260, 20);
		lDesc.setHorizontalAlignment(SwingConstants.CENTER);
		lDesc.setFont(new Font("Dialog", Font.ITALIC, 8));
		this.add(lDesc);
		
		JButton bGer = new JButton("Gerenciar Jedi Initiates");
		bGer.setBounds(20, 55, 220, 25);
		this.add(bGer);
		
		JButton bRel = new JButton("Relatórios de Controle");
		bRel.setBounds(20, 85, 220, 25);
		this.add(bRel);
		
		JButton bSobre = new JButton("Sobre o Sistema");
		bSobre.setBounds(20, 115, 220, 25);
		this.add(bSobre);
		
//		bSobre.addActionListener(new ActionListener() {
//			
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				// TODO Auto-generated method stub
//				JOptionPane.showMessageDialog(null, "PEIDO HAHAHAHAHAHA!");
//				
//			}
//		});
		
		bSobre.addActionListener((ActionEvent e) -> {
			JOptionPane.showMessageDialog(null, "Jedi Academy v1.0 !!");
			});
	
		bGer.addActionListener((ActionEvent e) -> {
			ManagerWindow managerWindow = new ManagerWindow();
			managerWindow.setVisible(true);
		});
		
	}
	
	public static void main(String[] args) {
		JediAcademy mainWindow = new JediAcademy();
		mainWindow.setVisible(true);
	}
	
}
