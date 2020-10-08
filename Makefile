all:
	@ksh ./configure CREATE_VERSION_H
	@make -f Makefile.tmp
	@rm Makefile.tmp

depend:
	@ksh ./configure CREATE_VERSION_H
	@make -f Makefile.tmp depend 
	@rm Makefile.tmp

clean:
	@ksh ./configure
	@make -f Makefile.tmp clean
	@rm Makefile.tmp

install:
	@ksh ./configure
	@make -f Makefile.tmp install
	@rm Makefile.tmp

uninstall:
	@ksh ./configure
	@make -f Makefile.tmp uninstall
	@rm Makefile.tmp

