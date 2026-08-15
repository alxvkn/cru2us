all: cru2us cus2ru

cru2us: cru2us.o layouts.o

cus2ru: cus2ru.o layouts.o

clean:
	$(RM) *.o cru2us cus2ru

.PHONY: clean all
