#pragma once

#include "stout/undefined.h"

namespace stout {
namespace eventuals {

template <typename K>
struct IsContinuation : std::false_type {};

template <typename K, typename Value>
struct ValueFrom
{
  using type = typename K::Value;
};

template <typename Value>
struct ValueFrom<Undefined, Value>
{
  using type = Value;
};

template <typename K>
struct Compose
{
  template <typename Value>
  static auto compose(K k)
  {
    return std::move(k);
  }
};

template <typename Value, typename K>
auto compose(K k)
{
  return Compose<K>::template compose<Value>(std::move(k));
}

namespace detail {

template <typename E, typename K>
auto operator|(E e, K k)
{
  return std::move(e).k(compose<typename E::Value>(std::move(k)));
}

} // namespace detail {
} // namespace eventuals {
} // namespace stout {