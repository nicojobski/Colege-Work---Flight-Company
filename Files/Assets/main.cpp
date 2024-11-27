#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// ************  --------------  CLASSES   --------------  ************//

class Padroes
{
protected:
    int codigo;
    string nome;
};

class PASSAGEIRO : protected Padroes
{
private:
    int telefone, pontosFidelidade;
    string endereco;
    bool fidelidade;

public:
    void setCodigoPassageiro(int codigoPassageiro) { codigo = codigoPassageiro; }
    int getCodigoPassageiro() const { return codigo; }

    void setTelefonePassageiro(int telefonePassageiro) { telefone = telefonePassageiro; }
    int getTelefonePassageiro() const { return telefone; }

    void setPontosFidelidadePassageiro(int pontosFidelidadePassageiro) { pontosFidelidade = pontosFidelidadePassageiro; }
    int getPontosFidelidadePassageiro() const { return pontosFidelidade; }

    void setNomePassageiro(string nomePassageiro) { nome = nomePassageiro; }
    string getNomePassageiro() const { return nome; }

    void setEnderecoPassageiro(string enderecoPassageiro) { endereco = enderecoPassageiro; }
    string getEnderecoPassageiro() const { return endereco; }

    void setFidelidadePassageiro(bool fidelidadePassageiro) { fidelidade = fidelidadePassageiro; }
    bool getFidelidadePassageiro() const { return fidelidade; }
};

class CARGO
{
public:
    int codigoPiloto, codigoCopiloto, codigoComissario;
    string nomePiloto, nomeCopiloto, nomeComissario;

    void setCodigoPiloto(int codigo)
    {
        if (codigo > 0)
        {
            codigoPiloto = codigo;
        }
        else
        {
            throw invalid_argument("O código tem que ser maior que 0");
        }
    }

    void setNomePiloto(const string nome) { nomePiloto = nome; }
    string getNomePiloto() const { return nomePiloto; }

    void setCodigoCopiloto(int codigo)
    {
        if (codigo > 0)
        {
            codigoCopiloto = codigo;
        }
        else
        {
            throw invalid_argument("O código tem que ser maior que 0");
        }
    }

    void setNomeCopiloto(const string nome) { nomeCopiloto = nome; }
    string getNomeCopiloto() const { return nomeCopiloto; }

    void setCodigoComissario(int codigo)
    {
        if (codigo > 0)
        {
            codigoComissario = codigo;
        }
        else
        {
            throw invalid_argument("O código tem que ser maior que 0");
        }
    }

    void setNomeComissario(string nome) { nomeComissario = nome; }
    string getNomeComissario() const { return nomeComissario; }
};

