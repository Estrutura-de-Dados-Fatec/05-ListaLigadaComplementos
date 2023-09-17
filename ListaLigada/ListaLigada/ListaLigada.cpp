 #include <iostream>
 #include <cstdio>
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
                 system("clear"); // somente no windows 
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
  
                 getchar(); // somente no windows 
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
         cout<<"\nPressione ENTER para continuar";
         getchar();
  
 } 
  
 void exibirQuantidadeElementos() { 
  
         int nElementos = 0; 
         NO* aux = primeiro; 
         while (aux != NULL) { 
                 nElementos++; 
                 aux = aux->prox; 
         } 
         cout << "Quantidade de elementos: " << nElementos << endl;
         cout<<"\nPressione ENTER para continuar";
         getchar();
  
 } 
  
 void exibirElementos() 
 { 
         if (primeiro == NULL) { 
                 cout << "Lista vazia \n";
                 getchar();
                 return; 
         } 
         else { 
                 cout << "Elementos: \n"; 
                 NO* aux = primeiro; 
                 while (aux != NULL) { 
                         cout << aux->valor << endl; 
                         aux = aux->prox; 
                 }
                 cout<<"\nPressione ENTER para continuar";
                 getchar();
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
                 ultimo = primeiro;
         } 
         else 
         { 
                 // procura o final da lista
                 NO* atual = primeiro;
                 while(atual!=NULL){
                     if(novo->valor<atual->valor){
                         novo->prox = atual;
                         primeiro=novo;
                         break;
                     }
                     else{
                         if(atual->prox==NULL||novo->valor<atual->prox->valor){
                             novo->prox=atual->prox;
                             atual->prox=novo;
                             break;
                         }
                         atual = atual->prox;
                     }
                 }
         }
         cout<<"\nValor Inserido\n";
         cout<<"\nPressione ENTER para continuar";
         getchar();
 } 
  
 void excluirElemento() 
 { 
  
 } 
  
 void buscarElemento() 
 { 
  
 }