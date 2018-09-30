#include "lib.h"

#include <spdlog/spdlog.h>

int main()
{
  auto logger = spdlog::spdout_logger_mt("console");
  logger->info("version {} was started", version());
  return 0;
}
