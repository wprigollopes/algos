#include<iostream>
#include<string>

using namespace std;
void altera2(int &a, int &b) {
    a = a+1;
    b = b+10;
}

// Cria outra variável do tipo ponteiro
// Dentro da variável, acessa-se o ponteiro do ponteiro para
// alcançar a variável lá dentro
void altera(int *a, int *b) {
    // Aqui é o mesmo caso do &ptr,  
    *a = *a + 1;
    *b = *b + 10;
}

int main() {
    int x = 10;
    // Declara um ponteiro do tipo inteiro
    // Ele guarda o endereço de memória de uma variável
    int *ptr;

    // Para carregar o endereço de memória do ponteiro, você
    // precisa usar o & para passar o ponteiro
    ptr = &x;
    // Variável x
    cout << x << endl;
    // Ponteiro X
    cout << &x << endl;
    // Variável ptr que contém o endereço de memória de X
    cout << ptr << endl;
    // Endereço de memória do ponteiro X
    cout << &ptr << endl;
    // Deferência do ptr, ou seja, ele vai pegar o valor do dado
    // que está contido dentro do do endereço de ptr,
    // ou seja, vai mostrar o valor de x, que é o endereço referenciado
    cout << *ptr << endl;

    // Para alterar x por ponteiro
    *ptr = 5;

    cout << *ptr << endl;
    cout << x << endl;

    // Em funções, tem que passar o endereço da variável
    int a = 5;
    int b = 10;

    // Assim, passa-se a referência de a e b
    // e a função pega o ponteiro dessa referência para
    // manipular
    altera(&a, &b);
    cout << a << endl;
    cout << b << endl;

    // Assim, na declaração da função (olhar função), passa-se a
    // referência de a e b para a função e lá se manipula essa variável
    // bem mais simples, com referência direta
    altera2(a, b);
    cout << a << endl;
    cout << b << endl;

    cout << "Ponteiro do ponteiro" << endl;
    int d = 5;
    int *ptr1;
    int **ptr2;
    // Colocando o endereço de a no ptr1 que é um ponteiro
    ptr1 = &a;
    // Colocando o endereço
    ptr2 = &ptr1;
    cout << "     a: " << a << endl;
    cout << "    &a: " << &a << endl;
    cout << "  ptr1: " << ptr1 << endl;   // Variável normal se chamar assim mostra o endereço de memória
    cout << " *ptr1: " << *ptr1 << endl;  // * chama o conteúdo do ponteiro
    cout << " &ptr1: " << &ptr1 << endl;  // Se chamarmos & chama o endereço do próprio ponteiro
    cout << "  ptr2: " << ptr2 << endl;
    cout << " *ptr2: " << *ptr2 << endl;
    cout << "**ptr2: " << **ptr2 << endl;
    cout << " &ptr2: " << &ptr2 << endl;

    return x;
}