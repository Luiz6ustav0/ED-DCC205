// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "../include/Queue.hpp"


TEST_SUITE("Queue") {
  TEST_CASE("Queue::Queue()") {
    Queue q;
    CHECK(q.getSize() == 0);
    CHECK(q.getBack() == 0);
    CHECK(q.getFront() == 0);
  }

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
