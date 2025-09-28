#include "biblioteca.h"

int main() {
  BibliotecaDB biblioteca;
  int opcion;

  cout << "Bienvenido al Sistema de Gestion de Biblioteca" << endl;
  cout << "Cargando datos existentes..." << endl;

  do {
    biblioteca.mostrarMenu();
    cin >> opcion;
    cin.ignore(); // Limpiar el buffer de entrada

    switch (opcion) {
    case 1: { // Agregar Autor
      string nombre, nacionalidad;
      cout << "\n=== AGREGAR AUTOR ===" << endl;
      cout << "Nombre: ";
      getline(cin, nombre);
      cout << "Nacionalidad: ";
      getline(cin, nacionalidad);
      biblioteca.agregarAutor(nombre, nacionalidad);
      biblioteca.pausar();
      break;
    }

    case 2: { // Listar Autores
      biblioteca.listarAutores();
      biblioteca.pausar();
      break;
    }

    case 3: { // Buscar Autor por ID
      int id;
      cout << "\n=== BUSCAR AUTOR POR ID ===" << endl;
      cout << "ID del autor: ";
      cin >> id;
      biblioteca.buscarAutorPorId(id);
      biblioteca.pausar();
      break;
    }

    case 4: { // Actualizar Autor
      int id;
      string nombre, nacionalidad;
      cout << "\n=== ACTUALIZAR AUTOR ===" << endl;
      cout << "ID del autor: ";
      cin >> id;
      cin.ignore();
      cout << "Nuevo nombre: ";
      getline(cin, nombre);
      cout << "Nueva nacionalidad: ";
      getline(cin, nacionalidad);
      biblioteca.actualizarAutor(id, nombre, nacionalidad);
      biblioteca.pausar();
      break;
    }

    case 5: { // Eliminar Autor
      int id;
      cout << "\n=== ELIMINAR AUTOR ===" << endl;
      cout << "ID del autor: ";
      cin >> id;
      biblioteca.eliminarAutor(id);
      biblioteca.pausar();
      break;
    }

    case 6: { // Agregar Estudiante
      string nombre, grado;
      cout << "\n=== AGREGAR ESTUDIANTE ===" << endl;
      cout << "Nombre: ";
      getline(cin, nombre);
      cout << "Grado: ";
      getline(cin, grado);
      biblioteca.agregarEstudiante(nombre, grado);
      biblioteca.pausar();
      break;
    }

    case 7: { // Listar Estudiantes
      biblioteca.listarEstudiantes();
      biblioteca.pausar();
      break;
    }

    case 8: { // Buscar Estudiante por ID
      int id;
      cout << "\n=== BUSCAR ESTUDIANTE POR ID ===" << endl;
      cout << "ID del estudiante: ";
      cin >> id;
      biblioteca.buscarEstudiantePorId(id);
      biblioteca.pausar();
      break;
    }

    case 9: { // Actualizar Estudiante
      int id;
      string nombre, grado;
      cout << "\n=== ACTUALIZAR ESTUDIANTE ===" << endl;
      cout << "ID del estudiante: ";
      cin >> id;
      cin.ignore();
      cout << "Nuevo nombre: ";
      getline(cin, nombre);
      cout << "Nuevo grado: ";
      getline(cin, grado);
      biblioteca.actualizarEstudiante(id, nombre, grado);
      biblioteca.pausar();
      break;
    }

    case 10: { // Eliminar Estudiante
      int id;
      cout << "\n=== ELIMINAR ESTUDIANTE ===" << endl;
      cout << "ID del estudiante: ";
      cin >> id;
      biblioteca.eliminarEstudiante(id);
      biblioteca.pausar();
      break;
    }

    case 11: { // Agregar Libro
      string titulo, isbn;
      int ano, id_autor;
      cout << "\n=== AGREGAR LIBRO ===" << endl;
      cout << "Titulo: ";
      getline(cin, titulo);
      cout << "ISBN: ";
      getline(cin, isbn);
      cout << "Ano: ";
      cin >> ano;
      cout << "ID del autor: ";
      cin >> id_autor;
      biblioteca.agregarLibro(titulo, isbn, ano, id_autor);
      biblioteca.pausar();
      break;
    }

    case 12: { // Listar Libros
      biblioteca.listarLibros();
      biblioteca.pausar();
      break;
    }

    case 13: { // Buscar Libro por ID
      int id;
      cout << "\n=== BUSCAR LIBRO POR ID ===" << endl;
      cout << "ID del libro: ";
      cin >> id;
      biblioteca.buscarLibroPorId(id);
      biblioteca.pausar();
      break;
    }

    case 14: { // Buscar Libros por Autor
      int id_autor;
      cout << "\n=== BUSCAR LIBROS POR AUTOR ===" << endl;
      cout << "ID del autor: ";
      cin >> id_autor;
      biblioteca.buscarLibrosPorAutor(id_autor);
      biblioteca.pausar();
      break;
    }

    case 15: { // Actualizar Libro
      int id, ano, id_autor;
      string titulo, isbn;
      cout << "\n=== ACTUALIZAR LIBRO ===" << endl;
      cout << "ID del libro: ";
      cin >> id;
      cin.ignore();
      cout << "Nuevo titulo: ";
      getline(cin, titulo);
      cout << "Nuevo ISBN: ";
      getline(cin, isbn);
      cout << "Nuevo ano: ";
      cin >> ano;
      cout << "Nuevo ID del autor: ";
      cin >> id_autor;
      biblioteca.actualizarLibro(id, titulo, isbn, ano, id_autor);
      biblioteca.pausar();
      break;
    }

    case 16: { // Eliminar Libro
      int id;
      cout << "\n=== ELIMINAR LIBRO ===" << endl;
      cout << "ID del libro: ";
      cin >> id;
      biblioteca.eliminarLibro(id);
      biblioteca.pausar();
      break;
    }

    case 17: { // Realizar Prestamo
      int id_libro, id_estudiante;
      cout << "\n=== REALIZAR PRESTAMO ===" << endl;
      cout << "ID del libro: ";
      cin >> id_libro;
      cout << "ID del estudiante: ";
      cin >> id_estudiante;
      biblioteca.realizarPrestamo(id_libro, id_estudiante);
      biblioteca.pausar();
      break;
    }

    case 18: { // Devolver Libro
      int id_prestamo;
      cout << "\n=== DEVOLVER LIBRO ===" << endl;
      cout << "ID del prestamo: ";
      cin >> id_prestamo;
      biblioteca.devolverLibro(id_prestamo);
      biblioteca.pausar();
      break;
    }

    case 19: { // Listar Prestamos
      biblioteca.listarPrestamos();
      biblioteca.pausar();
      break;
    }

    case 20: { // Buscar Prestamos por Estudiante
      int id_estudiante;
      cout << "\n=== BUSCAR PRESTAMOS POR ESTUDIANTE ===" << endl;
      cout << "ID del estudiante: ";
      cin >> id_estudiante;
      biblioteca.buscarPrestamosPorEstudiante(id_estudiante);
      biblioteca.pausar();
      break;
    }

    case 21: { // Libros Prestados por Estudiante
      int id_estudiante;
      cout << "\n=== LIBROS PRESTADOS POR ESTUDIANTE ===" << endl;
      cout << "ID del estudiante: ";
      cin >> id_estudiante;
      biblioteca.listarLibrosPrestadosPorEstudiante(id_estudiante);
      biblioteca.pausar();
      break;
    }

    case 22: { // Autores con Mas Libros
      biblioteca.autoresConMasLibros();
      biblioteca.pausar();
      break;
    }

    case 23: { // Guardar Datos
      biblioteca.guardarDatos();
      biblioteca.pausar();
      break;
    }

    case 0: { // Salir
      cout << "\n¿Desea guardar los datos antes de salir? (s/n): ";
      char respuesta;
      cin >> respuesta;
      if (respuesta == 's' || respuesta == 'S') {
        biblioteca.guardarDatos();
      }
      cout << "¡Gracias por usar el Sistema de Gestion de Biblioteca!" << endl;
      break;
    }

    default: {
      cout << "\nOpcion no valida. Por favor, seleccione una opcion del menu."
           << endl;
      biblioteca.pausar();
      break;
    }
    }

    if (opcion != 0) {
      biblioteca.limpiarPantalla();
    }

  } while (opcion != 0);

  return 0;
}