# Список имен файлов
OBJECTS = main.o swapAdjacentPairs.o deleteSpacesFromText.o changeTheExtension.o

# Название главной цели
TARGET = main.exe

all: $(TARGET)

# Правило для создания главной цели
$(TARGET): $(OBJECTS)
	gcc -o $(TARGET) $(OBJECTS)

# Так как у меня задачи расположены в подкаталогах, создание объектных файлов остаются базовыми. 
# В дальнейшем есть теоретический вариант собирать *.c файлы по подкаталогам и использовать генерацию целей в цикле. 
# Пока это слишком сложно.
main.o: main.c
	gcc -c --std=c99 -o main.o main.c

swapAdjacentPairs.o: task_1\swapAdjacentPairs.c
	gcc -c --std=c99 -o swapAdjacentPairs.o task_1\swapAdjacentPairs.c

deleteSpacesFromText.o: task_2\deleteSpacesFromText.c
	gcc -c --std=c99 -o deleteSpacesFromText.o task_2\deleteSpacesFromText.c

deleteSpacesFromText.o: task_3\changeTheExtension.c
	gcc -c --std=c99 -o changeTheExtension.o task_3\changeTheExtension.c