class TRIPULACAO : protected Padroes
{
private:
    int telefone;
    string nome;
    class CARGO cargo;

public:
    void setCodigo(int codigoTripulacao)
    {
        if (codigoTripulacao > 0)
        {
            codigo = codigoTripulacao;
        }
        else
        {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigo() const { return codigo; }

    void setTelefone(int telefoneTripulacao)
    {
        if (telefoneTripulacao > 0)
        {
            telefone = telefoneTripulacao;
        }
        else
        {
            throw invalid_argument("Digite um telefone maior que 0");
        }
    }

    int getTelefone() const { return telefone; }

    void setNomeTripulacao(string nomeTripulacao) { nome = nomeTripulacao; }
    string getNomeTripulacao() const { return nome; }

    CARGO getCargo() { return cargo; }
};

class DATA
{
private:
    int dia;
    int mes;
    int ano;

public:
    void setDia(int d)
    {
        if (d > 0 && d <= 31)
        {
            dia = d;
        }
        else
        {
            throw invalid_argument("Escolha uma data entre 1 a 31");
        }
    }

    int getDia() const { return dia; }

    void setMes(int m)
    {
        if (m > 0 && m <= 12)
        {
            mes = m;
        }
        else
        {
            throw invalid_argument("Escolha uma data entre 1 a 12");
        }
    }

    int getMes() const { return mes; }

    void setAno(int a)
    {
        if (a >= 2024 && a <= 2050)
        {
            ano = a;
        }
        else
        {
            throw invalid_argument("Escolha uma data entre 2024 a 2050");
        }
    }

    int getAno() const { return ano; }
};

class VOO : protected Padroes
{
public:
    int codigoVoo, codigoAviao;
    class DATA dataVoo;
    string origem, destino;
    class CARGO cargo;
    bool status;
    float tarifa;

public:
    void setCodigoVoo(int codigo)
    {
        if (codigo > 0)
        {
            codigoVoo = codigo;
        }
        else
        {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigoVoo() const { return codigoVoo; }

    void setCodigoAviao(int codigo)
    {
        if (codigo > 0)
        {
            codigoAviao = codigo;
        }
        else
        {
            throw invalid_argument("Digite um codigo maior que 0");
        }
    }

    int getCodigoAviao() const { return codigoAviao; }

    void setOrigem(string origem) { this->origem = origem; }
    string getOrigem() const { return origem; }

    void setDestino(string destino) { this->destino = destino; }
    string getDestino() const { return destino; }

    void setStatus(bool status) { this->status = status; }
    bool getStatus() const { return status; }

    void setTarifa(float tarifa)
    {
        if (tarifa >= 0)
        {
            this->tarifa = tarifa;
        }
        else
        {
            throw invalid_argument("Digite um valor que seja R$ 0");
        }
    }

    float getTarifa() const { return tarifa; }

    void setDataVoo(const DATA &data) { dataVoo = data; }
    DATA getDataVoo() const { return dataVoo; }

    CARGO &getCargo() { return cargo; }
};

class ASSENTO
{
public:
    int numeroAssento;
    class VOO voo;
    bool status;

    void setVoo(const VOO &voo) { this->voo = voo; }
    VOO getVoo() const { return voo; }

    void setNumeroAssento(int numAssento)
    {
        if (numAssento > 0)
        {
            numeroAssento = numAssento;
        }
        else
        {
            throw invalid_argument("Digite um numero maior que 0");
        }
    }

    int getNumeroAssento() const { return numeroAssento; }

    void setStatus(bool status) { this->status = status; }
    bool getStatus() const { return status; }
};

class RESERVA
{
public:
    class VOO voo;
    class ASSENTO assento;
    class PASSAGEIRO passageiro;

    void setVoo(const VOO &voo) { this->voo = voo; }
    VOO getVoo() const { return voo; }

    void setAssento(const ASSENTO &assento) { this->assento = assento; }
    ASSENTO getAssento() const { return assento; }

    void setPassageiro(const PASSAGEIRO &passageiro) { this->passageiro = passageiro; }
    PASSAGEIRO getPassageiro() const { return passageiro; }
};


// ************  --------------  FUNCOES   --------------  ************//

int CadastroPassageiro(class PASSAGEIRO &passageiro) {
    cout<<"---------- Cadastro de Passageiros Selecionado ----------\n"<<endl;
  
    return 0;
};

int CadastroTripulacao(class TRIPULACAO &tripulacao) {
  cout<<"---------- Cadastro de Tripulação Selecionado ----------\n"<<endl;
    return 0;
};

int CadastroVoo(class VOO &voo) {
  cout<<"---------- Cadastro de Voo Selecionado ----------\n"<<endl;
    return 0;
};

int CadastroAssento(class ASSENTO &assento) {
  cout<<"---------- Cadastro de Assento Selecionado ----------\n"<<endl;
    return 0;
};

int VerificarReserva(class RESERVA &reserva) {
  cout<<"---------- Verificação de Reservas Selecionado ----------\n"<<endl;
    return 0;
};

int BaixarReserva(class RESERVA &reserva) {
  cout<<"---------- Baixar Reservas Selecionado ----------\n"<<endl;
    return 0;
};

int PesquisarPessoa(class PASSAGEIRO &passageiro, class TRIPULACAO &tripulacao) {
  cout<<"---------- Pesquisa de Pessoa Selecionado ----------\n"<<endl;
    return 0;
};

int escolhaFuncao(int escolhaFuncao){

  PASSAGEIRO passageiro;
  TRIPULACAO tripulacao;
  VOO voo;
  ASSENTO assento;
  RESERVA reserva;

  switch(escolhaFuncao){

  case 1: CadastroPassageiro(passageiro); break;
  case 2: CadastroTripulacao(tripulacao); break;
  case 3: CadastroVoo(voo); break;
  case 4: CadastroAssento(assento); break;
  case 5: VerificarReserva(reserva); break;
  case 6: BaixarReserva(reserva); break;
  case 7: PesquisarPessoa(passageiro,tripulacao); break;
  case 0: cout << "Fechando o programa" << endl; return 0;
  default: cout <<"Opção invalida, escolha uma opção de 1 a 7"<<endl; return escolhaFuncao;

  }

  return 0;
};

// ************  --------------  MAIN   --------------  ************//

int main(){
    setlocale(LC_ALL, "portuguese");
    int escolha = 0;

  do {
      cout << "\nBem-vindo(a) ao Voe Tranquilo!\n"
           << "------------------------------------\n"
           << "O que você deseja?\n"
           << "1 - Cadastrar Passageiro\n"
           << "2 - Cadastrar Tripulação\n"
           << "3 - Cadastrar Voos\n"
           << "4 - Cadastrar Assento\n"
           << "5 - Verificar Reserva\n"
           << "6 - Baixar Reserva\n"
           << "7 - Pesquisa de Pessoa\n"
           << "0 - Encerrar o Programa\n" << endl;
      cout << "Escolha o que deseja: ";
      cin >> escolha;
  } while (escolhaFuncao(escolha) < 0);


    }
