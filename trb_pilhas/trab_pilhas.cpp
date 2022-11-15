#include <iostream>

using namespace std;

// classe para nodo da pilha
class nodoPilha
{
public:
    string data;
    nodoPilha *proximo;
};

nodoPilha *novoNodo(string data)
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
void push(nodoPilha **base, string novoItem)
{
    nodoPilha *nodo = novoNodo(novoItem);
    nodo->proximo = *base;
    *base = nodo;
}
string pop(nodoPilha **base)
{
    if (isEmpty(*base))
        return NULL;
    nodoPilha *temp = *base;
    *base = (*base)->proximo;
    string popped = temp->data;
    free(temp);

    return popped;
}
string peek(nodoPilha *base)
{
    if (isEmpty(base))
        return NULL;
    return base->data;
}
int imprimePilha(nodoPilha* base)
{
    if (isEmpty(base)){
        return -1;
    }
    else {
        cout << "Os itens da pilha são: "<<endl ;
        while (base != NULL) {
            cout<< base->data << endl;
            base = base->proximo;
        }
    }
    cout << endl;
    return 0;
}

void esvaziaPilha(nodoPilha** base)
{
    while(!isEmpty(*base))
    {
        nodoPilha* temp = *base;
        *base = (*base)->proximo;
        free(temp);
    }
    cout << "A pilha foi esvaziada :/" << endl;
}
bool checker(string a)
{
    char url[] = "http";
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == url[i])
        {
            count++;
        }
    }
    if (count == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout << "SELECIONE A OPÇÃO DESEJADA:" << endl
         << "digite 1 para ADICIONAR uma URL ao registro " << endl
         << "digite 2 para REMOVER o último registro " << endl
         << "digite 3 para IMPRIMIR todas as URLs salvas " << endl
         << "digite 4 para EXCLUIR várias URLs registradas (defina a quantidade) " << endl
         << "digite 5 para FINALIZAR o programa. " << endl;
    int selec = 0;
    int NError = 0;
    nodoPilha *base = NULL;
    while (selec != 5)
    {
        cout << "-----------------------------" << endl;
        cout << "ESCOLHA UMA OPCAO" << endl;
        cin >> selec;
        switch (selec)
        {
        case 1:
        {
            cout << "digite uma URL a ser adicionada" << endl;
            string value;
            cin >> value;
            cout << "------------------------" << endl;
            if (checker(value) == true)
            {
                cout << "url adicionada!" << endl;
                push(&base, value);
                NError++;
            }
            else
            {
                cout << "insira uma url válida " << endl;
            }
        }
        break;

        case 2:
        {
            if (NError > 0)
            {
                cout << "Removendo item do topo da pilha" << endl;
                pop(&base);
            }
            else
            {
                cout << "nao ha nada para remover" << endl;
            }
        }
        break;

        case 3:
        {
            if (NError > 0)
            {
                if (!isEmpty(base))
                {
                    imprimePilha(base);
                }
            }
            else
            {
                cout << "pilha vazia" << endl;
            }
        }
        break;
        case 4:
        {
            cout << "Quantas urls serao removidas: " << endl;
            int remove = 0;
            cin >> remove;
            if (remove > NError)
            {
                esvaziaPilha(&base);
                NError = 0;
            }
            else
            {
                for (int i = 0; i < remove; i++)
                {
                    NError--;
                    pop(&base);
                }
                cout << "removido" << endl;
            }
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