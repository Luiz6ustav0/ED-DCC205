// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "CommandOrder.hpp"
#include "DirectOrder.hpp"
#include "Queue.hpp"
#include "Robot.hpp"

TEST_SUITE("Order nodes") {
  TEST_CASE("DirectOrder nodes") {
    // given
    DirectOrder *ord1 = new DirectOrder("ATIVAR", 1);
    DirectOrder *ord2 = new DirectOrder("RELATORIO", 3);

    // when
    ord1->setNext(ord2);

    // then
    CHECK(ord1->getOrder() == "ATIVAR");
    CHECK(ord1->getRobot() == 1);
    CHECK(ord1->getNext() == ord2);
    CHECK(ord2->getNext() == nullptr);

    delete ord1;
    delete ord2;
  }

  TEST_CASE("CommandOrders") {
    // given
    CommandOrder *ord1 = new CommandOrder("COLETAR", 2);
    CommandOrder *ord2 = new CommandOrder("MOVER", 4, 5, 8);

    // when
    ord1->setNext(ord2);

    // then
    CHECK(ord1->getX() == -1);
    CHECK(ord1->getY() == -1);
    CHECK(ord2->getX() == 5);
    CHECK(ord2->getY() == 8);
    CHECK(ord1->getOrder() == "COLETAR");
    CHECK(ord2->getRobot() == 4);

    CHECK(ord1->getNext() == ord2);
    CHECK(ord2->getNext() == nullptr);

    delete ord1;
    delete ord2;
  }
}

TEST_SUITE("Queue") {
  TEST_CASE("Instantiation") {
    // given
    Queue<DirectOrder> q;

    // then
    CHECK(q.getFront() == nullptr);
    CHECK(q.getSize() == 0);
    CHECK(q.isEmpty() == true);
  }

  TEST_CASE("Insert first element") {
    // given
    Queue<DirectOrder> q;
    DirectOrder ord1("ATIVAR", 1);

    // when
    q.insert(ord1);

    // then
    CHECK(q.isEmpty() == false);
    CHECK(q.getSize() == 1);
    CHECK(q.getFront()->getItem().getOrder() == ord1.getOrder());
  }

  TEST_CASE("Insert more elements") {
    // given
    Queue<CommandOrder> q;
    CommandOrder ord1("MOVER", 1, 5, 3);
    CommandOrder ord2("COLETAR", 8);

    // when
    q.insert(ord1);
    q.insert(ord2);

    // then
    CHECK(q.isEmpty() == false);
    CHECK(q.getSize() == 2);
    CHECK(q.getFront()->getItem().getOrder() == ord1.getOrder());
    CHECK(q.getFront()->getItem().getRobot() == ord1.getRobot());
  }

  TEST_CASE("Insert elements and dequeue") {
    // given
    Queue<DirectOrder> q;
    DirectOrder ord1("ATIVAR", 1);
    DirectOrder ord2("ATIVAR", 8);
    DirectOrder ord3("ATIVAR", 3);

    // when
    q.insert(ord1);
    q.insert(ord2);
    q.insert(ord3);

    // then
    CHECK(q.isEmpty() == false);
    CHECK(q.getSize() == 3);

    CHECK(q.dequeue().getRobot() == ord1.getRobot());
    CHECK(q.getSize() == 2);
    CHECK(q.dequeue().getRobot() == ord2.getRobot());
    CHECK(q.getSize() == 1);
    CHECK(q.getFront()->getItem().getRobot() == ord3.getRobot());
  }

  TEST_CASE("Empty queue") {
    // given
    Queue<DirectOrder> q;
    DirectOrder ord1("ATIVAR", 1);
    DirectOrder ord2("ATIVAR", 8);
    DirectOrder ord3("ATIVAR", 3);

    // when
    q.insert(ord1);
    q.insert(ord2);
    q.insert(ord3);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // then
    CHECK(q.isEmpty() == true);
    CHECK(q.getSize() == 0);
  }

  TEST_CASE("Clear queue") {
    // given
    Queue<DirectOrder> q;
    DirectOrder ord1("ATIVAR", 1);
    DirectOrder ord2("ATIVAR", 8);

    // when
    q.insert(ord1);
    q.insert(ord2);
    q.clear();

    // then
    CHECK(q.getFront() == nullptr);
    CHECK(q.isEmpty() == true);
    CHECK(q.getSize() == 0);
  }

  TEST_CASE("Clear queue then add elements") {
    // given
    Queue<DirectOrder> q;
    DirectOrder ord1("ATIVAR", 1);
    DirectOrder ord2("ATIVAR", 8);

    // when
    q.insert(ord1);
    q.insert(ord2);
    q.clear();
    q.insert(ord1);

    // then
    CHECK(q.isEmpty() == false);
    CHECK(q.getSize() == 1);
    CHECK(q.dequeue().getOrder() == ord1.getOrder());
  }
}

TEST_SUITE("Robot class") {
  TEST_CASE("Instantiation") {
    // given when
    Robot r = Robot();

    // then
    CHECK(r.isActivated() == false);
    CHECK(r.getPosX() == 0);
    CHECK(r.getPosY() == 0);
    CHECK(r.isLogEmpty() == true);
    CHECK(r.directOrders.isEmpty() == true);
    CHECK(r.commandOrders.isEmpty() == true);
  }

  TEST_CASE("Activates") {
    // given
    Robot r = Robot();

    // when
    r.activate();

    // then
    CHECK(r.isActivated() == true);

  }

  TEST_CASE("Moves") {}

  TEST_CASE("Prints history") {}

  TEST_CASE("Cleans history") {}
}
