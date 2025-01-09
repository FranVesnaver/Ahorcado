# Ahorcado
## Descripción
Un juego del ahorcado desarrollado mientras estudiaba para Introducción a la Algorítmica, el cual retomo un año más tarde para aplicar algunos de los conceptos que aprendí cursando el segundo año de la Licenciatura en Ciencias de la Computación de la UNRC.
## Juego del Ahorcado
El juego consiste en adivinar una palabra dada su cantidad de letras. Para esto podemos "tirar" una letra o "arriesgar" intentando adivinar la palabra. Al tirar una letra, si la palabra contiene la letra que tiramos se revela su posición en ella, y si no la tiene perdemos una vida. Al perder las 5 vidas que tenemos o al arriesgar la palabra y fallar, perdimos el juego. Si adivinamos la palabra al arriesgar o tiramos correctamente todas sus letras, ganamos el juego.
## Retomando el proyecto
La idea de retomar el proyecto es, en primer lugar que quede registrado y guardado en gitHub en lugar de estar tirado en mi compu y que eventualmente se pierda. En segundo lugar, es un proyecto ya iniciado que puedo usar para aplicar cosas que fui aprendiendo, de manera rápida y sin tener que arrancar algo de cero. 

---
### v1.0 [^1]
- El juego está totalmente funcional y listo para jugarlo en la consola
- Tiene 20 palabras pero organizadas de una forma horrible, la idea es mejorar esto guardandolas en un arreglo

### v1.0.1
- Se hizo una reestructuración del código para organizarlo mejor
- Ahora el juego va limpiando la consola a medida que se ejecuta

### v1.0.2
- Se refactorizó el código para cambiar la forma en que se eligen las palabras de forma aleatoria
- Ahora se utiliza un arreglo predefinido que contiene las cadenas con las palabras en lugar de una función con un switch
- De esta forma tenemos un código más limpio, más eficiente, y una mejor forma de agregar palabras al juego
- Para eso simplemente agregamos la nueva palabra al arreglo e incrementamos la variable 'cant'

[^1]: **Nota:** Arranco desde la v1.0 porque el juego técnicamente está terminado, es como dejé lo dejé en Enero de 2024
