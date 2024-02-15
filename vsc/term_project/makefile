# Список имен файлов
OBJECTS = temp_functions.o load_data.o search_and_print_data.o

# Название главной цели
TARGET = temp_functions.exe

all: $(TARGET)

# Правило для создания главной цели
$(TARGET): $(OBJECTS)
	gcc -o $(TARGET) $(OBJECTS)

# Так как у меня задачи расположены в подкаталогах, создание объектных файлов остаются базовыми. 
# В дальнейшем есть теоретический вариант собирать *.c файлы по подкаталогам и использовать генерацию целей в цикле. 
# Пока это слишком сложно.
temp_functions.o: temp_functions.c
	gcc -c --std=c99 -o temp_functions.o temp_functions.c

load_data.o: load_data.c
	gcc -c --std=c99 -o load_data.o load_data.c

search_and_print_data.o: search_and_print_data.c
	gcc -c --std=c99 -o search_and_print_data.o search_and_print_data.c

debug: $(TARGET)
	gdb $(TARGET)

.PHONY: clean