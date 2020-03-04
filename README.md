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
   
  # Exemplo completo:
    Automato que aceita palavras que começam apenas com ab sobre o alfabeto A = {a, b}.
    
    ~~~C++
    Automato automato1(4, std::vector<char>{'a', 'b'});
    automato1.criarTransicao(0, 1, 'a');
    automato1.criarTransicao(0, 3, 'b');
    automato1.criarTransicao(1, 3, 'a');
    automato1.criarTransicao(1, 2, 'b');
    automato1.criarTransicao(2, 2, 'a');
    automato1.criarTransicao(2, 2, 'b');
    automato1.criarTransicao(3, 3, 'a');
    automato1.criarTransicao(3, 3, 'b');
    automato1.definirEstadoFinal(2);
    const char *palavra = "abababababa";
    std::cout << "Testes sobre o Automato 1" << std::endl;
    std::cout << automato1.lerPalavra(palavra) << std::endl;
    palavra = "babababababababa";
    std::cout << automato1.lerPalavra(palavra) << std::endl;
    ~~~
