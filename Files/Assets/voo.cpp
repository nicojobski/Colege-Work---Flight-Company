#include <iostream>
#include <fstream>
#include <string>

class Voo {
private:
    std::string codigoVoo, data, hora, origem, destino, codigoAviao, codigoPiloto, codigoCopiloto, codigoComissario;
    bool status;  // true = ativo, false = inativo
    double tarifa;

public:
    void criarInformacoes(const std::string& nomeArquivo) {
        std::cout << "Digite o código do voo: ";
        std::cin >> codigoVoo;

        std::cout << "Digite a data (DD-MM-AAAA): ";
        std::cin >> data;

        std::cout << "Digite a hora (HH:MM): ";
        std::cin >> hora;

        std::cout << "Digite a origem: ";
        std::cin >> origem;

        std::cout << "Digite o destino: ";
        std::cin >> destino;

        std::cout << "Digite o código do avião: ";
        std::cin >> codigoAviao;

        std::cout << "Digite o código do piloto (digite 0 se não houver piloto): ";
        std::cin >> codigoPiloto;

        if (codigoPiloto == "0") {
            codigoPiloto.clear();  // Se o código do piloto for 0, considera que não há piloto
        }

        std::cout << "Digite o código do copiloto (digite 0 se não houver copiloto): ";
        std::cin >> codigoCopiloto;

        if (codigoCopiloto == "0") {
            codigoCopiloto.clear();  // Se o código do copiloto for 0, considera que não há copiloto
        }

        std::cout << "Digite o código do comissário: ";
        std::cin >> codigoComissario;

        status = (!codigoPiloto.empty() && !codigoCopiloto.empty());

        std::cout << "Status do voo definido como: " << (status ? "Ativo" : "Inativo") << std::endl;

        std::cout << "Digite a tarifa: ";
        std::cin >> tarifa;

        cadastrarVoo(nomeArquivo);
    }

    // Método para cadastrar voo em um arquivo
    void cadastrarVoo(const std::string& nomeArquivo) {
        std::ifstream arquivoVerificar(nomeArquivo);
        bool arquivoExiste = arquivoVerificar.is_open();
        arquivoVerificar.close();

        std::ofstream arquivo(nomeArquivo, std::ios::app); /* flags, escrever ao final do arquivo sem sobrescrever */
        if (arquivo.is_open()) {
            if (!arquivoExiste) {
                arquivo << "Código do Voo,Data,Hora,Origem,Destino,Código do Avião,Código do Piloto,"
                        << "Código do Copiloto,Código do Comissário,Status, Tarifa\n";
            }
            arquivo << codigoVoo << "," << data << "," << hora << "," << origem << "," << destino << ","
                    << codigoAviao << "," << (codigoPiloto.empty() ? "Nenhum" : codigoPiloto) << ","
                    << (codigoCopiloto.empty() ? "Nenhum" : codigoCopiloto) << "," << codigoComissario << ","
                    << (status ? "Ativo" : "Inativo") << "," << tarifa << "\n";
            std::cout << "Voo cadastrado com sucesso no arquivo.\n";

            /* se o copiloto ou piloto estiverem vazios, escreve nenhum */
            /* status ? true : false */
        } else {
            std::cerr << "Erro ao abrir o arquivo para cadastro.\n";
        }
    }

    // Método criado para verificar se estava funcionando
    void abrirArquivo(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            std::string linha;
            std::cout << "Voos cadastrados no arquivo:\n";
            while (std::getline(arquivo, linha)) {
                std::cout << linha << std::endl;
            }
            arquivo.close();
        } else {
            std::cerr << "Erro ao abrir o arquivo para leitura.\n";
        }
    }
};

void exibirMenu() {
    int opcao;
    Voo voo;
    std::string nomeArquivo = "voos.txt";  // Nome do arquivo onde os voos serão cadastrados

    do {
        std::cout << "\nMenu de Opções:\n";
        std::cout << "1. Cadastrar Passageiro\n\n";
        std::cout << "2. Cadastrar Tripulação\n";
        std::cout << "3. Cadastrar Voo\n";
        std::cout << "4. Exibir Voos Cadastrados\n";
        std::cout << "5. Cadastrar Assento\n";
        std::cout << "6. Cadastrar Reserva\n";
        std::cout << "7. Baixa em Reservas\n";
        std::cout << "8. Pesquisa\n";
        std::cout << "9. Consultar Programa de Fidelidade\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Cadastrar Passageiro - em construção\n";
                voo.criarInformacoes(nomeArquivo);
                break;
            case 2:
                std::cout << "Cadastrar Tripulação - em construção\n";
                voo.abrirArquivo(nomeArquivo);
                break;
            case 3:
                voo.criarInformacoes(nomeArquivo);
                break;
            case 4:
                voo.abrirArquivo(nomeArquivo);
                break;
            case 5:
                std::cout << "Cadastrar Assento - em construção\n";
                break;
            case 6:
                std::cout << "Cadastrar Reserva - em construção\n";
                break;
            case 7:
                std::cout << "Baixa em Reservas - em construção\n";
                break;
            case 8:
                std::cout << "Pesquisa - em construção\n";
                break;
            case 9:
                std::cout << "Consultar Programa de Fidelidade - em construção\n";
                break;
            case 0:
                std::cout << "Saindo... Até logo!\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 0);
}

int main() {
    exibirMenu();
    return 0;
}
