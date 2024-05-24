## Gestión de memoria en Arduino Zero

<div align="center">

|Memoria            |Dirección de inicio|Tamaño |
|:------------------|:-----------------:|:-----:|
|Flash interna      | 0x00000000        | 256KB |
|Sección RWW interna| 0x00400000        |   -   |
|SRAM interna       | 0x20000000        | 32KB  |
|Bridge periférico A| 0x40000000        | 64KB  |
|Bridge periférico B| 0x41000000        | 64KB  |
|Bridge periférico C| 0x42000000        | 64KB  |

</div>

### Espacio de direccionamiento

![alt text](/Depuracion%20y%20Memoria/img/cortex-m0-mem.png "Espacio de direccionamiento")

- Único espacio de direccionamiento que engloba a la memoria Flash y la SRAM
- Direcciones de memoria desde 0x00000000 hasta 0xFFFFFFFF
- La pila es LIFO, y sirve para almacenar variables temporales y servir de soporte a llamadas a procediientos cuyos argumentos no pueden ser pasados por registros
- Montículo (heap) comparte región de memoria con la Pila, ambos extremos pueden encontrarse (respuesta inesperada!) $\rightarrow$ referencia a la cabeza de la pila y al montículo para controlar el crecimiento

## Arquitectura Von Neumann

La arquitectura Von Neumann fue establecida por John Von Neumann en 1945. Las instrucciones máquina a ejecutar son almacenadas en una memoria principal (MP) y está compuesta por las siguientes unidades:

- Memoria Principal
- Unidad Aritmética
- Unidad de Control
- Unidad de Entrada/Salida

![alt text](/Depuracion%20y%20Memoria/img/von-neumann.png "Arquitectura Von Neumann")

**Los procesadores de esta arquitectura poseen el mismo dispositivo de almacenamiento tanto para los datos como para las instrucciones**. 

## Arquitectura Harvard

Establecida en 1947 y debe su nombre a la computadora Harvard Mark I basada en relés. Se caracteriza por tener dos memorias principales: una para almacenar las instrucciones y otra para almacenar los datos.

![alt text](/Depuracion%20y%20Memoria/img/harvard.png "Arquitectura Harvard")

## Otras diferencias entre ambas arquitecturas

|Arquitectura Von Neumann|Arquitectura Harvard|
|:--|:--|
|Datos e instrucciones en una misma memoria de lectura/escritura|Datos e instrucciones en memorias caché separadas|
|Se puede diferenciar entre datos e instrucciones al examinar una posición de memoria (Location)|No es necesario discriminar el tipo de dato con el que se está trabajando|
|Los contenidos de memoria son direccionados por su ubicación sin importar el tipo de datos que contengan|Los contenidos de las memorias se direccionan dependiendo del tipo de dato que sea|
|Ejecución secuencial de lectura de la memoria|Ejecución paralela de lectura de instrucciones y datos|

# Demostrar que la plataforma Arduino Zero implementa una arquitectura Harvard

Se va a emplear el código de ejemplo localizado [aquí](/Depuracion%20y%20Memoria/ejemplo_arquitectura_harvard/src/main.cpp)

## Paso 1: Localización de los datos (Variables estáticas y automáticas)

```console
Direccion de a: 200000ac
Direccion de b: 20007f9c
```
Vemos que la variable estática `a` tiene como valor `0x200000ac`, y `b`, la cual es una variable del método `setup()`, tiene como valor `0x20007f9c`, lo que quiere decir que ambas variables se encuentran en la SRAM:
- `a` se encuentra en el principio de la SRAM (globals)
- `b` se encuentra en el final de la SRAM, presumiblemente en la _pila_

## Paso 2: Localización de las instrucciones del programa

Para este paso hay que traducir a lenguaje máquina (disassemble function), traduciendo "main". Posteriormente, se depurará el programa e iniciamos:

![alt text](/Depuracion%20y%20Memoria/img/disassembly.png "Función a Lenguaje Máquina")

También se puede consultar el registro Contador de Programa (PC), que siempre apunta a las próximas instrucciones a ejecutar, y este marca `pc = 0x00002990`.

**Por lo tanto, queda claro que las instrucciones máquina se encuentra en la memoria FLASH del Arduino Zero, ya que estas se encuentran en el principio del espacio de memoria**.

## Conclusión. ¿Harvard o Von Neumann?

Como hemos podido ver, las instrucciones se almacenan en la memoria FLASH y las variables en la SRAM que lleva instalada la placa. **Son memorias diferentes**, por lo que **NO es una arquitectura Von Neumann**, pues si fuera así, datos e instrucciones irían en un mismo espacio de memoria. **USA ARQUITECTURA HARVARD**.

# Demostrar que la plataforma Arduino Zero implementa una estrategia Little Endian

Se refiere a demostrar que el orden en que se guardan en memoria los bytes que componen una palabra es del tipo Little Endian, ya que _existen dos configuraciones_:
- Little endian
    - **El byte más significativo se guarda en las posición de memoria más baja**
    - MSB (Most-Significant Byte), que incluye los bits 24-31 de la palabra, se almacena en la posición de memoria mayor (M+3)
    - Más extendida
- Big endian
    - **El byte más significativo se guarda en las posición de memoria más alta**
    - LSB (Least-Significant Byte), que incluye los 
bits 0-7 de la palabra, se almacena en la 
posición de memoria menor (M+0)

![alt text](/Depuracion%20y%20Memoria/img/little-endian-vs-big-endian.png "Little Endian vs. Big Endian")

EABI permite cualquiera de las dos configuraciones, mas Arduino implementa Little endian, entonces el ejercicio consiste en **demostrarlo**.

