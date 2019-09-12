DUNE := dune

.PHONY: all
all:
	dune build main.exe
	if test -x _build/default/main.exe ; then \
	  rm -f bx0.exe ; \
	  ln -s _build/default/main.exe bx0.exe ; \
	fi

.PHONY: testbench
testbench: bx0.exe
	for bxfile in test/*.bx ; do \
	  if test -f $${bxfile%bx}expected ; then \
	    ./bx0.exe $$bxfile \
	    && ( $${bxfile%bx}exe > $${bxfile%bx}actual 2>&1 ) \
	    && ( diff $${bxfile%bx}actual $${bxfile%bx}expected || echo Test $${bxfile} failed ) \
	    || exit 255 ; \
	  fi ; \
	done

.PHONY: clean
clean:
	dune clean
	rm -f bx0.exe
