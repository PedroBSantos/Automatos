#include <iostream>
#include "../inc/automata.h"

int main(int argc, char const* argv[])
{
    //Automata que aceita words que começam apenas com ab sobre o alphabet A = {a, b}.
    Automata automata1(4, std::vector<char>{'a', 'b'});
    automata1.createTransiction(0, 1, 'a');
    automata1.createTransiction(0, 3, 'b');
    automata1.createTransiction(1, 3, 'a');
    automata1.createTransiction(1, 2, 'b');
    automata1.createTransiction(2, 2, 'a');
    automata1.createTransiction(2, 2, 'b');
    automata1.createTransiction(3, 3, 'a');
    automata1.createTransiction(3, 3, 'b');
    automata1.makeFinalState(2);
    const char* word = "abababababa";
    std::cout << "Testes sobre o Automata 1" << std::endl;
    std::cout << automata1.readWord(word) << std::endl;
    word = "babababababababa";
    std::cout << automata1.readWord(word) << std::endl;

    //Automata que aceita words que terminam com 011 sobre o alphabet A = {0, 1}.
    Automata automata2(4, std::vector<char>{'0', '1'});
    automata2.createTransiction(0, 0, '1');
    automata2.createTransiction(0, 1, '0');
    automata2.createTransiction(1, 1, '0');
    automata2.createTransiction(1, 2, '1');
    automata2.createTransiction(2, 1, '0');
    automata2.createTransiction(2, 3, '1');
    automata2.createTransiction(3, 0, '0');
    automata2.createTransiction(3, 0, '1');
    automata2.makeFinalState(3);
    word = "011";
    std::cout << "\nTestes sobre o Automata 2" << std::endl;
    std::cout << automata2.readWord(word) << std::endl;
    word = "010101010101";
    std::cout << automata2.readWord(word) << std::endl;
    word = "01111111111111111111111";
    std::cout << automata2.readWord(word) << std::endl;

    //Automata que aceita words com substring aa sobre o alphabet A = {a, b}.
    Automata automata3(3, std::vector<char>{'a', 'b'});
    automata3.createTransiction(0, 0, 'b');
    automata3.createTransiction(0, 1, 'a');
    automata3.createTransiction(1, 0, 'b');
    automata3.createTransiction(1, 2, 'a');
    automata3.createTransiction(2, 2, 'a');
    automata3.createTransiction(2, 2, 'b');
    automata3.makeFinalState(2);
    std::cout << "\nTestes sobre o Automata 3" << std::endl;
    word = "aaaaaaaaaaaaaaaa";
    std::cout << automata3.readWord(word) << std::endl;
    word = "babababababababab";
    std::cout << automata3.readWord(word) << std::endl;
    word = "aabbbbbbbbbbb";
    std::cout << automata3.readWord(word) << std::endl;
    word = "bbbbbbbbbbaabbabababab";
    std::cout << automata3.readWord(word) << std::endl;

    //AFND que aceita words que terminam apenas com 01
    Automata automata4(3, std::vector<char>{'0', '1'}, true);
    automata4.createTransiction(0, 0, '0');
    automata4.createTransiction(0, 1, '0');
    automata4.createTransiction(0, 0, '1');
    automata4.createTransiction(1, 2, '1');
    automata4.makeFinalState(2);
    word = "11111111101011010101111101";
    std::cout << "\nTestes sobre o Automata 4" << std::endl;
    std::cout << automata4.readWord(word) << std::endl;

    //AFND que aceita words com 1 na terceira posição antes do final
    Automata automata5(4, std::vector<char>{'0', '1'}, true);
    automata5.createTransiction(0, 0, '0');
    automata5.createTransiction(0, 0, '1');
    automata5.createTransiction(0, 1, '1');
    automata5.createTransiction(1, 2, '0');
    automata5.createTransiction(1, 2, '1');
    automata5.createTransiction(2, 3, '0');
    automata5.createTransiction(2, 3, '1');
    automata5.makeFinalState(3);
    word = "100";
    std::cout << "\nTestes sobre o Automata 5" << std::endl;
    std::cout << automata5.readWord(word) << std::endl;

    //AFN que aceita words sobre o alphabet {0} que tem uma quantidade de 0's multiplo de 3 ou 2.
    Automata automata6(6, std::vector<char>{'0', '1'}, true);
    automata6.createTransiction(0, 1, '0');
    automata6.createTransiction(0, 3, '0');
    automata6.createTransiction(1, 2, '0');
    automata6.createTransiction(2, 1, '0');
    automata6.createTransiction(3, 4, '0');
    automata6.createTransiction(4, 5, '0');
    automata6.createTransiction(5, 3, '0');
    automata6.makeFinalState(5);
    automata6.makeFinalState(2);
    word = "00000";
    std::cout << "\nTestes sobre o Automata 6" << std::endl;
    std::cout << automata6.readWord(word) << std::endl;

    //AFND que aceita words sobre o alphabet {a, b} e que possuem substring aa ou bb.
    Automata automata7(4, std::vector<char>{'a', 'b'}, true);
    automata7.createTransiction(0, 0, 'a');
    automata7.createTransiction(0, 0, 'b');
    automata7.createTransiction(0, 1, 'a');
    automata7.createTransiction(0, 3, 'b');
    automata7.createTransiction(1, 2, 'a');
    automata7.createTransiction(3, 2, 'b');
    automata7.createTransiction(2, 2, 'a');
    automata7.createTransiction(2, 2, 'b');
    automata7.makeFinalState(2);
    word = "abababaababb";
    std::cout << "\nTestes sobre o Automata 7" << std::endl;
    std::cout << automata7.readWord(word) << std::endl;

    //AFND que aceita words sobre o alphabet {0, 1} e que possuem substring 0101.
    Automata automata8(5, std::vector<char>{'0', '1'}, true);
    automata8.createTransiction(0, 0, '0');
    automata8.createTransiction(0, 0, '1');
    automata8.createTransiction(0, 1, '0');
    automata8.createTransiction(1, 2, '1');
    automata8.createTransiction(2, 3, '0');
    automata8.createTransiction(3, 4, '1');
    automata8.createTransiction(4, 4, '0');
    automata8.createTransiction(4, 4, '1');
    automata8.makeFinalState(4);
    word = "01010";
    std::cout << "\nTestes sobre o Automata 8" << std::endl;
    std::cout << automata8.readWord(word) << std::endl;

    //AFND que aceita words sobre o alphabet {0, 1} e que terminam com 00.
    Automata automata9(3, std::vector<char>{'0', '1'}, true);
    automata9.createTransiction(0, 0, '0');
    automata9.createTransiction(0, 0, '1');
    automata9.createTransiction(0, 1, '0');
    automata9.createTransiction(1, 2, '0');
    automata9.makeFinalState(2);
    word = "11100";
    std::cout << "\nTestes sobre o Automata 9" << std::endl;
    std::cout << automata9.readWord(word) << std::endl;
    system("pause");
    return 0;
}
