// Copyright (c) 2022 Stephen David Cope III. All rights reserved.

#pragma once

#include <any>
#include <stdexcept>
#include <vector>

namespace sdc {
namespace util {

class cAnyVector : public std::vector<std::any> {
  using SUPERCLASS = std::vector<std::any>;

 public:
  using SUPERCLASS::SUPERCLASS;

  // Return the item at the given index cast to the appropriate type. On error,
  // return a default constructed value of the appropriate type. If ok is given,
  // it will indicate if the operation was successful or not.
  template <typename T>
  const T& get(std::size_t i, bool* ok = nullptr) const {
    static const T defaultValue = T();
    return get<T>(i, defaultValue, ok);
  }

  // Return the item at the given index cast to the appropriate type. On error,
  // return the specified default value. If ok is given, it will indicate if the
  // operation was successful or not.
  template <typename T>
  const T& get(std::size_t i, const T& defaultValue, bool* ok = nullptr) const {
    if (ok != nullptr) {
      *ok = true;
    }

    try {
      return std::any_cast<const T&>(this->at(i));
    } catch (const std::bad_any_cast& /*e*/) {
      // TODO Log an error/warning when (at least) running in debug mode?
    } catch (const std::out_of_range& /*e*/) {
      // TODO Log an error/warning when (at least) running in debug mode?
    }

    if (ok != nullptr) {
      *ok = false;
    }

    return defaultValue;
  }
};

}  // namespace util
}  // namespace sdc
