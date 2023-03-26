#pragma once

#include <memory>
#include <functional>
#include <list>
#include <vector>
#include <algorithm>

template<typename> class Event;

template<typename Ret, typename... Args>
class Event<Ret (Args...)> {
 public:
  using HandlerType = std::function<Ret (Args...)>;
  using Result = typename HandlerType::result_type;

  bool SetHandler(HandlerType&& handler) {
    handler_ = std::forward<HandlerType>(handler);
    return true;
  }
  
  Result Emit(Args && ... args) {
    return handler_(std::forward<Args>(args)...);
  }

  void EmitAsync(Args && ... args) {
    //TODO
  }
 private:
  HandlerType handler_;
};