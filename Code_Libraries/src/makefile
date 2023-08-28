CC=g++
LIBS = -lGL -lGLU -lglut -lSOIL -lpthread -L../irrKlang-64bit-1.6.0/bin/linux-gcc-64/ -lIrrKlang
LD_FLAGS = -Wl,-rpath=../irrKlang-64bit-1.6.0/bin/linux-gcc-64/ 
OPTS = -I"../irrKlang-64bit-1.6.0/include"


main: main.o Ammobox.o Bullet.o CameraMovementCallbacks.o DrawingRoutines.o GameAssets.o Model.o ResourceManager.o Sandbags.o Table.o Target.o Utils.o
	$(CC) $(CFLAGS) -o main main.o Ammobox.o Bullet.o CameraMovementCallbacks.o DrawingRoutines.o GameAssets.o Model.o ResourceManager.o Sandbags.o Table.o Target.o Utils.o $(LIBS) $(LD_FLAGS)

main.o: main.cpp GameAssets.h DrawingRoutines.h ModelsClasses.h Utils.h
	$(CC) $(CFLAGS) -c main.cpp $(OPTS)

Ammobox.o: Ammobox.cpp ModelsClasses.h
	$(CC) $(CFLAGS) -c Ammobox.cpp

Bullet.o: Bullet.cpp ModelsClasses.h
	$(CC) $(CFLAGS) -c Bullet.cpp

CameraMovementCallbacks.o: CameraMovementCallbacks.cpp 
	$(CC) $(CFLAGS) -c CameraMovementCallbacks.cpp

DrawingRoutines.o: DrawingRoutines.cpp DrawingRoutines.h Utils.h
	$(CC) $(CFLAGS) -c DrawingRoutines.cpp

GameAssets.o: GameAssets.cpp GameAssets.h
	$(CC) $(CFLAGS) -c GameAssets.cpp

Model.o: Model.cpp Model.h
	$(CC) $(CFLAGS) -c Model.cpp

ResourceManager.o: ResourceManager.cpp ResourceManager.h
	$(CC) $(CFLAGS) -c ResourceManager.cpp

Sandbags.o: Sandbags.cpp ModelsClasses.h
	$(CC) $(CFLAGS) -c Sandbags.cpp

Table.o: Table.cpp ModelsClasses.h
	$(CC) $(CFLAGS) -c Table.cpp

Target.o: Target.cpp ModelsClasses.h
	$(CC) $(CFLAGS) -c Target.cpp

Utils.o: Utils.cpp Utils.h
	$(CC) $(CFLAGS) -c Utils.cpp

clean:
	rm -f *.o main