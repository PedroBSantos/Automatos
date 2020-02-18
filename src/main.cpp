#include <iostream>
#include "estado.cpp"
#include "transicao.cpp"
#include "automato.cpp"

int main(int argc, char const *argv[])
{
    //Autômato que aceita palavras que começam apenas com ab sobre o alfabeto A = {a, b}.
    Automato automato1(4);
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
    std::cout << "Testes sobre o autômato 1" << std::endl;
    std::cout << automato1.lerPalavra(palavra) << std::endl;
    palavra = "babababababababa";
    std::cout << automato1.lerPalavra(palavra) << std::endl;

    //Autômato que aceita palavras que terminam com 011 sobre o alfabeto A = {0, 1}.
    Automato automato2(4);
    automato2.criarTransicao(0, 0, '1');
    automato2.criarTransicao(0, 1, '0');
    automato2.criarTransicao(1, 1, '0');
    automato2.criarTransicao(1, 2, '1');
    automato2.criarTransicao(2, 1, '0');
    automato2.criarTransicao(2, 3, '1');
    automato2.criarTransicao(3, 0, '0');
    automato2.criarTransicao(3, 0, '1');
    automato2.definirEstadoFinal(3);
    palavra = "011";
    std::cout << "\nTestes sobre o autômato 2" << std::endl;
    std::cout << automato2.lerPalavra(palavra) << std::endl;
    palavra = "010101010101";
    std::cout << automato2.lerPalavra(palavra) << std::endl;
    palavra = "01111111111111111111111";
    std::cout << automato2.lerPalavra(palavra) << std::endl;

    //Autômato que aceita palavras com substring aa sobre o alfabeto A = {a, b}.
    Automato automato3(3);
    automato3.criarTransicao(0, 0, 'b');
    automato3.criarTransicao(0, 1, 'a');
    automato3.criarTransicao(1, 0, 'b');
    automato3.criarTransicao(1, 2, 'a');
    automato3.criarTransicao(2, 2, 'a');
    automato3.criarTransicao(2, 2, 'b');
    automato3.definirEstadoFinal(2);
    std::cout << "\nTestes sobre o autômato 3" << std::endl;
    palavra = "aaaaaaaaaaaaaaaa";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    palavra = "babababababababab";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    palavra = "aabbbbbbbbbbb";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    palavra = "bbbbbbbbbbaabbabababab";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    system("pause");
    return 0;
}
