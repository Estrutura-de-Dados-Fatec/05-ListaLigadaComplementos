#include <iostream>       
  #include <cmath>           
  #include <cstdio>             
  using namespace std;             
  
  // definição de tipo             
  struct NO {             
     int value;             
     NO* prox;             
  };             
  
  NO* first = NULL;             
  NO* MidList = NULL;          
  int qtde = 0;          
  int Soma = 0;          
  float Media;        
  int MediaInt;        
  
  // headers             
  void menu();             
  void start();             
  void showQtdeElements();             
  void showElements();             
  void insertElement();             
  void deleteElement();             
  void searchElement();     
  void eraser(NO* ValorInicial,int NumExc, bool Tanomeio);     
  void showData();  
  void search(int Num,NO* Inicio,NO* Fim);  
  NO* position(int numero);             
             //--------------------------             
  
  
  int main(){             
    menu();             
  }             
  
  void menu(){             
     int op = 0;             
     while (op != 7) {             
        system("clear"); // windows only           
        cout << "Menu Lista Ligada";             
        cout << endl << endl;             
        cout << "1 - Start List \n";             
        cout << "2 - Show Qtde Elements \n";             
        cout << "3 - show Elements\n";             
        cout << "4 - search Element \n";             
        cout << "5 - insert Element \n";             
        cout << "6 - delete Element \n";             
        cout << "7 - Quit \n\n";             
  
        cout << "Option: ";             
        cin >> op;             
  
        switch (op){             
           case 1: start();             
                   break;             
           case 2: showQtdeElements();             
                   break;             
           case 3: showElements();             
                   break;             
           case 4: searchElement();             
                   break;             
           case 5: insertElement();             
                   break;             
           case 6: deleteElement();             
                   break;             
           case 7: return;       
           case 8: showData();       
                   break;       
           default: break;             
        }             
        getchar();             
     }             
  }             
  
  
  void start(){             
     // libera memória ocupada se ja tiver dados           
     NO* aux = first;             
     while (aux != NULL) {             
        NO* toDelete = aux;             
        aux = aux->prox;             
        free(toDelete);             
     }             
  
     first = NULL;     
     qtde = 0;    
     cout << "Lista inicializada \n";             
     cout << "\nPressione ENTER para continuar\n";             
     getchar();             
  
  }             
  
  void showQtdeElements() {             
  
     int nElements = 0;             
     NO* aux = first;             
     while (aux != NULL) {             
        nElements++;             
        aux = aux->prox;             
     }             
     cout << "Qtde de elementos: " << nElements << endl;     
     cout << "\nPressione ENTER p/ continuar\n";             
     getchar();     
  
  }             
  
  void showElements(){             
     if(first == NULL) {             
        cout << "Lista vazia \n";             
        cout << "\nPressione ENTER p/ continuar\n";             
        getchar();             
        return;             
     }             
     else {             
        cout << "Elementos: \n";             
        NO* aux = first;             
        while (aux != NULL){             
           cout << aux->value << endl;             
           aux = aux->prox;             
        }             
        cout << "\nPressione ENTER para continuar\n";             
        getchar();             
     }             
  }             
  
 void insertElement(){ 
    int ValNum;             
    cout << "Digite o elemento: ";             
    cin >> ValNum;             
    bool Inseriu=false;             
    // aloca memoria dinamicamente pro novo elemento             
    if(position(ValNum)==NULL){             
  
       NO* novo = (NO*)malloc(sizeof(NO));             
       bool FirstTime=true;             
       if (novo == NULL){             
           return;             
       }             
       novo->value=ValNum;             
       novo->prox = NULL;             
       NO* ActualValue;             
       NO* Previous;
       NO* Final;
       if(qtde>=5){
           if(novo->value<MidList->value){
               ActualValue=MidList;
               Final=NULL;
           }
           else{
               ActualValue=first;
               Final=MidList->prox;
           }
       }
       else{
           ActualValue=first;
           Final=NULL;
       }
       
       if(first==NULL){          
           first=novo;
       }          
        else{          
           while(ActualValue!=Final){          
              if(first){          
                 if(novo->value>ActualValue->value){          
                    novo->prox=ActualValue;          
                    first=novo;          
                    Inseriu=true;          
                 }          
                 else{          
                    if(ActualValue->prox==Final){          
                       ActualValue->prox=novo;          
                       Inseriu=true;          
                    }          
                    Previous=ActualValue;          
                 }          
                 FirstTime=false;          
              }          
              else{          
                 if(novo->value>ActualValue->value){          
                    Previous->prox=novo;          
                    novo->prox=ActualValue;          
                    Inseriu=true;          
                 }          
                 else{          
                    if(ActualValue->prox==Final){          
                       ActualValue->prox=novo;          
                       Inseriu=true;          
                    }          
                 }          
              }          
              if(Inseriu){          
                 break;          
              }          
              ActualValue=ActualValue->prox;          
           }          
        }          
        cout <<"Valor inserido \n";           
        qtde++; 
        MediaInt = (qtde - (qtde % 2))/2; 
        ActualValue=first; 
        for(int i=0;i<qtde+1;i++){    
           if(i==MediaInt){    
              MidList=ActualValue; 
              break; 
           }    
           else{    
              ActualValue=ActualValue->prox;    
           }    
        } 
        cout << "\nPressione ENTER p/ continuar\n";             
        getchar();             
     }             
     else{             
        cout << "Esse valor já está na lista";             
        cout << "\nPressione ENTER p/ continuar\n";             
        getchar();             
     }             
  
 }         
  
             void deleteElement(){         
                 int NumExc;       
                 NO* ActualValue=first;       
                 NO* Previous=first;       
                 if(qtde<=0){         
                     cout<<"Lista Vazia.";         
                     getchar();         
                 }         
                 else{         
                     cout<<"Digite o numero a ser excluido:\n";         
                     cin >> NumExc;         
                     if(qtde>=3&&MidList!=NULL){        
                         if(NumExc<MidList->value){       
                             cout<<"contando a partir do meio da lista"<<endl;       
                             eraser(MidList,NumExc,true);       
                         }        
                         else{       
                             cout<<"contando do comeco da lista";       
                             eraser(first,NumExc,false);        
                         }        
                     }         
                     else{         
                         eraser(first,NumExc,false);         
                     }       
                     MediaInt = (qtde - (qtde % 2))/2; 
                     ActualValue=first;  
                     for(int i=0;i<qtde+1;i++){    
                         if(i==MediaInt){    
                             MidList=ActualValue; 
                             break; 
                         }    
                         else{    
                             ActualValue=ActualValue->prox;    
                         }    
                     }     
                 }         
             }         
  
  
  
             void searchElement(){  
                 int NumSearch;  
                 if(qtde<=0){  
                     cout<<"Lista Vazia. \n";  
                     getchar();  
                 }  
                 else{  
                     cout<<"Digite o valor: \n";  
                     cin>>NumSearch;  
                     if(qtde>=5){  
                         if(NumSearch<MidList->value){  
                              search(NumSearch,MidList,NULL);  
                         }  
                         else{  
                              search(NumSearch,first,MidList);  
                         }  
                     }  
                     else{  
                         search(NumSearch,first,NULL);  
                     }  
                 }  
             }       
  
             void showData(){       
                 cout<<"MediaInt: "<<MediaInt<<endl;       
                 cout<<"quant: "<<qtde<<endl;       
                 if(MidList==NULL){       
                     cout<<"a variavel esta nula";       
                 }       
                 else{       
                     cout<<"MeioDaLista: "<<MidList->value;   
  
                 }       
                 getchar();       
             }       
  
             NO* position(int number)  {               
                       NO* aux = first; //mudar valor de aux para o argumento               
                       while (aux != NULL) {               
                               if (aux->value == number)               
                               {               
                                       break;               
                               }               
                               aux = aux->prox;               
                       }               
                       return aux;               
             }  
  
             void search(int Num,NO* Start,NO* End){  
                 while(Start!=End){  
                     if(Start->value==Num){  
                         cout<<"\nValor encontrado\n";  
                         break;  
                     }  
                     else{  
                         if(Start->prox==End){  
                             cout<<"\nValor nao encontrado\n";  
                             break;  
                         }  
                     }  
                     Start=Start->prox;  
                 }  
                 getchar();  
             }  
  
             void eraser(NO* InitialValue,int  NumExc, bool Mid){         
                 NO* ActualValue;         
                 NO* Previous;     
                 if(Mid){     
                     ActualValue=InitialValue->prox;     
                     Previous=InitialValue;     
                 }     
                 else{     
                     ActualValue=InitialValue;     
                 }     
                 bool FirstTime= true;         
                 bool erased = false;         
                 while(ActualValue!=NULL){         
                     if(FirstTime){         
                         if(ActualValue->value==NumExc){     
                             if(Mid==false){     
                                 first=ActualValue->prox;     
                             }     
                             else{     
                                 Previous->prox=ActualValue->prox;     
                             }     
                             cout<<"\nValor apagado\n";         
                             qtde--;         
                             Soma = Soma - ActualValue->value;         
                             free(ActualValue);         
                             erased= true;         
                         }         
                         else{         
                             if(ActualValue->prox==NULL){         
                                 cout<<"\nValor não encontrado\n";         
                             }         
                             Previous=ActualValue;         
                         }         
                         FirstTime=false;         
                     }         
                     else{         
                         if(ActualValue->value==NumExc){         
                             Previous->prox=ActualValue->prox;         
                             cout<<"\nValor excluido\n";         
                             qtde--;         
                             Soma = Soma - ActualValue->value;         
                             free(ActualValue);         
                             erased=true;         
                         }         
                         else{         
                             Previous=ActualValue;         
                             if(ActualValue->prox==NULL){         
                                 cout<<"\nValor não encontrado\n";         
                             }         
                         }         
                     }         
                     if(erased){         
                         break;         
                     }         
                     ActualValue=ActualValue->prox;         
                 }         
                 getchar();         
             }
