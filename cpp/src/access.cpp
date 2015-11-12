#include "access.h"
#include "user.h"

#include <vector>

namespace webdev
  {

  using std::string;
  using std::vector;
  using redox::Redox;

  bool user_exists(Redox & redis, user const & user)
    {
    return redis.commandSync<string>({"HGET", "users", user.name()}).status() != redox::Command<std::string>::NIL_REPLY;
    }

  bool user_create(Redox & redis, user const & user)
    {
    return redis.commandSync<string>({"HMSET", "user:" + user.hash(), "name", user.name()}).ok() &&
           redis.commandSync<int>({"HSET", "users", user.name(), user.hash()}).ok();
    }

  vector<string> users_getall(Redox & redis)
    {
    auto & result = redis.commandSync<vector<string>>({"HGETALL", "users"});
    return result.ok() ? result.reply() : vector<string>{};
    }

  }
