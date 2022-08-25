// Copyright (c) 2022 Stephen David Cope III. All rights reserved.

#include "api/sdc/flux/cAction.h"

sdc::flux::cAction_csptr sdc::flux::cAction::clone(int newType) const {
  return make(*this, newType);
}
