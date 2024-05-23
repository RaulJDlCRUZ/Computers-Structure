## 1. Experimenta con todo el código que se presentado de ejemplo
### Salidas de cada programa
#### [`ex01`](/Basic%20C/ex01.c)
A firt functional program with variable definition, initialization and arithmetics
```console
sum is 6
```
#### [`ex02`](/Basic%20C/ex02.c)
While loop and use of `getchar()` and `putchar()` functions
```console
bebe
b
e
b
e
```
#### [`ex03`](/Basic%20C/ex03.c)
Use of `printf` function to show variales in different formats
```console
What is the value of 511 in octal notation?
Correct! 511 decimal is 777 octal
```
#### [`ex04`](/Basic%20C/ex04.c)
Transforming letters from capital to lower case
```console
BarajACartaS
barajacartas
```
#### [`ex05`](/Basic%20C/ex05.c)
Counting different types of characters: letters, numbers and other symbols
```console
Mibarajatiene40cartas
19 letters, 2 digits, 0 rest
```
#### [`ex06`](/Basic%20C/ex06.c)
Preincrementing and postincrementing variables
```console
a=6, b=6, x=5 and y=6
```
#### [`ex07`](/Basic%20C/ex07.c)
Using vectors (arrays) of characters (strings)
```console
Estoy hasta la po**a de estudiar c
The string array Estoy hasta la po**a de estudiar cr has 34 elements
```
#### [`ex08`](/Basic%20C/ex08.c)
Copying strings
```console
The string s 'hello' is now copied in the string t 'hello'
```
#### [`ex09`](/Basic%20C/ex09.c)´
Adding the elements of an array
```console
The sum of the elements of the array is equal to 10
```
#### [`ex10`](/Basic%20C/ex10.c)
Initializing a 2D array with two nested for loops
```console
Element [0][0] or array is 0
Element [0][1] or array is 0
Element [0][2] or array is 0
Element [0][3] or array is 0
Element [1][0] or array is 0
Element [1][1] or array is 0
Element [1][2] or array is 0
Element [1][3] or array is 0
Element [2][0] or array is 0
Element [2][1] or array is 0
Element [2][2] or array is 0
Element [2][3] or array is 0
Element [3][0] or array is 0
Element [3][1] or array is 0
Element [3][2] or array is 0
Element [3][3] or array is 0
```
#### [`ex11`](/Basic%20C/ex11.c)
Declaring and using functions
```console
The minimum between 10 and 5 is 5
```
#### [`ex12`](/Basic%20C/ex12.c)
Use of pointers
```console
The variable a is stored in the address 000000000062FE14 and contains the value 10
The pointer b points to the address 000000000062FE14 which contains the value 10
The variable c is stored in the address 000000000062FE10 and contains the value 10
```
#### [`ex13`](/Basic%20C/ex13.c)
Pointers and arrays
```console
The pointer y points to the address 000000000062FE00 which is the first element of the array x
The pointer z also points to the address 000000000062FE00 which is the first element of the array x
The content of x is 'hello'
The content of x is 'hello'
```
#### [`ex14`](/Basic%20C/ex14.c)
Length of an string
```console
The length of the string x 'hello World' is 11
```
#### [`ex15`](/Basic%20C/ex15.c)
A function to swap values of two variables only works if we pass values by reference using pointers
```console
If we pass arguments by value now x is 1 and y is 2
If we pass arguments by reference now x is 2 and y is 1
```
#### [`ex16`](/Basic%20C/ex16.c)
Program with arguments
> It must be executed from the command line as: `./ex16 arg`, where arg is a string of characters such as "FRedRT".
```console
C:\Users\Usuario\Desktop\C_examples>ex16 FRedRT
redrt
```
#### [`ex17`](/Basic%20C/ex17.c)
Use of `switch` case
```console
no se que poner asi que me imagino que es la ruleta de la suerte
The number of a's, b's, c's and other characters is: 5, 0, 0 and 59, respectively
```
#### [`ex18`](/Basic%20C/ex18.c)
Use of structures
```console
The name, age, gender, height and weight of user 0 is: John, 20, M, 1.780000, 72.599998
The name, age, gender, height and weight of user 1 is: Sally, 25, F, 1.650000, 60.299999
```
#### [`ex19`](/Basic%20C/ex19.c)
Use of floating point
```console
The average value of the elments in vector y is: 4.300000
The sum value of the elments in vector y is: 21.500000
```
#### [`ex20`](/Basic%20C/ex20.c)
Passing arguments by value or reference
```console
Address of vpi: 000000000062FDE0
Value of vpi: 0.000000
Address of pi: 000000000062FE1C
Value of pi: 3.140000
Address of vpi: 000000000062FE1C
Value of vpi: 0.000000
Address of pi: 000000000062FE1C
Value of pi: 0.000000
```
#### [`ex21`](/Basic%20C/ex21.c)
Size of different basic data types
```console
Address of c: 000000000062FDEF and address pointed by pc+1: 000000000062FDF0, What is the char size? 1 byte
Address of i: 000000000062FDE8 and address pointed by pi+1: 000000000062FDEC, What is the int size? 4 bytes
Address of f: 000000000062FDE4 and address pointed by pf+1: 000000000062FDE8, What is the float size? 4 bytes
Address of d: 000000000062FDD8 and address pointed by pd+1: 000000000062FDE0, What is the double size? 8 bytes
```
#### [`ex22`](/Basic%20C/ex22.c)
Little Endian or Big Endian?
```console
pi 000000000062FE08, pi+1 000000000062FE0C, i AABBCCDD
pc+1 000000000062FE10, *(pc+) 8
pc+2 000000000062FE11, *(pc+2) FFFFFFFE
pc+3 000000000062FE12, *(pc+3) 62
pc+4 000000000062FE13, *(pc+4) 0
The byte content in the address pc+1 000000000062FE10 is 0000000000000008 and therefore our computer is Little Endian
```
---
## 2. Ejecuta el programa "Hola, mundo"
#### [`helloworld`](/Basic%20C/helloworld.c)
```console
hello world!
```
#### Experimenta con la omisión de partes del programa para ver qué mensajes de error se obtienen
## 3. Escribe un programa que cuente espacios en blanco
Consultar [`white_spaces_counter`](/Basic%20C/white_spaces_counter.c)
```console
hasta los cojines de la vida
It has 5 white spaces
```
## 4. Escribe una función que reciba una cadena de texto y la convierta a minúsculas
Consultar [`string_to_capital`](/Basic%20C/string_to_capital.c)
DALE A LA RULETA
dale a la ruleta
> :warning: Otra solución (Más correcta) es consultar el ejemplo 4: `ex04`
### [`invert_string`](/Basic%20C/invert_string.c)
```console
dalealaruleta
Program Name: invert_string      2 arguments
ateluralaelad
```