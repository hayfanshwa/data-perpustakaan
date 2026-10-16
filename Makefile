CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -O2
TARGET = perpustakaan.exe
OBJECTS = main.o buku.o berkas.o menu.o

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

main.o: src/main.cpp src/buku.h src/berkas.h src/menu.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o main.o

buku.o: src/buku.cpp src/buku.h
	$(CXX) $(CXXFLAGS) -c src/buku.cpp -o buku.o

berkas.o: src/berkas.cpp src/berkas.h src/buku.h
	$(CXX) $(CXXFLAGS) -c src/berkas.cpp -o berkas.o

menu.o: src/menu.cpp src/menu.h src/buku.h src/berkas.h
	$(CXX) $(CXXFLAGS) -c src/menu.cpp -o menu.o

run: all
	./$(TARGET)

clean:
	-del /Q $(TARGET) $(OBJECTS) 2>NUL || rm -f $(TARGET) $(OBJECTS)