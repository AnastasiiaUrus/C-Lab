all:
	g++ geom.cpp main_geom.cpp -o geom_app
clean:
	rm geom_app