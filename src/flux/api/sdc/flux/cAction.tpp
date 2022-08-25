// Copyright (c) 2022 Stephen David Cope III. All rights reserved.

#pragma once

template <typename cActionType>
sdc::flux::cAction_csptr sdc::flux::cAction::make() {
  return std::make_shared<const cActionType>();
}

template <typename cActionType, typename... Args>
sdc::flux::cAction_csptr sdc::flux::cAction::make(int type, Args&&... args) {
  util::cAnyVector payload{args...};
  return std::make_shared<const cActionType>(type, payload);
}

template <typename cActionType>
sdc::flux::cAction_csptr sdc::flux::cAction::make(const cAction& action, int newType) {
  int type = newType < 0 ? action.m_type : newType;
  return std::make_shared<const cActionType>(type, action.m_payload);
}
