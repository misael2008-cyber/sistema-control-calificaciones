#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string respuestaOtroGrupo = "s";

    cout << fixed << setprecision(2);
    cout << "==============================================\n";
    cout << "  LA NUEVA ESCUELA - CONTROL DE CALIFICACIONES\n";
    cout << "==============================================\n";

    // Bucle do-while principal: permite procesar varios grupos hasta elegir 'n'.
    do {
        int cantidadEstudiantes = 0;
        bool cantidadValida = false;
        string entradaCantidad;
        size_t caracteresLeidos = 0;

        // Bucle do-while de validacion: exige una cantidad entera mayor que cero.
        do {
            cout << "\nCantidad de estudiantes: ";
            if (!getline(cin, entradaCantidad)) {
                return 0;
            }

            cantidadValida = false;
            try {
                cantidadEstudiantes = stoi(entradaCantidad, &caracteresLeidos);
                cantidadValida = (caracteresLeidos == entradaCantidad.length()
                                  && cantidadEstudiantes > 0);
            } catch (...) {
                cantidadValida = false;
            }

            if (!cantidadValida) {
                cout << "Error: ingrese un numero entero mayor que 0.\n";
            }
        } while (!cantidadValida);

        int aprobados = 0;
        int reprobados = 0;
        double sumaPromedios = 0.0;
        double mejorPromedio = 0.0;
        string nombreMejorEstudiante;

        // Bucle for: recorre una sola vez a cada estudiante del grupo.
        for (int numeroEstudiante = 1; numeroEstudiante <= cantidadEstudiantes;
             numeroEstudiante++) {
            string nombreEstudiante;
            double sumaNotas = 0.0;

            cout << "\n--- Estudiante " << numeroEstudiante << " ---\n";

            // Bucle do-while: no permite dejar vacio el nombre del estudiante.
            do {
                cout << "Nombre: ";
                if (!getline(cin, nombreEstudiante)) {
                    return 0;
                }
                if (nombreEstudiante.empty()) {
                    cout << "Error: el nombre no puede estar vacio.\n";
                }
            } while (nombreEstudiante.empty());

            // Bucle for: solicita exactamente cuatro calificaciones por estudiante.
            for (int numeroNota = 1; numeroNota <= 4; numeroNota++) {
                double calificacion = 0.0;
                bool notaValida = false;
                string entradaNota;
                size_t caracteresNota = 0;

                // Bucle do-while: repite solo la calificacion que no este entre 0 y 100.
                do {
                    cout << "Calificacion " << numeroNota << ": ";
                    if (!getline(cin, entradaNota)) {
                        return 0;
                    }

                    notaValida = false;
                    try {
                        calificacion = stod(entradaNota, &caracteresNota);
                        notaValida = (caracteresNota == entradaNota.length()
                                      && calificacion >= 0.0
                                      && calificacion <= 100.0);
                    } catch (...) {
                        notaValida = false;
                    }

                    if (!notaValida) {
                        cout << "Error: ingrese una calificacion entre 0 y 100.\n";
                    }
                } while (!notaValida);

                sumaNotas += calificacion;
            }

            double promedioEstudiante = sumaNotas / 4.0;
            sumaPromedios += promedioEstudiante;

            if (promedioEstudiante >= 70.0) {
                aprobados++;
                cout << "Promedio: " << promedioEstudiante << " - Aprobado\n";
            } else {
                reprobados++;
                cout << "Promedio: " << promedioEstudiante << " - Reprobado\n";
            }

            if (numeroEstudiante == 1 || promedioEstudiante > mejorPromedio) {
                mejorPromedio = promedioEstudiante;
                nombreMejorEstudiante = nombreEstudiante;
            }
        }

        double promedioGrupo = sumaPromedios / cantidadEstudiantes;
        cout << "\n===== RESUMEN =====\n";
        cout << "Aprobados: " << aprobados
             << " | Reprobados: " << reprobados << "\n";
        cout << "Promedio del grupo: " << promedioGrupo << "\n";
        cout << "Mejor promedio: " << nombreMejorEstudiante
             << " (" << mejorPromedio << ")\n";

        bool respuestaValida = false;

        // Bucle do-while: obliga a responder s/n antes de continuar o terminar.
        do {
            cout << "\nDesea procesar otro grupo? (s/n): ";
            if (!getline(cin, respuestaOtroGrupo)) {
                return 0;
            }
            respuestaValida = (respuestaOtroGrupo == "s" || respuestaOtroGrupo == "S"
                               || respuestaOtroGrupo == "n" || respuestaOtroGrupo == "N");
            if (!respuestaValida) {
                cout << "Error: responda solamente s o n.\n";
            }
        } while (!respuestaValida);

    } while (respuestaOtroGrupo == "s" || respuestaOtroGrupo == "S");

    cout << "\nPrograma finalizado. Gracias por usar el sistema.\n";
    return 0;
}
