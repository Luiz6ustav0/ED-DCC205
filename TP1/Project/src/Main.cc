// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../include/CommandOrder.hpp"
#include "../include/DirectOrder.hpp"
#include "../include/Queue.hpp"

TEST_SUITE("Order nodes") {
  TEST_CASE("DirectOrder nodes") {
    DirectOrder *ord1 = new DirectOrder("ATIVAR", 1);
    DirectOrder *ord2 = new DirectOrder("RELATORIO", 3);

    CHECK(ord1->getOrder() == "ATIVAR");
    CHECK(ord1->getRobot() == 1);
    CHECK(ord2->getNext() == nullptr);

    ord1->setNext(ord2);
    CHECK(ord1->getNext() == ord2);
    CHECK(ord2->getNext() == nullptr);

    delete ord1;
    delete ord2;
  }

  TEST_CASE("CommandOrders") {
    CommandOrder *ord1 = new CommandOrder("COLETAR", 2);
    CommandOrder *ord2 = new CommandOrder("MOVER", 4, 5, 8);

    CHECK(ord1->getX() == -1);
    CHECK(ord1->getY() == -1);
    CHECK(ord2->getX() == 5);
    CHECK(ord2->getY() == 8);
    CHECK(ord1->getOrder() == "COLETAR");
    CHECK(ord2->getRobot() == 4);

    CHECK(ord1->getNext() == nullptr);
    CHECK(ord1->getNext() == ord2->getNext());

    ord1->setNext(ord2);
    CHECK(ord1->getNext() == ord2);

    delete ord1;
    delete ord2;
  }
}

TEST_SUITE("Queue") {
  TEST_CASE("Instantiation") {
    Queue<DirectOrder> q;

    CHECK(q.getFront() == nullptr);
    CHECK(q.getBack() == nullptr);
    CHECK(q.getSize() == 0);
    CHECK(q.isEmpty() == true);
  }

}
