# Copyright (c) 2022 Stephen David Cope III. All rights reserved.

####### Component dependencies

smoke.component_deps := flux json util

####### Variables

smoke.srcs := $(wildcard $(smoke.root)/*.cpp)
smoke.objs := $(addprefix $(smoke.build_root)/,$(notdir $(smoke.srcs:.cpp=.o)))
smoke.exe := $(smoke.build_root)/smoke$(exe_ext)

smoke.depfiles := $(smoke.objs:%.o=%.d)
-include $(smoke.depfiles)

####### Targets

.PHONY: smoke.clean
smoke.clean: component = smoke
smoke.clean: $(call fn.get_clean_prereqs,smoke)
	$(rx.clean)

.PHONY: smoke.exe
smoke.exe: $(smoke.exe)

.PHONY: smoke.run
smoke.run: $(smoke.exe)
	$(rx.run)

$(smoke.exe): $(call fn.get_link_prereqs,smoke,objs)
	$(rx.link)

$(smoke.build_root):
	$(rx.make_target_dir)

$(smoke.build_root)/%.o: component = smoke
$(smoke.build_root)/%.o: $(smoke.root)/%.cpp | $(smoke.build_root)
	$(rx.compile)
