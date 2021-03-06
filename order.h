#ifndef ORDER_H
#define ORDER_H

#include <iostream>

/*
 *  Struktura Order będzie przetrzymywała zapisane polecenie dla mikroprocesora.
 *  Wewnątrz będzie się znajdowało np. order = MOV | first = "A" (pojedyncza litera oznaczająca pobranie aktualnej wartości rejestru A) |
 *  second = "0001000111001010" (zawartość immidiate input w momencie zapisania rozkazu) | third = "_" (dla rozkazóW immidiate nie używamy trzeciego adresu)
 *  Dzięki tym strukturom łątwo będzie przetrzymywać zapisane rozkazy oraz wypisywać je.
 */

typedef enum{
    MOV,
    ADD,
    SUB,
    INT_00H,
    INT_2AH,
    INT_2CH,
    PUSH,
    POP,
    INT_0DH,
    INT_41H,
    INT_56H,
    INT_47H,
    INT_48H,
    INT_49H,
    INT_4AH
}order_type;

typedef struct{
    order_type order;
    std::string first, second, third;
}Order;

#endif // ORDER_H
