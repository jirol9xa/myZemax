CC = clang++
I_FLAG = -I ./src/Include
C_FLAG = -c -O3
SFML_FLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system
DEBUG_FLAGS = -Wall -Wextra -Wpedantic -fsanitize=address,leak


all: main.o vector.o render.o sphere.o scene.o plane.o vec2.o button.o vec3.o
	$(CC) main.o vector.o render.o sphere.o scene.o plane.o vec2.o button.o vec3.o -o test $(SFML_FLAGS) $(DEBUG_FLAGS)
clear:
	rm -rf *.o

main.o:		main.cpp
	$(CC) $(C_FLAG)	main.cpp -o main.o	$(I_FLAG)					-g
vector.o:	src/Vector/vector.cpp
	$(CC) $(C_FLAG) src/Vector/vector.cpp -o vector.o	$(I_FLAG)	-g
render.o:	src/Render/render.cpp
	$(CC) $(C_FLAG) src/Render/render.cpp -o render.o	$(I_FLAG)	-g
sphere.o:	src/Sphere/sphere.cpp
	$(CC) $(C_FLAG) src/Sphere/sphere.cpp -o sphere.o	$(I_FLAG)	-g
scene.o:	src/Scene/scene.cpp
	$(CC) $(C_FLAG) src/Scene/scene.cpp   -o scene.o 	$(I_FLAG)	-g
plane.o:	src/Plane/plane.cpp
	$(CC) $(C_FLAG) src/Plane/plane.cpp	  -o plane.o	$(I_FLAG)	-g
vec2.o:		src/Vec2/vec2.cpp
	$(CC) $(C_FLAG) src/Vec2/vec2.cpp 	  -o vec2.o 	$(I_FLAG)	-g
button.o:	src/Button/button.cpp
	$(CC) $(C_FLAG) src/Button/button.cpp  -o button.o	$(I_FLAG)	-g
vec3.o:		src/Vec3/vec3.cpp
	$(CC) $(C_FLAG) src/Vec3/vec3.cpp 	   -o vec3.o 	$(I_FLAG)	-g
