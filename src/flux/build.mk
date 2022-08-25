# Copyright (c) 2022 Stephen David Cope III. All rights reserved.

####### Component dependencies

flux.component_deps := util

####### Variables

flux.srcs := $(wildcard $(flux.root)/*.cpp)
flux.objs := $(addprefix $(flux.build_root)/,$(notdir $(flux.srcs:.cpp=.o)))

flux.depfiles := $(flux.objs:%.o=%.d)
-include $(flux.depfiles)

####### Targets

.PHONY: flux.clean
flux.clean: component = flux
flux.clean: $(call fn.get_clean_prereqs,flux)
	$(rx.clean)

.PHONY: flux.lib
flux.lib: $(flux.lib)

$(flux.lib): $(flux.objs)
	$(rx.make_static_lib)

$(flux.build_root):
	$(rx.make_target_dir)

$(flux.build_root)/%.o: component = flux
$(flux.build_root)/%.o: $(flux.root)/%.cpp | $(flux.build_root)
	$(rx.compile)
