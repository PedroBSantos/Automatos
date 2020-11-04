# Autômatos

  Implementação de autômato finito deterministico para a disciplina de linguagens formais e autômatos.
  
  O método de conversão implementado apenas converte AFND's para AFD. Não é possivel converter AFND-E's para AFD.

# Criando um autômato:
  Automata automata(quantidade de estados, alfabeto do autômato, é afnd?);
  ~~~C++
  Automata automata(4, std::vector<char>{'a', 'b'}, false);
  ~~~
  
  O estado inicial por padrão é o 0.
 
 # Adicionando transições:
  automata.createTransiction(estado inicial da transicao, estado final da transicao, simbolo).
  
  Usando o autômato criado acima, podemos adicionar uma transição do estado 0 para o estado 1 ao recebermos 'a' em 0.
  ~~~C++
  automata.createTransiction(0, 1, 'a');
  ~~~
  
  # Definindo o estado final do autômato:
   automata.makeFinalState(estado).
    
   Antes de realizar a definição, é verificado se o valor passado como argumento esta dentro do 
   intervalo [0, quantidade de estados).
   ~~~C++ 
   Automata.makeFinalState(2);
   ~~~
   
  # Exemplo completo:
   Automata que aceita palavras que começam apenas com ab sobre o alfabeto A = {a, b}.
    
   ~~~C++
   Automata automata(4, std::vector<char>{'a', 'b'});
   automata.createTransiction(0, 1, 'a');
   automata.createTransiction(0, 3, 'b');
   automata.createTransiction(1, 3, 'a');
   automata.createTransiction(1, 2, 'b');
   automata.createTransiction(2, 2, 'a');
   automata.createTransiction(2, 2, 'b');
   automata.createTransiction(3, 3, 'a');
   automata.createTransiction(3, 3, 'b');
   automata.makeFinalState(2);
   const char *word = "abababababa";
   std::cout << "Testes sobre o Automato 1" << std::endl;
   std::cout << automata.readWord(word) << std::endl;
   palavra = "babababababababa";
   std::cout << automata.readWord(word) << std::endl;
   ~~~
