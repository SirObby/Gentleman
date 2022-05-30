OBJS=obj/main.o \
		 obj/foo.o

all: gent

gent: ${OBJS}
	${CC} ${OBJS}  -o gent

obj/%.o: src/%.c
	${CC} -c $< -o $@
