# All Target
all: clean cliqueBP

# Tool invocations
cliqueBP: 
	
	g++ -c cliqueNormal.cpp geracaoGrafo.cpp russianDoll.cpp utilitarios.cpp
	g++ main.cpp cliqueNormal.o geracaoGrafo.o russianDoll.o utilitarios.o -o cliquebp.out

# Other Targets
clean:
	rm *.o
