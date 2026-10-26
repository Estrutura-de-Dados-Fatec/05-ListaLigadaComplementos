#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

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

	// procura a posicao correta para manter a lista ordenada
	NO* atual = primeiro;
	NO* anterior = NULL;
	while (atual != NULL && atual->valor < novo->valor) {
		anterior = atual;
		atual = atual->prox;
	}

	// nao permite valores duplicados
	if (atual != NULL && atual->valor == novo->valor) {
		cout << "Elemento ja existe na lista \n";
		free(novo);
		return;
	}

	if (anterior == NULL)
	{
		// lista vazia ou novo elemento deve ser o primeiro
		primeiro = novo;
	}
	else
	{
		// insere no meio ou no fim
		anterior->prox = novo;
	}
	novo->prox = atual;
}

void excluirElemento()
{
	int numero;
	cout << "Digite o elemento a ser excluido: ";
	cin >> numero;

	NO* atual = primeiro;
	NO* anterior = NULL;
	while (atual != NULL && atual->valor < numero) {
		anterior = atual;
		atual = atual->prox;
	}

	// chegou ao fim da lista ou passou do ponto onde o numero deveria estar
	if (atual == NULL || atual->valor > numero) {
		cout << "ELEMENTO NAO ENCONTRADO \n";
		return;
	}

	if (anterior == NULL)
	{
		// o elemento e o primeiro
		primeiro = atual->prox;
	}
	else
	{
		// o elemento esta no meio ou no fim
		anterior->prox = atual->prox;
	}

	free(atual);
	cout << "Elemento excluido \n";
}

void buscarElemento()
{
	int numero;
	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;

	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero) {
			cout << "ENCONTRADO \n";
			return;
		}
		if (aux->valor > numero) {
			// ja passou do ponto onde o numero deveria estar
			cout << "ELEMENTO NAO ENCONTRADO \n";
			return;
		}
		aux = aux->prox;
	}

	// chegou ao fim da lista sem encontrar
	cout << "ELEMENTO NAO ENCONTRADO \n";
}
