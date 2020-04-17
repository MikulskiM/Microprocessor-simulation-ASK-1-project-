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
    SUB
}order_type;

typedef struct{
    order_type order;
    std::string first, second, third;
}Order;

#endif // ORDER_H
