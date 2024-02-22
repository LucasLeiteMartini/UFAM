package manager;
import javax.swing.JOptionPane;

public class CadastroUsuarioDialog {

    public static void main(String[] args) {
        // Objeto para armazenar os dados do usuário
        Usuario usuario = new Usuario();

        // Pedir nome completo
        usuario.setNomeCompleto(obterEntrada("Digite seu nome completo:"));

        // Pedir email
        usuario.setEmail(obterEntrada("Digite seu email:"));

        // Pedir endereço
        usuario.setEndereco(obterEntrada("Digite seu endereço:"));

        // Exibir janela de confirmação com todos os dados
        int confirmacao = JOptionPane.showConfirmDialog(
                null,
                "Confirme seus dados:\n\n" +
                        "Nome: " + usuario.getNomeCompleto() + "\n" +
                        "Email: " + usuario.getEmail() + "\n" +
                        "Endereço: " + usuario.getEndereco(),
                "Confirmação de Cadastro",
                JOptionPane.YES_NO_OPTION
        );

        if (confirmacao == JOptionPane.YES_OPTION) {
            JOptionPane.showMessageDialog(null, "Cadastro confirmado!");
            // Adicione o código para processar o cadastro confirmado aqui
        } else {
            JOptionPane.showMessageDialog(null, "Cadastro cancelado.");
            // Adicione o código para lidar com o cancelamento do cadastro aqui
        }
    }

    // Método auxiliar para obter entrada do usuário
    private static String obterEntrada(String mensagem) {
        return JOptionPane.showInputDialog(mensagem);
    }

    // Classe para representar os dados do usuário
    static class Usuario {
        private String nomeCompleto;
        private String email;
        private String endereco;

        public String getNomeCompleto() {
            return nomeCompleto;
        }

        public void setNomeCompleto(String nomeCompleto) {
            this.nomeCompleto = nomeCompleto;
        }

        public String getEmail() {
            return email;
        }

        public void setEmail(String email) {
            this.email = email;
        }

        public String getEndereco() {
            return endereco;
        }

        public void setEndereco(String endereco) {
            this.endereco = endereco;
        }
    }
}
