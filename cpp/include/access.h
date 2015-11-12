#ifndef __WEBDEV_ACCESS
#define __WEBDEV_ACCESS

#include "user.h"
#include "redox/client.hpp"

#include <vector>
#include <string>

namespace webdev
  {

  bool user_exists(redox::Redox & redis, user const & user);
  bool user_create(redox::Redox & redis, user const & user);
  std::vector<std::string> users_getall(redox::Redox & redis);

  }

#endif
