# PRACTICA 9: Forma Normal de Chomsky de una Gramática Independiente del Contexto

## 9.1. Objetivos
- Consolidar los conocimientos adquiridos sobre Gramáticas.
- Estudiar y practicar el algoritmo de transformación de una gramática a su forma normal de Chomsky.
- Ampliar las funcionalidades definidas en la clase que se ha desarrollado para representar Gramáticas.
- Profundizar en las capacidades de diseñar y desarrollar programas orientados a objetos en C++.

## 9.3. Ejercicio práctico

Desarrollar un programa G2CNF.cpp que lea un fichero de texto en el que figura la
especificación de una Gramática Independiente del Contexto que no contenga sı́mbolos
ni producciones inútiles, unitarias ni vacı́as, y genere otro fichero de texto en el que se
especifique una gramática equivalente (L(G in ) = L(G out )) a la de entrada, escrita en
Forma Normal de Chomsky.
El comportamiento del programa al ejecutarse en lı́nea de comandos debiera ser:
```terminal
$ ./G2CNF
Modo de empleo: ./G2CNF input.gra output.gra
Pruebe ‘G2CNF --help’ para más información.
```
Donde input.gra y output.gra son los ficheros que especifican las gramáticas de
entrada y salida respectivamente. La opción --help en lı́nea de comandos ha de producir
que se imprima en pantalla un breve texto explicativo del funcionamiento del programa.
Los ficheros de especificación de gramáticas son ficheros de texto plano con
extensión .gra que contienen los elementos definitorios de la Gramática G ≡ (Σ, V,
S, P) en este orden: sı́mbolos terminales, sı́mbolos no terminales, sı́mbolo de arranque
y producciones. El formato de cada uno de estos elementos en el fichero es el siguiente:
1. Sı́mbolos terminales (alfabeto): una lı́nea que contiene N, el número de sı́mbolos
en el alfabeto seguida de N lı́neas, cada una de las cuales contiene un sı́mbolo del
alfabeto. Cada sı́mbolo del alfabeto debe ser un único caracter imprimible.
2. Conjunto de sı́mbolos no terminales: una lı́nea que contiene V, el número de
sı́mbolos no terminales, seguida de V lı́neas, cada una de las cuales contiene una
cadena alfanumérica sin espacios.
3. Sı́mbolo de arranque: una única lı́nea que contiene el sı́mbolo de arranque,
S, de la gramática. Ha de ser uno de los sı́mbolos no terminales relacionados
anteriormente.
4. Producciones: una lı́nea que contiene P, el número de producciones de la
gramática, seguida por P lı́neas cada una de las cuales contiene una producción
en el formato:
A -> α
siendo α ∈ (Σ∪V ) ∗ , es decir una secuencia de sı́mbolos terminales y no terminales.
La cadena vacı́a,  se representa mediante el carácter ~ (código ASCII 126).
Todas las lı́neas de un fichero .gra que comiencen con los caracteres // corresponden
a comentarios, y deben ser ignorados por el programa a la hora de procesar el fichero.