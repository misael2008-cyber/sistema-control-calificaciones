# Sistema de control de calificaciones de un centro educativo

## Datos del estudiante

- **Nombre completo:** Misael Efraín de los Santos
- **Matrícula:** 2026-2026
- **Asignatura:** Lógica de Programación
- **Profesor:** Gamalier Reyes del Carmen
- **Tema:** Uso de bucles en C++: sistema de control de calificaciones
- **Fecha de elaboración:** 18 de noviembre de 2026

## Descripción del programa

Este es un programa de consola en **C++** para el centro educativo ficticio **La Nueva Escuela**. Permite ingresar un grupo de estudiantes, registrar cuatro calificaciones por estudiante, calcular su promedio y determinar si ha aprobado o reprobado. Al concluir, presenta el resumen del grupo y da la opción de procesar otro grupo.

El programa utiliza únicamente las bibliotecas estándar autorizadas en la tarea: `<iostream>`, `<string>` y `<iomanip>`. No utiliza arreglos, vectores, `goto`, `break`, `continue` ni funciones propias adicionales a `main()`.

## Datos de entrada

1. Cantidad de estudiantes del grupo: número entero mayor que **0**.
2. Nombre de cada estudiante: texto no vacío (puede incluir espacios).
3. **Cuatro** calificaciones por estudiante: números entre **0 y 100**, inclusive; se aceptan decimales escritos con punto.
4. Respuesta al finalizar: **s** para otro grupo o **n** para terminar; también se aceptan mayúsculas.

## Proceso

1. Pedir y validar la cantidad de estudiantes; si es inválida, volver a solicitarla.
2. Para cada estudiante, solicitar el nombre y las cuatro notas. Si una nota es inválida, repetir **solamente esa nota**.
3. Acumular las cuatro notas y obtener el promedio de cada estudiante mediante `sumaNotas / 4.0`.
4. Clasificar como **Aprobado** si su promedio es mayor o igual a **70.00** y como **Reprobado** en otro caso.
5. Contabilizar aprobados y reprobados, y sumar los promedios individuales.
6. Obtener el promedio general mediante `sumaPromedios / cantidadEstudiantes` y conservar el nombre y promedio del estudiante que alcanzó el valor más alto.
7. Mostrar el resumen y decidir si se procesa otro grupo. Los contadores y acumuladores se reinician para cada grupo nuevo.

## Datos de salida

- Promedio individual de cada estudiante con **dos decimales**.
- Estado de cada estudiante: **Aprobado** o **Reprobado**.
- Cantidad total de aprobados y reprobados del grupo.
- Promedio general del grupo con **dos decimales**.
- Nombre y promedio de quien obtuvo el promedio más alto.
- Mensajes de validación y opción para repetir el programa.

## Bucles utilizados y explicación

| Tipo de bucle | Dónde se usa | Por qué se usa |
| --- | --- | --- |
| `do...while` | Bucle principal de grupos | Ejecuta el sistema al menos una vez y lo repite cuando se responde `s`. |
| `do...while` | Validación de cantidad de estudiantes | Repite la solicitud hasta recibir un entero mayor que cero. |
| `for` | Recorrido de estudiantes | Ejecuta el registro exactamente tantas veces como estudiantes haya en el grupo. |
| `do...while` | Validación del nombre | Evita registrar un nombre vacío. |
| `for` | Recorrido de calificaciones | Solicita exactamente cuatro notas por estudiante. |
| `do...while` | Validación de cada calificación | Repite la nota actual hasta que esté entre 0 y 100. |
| `do...while` | Validación de la respuesta final | Solo acepta `s` o `n` antes de repetir o cerrar el programa. |

Los bucles `for` controlan cantidades conocidas de repeticiones. Los `do...while` se utilizan cuando la cantidad de intentos no se conoce de antemano, porque depende de la validez de la entrada o de la decisión del usuario.

## Variables principales

- `cantidadEstudiantes`: tamaño del grupo.
- `numeroEstudiante` y `numeroNota`: contadores de los bucles `for`.
- `sumaNotas`: acumulador de las cuatro calificaciones de un estudiante.
- `promedioEstudiante`: promedio individual.
- `aprobados` y `reprobados`: contadores de resultados.
- `sumaPromedios`: acumulador de los promedios individuales.
- `promedioGrupo`: promedio general del grupo.
- `mejorPromedio` y `nombreMejorEstudiante`: datos del estudiante con mejor promedio.

## Compilación y ejecución

Se necesita un compilador de C++ compatible con **C++11** o posterior.

**En Linux o macOS, con g++:**

```bash
g++ -std=c++11 -Wall -Wextra -Wpedantic control_calificaciones.cpp -o control_calificaciones
./control_calificaciones
```

**En Windows, con g++ (MinGW):**

```bash
g++ -std=c++11 control_calificaciones.cpp -o control_calificaciones.exe
control_calificaciones.exe
```

No se requiere conexión a Internet ni instalación de librerías externas.

## Capturas de pantalla de las pruebas

Todas las imágenes corresponden a **ejecuciones reales del programa compilado**, capturadas directamente de la ventana de consola, sin incluir el escritorio completo.

### Prueba 1 — Grupo de dos estudiantes aprobados

Se ingresan Ana (90, 85, 80, 85) y Pedro (80, 85, 80, 75). Se obtiene: **2 aprobados**, **0 reprobados**, promedio general **82.50** y mejor promedio **Ana (85.00)**.

![Prueba 1: grupo con dos estudiantes aprobados](capturas/prueba_01.png)

### Prueba 2 — Validaciones y promedio mínimo para aprobar

Se comprueba que el sistema rechaza cantidades inválidas (`0`, letras y números negativos), nombres vacíos, notas fuera de rango (`-5` y `101`) y una nota escrita con letras. Finalmente registra a Carla con cuatro notas de 70 y la clasifica como **Aprobado (70.00)**.

![Prueba 2: validación de entradas y calificaciones](capturas/prueba_02.png)

### Prueba 3 — Repetir grupos y calificaciones límite

Se procesa un primer grupo con José (cuatro notas de 100), se rechaza una respuesta distinta de `s/n`, se elige `s` y se procesa un segundo grupo con María Elena (cuatro notas de 0). Se comprueba el reinicio del resumen y el cierre al responder `n`.

![Prueba 3: procesamiento de dos grupos](capturas/prueba_03.png)

## Estructura de los archivos

```text
Sistema_Control_Calificaciones_Misael/
├── control_calificaciones.cpp
├── README.md
├── PORTADA.pdf
├── EVIDENCIAS.pdf
├── PRUEBAS.txt
└── capturas/
    ├── prueba_01.png
    ├── prueba_02.png
    └── prueba_03.png
```

**Nota de publicación:** Los archivos y el repositorio Git local quedan preparados. El enlace público de GitHub se incorpora después de publicar el repositorio; no se incluye una dirección inventada.