Para la demostración, habrá que convertir a lenguaje máquina el código [anterior](/Depuracion%20y%20Memoria/ejemplo_arquitectura_harvard/src/main.cpp), que lo tomaremos **con una modificación en la línea 3, en la que la variable estática `a` toma el valor `1587879870`**:

```c
static int a = 1587879870;
```

Podemos probar a ejecutar el programa, y es posible que cambien las direcciones en comparación con el ejercicio anterior (¡no tiene por qué!):

```console
Direccion de a: 20000000
Direccion de b: 20007fe4
```
> También coincide con los valores en VARIABLES en la interfaz de VS Code: `a_dir`: 0x20000000, `b_dir`: 0x20007fe4

Entonces, tanto `a` como `b` en base 16 son `5E A5 1F BE`
> Cómo se ha hecho? Con el método de las divisiones sucesivas. Sin embargo, un script en C que muestra números enteros en hexadecimas está [aquí](/Depuracion%20y%20Memoria/hexadecimal.c)

Sabiendo esto, primero indicamos al depurador que queremos en 'MEMORY' leer 4 bytes, a partir de `0x20000000` (primera dirección de todas), después se colocará un _breakpoint_ en la línea 14 (a continuación), avanzando la depuración hasta dicho punto:

> Según el ABI, el tipo `int` son 4 bytes

```c 
Serial.print(text);
```

Con la depuración en marcha, obtenemos las direcciones `0x20000000` y `0x20007fe4`, ¡las mismas direcciones de memoria que en la consola de comandos!

Memory [0x20000000+4].dbgmem:
```console
Offset:   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
20000000: BE 1F A5 5E                                     ¾.¥^
```
`5E A5 1F BE = 0101 1110 1010 0101 0001 1111 1011 1110` $_\texttt{2}$
Como se puede comprobar, MSB se almacena en la posición de memoria mayor, en este caso está en el offset `03` (M+3) $\Rightarrow$ posición mayor (_de hecho, el número en sí está escrito de derecha a izquierda_)
> MSB = 0101 1110

Memory [0x20007fe4+4].dbgmem:
```console
Offset:   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
20007fe0:             BE 1F A5 5E                                     ¾.¥^
```

Por tanto, **Arduino Zero emplea Little Endian**

# Demostrar que el compilador inicializa a 0 las variables estáticas o globales no inicializadas

De nuevo, vamos a tomar el ejemplo de la arquitectura Harvard (encontrado [aquí](/Depuracion%20y%20Memoria/ejemplo_arquitectura_harvard/src/main.cpp)) sin la modificación de la sección anterior.

> De hecho, se tomarán como ejemplo las direcciones de memoria `a_dir`: 0x20000000, `b_dir`: 0x20007fe4

Entonces, se proponer depurar el programa en `setup()`, y en el `sprintf()`, ya que en ese punto `b` ya se habrá asignado a 1587879870. El resto del procedimiento será igual al apartado anterior:

### Breakpoint en `setup()`

Memory [0x20000000+4].dbgmem: (variable `a` con localización `a_dir`)
```console
Offset:   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
20000000:                                     00 00 00 00           ...
```

Memory [0x20007fe4+4].dbgmem: (variable `b` con localización `b_dir`)
```console
Offset:   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
20007fe0:             FF FF FF FF                                   ...
```

> Donde `FF FF FF FF` es un valor basura de la pila; puede ser cualquier valor hexadecimal
 
### Breakpoint en `sprintf()`

Memory [0x20000000+4].dbgmem: (variable `a` con localización `a_dir`)
```console
Offset:   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
20000000:                                     00 00 00 00           ...
```

Memory [0x20007fe4+4].dbgmem: (variable `b` con localización `b_dir`)
```console
Offset:   00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 
20007fe0:             BE 1F A5 5E                                     ¾.¥^
```

Como se puede ver, la variable `a` se mantiene en `00 00 00 00`, ya que no ha sido inicializada en ningún momento en el código, mientras que `b` ya tomó el valor esperado: 1587879870 (5E A5 1F BE, en los extractos anteriores al revés al ser Little Endian)

# Demuestra que el puntero de pila crece a partir del límite superior de la SRAM hacia posiciones de memoria descendentes

Para este ejercicio, se requiere un código que consista de un bucle, por lo que se adjuntará un [ejemplo muy sencillo](/Depuracion%20y%20Memoria/IncrementadorRegistro/src/main.cpp)

Entonces, lo que se hará en este ejercicio es ejecutar paso a paso el código proporcionado, poniendo especial atención al Stack Pointer (SP), a través de la depuración:

```console
REGISTERS
sp = 0x20007ff0
sp = 0x20007fe8
sp = 0x20007fd8
sp = 0x20007fe8
sp = 0x20007fd8
```

El comportamiento por cada iteración resulta muy interesante, ya que aparentemente el registro va para atrás y para alante (oscila entre `0x20007fe8` y `0x20007fd8`), junto con el código de depuración `wiring_digital.c`. Tras hacer el `while` (mucho tiempo), llega al código `main.cpp`, donde el registro SP se queda permanentemente en `0x20007ff0`.

Entonces, con esto podemos entender lo siguiente:
- El registro SP está inicializado a la dirección `0x20007fe8`, donde escribirá el primer valor
- Alterna entre `0x20007fe8` y `0x20007fd8`
    - El puntero aumenta a valores más bajos (_o decrecientes_), pero el puntero se mantendrá en `0x20007ff0`

Por ello, podemos decir que el **puntero de la pila avanza en posiciones descendientes, pese a que sus valores sean oscilantes dentro de "Stack"** (ver Arduino Memory Layout)
