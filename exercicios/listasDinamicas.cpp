#include <iostream>

using namespace std;

class Nodo
{
public:
    string data; // valor do nodo
    Nodo *nextD; // ponteiro que sempre aponta para o proximo link
};
void push(Nodo **head_ref, string new_data) //**head_ref é o ponteiro do ponteiro
{
    Nodo *new_Nodo = new Nodo();   // cria novo nodo
    new_Nodo->data = new_data;     // armazena o valor passado no main
    new_Nodo->nextD = (*head_ref); // passa o ponteiro pro proximo nodo
    (*head_ref) = new_Nodo;        // altera o ponteiro pra variavel do main (head)
}

void deletaNodo(Nodo **head_ref, string key)
{

    Nodo *temp = *head_ref; // cria ponteiro temporario para armazenar o ponteiro head
    Nodo *prec = NULL;      // predecessor aponta para o ultimo node

    if (temp != NULL && temp->data == key) // se temporario for não nulo e o valor guardado no temporario for igual a chave passada na função
    {

        *head_ref = temp->nextD; // altera o ponteiro pra variavel do main (head)
        cout << "Node deletado: ";
        cout << temp->data << endl; // ou (*temp).data;
        delete temp;                // exclui da memoria(free(temp) deleta so o ponteiro e delete deleta tudo que tiver dentro do ponteiro)
        return;
    }

    else
    {
        while (temp != NULL && temp->data != key) // ensquanto o temporario for nao nulo e o valor dentro do ponteiro temp for diferente da chave
        {
            prec = temp;        // ponteiro predecessor passa a ser o temporario
            temp = temp->nextD; // temporario passa a ser o proximo node
        }

        if (temp == NULL) // se o valor temporario for nulo (nao ha letras iguais)
        {
            cout << "Nenhum node deletado" << endl;
            return;
        }
        prec->nextD = temp->nextD; // predecessor passa apontar pro next node do temporario
        cout << "Node deletado: ";
        cout << temp->data << endl; // printa no console a data armazenada no temp
        delete temp;                // deleta temp
    }
}

void printList(Nodo *Nodo)
{
    while (Nodo != NULL) // enquanto houver nodes(letras)
    {
        cout << " -> " << Nodo->data; // printa a data do node
        Nodo = Nodo->nextD;           // pula pro proxino node
    }
    cout << endl;
}
string vogais(string b)
{
    int c = -1;
    char vogal[] = "aeiou";
    int contador = 0;
    string letra;
    for (int i = 0; i < b.length(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (vogal[j] == b[i] && contador == 0)
            {
                contador++;
            }
            else if (vogal[j] == b[i] && contador == 1)
            {
                c = i;
                contador++;
                letra = b[c];
                break;
            }
        }
        if (i != c)
        {
            cout << b[i];
        }
    }
    cout << endl;
    cout << "Vogal repetida: [" << b[c] << "] na posição " << endl;
    return letra;
}
int main()
{
    Nodo *head = NULL; // cria um ponteiro na classe nodo chamado head que aponta para NULL
    string name;
    cin >> name;
    cout << "Lista inicial: " << endl;
    for (int i = 0; i < name.length(); i++)
    {
        char letter[2]; // cria funçao com 2 valores, a letra e o byte null
        letter[0] = name[i];
        letter[1] = '\0';    // byte null \(toda string acaba com byte null)
        push(&head, letter); // chama a função push e da o ponteiro para a variavel head(&), alterando pelo valor passado(letter)
    }
    printList(head);                 // printa tudo começando pelo head
    deletaNodo(&head, vogais(name)); // chama a função push e da o ponteiro para a variavel head(&), alterando pelo valor passado(name)
    return 0;
}
// caso nao tenha o byte null, ele vai printar os valores de antes da letra: no caso o -> ro -> dro; quando devia ser o-> r (null) -> d (null)