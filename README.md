# Guia de Atividade: Otimizando e Ordenando Listas Ligadas em C++

## Introdução: Elevando o Nível da Nossa Lista

Parabéns por ter implementado sua primeira lista ligada\! Você já domina a arte de conectar "notas adesivas" (nós) usando "setas" (ponteiros). Agora, vamos aprimorar nossa estrutura para torná-la mais eficiente e poderosa.

Na atividade anterior, para adicionar um novo item, precisávamos percorrer a lista inteira até encontrar o final. Imagine uma lista de compras com 100 itens; para adicionar o 101º, teríamos que passar por todos os 100 anteriores. Podemos fazer melhor\! Vamos adicionar um "atalho", um ponteiro que aponta sempre para a **última nota adesiva**, permitindo inserções instantâneas no final.

Depois, enfrentaremos um desafio ainda mais interessante: e se a lista precisasse estar sempre em ordem numérica? Ao invés de simplesmente colar a nova nota no final, teríamos que encontrar o lugar exato para encaixá-la, mantendo a sequência. Isso não só organiza os dados, mas também torna as buscas e exclusões mais inteligentes.

## Objetivos de Aprendizagem

Ao concluir esta atividade, você será capaz de:

  * **Otimizar a inserção** em uma lista ligada simples usando um ponteiro para o último elemento (`tail pointer`).
  * **Analisar o impacto no desempenho** de diferentes estratégias de implementação (complexidade O(n) vs. O(1)).
  * **Implementar uma lista ligada ordenada**, garantindo que os elementos sejam inseridos em sua posição correta.
  * **Adaptar os algoritmos de busca e exclusão** para se beneficiarem de uma estrutura ordenada, interrompendo a busca mais cedo.
  * **Gerenciar casos especiais** como inserção no início, no meio e no fim de uma lista ordenada.

-----

## Novos Conceitos Fundamentais

### 1\. Otimizando a Inserção: O Ponteiro `ultimo`

Atualmente, nossa função `inserirElemento` tem um laço `while` que percorre toda a lista para encontrar o último nó. Isso é chamado de uma operação de complexidade **O(n)**, pois o tempo de execução cresce linearmente com o número de elementos (`n`).

Para otimizar isso, vamos introduzir um novo ponteiro global:

```cpp
NO* ultimo = NULL;
```

Este ponteiro terá uma única responsabilidade: **sempre guardar o endereço do último nó da lista**.

**Como isso muda a lógica de inserção?**

1.  **Lista Vazia:** Se a lista está vazia (`primeiro == NULL`), o novo nó é tanto o primeiro quanto o último. Então, `primeiro` e `ultimo` devem apontar para ele.
2.  **Lista com Elementos:** Se a lista já tem nós, não precisamos mais percorrê-la\! A inserção se resume a dois passos simples:
      * Conectar o nó que *atualmente* é o último ao novo nó: `ultimo->prox = novo;`
      * Atualizar o ponteiro `ultimo` para que ele agora aponte para o novo nó, que é o novo final da lista: `ultimo = novo;`

Essa operação é de complexidade **O(1)**, ou "tempo constante", pois leva o mesmo tempo, não importa se a lista tem 10 ou 10 milhões de elementos.

> **Atenção:** Se um ponteiro `ultimo` existe, ele precisa ser gerenciado em **todas** as operações que modificam a lista. Ao inicializar a lista, ele deve ser `NULL`. Ao excluir o último elemento, ele precisa ser atualizado para apontar para o novo último elemento.

### 2\. A Lógica da Lista Ordenada

Manter uma lista ordenada muda completamente a forma como inserimos, buscamos e excluímos elementos.

#### Inserção Ordenada

Não podemos mais inserir no final. Precisamos encontrar a posição correta para o novo elemento. Para isso, geralmente usamos dois ponteiros auxiliares para percorrer a lista:

  * `NO* atual`: O nó que estamos inspecionando.
  * `NO* anterior`: O nó que veio imediatamente antes do `atual`.

Percorremos a lista até encontrar o ponto de inserção, que é quando `novo->valor` é menor que `atual->valor`. O `anterior` é crucial, pois é o ponteiro `prox` dele que precisará ser modificado para "encaixar" o novo nó.

**Casos a tratar na inserção ordenada:**

1.  A lista está vazia.
2.  O novo elemento é o menor de todos e deve ser inserido no início.
3.  O novo elemento deve ser inserido no meio da lista.
4.  O novo elemento é o maior de todos e deve ser inserido no final.

