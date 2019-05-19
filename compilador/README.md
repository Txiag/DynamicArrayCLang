# Trabalho de algoritmos

## _Array_ dinâmico de números inteiros

### Objetivo

Desenvolver e testar uma biblioteca que implemente um _array_ dinâmico de números
inteiros.

## Descrição do trabalho

Implementar e documentar um _array_ dinâmico de números inteiros em **C**.
Para a implementação do _array_ é definia a estrutura `struct array_list_int`,
que define os elementos para manter informações do _array_: espaço de memória,
tamanho do espaço de memória e quantidade usada.

```c
struct array_list_int{
  int *a;
  int size;
  int capacity;
  int magic;
};
```

_OBS: o campo `magic` é um marcador para identificar **arrays** válidos._

Para encapsular a representação interna esta estrutura é definida no arquivo de
implementação `array_list_int.c`. A exposição é feita através de um ponteiro
definido no arquivo de cabeçalho `array_list_int.h`.

```c
typedef struct array_list_int * array_list_int;
```

A manipulação do _array_ é feita através de um conjunto de funções. Toda função
recebe uma referência para um _array_ dinâmico.
As funções que deve ser implementadas são:

  - `array_list_int ali_create()`: Cria um novo _array_ e retorna um ponteiro para a estrutura que implementa o _array_.
  - `int ali_get(array_list_int ali, int index)`: Retorna o elemento armazenado
  no índice `index` do _array_ `ali`.
  - `unsigned int ali_push_back(array_list_int ali, int i)`: Acrescentar um elemento no final do _array_. (equivalente ao `append` da lista do **Python**).
  - `unsigned int ali_pop_back(array_list_int ali)`: Remove o último elemento
  do _array_ `ali`.
  - `unsigned int ali_size(array_list_int ali)`: Retorna a quantidade de elementos
  efetivamente armazenados no _array_ `ali`.
  - `int ali_find(array_list_int ali, int value)`:  Retorna o índice do elemento
  `value`.
  - `int ali_insert_at(array_list_int ali, int index, int value)`: Insere o elemento `value` no _array_ `ali`, deslocando para a direita os elementos a
  partir do índice `index`.
  - `int ali_remove_from(array_list_int ali, int index)`: Remove o elemento
  armazenado no índice `index`, movendo para a esquerda os elementos
  armazenados após `index`.
  - `unsigned int ali_capacity(array_list_int ali)`: Retorna a capacidade atual
  de armazenamento do _array_ `ali`.
  - `double ali_percent_occuped(array_list_int ali)`: Retorna o percentual de espaço ocupado pelo _array_ `ali`.
  - `void ali_destroy(array_list_int ali)`: Libera a memória usada pelo _array_
  `ali`

# Instruções

Antes de começar a implementar você deve entender a organização de arquivos
e o código já implementado.

1. Leia e entenda o conteúdo dos arquivos `array_list_int.h` e `array_list_int.c`.
1. Leia e entenda o arquivo de testes `test_01.c`. O comando para compilar é `gcc -O2 -o test01 test01.c array_list_int.c`
1. Desenvolva arquivos para testar o tipo `array_list_int`. Defina, para cada
arquivo de teste, o que deve ser testado.
1. Implemente e documente as funções que não estão implementadas.
1. Faça uma análise de desempenho de cada função implementada.
1. Realize testes de desempenho para comprovar a análise. Faça um teste para
cada função, gerando um gráfico com o valores de tamanho de entrada e tempo de execução.
O arquivo `teste_desempenho_exemplo.c` contém código exemplo de como medir
o tempo de execução em nanosegundos, usando **ANSI C**.
1. Os trechos de código não implementados estão marcados com `TODO`.

# Informações importante

O trabalho deve ser entregue dia **20 de maio de 2019**. Uma avaliação individual oral será marcada para verificação do aprendizado. O trabalho fazer parte
da nota do segundo bimestre e terá uma pontuação máxima de `100` com peso `15`,
valendo `15%` da nota do bimestre.

## Entrega

Relatório **impresso** detalhando o objetivo da biblioteca. Todas as funções
implementadas devem ser explicadas e uma análise do tempo de execução,
usando a notação _big-Oh_ feita.  O código completo deve ser colocado como
anexo do relatório.
