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
> :warning: PREGUNTA 1 en Prueba de Laboratorio - Parte 2 de Ordinaria (0,5 puntos)

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
    ...
```

El comportamiento por cada iteración resulta muy interesante, ya que aparentemente el registro va para atrás y para alante (oscila entre `0x20007fe8` y `0x20007fd8`), junto con el código de depuración `wiring_digital.c`. Tras hacer el `while` (mucho tiempo), llega al código `main.cpp`, donde el registro SP se queda permanentemente en `0x20007ff0`.

Entonces, con esto podemos entender lo siguiente:
- El registro SP está inicializado a la dirección `0x20007fe8`, donde escribirá el primer valor
- Alterna entre `0x20007fe8` y `0x20007fd8`
    - El puntero aumenta a valores más bajos (_o decrecientes_), pero el puntero se mantendrá en `0x20007ff0`

Por ello, podemos decir que el **puntero de la pila avanza en posiciones descendientes, pese a que sus valores sean oscilantes dentro de "Stack"** (ver Arduino Memory Layout)

# Trabajo autónomo en Lenguaje máquina en Arduino

Para el caso, se empleará una versión del "Hola Mundo!" en bucle, que se puede encontrar [aquí](/Depuracion%20y%20Memoria/Lenguaje_Maquina_Hola/src/main.cpp)

## Descomposición del programa en lenguaje máquina

### setup.dbgasm (`void setup()`)

```asm
0x00002118: 10 b5           	push	{r4, lr}
0x0000211a: 96 21           	movs	r1, #150	; 0x96
0x0000211c: 89 01           	lsls	r1, r1, #6
0x0000211e: 02 48           	ldr	r0, [pc, #8]	; (0x2128 <setup()+16>)
0x00002120: 00 f0 8c f9     	bl	0x243c <Uart::begin(unsigned long)>
0x00002124: 10 bd           	pop	{r4, pc}
0x00002126: c0 46           	nop			; (mov r8, r8)
0x00002128: ac 00           	lsls	r4, r5, #2
0x0000212a: 00 20           	movs	r0, #0
```

### main.dbgasm (`main`)

```asm
0x00002ae0: 10 b5           	push	{r4, lr}
0x00002ae2: 00 f0 e3 f8     	bl	0x2cac <init>
0x00002ae6: 02 f0 99 f9     	bl	0x4e1c <__libc_init_array>
0x00002aea: ff f7 f8 ff     	bl	0x2ade <initVariant()>
0x00002aee: 01 20           	movs	r0, #1
0x00002af0: ff f7 ca ff     	bl	0x2a88 <delay>
0x00002af4: 08 4c           	ldr	r4, [pc, #32]	; (0x2b18 <main()+56>)
0x00002af6: 20 00           	movs	r0, r4
0x00002af8: 00 f0 2e fc     	bl	0x3358 <USBDeviceClass::init()>
0x00002afc: 20 00           	movs	r0, r4
0x00002afe: 00 f0 fb fc     	bl	0x34f8 <USBDeviceClass::attach()>
0x00002b02: ff f7 09 fb     	bl	0x2118 <setup()>
0x00002b06: ff f7 f9 fa     	bl	0x20fc <loop()>
0x00002b0a: 04 4b           	ldr	r3, [pc, #16]	; (0x2b1c <main()+60>)
0x00002b0c: 00 2b           	cmp	r3, #0
0x00002b0e: fa d0           	beq.n	0x2b06 <main()+38>
0x00002b10: 00 e0           	b.n	0x2b14 <main()+52>
0x00002b12: 00 bf           	nop
0x00002b14: f7 e7           	b.n	0x2b06 <main()+38>
0x00002b16: c0 46           	nop			; (mov r8, r8)
0x00002b18: 7c 02           	lsls	r4, r7, #9
0x00002b1a: 00 20           	movs	r0, #0
0x00002b1c: 00 00           	movs	r0, r0
0x00002b1e: 00 00           	movs	r0, r0
```

### loop.dbgasm (`void loop()`)

```asm
0x000020fc: 10 b5           	push	{r4, lr}
0x000020fe: 04 49           	ldr	r1, [pc, #16]	; (0x2110 <loop()+20>)
0x00002100: 04 48           	ldr	r0, [pc, #16]	; (0x2114 <loop()+24>)
0x00002102: 00 f0 22 fc     	bl	0x294a <arduino::Print::print(char const*)>
0x00002106: fa 20           	movs	r0, #250    ; 0xfa
0x00002108: 80 00           	lsls	r0, r0, #2
0x0000210a: 00 f0 bd fc     	bl	0x2a88 <delay>
0x0000210e: 10 bd           	pop	{r4, pc}
0x00002110: 6c 50           	str	r4, [r5, r1]
0x00002112: 00 00           	movs	r0, r0
0x00002114: ac 00           	lsls	r4, r5, #2
0x00002116: 00 20           	movs	r0, #0
```

## Identifica una instrucción que utilice un modo de direccionamiento relativo al contador de programa

Las instrucciones de direccionamiento relativo son aquellas con la etiqueta `ldr`:

|`setup`   |`main`    |`loop`    |
|----------|----------|----------|
|0x0000211e|0x00002af4|0x000020fe|
|          |0x00002b0a|0x00002100|

> Ejemplo visual: `ldr	r1, [pc, #16]	; (0x2110 <loop()+20>)`
---
`LDR <Rt>, [PC, #immed8];`

Word read: Lee un dato en memoria y lo carga en un registro. Utiliza un direccionamiento con desplazamiento. Utiliza un direccionamiento con desplazamiento relativo al contador de programa. Es decir: se trata una instrucción de **carga a un registro**, más concretamente, carga un valor en el registro `r1`. El segundo operando de esta instrucción se trata de un operando relativo al contador de programa, con un desplazamiento de 16 bits.

## Siguiendo la traza de ejecución del programa, identifica una instrucción en ensamblador que se corresponda con una bifurcación condicional y coméntala

> :warning: PREGUNTA 2 en Prueba de Laboratorio - Parte 2 de Ordinaria (0,5 puntos)

Un ejemplo de bifurcación condicional se encuentra en el código `main.dbgasm`, concretamente la instrucción `0x00002b0e`:

```asm
0x00002b0e: fa d0           	beq.n	0x2b06 <main()+38>
```

Esta instrucción quiere decir que si el bit N está activado se salta a la dirección de memoria `0x2b06`...de acuerdo al manual de Estructura de computadores, con ISBN = 978-84-9044-411-5.

Sin embargo, también podría ser que el `.n` simplemente se trata de un sufijo de 16-bits Thumb ("narrow"), lo cual quiere decir que _es una versión de tamaño corto o compacta de la instrucción_ (palabra de 16 bits), común en arquitecturas compactas ARM, como la es la del Arduino Zero. ¿Y de qué instrucción es la versión compacta? De **branch if-equal**, es decir, el flujo del programa saltará a una dirección específica si dos registros son _iguales_.

Esto último tiene relación con la instrucción inmediatamente anterior:

```asm
0x00002b0c: 00 2b           	cmp	r3, #0
```

Esta instrucción compara el contenido del registro `r3` con el valor inmediato `0`. El resultado de esta comparación se almacena por medio de flags en el procesador. La más interesante para el caso es (Z): "indicador de cero". Esta se activa si `r3` _es igual_ a `0`.

Entonces, `beq.n` comprueba si esta flag se activó, para decidir si saltar o no a la dirección de memoria en cuestión.

**CONCLUSIÓN:**`cmp` compara el valor de `r3` con `0`, y si resulta que son _iguales_(`beq.n`), entonces salta a la dirección `0x2b06`, es decir, a `<main()+38>`. **Esto es un salto condicional en toda regla**.

## Identifica una instrucción que utilice un operando con direccionamiento relativo al stack pointer (SP)

**En el código ensamblador obtenido no se ha localizado un operando del estilo**, sin embargo, un ejemplo de este se sugiere de la siguiente forma:

```asm
0x2748 ldr r3, [sp, #4]
```

Donde, en lugar de encontrarse el Contador de Programa (PC), se considera el Stack Pointer (SP)

## Identifica un fragmento de código ensamblador que se corresponda con un bucle y analízalo

Para este ejercicio, el código empleado será diferente. Será un incrementador de registro como vimos anteriormente. El código empleado se encuentra [aquí](/Depuracion%20y%20Memoria/Lenguaje_Maquina_Bucle/src/main.cpp)

### Traducción a lenguaje máquina

```asm
0x000020fc: 00 23           	movs	r3, #0
0x000020fe: 09 2b           	cmp	r3, #9
0x00002100: 01 dc           	bgt.n	0x2106 <loop()+10>
0x00002102: 01 33           	adds	r3, #1
0x00002104: fb e7           	b.n	0x20fe <loop()+2>
0x00002106: 70 47           	bx	lr
```
### Análisis
```asm
0x000020fc: 00 23           	movs	r3, #0				
```

Inicializa la variable `i`. Mueve un registro a otro registro y actualiza el APSR o registro de estado al mismo tiempo.

```asm
0x000020fe: 09 2b           	cmp	r3, #9				
```

Compara la variable con el valor 9
```asm
0x00002100: 01 dc           	bgt.n	0x2106 <loop()+10>	
```

Se salta a `0x00002106 <loop()+10>` si dicha variable es mayor ("greater than") que 9, de ser así se sale del bucle (`0x2106`: última instrucción). De nuevo, el sufijo `.n` significa palabra de 16 bits. NO ES RELEVANTE.

```asm
0x00002102: 01 33           	adds	r3, #1				
```

Incrementa en 1 la variable `i`: `ADDS <Rd>, <Rn>, #immed3` Suma un valor inmediato a un registro.

```asm
0x00002104: fb e7           	b.n	0x20fe <loop()+2>
```

Vuelve sí o sí al principio del bucle `for` (label `20fe`)

```asm
0x00002106: 70 47           	bx	lr				
```

Se sale del `loop`. `BX` $\rightarrow$ Bifurcación a una dirección especificada en un registro cambiando el estado del procesador dependiendo del bit 0 del registro.
