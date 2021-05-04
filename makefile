compilar:
		g++ -o vereadores *.cpp

clean:
		rm *.o
		
run:
		./vereadores candidatos.csv partidos.csv 15/11/2020