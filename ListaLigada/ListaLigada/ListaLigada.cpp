#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		ultimo->prox = novo;
		ultimo = novo;
	}
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}

	int numero;
	cout << "Digite o elemento a ser excluido: ";
	cin >> numero;

	// procura o no, guardando o anterior
	NO* anterior = NULL;
	NO* atual = primeiro;
	while (atual != NULL && atual->valor != numero) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL) {
		cout << "Elemento nao encontrado \n";
		return;
	}

	if (atual == primeiro) {
		primeiro = atual->prox;
		if (atual == ultimo) {
			// era o unico elemento
			ultimo = NULL;
		}
	}
	else {
		anterior->prox = atual->prox;
		if (atual == ultimo) {
			// o penultimo passa a ser o ultimo
			ultimo = anterior;
		}
	}

	free(atual);
	cout << "Elemento excluido \n";
}

void buscarElemento()
{
	int numero;
	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;

	NO* pos = posicaoElemento(numero);
	if (pos == NULL) {
		cout << "Elemento nao encontrado \n";
	}
	else {
		cout << "Elemento encontrado: " << pos->valor << endl;
	}
}

// retorna o ponteiro para o no que contem o valor, ou NULL se nao existir
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero) {
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}
