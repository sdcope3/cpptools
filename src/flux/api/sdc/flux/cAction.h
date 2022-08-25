// Copyright (c) 2022 Stephen David Cope III. All rights reserved.

#pragma once

#include <memory>

#include "sdc/util/cAnyVector.h"

namespace sdc {
namespace flux {

class cAction;
using cAction_csptr = std::shared_ptr<const cAction>;

class cAction {
 public:
  virtual ~cAction() {}

  // This constructor is not intended to be called directly. It is preferred to
  // instantiate a shared pointer to an action via a static factory method.
  explicit cAction(int type = -1, const util::cAnyVector& payload = {})
      : m_type(type), m_payload(payload) {}

  // Make a null action.
  template <typename cActionType = cAction>
  static cAction_csptr make();

  // Make an action with an arbitrary payload.
  template <typename cActionType = cAction, typename... Args>
  static cAction_csptr make(int type, Args&&... args);

  // Make an action by cloning an existing action.
  template <typename cActionType = cAction>
  static cAction_csptr make(const cAction& action, int newType = -1);

 public:
  // Return a clone of this action. Optionally specify a new type for the cloned
  // action. Otherwise the cloned action will inherit its type from this action.
  virtual cAction_csptr clone(int newType = -1) const;

  // Return true if this action is null, false otherwise. Any action with a
  // valid type is considered non-null, even if it has an empty payload.
  bool isNull() const { return m_type < 0; }

  // Return the payload at the given index cast to the appropriate type. Return
  // a default constructed value of the appropriate type if an error occurrs.
  template <typename T>
  const T& payload(int i = 0) const {
    return m_payload.get<T>(i);
  }

  // Return the payload at the given index cast to the appropriate type. Return
  // the specified default value if an error occurrs.
  template <typename T>
  const T& payload(int i, const T& defaultValue) const {
    return m_payload.get<T>(i, defaultValue);
  }

  // Return this action's type.
  int type() const { return m_type; }

 private:
  const int m_type;
  const util::cAnyVector m_payload;
};

#include "cAction.tpp"

}  // namespace flux
}  // namespace sdc
