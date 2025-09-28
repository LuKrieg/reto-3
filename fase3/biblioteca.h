#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para representar un Autor
struct Autor {
  int id;
  string nombre;
  string nacionalidad;

  Autor() : id(0), nombre(""), nacionalidad("") {}
  Autor(int i, string n, string nac) : id(i), nombre(n), nacionalidad(nac) {}
};

// Estructura para representar un Estudiante
struct Estudiante {
  int id;
  string nombre;
  string grado;

  Estudiante() : id(0), nombre(""), grado("") {}
  Estudiante(int i, string n, string g) : id(i), nombre(n), grado(g) {}
};

// Estructura para representar un Libro
struct Libro {
  int id;
  string titulo;
  string isbn;
  int ano;
  int id_autor;
  bool disponible;

  Libro()
      : id(0), titulo(""), isbn(""), ano(0), id_autor(0), disponible(true) {}
  Libro(int i, string t, string is, int a, int id_a)
      : id(i), titulo(t), isbn(is), ano(a), id_autor(id_a), disponible(true) {}
};

// Estructura para representar un Préstamo
struct Prestamo {
  int id;
  int id_libro;
  int id_estudiante;
  string fecha_prestamo;
  string fecha_devolucion;
  bool activo;

  Prestamo()
      : id(0), id_libro(0), id_estudiante(0), fecha_prestamo(""),
        fecha_devolucion(""), activo(false) {}
  Prestamo(int i, int id_l, int id_e, string f_p, string f_d = "",
           bool a = true)
      : id(i), id_libro(id_l), id_estudiante(id_e), fecha_prestamo(f_p),
        fecha_devolucion(f_d), activo(a) {}
};

// Clase principal para manejar la base de datos de la biblioteca
class BibliotecaDB {
private:
  vector<Autor> autores;
  vector<Estudiante> estudiantes;
  vector<Libro> libros;
  vector<Prestamo> prestamos;

  // Contadores para generar IDs únicos
  int next_autor_id;
  int next_estudiante_id;
  int next_libro_id;
  int next_prestamo_id;

  // Métodos auxiliares
  bool existeAutor(int id);
  bool existeEstudiante(int id);
  bool existeLibro(int id);
  bool libroDisponible(int id_libro);
  string obtenerFechaActual();

public:
  BibliotecaDB();

  // Métodos para Autores
  void agregarAutor(string nombre, string nacionalidad);
  void listarAutores();
  void buscarAutorPorId(int id);
  void actualizarAutor(int id, string nombre, string nacionalidad);
  void eliminarAutor(int id);

  // Métodos para Estudiantes
  void agregarEstudiante(string nombre, string grado);
  void listarEstudiantes();
  void buscarEstudiantePorId(int id);
  void actualizarEstudiante(int id, string nombre, string grado);
  void eliminarEstudiante(int id);

  // Métodos para Libros
  void agregarLibro(string titulo, string isbn, int ano, int id_autor);
  void listarLibros();
  void buscarLibroPorId(int id);
  void buscarLibrosPorAutor(int id_autor);
  void actualizarLibro(int id, string titulo, string isbn, int ano,
                       int id_autor);
  void eliminarLibro(int id);

  // Métodos para Préstamos
  void realizarPrestamo(int id_libro, int id_estudiante);
  void devolverLibro(int id_prestamo);
  void listarPrestamos();
  void buscarPrestamosPorEstudiante(int id_estudiante);

  // Consultas especiales
  void listarLibrosPrestadosPorEstudiante(int id_estudiante);
  void autoresConMasLibros();

  // Persistencia de datos
  void guardarDatos();
  void cargarDatos();

  // Métodos de utilidad
  void mostrarMenu();
  void limpiarPantalla();
  void pausar();
};

#endif // BIBLIOTECA_H
