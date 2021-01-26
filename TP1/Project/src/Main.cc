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
    DirectOrder *ord1 = new DirectOrder("Activate", 1);
    DirectOrder *ord2 = new DirectOrder("Deactivate", 3);

    CHECK(ord1->getOrder() == "Activate");
    CHECK(ord1->getRobot() == 1);
    CHECK(ord2->getNext() == nullptr);

    ord1->setNext(ord2);
    CHECK(ord1->getNext() == ord2);
    CHECK(ord2->getNext() == nullptr);

    delete ord1;
    delete ord2;
  }

  TEST_CASE("CommandOrders") {
    CommandOrder *ord1 = new CommandOrder("Collect", 2);

    CHECK(ord1->getX() == -1);
  }

  // TEST_CASE("Inserting in a queue") {
  //   Queue q;
  //   CHECK(q.getSize() == 0);
  //   q.insert(DirectOrder("Activate", 1));
  //   // CHECK(q.getFront().getOrder() == "Activate");
  //   // CHECK(q.getBack().getOrder() == );
  // }

  // TEST_CASE("Complexo::operator/(Complexo)") {
  //   Complexo zero;
  //   Complexo a(2, 3);
  //   Complexo b(-2, -3);
  //   Complexo c(0, 1);
  //   CHECK(a / a ==  Complexo(1, 0));
  //   CHECK(zero / a ==  Complexo(0, 0));
  //   CHECK(a / b == Complexo(-1, 0));
  //   CHECK(b / a == Complexo(-1, 0));
  //   CHECK(c / c == Complexo(1, 0));
  // }
}
