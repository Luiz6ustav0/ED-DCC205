// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>

#include "CommandOrder.hpp"
#include "DirectOrder.hpp"
#include "List.hpp"
#include "PlanetMap.hpp"
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

TEST_SUITE("List") {
  TEST_CASE("Instantiation") {
    // given
    List<CommandOrder> L;

    // then
    CHECK(L.getSize() == 0);
    CHECK(L.isEmpty() == true);
  }

  TEST_CASE("Insert element") {
    // given
    List<CommandOrder> L;
    CommandOrder ord1("MOVER", 1, 5, 3);

    // when
    L.insert(ord1);

    // then
    CHECK(L.getSize() == 1);
    CHECK(L.isEmpty() == false);
  }

  TEST_CASE("Insert elements and remove") {
    // given
    List<CommandOrder> L;
    CommandOrder ord1("MOVER", 1, 5, 3);
    CommandOrder ord2("MOVER", 3, 2, 2);

    // when
    L.insert(ord1);
    L.insert(ord2);

    // then
    CHECK(L.getSize() == 2);
    CHECK(L.isEmpty() == false);
    CHECK(L.remove().getOrder() == ord1.getOrder());
    CHECK(L.getSize() == 1);
  }

  TEST_CASE("Empty remove throws exception") {
    // given
    List<CommandOrder> L;

    // when removing then
    try {
      L.remove();
    } catch (std::string s) {
      CHECK(s == std::string("Can't remove element. Empty list"));
    }
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

  TEST_CASE("Moves") {
    // given
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);
    Robot r(m);
    int x = 5;
    int y = 4;

    // when
    r.move(x, y);

    // then
    CHECK(r.getPosX() == 5);
    CHECK(r.getPosY() == 4);
    delete m;
  }

  TEST_CASE("Does not move to invalid position") {
    // given
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);
    Robot r(m);
    int x = 99;
    int y = 99;

    // when
    r.move(x, y);

    // then
    CHECK(r.getPosX() == 0);
    CHECK(r.getPosY() == 0);
    delete m;
  }

  TEST_CASE("Prints history") {
    // given
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);
    Robot r = Robot(m, 4);

    // when
    r.activate();
    r.move(2, 3);
    r.move(99, 99);

    // then
    CHECK(r.removeFromHistory() == std::string("ROBO 4: MOVEU PARA (2,3)"));
    CHECK(r.removeFromHistory() ==
          std::string("ROBO 4: IMPOSSIVEL MOVER PARA (99,99)"));

    delete m;
  }

  TEST_CASE("Cleans history") {
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);
    Robot r = Robot(m, 4);

    // when
    r.activate();
    r.move(2, 3);
    r.move(99, 99);
    r.cleanHistory();

    // then
    try {
      r.printHistory();
    } catch (std::string e) {
      CHECK(e == std::string("Nothing to print. Empty history"));
    }
    delete m;
  }
}

TEST_SUITE("PlanetMap") {
  TEST_CASE("Default instantiation") {
    // given
    PlanetMap pm;

    // then
    CHECK(pm.getCols() == -1);
    CHECK(pm.getRows() == -1);
    CHECK(pm.get(0, 0) == -1);
  }

  TEST_CASE("Instantiation with a file") {
    // given when
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);

    // then
    CHECK(m->getCols() == 10);
    CHECK(m->getRows() == 9);
    CHECK(m->get(0, 0) == 'B');

    delete m;
  }

  TEST_CASE("Checking positions") {
    // given when
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);

    // then
    CHECK(m->get(0, 1) == '.');
    CHECK(m->get(2, 4) == 'R');
    CHECK(m->get(0, 0) == 'B');

    delete m;
  }

  TEST_CASE("Changes char to dot") {
    // given
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);

    // when
    m->changeToDot(2, 4); // 'R'
    m->changeToDot(0, 6); // 'O'

    // then
    CHECK(m->get(2, 4) == '.');
    CHECK(m->get(0, 6) == '.');

    delete m;
  }

  TEST_CASE("Does not change base to dot") {
    // given
    std::string fName = "./tests/mapa_test.txt";
    PlanetMap *m = new PlanetMap(fName);

    // when
    m->changeToDot(0, 0); // 'B'

    // then
    CHECK(m->get(0, 0) == 'B');

    delete m;
  }
}