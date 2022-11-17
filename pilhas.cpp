#include <iostream>

using namespace std;

// classe para nodo da pilha
class nodoPilha
{
public:
    int data;
    nodoPilha *proximo;
};

nodoPilha *novoNodo(int data)
{
    nodoPilha *nodo = new nodoPilha();
    nodo->data = data;
    nodo->proximo = NULL;
    return nodo;
}

int isEmpty(nodoPilha *base)
{
    return !base;
}
void push(nodoPilha **base, int novoItem)
{
    nodoPilha *nodo = novoNodo(novoItem);
    nodo->proximo = *base;
    *base = nodo;
    cout << novoItem << endl;
}
int pop(nodoPilha **base)
{
    if (isEmpty(*base))
        return -1;
    nodoPilha *temp = *base;
    *base = (*base)->proximo;
    int popped = temp->data;
    free(temp);

    return popped;
}
int peek(nodoPilha *base)
{
    if (isEmpty(base))
        return -1;
    return base->data;
}
int imprimePilha(nodoPilha *base)
{
    if (isEmpty(base))
    {
        return -1;
    }
    else
    {
        cout << "Os itens da pilha são: ";
        while (base != NULL)
        {
            cout << base->data << " ";
            base = base->proximo;
        }
    }
    cout << endl;
}

int esvaziaPilha(nodoPilha *base)
{
    while (!isEmpty(base))
    {
        pop(&base);
    }
    cout << "A pilha foi esvaziada :/" << endl;
}
int main()
{
    cout << "SELECIONE A OPÇÃO DESEJADA:" << endl
         << "digite 1 para ADICIONAR um item a pilha, " << endl
         << "digite 2 para REMOVER o item do topo da pilha, " << endl
         << "digite 3 para IMPRIMIR todos os itens da pilha, " << endl
         << "digite 4 para LIMPAR os itens da pilha, " << endl
         << "digite 5 para FINALIZAR o programa. " << endl;
    int selec = 0;
    nodoPilha *base = NULL;
    while (selec != 5)
    {
        cout << "escolha opcao" << endl;
        cin >> selec;
        switch (selec)
        {
        case 1:
        {
            cout << "digite valor a ser adicionado" << endl;
            int value = 0;
            cin >> value;
            cout << "adicionando: " << value << " a pilha" << endl;
            if (value <= 500 || value >= 1000)
            {
                push(&base, value);
            }
        }
        break;

        case 2:
        {
            cout << "Removendo item do topo da pilha" << endl;
            pop(&base);
        }
        break;

        case 3:
        {
            imprimePilha(base);
        }
        break;
        case 4:
        {
            esvaziaPilha(base);
        }
        break;
        case 5:
        {
        }
        break;
        default:
            cout << "insira valor válido" << endl;
            return selec = 5;
            break;
        }
    }
}