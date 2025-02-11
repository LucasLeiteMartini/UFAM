#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Função para remover aspas e ignorar o resto se encontrar ";"
std::string remover_aspas_input(const std::string& entrada) {
    std::string resultado;

    for (size_t i = 0; i < entrada.length(); ++i) {
        if (entrada[i] == '"' && i + 1 < entrada.length() && entrada[i + 1] == ';') {
            break; // Para se encontrar aspas seguidas de ponto e vírgula
        }
        resultado += entrada[i];
    }

    return resultado;
}

// Função para remover aspas em um stream de entrada
void remover_aspas(std::istream& stream, std::string& resultado) {
    resultado.clear();
    char ch;

    while (stream.get(ch)) {
        if (ch == '"' && stream.peek() == ';') {
            stream.get(); // Consome o próximo caractere (;) e sai do loop
            break;
        }
        resultado += ch;
    }
}

// Função para normalizar uma string (remove caracteres inválidos, múltiplos espaços)
std::string normalizar_string(std::string str) {
    // Substitui caracteres não ASCII, novas linhas e aspas por espaços
    for (char &c : str) {
        if (static_cast<unsigned char>(c) > 127 || c == '\n' || c == '\"') {
            c = ' ';
        }
    }

    // Remove espaços extras
    std::string resultado;
    bool inSpace = false;

    for (char c : str) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (!inSpace) {
                resultado += ' ';
                inSpace = true;
            }
        } else {
            resultado += c;
            inSpace = false;
        }
    }

    // Remove espaços no início e fim
    size_t start = resultado.find_first_not_of(' ');
    if (start == std::string::npos) return ""; // String apenas contém espaços

    size_t end = resultado.find_last_not_of(' ');
    return resultado.substr(start, end - start + 1);
}

void ler_arquivo_csv(const string& nome_arquivo)
{
    ifstream arquivo(nome_arquivo, ios::in);
    
    if (!arquivo.is_open())
    {
        cerr << "Nao foi possivel abrir o arquivo: " << nome_arquivo << "\n";
        return;
    }

    string linha;
    while (getline(arquivo, linha))
    {
        stringstream linha_analisada(linha);
        string dado;

        int id, year, citations;
        string title, authors, update, snippet;

        try
        {
            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            id = stoi(dado);

            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            title = dado;

            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            year = stoi(dado);

            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            authors = dado;

            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            citations = stoi(dado);

            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            update = dado;

            getline(linha_analisada, dado, '"');
            remover_aspas(linha_analisada, dado);
            snippet = dado;

            title = normalizar_string(title);
            authors = normalizar_string(authors);
            update = normalizar_string(update);
            snippet = normalizar_string(snippet);

            cout << id << endl;
          /*   Registro* novo_registro = criar_registro(id, title, year, authors, citations, update, snippet);
            size_t posicao = hash.inserir_registro_bucket(novo_registro);

            RegistroBPT* reg1 = new RegistroBPT(id, posicao);
            RegistroString* reg2 = new RegistroString(title, posicao);

            arvore1.inserir_arvore(reg1);
            arvore2.inserir_arvore_s(reg2);
            
            delete novo_registro; */
        } 
        catch (const std::exception& e)
        {
            //std::cerr << "Caught an exception: " << e.what() << " " << id << std::endl;
        }
    }
    arquivo.close();

    return;
}



int main() {
    ler_arquivo_csv("sample_parse.csv");

    return 0;
}