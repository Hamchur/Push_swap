# Push_swap
Школьный алгоритмический проект push_swap: цель состоит в том, чтобы сортировать данные, используя только два стека и ограниченный набор инструкций.

Создаёт две программы: checker и push_swap.

Программа checker считывает случайный список целых чисел из стандартного ввода, сохраняет их и проверяет, отсортированы ли они.

Программа push_swap вычисляет шаги для сортировки целых чисел — вталкивание, выталкивание, перестановка и ротация их между стеком a и стеком b — и отображает эти направления в стандартном выводе.

Вы можете передать push_swap в программу проверки, и программа проверки проверит, что инструкции push_swap были выполнены успешно.

Обе программы должны обязательно анализировать ввод на наличие ошибок, включая пустые строки, отсутствие параметров, нечисловые параметры, дубликаты и недопустимые/несуществующие инструкции.
## Визуализация и роботоспособность программы
Запуск ```make```

Проверка checker
```
./checker 5 2 3 1 4
./checker "-50 -400 -20 -1 -100"
./checker "-22" "35" "40" "-15" "75"
```
Проверка Push_swap
```
./push_swap 5 2 3 1 4
```
Для запуска визуализацию надо запустить
```
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```
![alt-текст](https://user-images.githubusercontent.com/38796098/57738594-6b6ae500-76b0-11e9-9d29-0f59ee825e8e.gif)

## Команды
- pa : push a — взять первый элемент в верхней части b и поместить его в верхнюю часть a. Ничего не делать, если b пусто.
- pb : push b — взять первый элемент в верхней части a и поместить его в верхнюю часть b. Ничего не делать, если a пусто.
- sa : swap a — поменять местами первые 2 элемента в верхней части стека a. Ничего не делать, если есть только один элемент или его нет).
- sb : swap b — поменять местами первые 2 элемента в верхней части стека b. Ничего не делать, если есть только один элемент или его нет).
- ss : sa и sb одновременно.
- ra : rotate a - сдвигает вверх все элементы стека a на 1. Первый элемент становится последним.
- rb : rotate b - сдвинуть вверх все элементы стека b на 1. Первый элемент становится последним.
- rr : ra и rb одновременно.
- rra : reverse rotate a - сдвигает вниз все элементы стека a на 1. Последний элемент становится первым.
- rrb : reverse rotate b - сдвинуть вниз все элементы стека b на 1. Последний элемент становится первым.
- rrr : rra и rrb одновременно.

## Алгоритм
Алгоритм состоит на основе быстрой сортировки
1.	Парсинг
-	склеиваем строку по пробелам и расплитовываем по пробелам
-	проверяем что подаются только числа, если попадается что-то иное, то выводится ошибка
-	проверяем числа на повторяемость, если попадаются одинаковые числа, то выводится ошибка
-	проверка на max и min int, если в списке есть числа больше 2147483647 и меньше -2147483648 соотвественно, то выводится ошибка
-	отсортировываем стек
-	прописываем каждому числу его индекс
-	добавляем аргументы в стек а
2.	Сортировка
-	проверяем, если стек отсортирован, то программа завершается
-	пишем команды push/swap/rotate/reverse
- пишем сортировку для 3-х и 5-ти чисел
-	ищем медианы
-	перебросываем в стек б все, что меньше медианы
-	запускаем цикл основного алгоритма, проверяем на отсортированность стека
-	перебрасываем в стек а по поколениям
-	ищем в стеках a и б минимального числа
3.	Чистим стек
-	после сортировки всю память очищаем и выходим