#### Busca e Exclusão Otimizadas

Em uma lista desordenada, para saber se um elemento **não existe**, precisamos ir até o final. Em uma lista ordenada, podemos parar mais cedo\!

Imagine buscar o número `25` na lista `[10, 20, 30, 40]`.

  * Você compara `25` com `10`. `25 > 10`, então continua.
  * Você compara `25` com `20`. `25 > 20`, então continua.
  * Você compara `25` com `30`. `25 < 30`. **Pronto\!** Se o `25` existisse, ele estaria antes do `30`. Como não estava, podemos afirmar que ele não está na lista sem precisar verificar o `40`.

Essa mesma lógica se aplica à exclusão.

-----

## Sua Missão: Atividade Proposta

Faça um *fork* do repositório original (ou continue no seu) e complete as tarefas abaixo, que são divididas em dois projetos.

### Parte 1: Projeto `ListaLigada` (Otimização)

Nesta parte, vamos modificar o código da primeira atividade (`ListaLigada.cpp`) para incluir o ponteiro `ultimo`.

#### Tarefa 1: Adicionar o Ponteiro `ultimo`

No escopo global, adicione o novo ponteiro e inicialize-o como nulo, junto com o `primeiro`.

```cpp
NO* primeiro = NULL;
NO* ultimo = NULL; // Adicionar esta linha
```

#### Tarefa 2: Atualizar a Função `inicializar`

Garanta que, ao limpar a lista, o ponteiro `ultimo` também seja resetado para `NULL`.

#### Tarefa 3: Implementar a Inserção Otimizada em `inserirElemento`

Reescreva a função `inserirElemento` para usar a lógica O(1).

1.  A lógica de alocação do `novo` nó permanece a mesma.
2.  Implemente a nova lógica de inserção:
      * **Se a lista está vazia (`primeiro == NULL`)**:
          * `primeiro` recebe `novo`.
          * `ultimo` também recebe `novo`.
      * **Caso contrário**:
          * `ultimo->prox` aponta para `novo`.
          * `ultimo` é atualizado para ser `novo`.

#### Tarefa 4 (Desafio): Atualizar `excluirElemento`

Modifique sua função de exclusão da atividade anterior. Pense no caso especial: o que acontece com o ponteiro `ultimo` se o usuário excluir o elemento que está no final da lista? Você precisará encontrar o **penúltimo** nó para que ele se torne o novo `ultimo`.

-----

### Parte 2: Projeto `ListaLigadaOrdenada`

Agora, vamos trabalhar no arquivo `ListaLigadaOrdenada.cpp`. O objetivo é implementar as operações para uma lista que se mantém sempre ordenada.

#### Tarefa 5: Implementar `inserirElemento` de Forma Ordenada

Esta é a mudança mais significativa. A função deve inserir um novo elemento mantendo a ordem crescente. Não permita valores duplicados.

**Roteiro Sugerido:**

1.  Aloque o `novo` nó e leia seu valor.
2.  Crie dois ponteiros auxiliares: `NO* atual = primeiro;` e `NO* anterior = NULL;`.
3.  Use um laço `while` para encontrar a posição correta. A condição deve ser `while (atual != NULL && atual->valor < novo->valor)`. Dentro do laço, avance os ponteiros: `anterior = atual;` e `atual = atual->prox;`.
4.  Após o laço, verifique se o elemento já existe (`if (atual != NULL && atual->valor == novo->valor)`). Se sim, informe o usuário e libere a memória do `novo` nó.
5.  **Caso contrário, realize a inserção:**
      * **Se `anterior == NULL`**: significa que a lista estava vazia ou o novo elemento deve ser o primeiro.
          * `primeiro = novo;`
      * **Senão (`anterior != NULL`)**: o elemento será inserido no meio ou no fim.
          * `anterior->prox = novo;`
      * Finalmente, conecte o resto da lista: `novo->prox = atual;`

#### Tarefa 6: Implementar `buscarElemento` com Otimização

1.  Peça ao usuário o número a ser buscado.
2.  Percorra a lista com um ponteiro `aux`.
3.  No laço, verifique duas condições:
      * Se `aux->valor == numero`, você encontrou. Exiba "ENCONTRADO" e saia da função.
      * Se `aux->valor > numero`, você já passou do ponto onde o número deveria estar. Exiba "ELEMENTO NAO ENCONTRADO" e saia da função.
4.  Se o laço terminar (chegar ao fim da lista), significa que o número não foi encontrado.

#### Tarefa 7: Implementar `excluirElemento` com Otimização

