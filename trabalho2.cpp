#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
class Nodo
{
public:
    string data;
    string data2;
    Nodo *proximo;
};
void append(Nodo **head_ref, string new_data)
{
    // 1. aloca
    Nodo *new_Nodo = new Nodo();
    // usado no passo 5
    Nodo *last = *head_ref;
    // 2. preenche com dados
    new_Nodo->data = new_data;
    /* 3. o novo nodo será o último, então o proximo será NULL*/
    new_Nodo->proximo = NULL;
    /* 4. se a lista encadeada está vazia, faz o novo ser o início */
    if (*head_ref == NULL)
    {
        *head_ref = new_Nodo;
        return;
    }
    /* 5. ou percorra até o último nodo */
    while (last->proximo != NULL)
    {
        last = last->proximo;
    }
    /* 6. altera o proximo do últio nodo */
    last->proximo = new_Nodo;
    return;
}

// imprime o conteúdo da lista a partir do início recebido
void printList(Nodo *Nodo)
{
    while (Nodo != NULL)
    {
        cout << " " << Nodo->data;
        Nodo = Nodo->proximo;
    }
    cout << endl;
}

/*
Implemente aqui a funçao que identifica e remove palavras duplicadas
*/
void deletaNodo(Nodo *key) // pega um valor de ponteiro como chave
{

    Nodo *ptr;  //  ponteiro fixo
    Nodo *temp; // comparador
    Nodo *dup;  // valor duplicados
    ptr = key;  // ptr passa a ser "head", já que o ponteiro "key" recebe head como referência
    while (ptr != NULL && ptr->proximo != NULL)
    {
        temp = ptr;
        while (temp->proximo != NULL) // se houverem valores no nodo
        {
            if (ptr->data == temp->proximo->data) // se os valores comparados forem iguais
            {
                dup = temp->proximo;                    // dup recebe o valor duplicado
                temp->proximo = temp->proximo->proximo; // temp pula o valor duplicado
                delete (dup);                           // deleta o duplicado
            }
            else // não iguais
            {
                temp = temp->proximo; // temp pula para o proximo nodo e continua comparando
            }
        }
        //acabem os nodos para "temp->proximo"
        ptr = ptr->proximo; // fixo passa pro proximo nodo e começa outra comparação
    }
}
int main(int argc, char **argv)
{
    fstream arquivo;
    string palavra;
    if (argc < 2)
    {
        cout << "Faltou passar o arquivo como argumento!\n";
        return 1;
    }
    // arg 1 é um arquivo com as palavras a ser aberto
    arquivo.open(argv[1]);
    if (!arquivo.is_open())
    { // Se retornar algum erro:
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }
    Nodo *head = NULL;
    // extrai todas as palavras e adiciona a lista:
    while (arquivo >> palavra)
    {
        append(&head, palavra);
    }
    cout << "ENTRADA:" << endl;
    printList(head);
    /* Aqui é chamada a função que filtra os dados duplicados */
    cout << endl;
    cout << "RESULTADO REMOVENDO DUPLICADOS:" << endl;
    deletaNodo(head); // passa o valor alocado no "head"
    printList(head);
    return 0;
}