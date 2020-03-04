#include <iostream>
#include "estado.cpp"
#include "transicao.cpp"
#include "automato.cpp"

int main(int argc, char const *argv[])
{
    //Automato que aceita palavras que começam apenas com ab sobre o alfabeto A = {a, b}.
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

    //Automato que aceita palavras que terminam com 011 sobre o alfabeto A = {0, 1}.
    Automato automato2(4, std::vector<char>{'0', '1'});
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
    std::cout << "\nTestes sobre o Automato 2" << std::endl;
    std::cout << automato2.lerPalavra(palavra) << std::endl;
    palavra = "010101010101";
    std::cout << automato2.lerPalavra(palavra) << std::endl;
    palavra = "01111111111111111111111";
    std::cout << automato2.lerPalavra(palavra) << std::endl;

    //Automato que aceita palavras com substring aa sobre o alfabeto A = {a, b}.
    Automato automato3(3, std::vector<char>{'a', 'b'});
    automato3.criarTransicao(0, 0, 'b');
    automato3.criarTransicao(0, 1, 'a');
    automato3.criarTransicao(1, 0, 'b');
    automato3.criarTransicao(1, 2, 'a');
    automato3.criarTransicao(2, 2, 'a');
    automato3.criarTransicao(2, 2, 'b');
    automato3.definirEstadoFinal(2);
    std::cout << "\nTestes sobre o Automato 3" << std::endl;
    palavra = "aaaaaaaaaaaaaaaa";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    palavra = "babababababababab";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    palavra = "aabbbbbbbbbbb";
    std::cout << automato3.lerPalavra(palavra) << std::endl;
    palavra = "bbbbbbbbbbaabbabababab";
    std::cout << automato3.lerPalavra(palavra) << std::endl;

    //AFND que aceita palavras que terminam apenas com 01
    Automato automato4(3, std::vector<char>{'0', '1'}, true);
    automato4.criarTransicao(0, 0, '0');
    automato4.criarTransicao(0, 1, '0');
    automato4.criarTransicao(0, 0, '1');
    automato4.criarTransicao(1, 2, '1');
    automato4.definirEstadoFinal(2);
    palavra = "11111111101011010101111101";
    std::cout << "\nTestes sobre o Automato 4" << std::endl;
    std::cout << automato4.lerPalavra(palavra) << std::endl;

    //AFND que aceita palavras com 1 na terceira posição antes do final
    Automato automato5(4, std::vector<char>{'0', '1'}, true);
    automato5.criarTransicao(0, 0, '0');
    automato5.criarTransicao(0, 0, '1');
    automato5.criarTransicao(0, 1, '1');
    automato5.criarTransicao(1, 2, '0');
    automato5.criarTransicao(1, 2, '1');
    automato5.criarTransicao(2, 3, '0');
    automato5.criarTransicao(2, 3, '1');
    automato5.definirEstadoFinal(3);
    palavra = "100";
    std::cout << "\nTestes sobre o Automato 5" << std::endl;
    std::cout << automato5.lerPalavra(palavra) << std::endl;

    //AFN que aceita palavras sobre o alfabeto {0} que tem uma quantidade de 0's multiplo de 3 ou 2.
    Automato automato6(6, std::vector<char>{'0', '1'}, true);
    automato6.criarTransicao(0, 1, '0');
    automato6.criarTransicao(0, 3, '0');
    automato6.criarTransicao(1, 2, '0');
    automato6.criarTransicao(2, 1, '0');
    automato6.criarTransicao(3, 4, '0');
    automato6.criarTransicao(4, 5, '0');
    automato6.criarTransicao(5, 3, '0');
    automato6.definirEstadoFinal(5);
    automato6.definirEstadoFinal(2);
    palavra = "00000";
    std::cout << "\nTestes sobre o Automato 6" << std::endl;
    std::cout << automato6.lerPalavra(palavra) << std::endl;

    //AFND que aceita palavras sobre o alfabeto {a, b} e que possuem substring aa ou bb.
    Automato automato7(4, std::vector<char>{'a', 'b'}, true);
    automato7.criarTransicao(0, 0, 'a');
    automato7.criarTransicao(0, 0, 'b');
    automato7.criarTransicao(0, 1, 'a');
    automato7.criarTransicao(0, 3, 'b');
    automato7.criarTransicao(1, 2, 'a');
    automato7.criarTransicao(3, 2, 'b');
    automato7.criarTransicao(2, 2, 'a');
    automato7.criarTransicao(2, 2, 'b');
    automato7.definirEstadoFinal(2);
    palavra = "abababaababb";
    std::cout << "\nTestes sobre o Automato 7" << std::endl;
    std::cout << automato7.lerPalavra(palavra) << std::endl;
    system("pause");
    return 0;
}
