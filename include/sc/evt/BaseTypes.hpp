#pragma once

#include<map>
#include<vector>
#include<functional>

namespace sc
{
  namespace evt
  {
    class Event;

    typedef int SlotId;
    typedef std::function< void( Event& ) > Callback;
    typedef std::vector< Callback > CallbackContainer;
    typedef std::map< SlotId, CallbackContainer > Registry;
  }
}

