#include <iostream>
#include <queue>

using namespace std;

// mostrar o conteúdo da fila
void display_queue(queue<string> q)
{
  while (!q.empty())
  {
    cout << q.front() << " - ";
    q.pop();
  }
  cout << endl;
}
int main()
{
  // cria uma fila do tipo string
  queue<string> clients;

  int escolha = 0;
  while (escolha != 6)
  {
    cout << "SELECIONE A OPÇÃO DESEJADA:" << endl
         << "digite 1 para ADICIONAR um novo cliente no final da fila" << endl
         << "digite 2 para REMOVER o cliente do início da fila (lugar disponivel) " << endl
         << "digite 3 para IMPRIMIR imprimir todos os clientes que estão na fila aguardando " << endl
         << "digite 4 para IMPRIMIR quantos clientes estão na fila aguardando " << endl
         << "digite 5 para EXCLUIR todos os clientes da fila " << endl
         << "digite 6 para FECHAR o programa." << endl;
    cin >> escolha;
    switch (escolha)
    {
    case 1:
    {
      cout << "digite o nome do cliente" << endl;
      string client;
      cin >> client;
      // Adicionando itens na fila
      clients.push(client);
    }
    break;
    case 2:
    {
      // Removendo itens na fila
      if (clients.empty())
      {
        cout << "lista vazia" << endl;
      }
      else
      {
        clients.pop();
        cout << "cliente removido" << endl;
      }
    }
    break;
    case 3:
    {
      if (clients.empty())
      {
        cout << "lista vazia" << endl;
      }
      else
      {
        display_queue(clients);
      }
    }
    break;
    case 4:
    {
      // Obtendo o tamanho da fila
      int size = clients.size();
      cout << "Tamanho da fila: " << size << endl;
    }
    break;

    case 5:
    {
      if (clients.empty())
      {
        cout << "lista vazia" << endl;
      }
      else
      {
        while (!clients.empty())
        {
          // Removendo itens na fila
          clients.pop();
        }
        cout << "todos os clientes da fila foram removidos" << endl;
      }
    }
    break;
    default:
    {
      cout << "Closed Program!" << endl;
      escolha = 6;
    }
    break;
    }
  }
}