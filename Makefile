all: string_utils

install:
	cd build && make install

uninstall:
	cd build && make uninstall


.PHONY: string_utils
string_utils:
	@mkdir -p build
	cd build && cmake $(CMAKE_FLAGS) ..
ifneq ($(MAKE),)
	cd build && $(MAKE)
else
	cd build && make
endif

clean:
	-cd build && make clean
	rm -Rf build bin lib