A lógica é muito similar à exclusão da lista desordenada, mas otimizada.

1.  Peça o número a ser excluído.
2.  Use a mesma lógica de travessia com `anterior` e `atual` da inserção ordenada para encontrar o elemento.
3.  **Otimização:** Se durante a busca `atual->valor` se tornar maior que o número procurado, você já sabe que o elemento não existe. Informe o usuário e encerre a função.
4.  Se encontrar o elemento, realize a exclusão tratando os dois casos clássicos:
      * **O elemento é o primeiro (`anterior == NULL`)**: `primeiro = atual->prox;`
      * **O elemento está no meio ou no fim**: `anterior->prox = atual->prox;`
5.  Não se esqueça de usar `free(atual)` para liberar a memória do nó excluído.

-----

## Sugestão de Roteiro de Testes

Teste seu código exaustivamente para garantir que todos os casos foram tratados.

**Para a Lista Ordenada:**

1.  **Lista Vazia**: Tente exibir, buscar e excluir em uma lista recém-inicializada.
2.  **Inserção Ordenada**:
      * Insira `20`. A lista deve ser `[20]`.
      * Insira `10`. A lista deve ser `[10, 20]`.
      * Insira `30`. A lista deve ser `[10, 20, 30]`.
      * Insira `25`. A lista deve ser `[10, 20, 25, 30]`.
      * Exiba a lista após cada inserção para confirmar a ordem.
3.  **Inserção Duplicada**: Tente inserir o valor `20` novamente. O programa deve impedir e informar o usuário.
4.  **Busca Otimizada**:
      * Busque por `25` (existente). Deve retornar "ENCONTRADO".
      * Busque por `15` (inexistente, mas no meio do intervalo). Deve retornar "ELEMENTO NAO ENCONTRADO".
      * Busque por `99` (inexistente, fora do intervalo). Deve retornar "ELEMENTO NAO ENCONTRADO".
5.  **Exclusão**:
      * Partindo da lista `[10, 20, 25, 30]`:
      * **Excluir o primeiro:** Exclua o `10`. Exiba a lista: `[20, 25, 30]`.
      * **Excluir o último:** Exclua o `30`. Exiba a lista: `[20, 25]`.
      * **Excluir do meio:** Exclua o `25`. Exiba a lista: `[20]`.
      * Tente excluir um elemento inexistente como `15`. Deve informar que não foi encontrado.

## Checklist de Entrega

Antes de submeter sua atividade, verifique se você completou todos os itens abaixo.

  * **[ ]** **Projeto `ListaLigada`:**
      * **[ ]** A inserção foi otimizada com o ponteiro `ultimo` e funciona corretamente.
      * **[ ]** A exclusão foi adaptada para atualizar o ponteiro `ultimo` quando necessário.
  * **[ ]** **Projeto `ListaLigadaOrdenada`:**
      * **[ ]** A função `inserirElemento` insere os nós em ordem crescente e não permite duplicatas.
      * **[ ]** A função `buscarElemento` foi implementada com a otimização de parada antecipada.
      * **[ ]** A função `excluirElemento` trata corretamente a exclusão no início, meio e fim, e também é otimizada.
  * **[ ]** O código compila sem erros e foi testado seguindo o roteiro de testes.
  * **[ ]** O código está salvo no seu repositório Git pessoal.

**Como entregar:**
Copie o link do seu repositório e cole-o na tarefa correspondente no Microsoft Teams para avaliação.

## Recursos Adicionais e Referências

(Os mesmos recursos da atividade anterior continuam sendo extremamente úteis\!)

  * **[Artigo] GeeksforGeeks - Linked List Data Structure**: Um dos melhores recursos online, com explicações detalhadas e exemplos de código para todas as operações.
      * [https://www.geeksforgeeks.org/data-structures/linked-list/](https://www.geeksforgeeks.org/data-structures/linked-list/)
  * **[Vídeo] Lista Encadeada - Estrutura de Dados (YouTube)**: Para quem prefere um aprendizado visual, este vídeo do canal "Programação Descomplicada" explica o conceito de forma clara (em português).
      * [https://www.youtube.com/watch?v=S5ZU8fErv\_E](https://www.youtube.com/watch?v=biTMaMxWLRc)
  * **[Documentação] cplusplus.com - Pointers**: Para revisar a sintaxe e o conceito de ponteiros em C++.
      * [https://cplusplus.com/doc/tutorial/pointers/](https://cplusplus.com/doc/tutorial/pointers/)
