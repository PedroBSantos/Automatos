# Autômatos

Implementação de autômato finito deterministico para a disciplina de linguagens formais e autômatos.

# Criando um autômato:
  Automato automato(quantidade de estados, alfabeto do autômato, é afnd?);
  ~~~C++
  Automato automato(4, std::vector<char>{'a', 'b'}, false);
  ~~~
  
  O estado inicial por padrão é o 0.
 
 # Adicionando transições:
  automato.criarTransicao(estado inicial da transicao, estado final da transicao, simbolo).
  
  Usando o autômato criado acima, podemos adicionar uma transição do estado 0 para o estado 1 ao recebermos 'a' em 0.
  ~~~C++
  automato.criarTransicao(0, 1, 'a');
  ~~~
  
  # Definindo o estado final do autômato:
  
      automato.definirEstadoFinal(estado).
    
      Antes de realizar a definição, é verificado se o valor passado como argumento esta dentro do 
      intervalo [0, quantidade de estados).
      
      ~~~C++
      automato.definirEstadoFinal(2);
      ~~~
