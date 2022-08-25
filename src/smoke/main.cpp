// Copyright (c) 2022 Stephen David Cope III. All rights reserved.

#include <iostream>
#include <string>

#include "sdc/flux/cAction.h"
#include "sdc/json/cJson.h"

int main() {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "  Smoke testing 'json' component" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  sdc::json::cJson json = 42.;
  std::cout << "t = " << json.type_name() << std::endl;
  std::cout << "v = " << json.get<double>() << std::endl;

  json = "42";
  std::cout << "t = " << json.type_name() << std::endl;
  std::cout << "v = " << json.get<std::string>() << std::endl;

  std::cout << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "  Smoke testing 'flux' component" << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  sdc::flux::cAction_csptr action = sdc::flux::cAction::make();
  std::cout << "isNull() = " << (action->isNull() ? "Yes" : "No") << std::endl;

  action = sdc::flux::cAction::make(1, 42);
  std::cout << "isNull() = " << (action->isNull() ? "Yes" : "No") << std::endl;
  std::cout << action->payload<int>() << std::endl;
  std::cout << action->payload<double>() << std::endl;

  sdc::flux::cAction_csptr clone = action->clone(1);
  std::cout << "type() = " << clone->type() << std::endl;
  std::cout << clone->payload<int>() << std::endl;

  return 0;
}
