#include "io_service.h"
#include "timer.h"

#include <iostream>
#include <ctime>

void on_timeout() {
  const time_t ctt = time(0);
  std::cout << asctime(localtime(&ctt)) << std::endl;
}

void test() {
  io_service io_service;

  timer t(io_service);
  t.expires_from_now(1);
  t.async_wait(&on_timeout);

  io_service.run();
}

int main(int argc, char* argv[]) {
  test();

  return 0;
}
