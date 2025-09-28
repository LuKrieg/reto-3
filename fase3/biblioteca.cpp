#include "biblioteca.h"
#include <ctime>
#include <sstream>

// Constructor
BibliotecaDB::BibliotecaDB()
    : next_autor_id(1), next_estudiante_id(1), next_libro_id(1),
      next_prestamo_id(1) {
  cargarDatos();
}

// Métodos auxiliares
bool BibliotecaDB::existeAutor(int id) {
  for (const auto &autor : autores) {
    if (autor.id == id)
      return true;
  }
  return false;
}

bool BibliotecaDB::existeEstudiante(int id) {
  for (const auto &estudiante : estudiantes) {
    if (estudiante.id == id)
      return true;
  }
  return false;
}

bool BibliotecaDB::existeLibro(int id) {
  for (const auto &libro : libros) {
    if (libro.id == id)
      return true;
  }
  return false;
}

bool BibliotecaDB::libroDisponible(int id_libro) {
  for (const auto &libro : libros) {
    if (libro.id == id_libro) {
      return libro.disponible;
    }
  }
  return false;
}

string BibliotecaDB::obtenerFechaActual() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  stringstream ss;
  ss << (1900 + ltm->tm_year) << "-" << setfill('0') << setw(2)
     << (1 + ltm->tm_mon) << "-" << setfill('0') << setw(2) << ltm->tm_mday;
  return ss.str();
}

// Métodos para Autores
void BibliotecaDB::agregarAutor(string nombre, string nacionalidad) {
  if (nombre.empty() || nacionalidad.empty()) {
    cout << "Error: El nombre y la nacionalidad no pueden estar vacios."
         << endl;
    return;
  }

  Autor nuevoAutor(next_autor_id++, nombre, nacionalidad);
  autores.push_back(nuevoAutor);
  cout << "Autor agregado exitosamente con ID: " << nuevoAutor.id << endl;
}

void BibliotecaDB::listarAutores() {
  if (autores.empty()) {
    cout << "No hay autores registrados." << endl;
    return;
  }

  cout << "\n=== LISTA DE AUTORES ===" << endl;
  cout << setw(5) << "ID" << setw(20) << "Nombre" << setw(15) << "Nacionalidad"
       << endl;
  cout << string(50, '-') << endl;

  for (const auto &autor : autores) {
    cout << setw(5) << autor.id << setw(20) << autor.nombre << setw(15)
         << autor.nacionalidad << endl;
  }
}

void BibliotecaDB::buscarAutorPorId(int id) {
  for (const auto &autor : autores) {
    if (autor.id == id) {
      cout << "\nAutor encontrado:" << endl;
      cout << "ID: " << autor.id << endl;
      cout << "Nombre: " << autor.nombre << endl;
      cout << "Nacionalidad: " << autor.nacionalidad << endl;
      return;
    }
  }
  cout << "No se encontro autor con ID: " << id << endl;
}

void BibliotecaDB::actualizarAutor(int id, string nombre, string nacionalidad) {
  for (auto &autor : autores) {
    if (autor.id == id) {
      autor.nombre = nombre;
      autor.nacionalidad = nacionalidad;
      cout << "Autor actualizado exitosamente." << endl;
      return;
    }
  }
  cout << "No se encontro autor con ID: " << id << endl;
}

void BibliotecaDB::eliminarAutor(int id) {
  for (auto it = autores.begin(); it != autores.end(); ++it) {
    if (it->id == id) {
      // Verificar si el autor tiene libros asociados
      bool tieneLibros = false;
      for (const auto &libro : libros) {
        if (libro.id_autor == id) {
          tieneLibros = true;
          break;
        }
      }

      if (tieneLibros) {
        cout << "No se puede eliminar el autor porque tiene libros asociados."
             << endl;
      } else {
        autores.erase(it);
        cout << "Autor eliminado exitosamente." << endl;
      }
      return;
    }
  }
  cout << "No se encontro autor con ID: " << id << endl;
}

// Métodos para Estudiantes
void BibliotecaDB::agregarEstudiante(string nombre, string grado) {
  if (nombre.empty() || grado.empty()) {
    cout << "Error: El nombre y el grado no pueden estar vacios." << endl;
    return;
  }

  Estudiante nuevoEstudiante(next_estudiante_id++, nombre, grado);
  estudiantes.push_back(nuevoEstudiante);
  cout << "Estudiante agregado exitosamente con ID: " << nuevoEstudiante.id
       << endl;
}

void BibliotecaDB::listarEstudiantes() {
  if (estudiantes.empty()) {
    cout << "No hay estudiantes registrados." << endl;
    return;
  }

  cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
  cout << setw(5) << "ID" << setw(20) << "Nombre" << setw(20) << "Grado"
       << endl;
  cout << string(50, '-') << endl;

  for (const auto &estudiante : estudiantes) {
    cout << setw(5) << estudiante.id << setw(20) << estudiante.nombre
         << setw(20) << estudiante.grado << endl;
  }
}

void BibliotecaDB::buscarEstudiantePorId(int id) {
  for (const auto &estudiante : estudiantes) {
    if (estudiante.id == id) {
      cout << "\nEstudiante encontrado:" << endl;
      cout << "ID: " << estudiante.id << endl;
      cout << "Nombre: " << estudiante.nombre << endl;
      cout << "Grado: " << estudiante.grado << endl;
      return;
    }
  }
  cout << "No se encontro estudiante con ID: " << id << endl;
}

void BibliotecaDB::actualizarEstudiante(int id, string nombre, string grado) {
  for (auto &estudiante : estudiantes) {
    if (estudiante.id == id) {
      estudiante.nombre = nombre;
      estudiante.grado = grado;
      cout << "Estudiante actualizado exitosamente." << endl;
      return;
    }
  }
  cout << "No se encontro estudiante con ID: " << id << endl;
}

void BibliotecaDB::eliminarEstudiante(int id) {
  for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
    if (it->id == id) {
      // Verificar si el estudiante tiene prestamos activos
      bool tienePrestamos = false;
      for (const auto &prestamo : prestamos) {
        if (prestamo.id_estudiante == id && prestamo.activo) {
          tienePrestamos = true;
          break;
        }
      }

      if (tienePrestamos) {
        cout << "No se puede eliminar el estudiante porque tiene prestamos "
                "activos."
             << endl;
      } else {
        estudiantes.erase(it);
        cout << "Estudiante eliminado exitosamente." << endl;
      }
      return;
    }
  }
  cout << "No se encontro estudiante con ID: " << id << endl;
}

// Métodos para Libros
void BibliotecaDB::agregarLibro(string titulo, string isbn, int ano,
                                int id_autor) {
  if (titulo.empty() || isbn.empty() || ano <= 0) {
    cout << "Error: Todos los campos son obligatorios y el ano debe ser valido."
         << endl;
    return;
  }

  if (!existeAutor(id_autor)) {
    cout << "Error: No existe autor con ID: " << id_autor << endl;
    return;
  }

  Libro nuevoLibro(next_libro_id++, titulo, isbn, ano, id_autor);
  libros.push_back(nuevoLibro);
  cout << "Libro agregado exitosamente con ID: " << nuevoLibro.id << endl;
}

void BibliotecaDB::listarLibros() {
  if (libros.empty()) {
    cout << "No hay libros registrados." << endl;
    return;
  }

  cout << "\n=== LISTA DE LIBROS ===" << endl;
  cout << setw(5) << "ID" << setw(25) << "Titulo" << setw(15) << "ISBN"
       << setw(8) << "Ano" << setw(8) << "Autor" << setw(12) << "Estado"
       << endl;
  cout << string(80, '-') << endl;

  for (const auto &libro : libros) {
    string estado = libro.disponible ? "Disponible" : "Prestado";
    cout << setw(5) << libro.id << setw(25) << libro.titulo << setw(15)
         << libro.isbn << setw(8) << libro.ano << setw(8) << libro.id_autor
         << setw(12) << estado << endl;
  }
}

void BibliotecaDB::buscarLibroPorId(int id) {
  for (const auto &libro : libros) {
    if (libro.id == id) {
      cout << "\nLibro encontrado:" << endl;
      cout << "ID: " << libro.id << endl;
      cout << "Titulo: " << libro.titulo << endl;
      cout << "ISBN: " << libro.isbn << endl;
      cout << "Ano: " << libro.ano << endl;
      cout << "ID Autor: " << libro.id_autor << endl;
      cout << "Estado: " << (libro.disponible ? "Disponible" : "Prestado")
           << endl;
      return;
    }
  }
  cout << "No se encontro libro con ID: " << id << endl;
}

void BibliotecaDB::buscarLibrosPorAutor(int id_autor) {
  if (!existeAutor(id_autor)) {
    cout << "No existe autor con ID: " << id_autor << endl;
    return;
  }

  cout << "\nLibros del autor ID " << id_autor << ":" << endl;
  bool encontrado = false;

  for (const auto &libro : libros) {
    if (libro.id_autor == id_autor) {
      cout << "ID: " << libro.id << " - " << libro.titulo << " (" << libro.ano
           << ") - " << (libro.disponible ? "Disponible" : "Prestado") << endl;
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No se encontraron libros de este autor." << endl;
  }
}

void BibliotecaDB::actualizarLibro(int id, string titulo, string isbn, int ano,
                                   int id_autor) {
  for (auto &libro : libros) {
    if (libro.id == id) {
      if (!existeAutor(id_autor)) {
        cout << "Error: No existe autor con ID: " << id_autor << endl;
        return;
      }

      libro.titulo = titulo;
      libro.isbn = isbn;
      libro.ano = ano;
      libro.id_autor = id_autor;
      cout << "Libro actualizado exitosamente." << endl;
      return;
    }
  }
  cout << "No se encontro libro con ID: " << id << endl;
}

void BibliotecaDB::eliminarLibro(int id) {
  for (auto it = libros.begin(); it != libros.end(); ++it) {
    if (it->id == id) {
      // Verificar si el libro esta prestado
      bool estaPrestado = false;
      for (const auto &prestamo : prestamos) {
        if (prestamo.id_libro == id && prestamo.activo) {
          estaPrestado = true;
          break;
        }
      }

      if (estaPrestado) {
        cout << "No se puede eliminar el libro porque esta prestado." << endl;
      } else {
        libros.erase(it);
        cout << "Libro eliminado exitosamente." << endl;
      }
      return;
    }
  }
  cout << "No se encontro libro con ID: " << id << endl;
}

// Métodos para Préstamos
void BibliotecaDB::realizarPrestamo(int id_libro, int id_estudiante) {
  if (!existeLibro(id_libro)) {
    cout << "Error: No existe libro con ID: " << id_libro << endl;
    return;
  }

  if (!existeEstudiante(id_estudiante)) {
    cout << "Error: No existe estudiante con ID: " << id_estudiante << endl;
    return;
  }

  if (!libroDisponible(id_libro)) {
    cout << "Error: El libro no esta disponible para prestamo." << endl;
    return;
  }

  // Marcar libro como no disponible
  for (auto &libro : libros) {
    if (libro.id == id_libro) {
      libro.disponible = false;
      break;
    }
  }

  // Crear prestamo
  Prestamo nuevoPrestamo(next_prestamo_id++, id_libro, id_estudiante,
                         obtenerFechaActual());
  prestamos.push_back(nuevoPrestamo);

  cout << "Prestamo realizado exitosamente con ID: " << nuevoPrestamo.id
       << endl;
}

void BibliotecaDB::devolverLibro(int id_prestamo) {
  for (auto &prestamo : prestamos) {
    if (prestamo.id == id_prestamo) {
      if (!prestamo.activo) {
        cout << "Este prestamo ya fue devuelto." << endl;
        return;
      }

      // Marcar prestamo como inactivo
      prestamo.activo = false;
      prestamo.fecha_devolucion = obtenerFechaActual();

      // Marcar libro como disponible
      for (auto &libro : libros) {
        if (libro.id == prestamo.id_libro) {
          libro.disponible = true;
          break;
        }
      }

      cout << "Libro devuelto exitosamente." << endl;
      return;
    }
  }
  cout << "No se encontro prestamo con ID: " << id_prestamo << endl;
}

void BibliotecaDB::listarPrestamos() {
  if (prestamos.empty()) {
    cout << "No hay prestamos registrados." << endl;
    return;
  }

  cout << "\n=== LISTA DE PRESTAMOS ===" << endl;
  cout << setw(5) << "ID" << setw(8) << "Libro" << setw(12) << "Estudiante"
       << setw(15) << "Fecha Prestamo" << setw(15) << "Fecha Devolucion"
       << setw(10) << "Estado" << endl;
  cout << string(80, '-') << endl;

  for (const auto &prestamo : prestamos) {
    string estado = prestamo.activo ? "Activo" : "Devuelto";
    string fechaDev =
        prestamo.fecha_devolucion.empty() ? "N/A" : prestamo.fecha_devolucion;

    cout << setw(5) << prestamo.id << setw(8) << prestamo.id_libro << setw(12)
         << prestamo.id_estudiante << setw(15) << prestamo.fecha_prestamo
         << setw(15) << fechaDev << setw(10) << estado << endl;
  }
}

void BibliotecaDB::buscarPrestamosPorEstudiante(int id_estudiante) {
  if (!existeEstudiante(id_estudiante)) {
    cout << "No existe estudiante con ID: " << id_estudiante << endl;
    return;
  }

  cout << "\nPrestamos del estudiante ID " << id_estudiante << ":" << endl;
  bool encontrado = false;

  for (const auto &prestamo : prestamos) {
    if (prestamo.id_estudiante == id_estudiante) {
      string estado = prestamo.activo ? "Activo" : "Devuelto";
      cout << "ID: " << prestamo.id << " - Libro: " << prestamo.id_libro
           << " - Fecha: " << prestamo.fecha_prestamo << " - " << estado
           << endl;
      encontrado = true;
    }
  }

  if (!encontrado) {
    cout << "No se encontraron prestamos de este estudiante." << endl;
  }
}

// Consultas especiales
void BibliotecaDB::listarLibrosPrestadosPorEstudiante(int id_estudiante) {
  if (!existeEstudiante(id_estudiante)) {
    cout << "No existe estudiante con ID: " << id_estudiante << endl;
    return;
  }

  cout << "\nLibros actualmente prestados al estudiante ID " << id_estudiante
       << ":" << endl;
  bool encontrado = false;

  for (const auto &prestamo : prestamos) {
    if (prestamo.id_estudiante == id_estudiante && prestamo.activo) {
      for (const auto &libro : libros) {
        if (libro.id == prestamo.id_libro) {
          cout << "Libro: " << libro.titulo << " (ID: " << libro.id
               << ") - Fecha prestamo: " << prestamo.fecha_prestamo << endl;
          encontrado = true;
          break;
        }
      }
    }
  }

  if (!encontrado) {
    cout << "El estudiante no tiene libros prestados actualmente." << endl;
  }
}

void BibliotecaDB::autoresConMasLibros() {
  cout << "\n=== AUTORES CON MAS LIBROS ===" << endl;

  for (const auto &autor : autores) {
    int cantidad = 0;
    for (const auto &libro : libros) {
      if (libro.id_autor == autor.id) {
        cantidad++;
      }
    }

    if (cantidad > 0) {
      cout << autor.nombre << " (" << autor.nacionalidad << "): " << cantidad
           << " libros" << endl;
    }
  }
}

// Persistencia de datos
void BibliotecaDB::guardarDatos() {
  // Guardar autores
  ofstream archivoAutores("autores.csv");
  archivoAutores << "ID,Nombre,Nacionalidad\n";
  for (const auto &autor : autores) {
    archivoAutores << autor.id << "," << autor.nombre << ","
                   << autor.nacionalidad << "\n";
  }
  archivoAutores.close();

  // Guardar estudiantes
  ofstream archivoEstudiantes("estudiantes.csv");
  archivoEstudiantes << "ID,Nombre,Grado\n";
  for (const auto &estudiante : estudiantes) {
    archivoEstudiantes << estudiante.id << "," << estudiante.nombre << ","
                       << estudiante.grado << "\n";
  }
  archivoEstudiantes.close();

  // Guardar libros
  ofstream archivoLibros("libros.csv");
  archivoLibros << "ID,Titulo,ISBN,Ano,ID_Autor,Disponible\n";
  for (const auto &libro : libros) {
    archivoLibros << libro.id << "," << libro.titulo << "," << libro.isbn << ","
                  << libro.ano << "," << libro.id_autor << ","
                  << (libro.disponible ? "1" : "0") << "\n";
  }
  archivoLibros.close();

  // Guardar prestamos
  ofstream archivoPrestamos("prestamos.csv");
  archivoPrestamos
      << "ID,ID_Libro,ID_Estudiante,Fecha_Prestamo,Fecha_Devolucion,Activo\n";
  for (const auto &prestamo : prestamos) {
    archivoPrestamos << prestamo.id << "," << prestamo.id_libro << ","
                     << prestamo.id_estudiante << "," << prestamo.fecha_prestamo
                     << "," << prestamo.fecha_devolucion << ","
                     << (prestamo.activo ? "1" : "0") << "\n";
  }
  archivoPrestamos.close();

  // Guardar contadores
  ofstream archivoContadores("contadores.csv");
  archivoContadores
      << "Next_Autor_ID,Next_Estudiante_ID,Next_Libro_ID,Next_Prestamo_ID\n";
  archivoContadores << next_autor_id << "," << next_estudiante_id << ","
                    << next_libro_id << "," << next_prestamo_id << "\n";
  archivoContadores.close();

  cout << "Datos guardados exitosamente en archivos CSV." << endl;
}

void BibliotecaDB::cargarDatos() {
  // Cargar contadores
  ifstream archivoContadores("contadores.csv");
  if (archivoContadores.is_open()) {
    string linea;
    getline(archivoContadores, linea); // Saltar encabezado
    if (getline(archivoContadores, linea)) {
      stringstream ss(linea);
      string token;
      vector<string> tokens;

      while (getline(ss, token, ',')) {
        tokens.push_back(token);
      }

      if (tokens.size() >= 4) {
        next_autor_id = stoi(tokens[0]);
        next_estudiante_id = stoi(tokens[1]);
        next_libro_id = stoi(tokens[2]);
        next_prestamo_id = stoi(tokens[3]);
      }
    }
    archivoContadores.close();
  }

  // Cargar autores
  ifstream archivoAutores("autores.csv");
  if (archivoAutores.is_open()) {
    string linea;
    getline(archivoAutores, linea); // Saltar encabezado
    while (getline(archivoAutores, linea)) {
      stringstream ss(linea);
      string token;
      vector<string> tokens;

      while (getline(ss, token, ',')) {
        tokens.push_back(token);
      }

      if (tokens.size() >= 3) {
        Autor autor(stoi(tokens[0]), tokens[1], tokens[2]);
        autores.push_back(autor);
      }
    }
    archivoAutores.close();
  }

  // Cargar estudiantes
  ifstream archivoEstudiantes("estudiantes.csv");
  if (archivoEstudiantes.is_open()) {
    string linea;
    getline(archivoEstudiantes, linea); // Saltar encabezado
    while (getline(archivoEstudiantes, linea)) {
      stringstream ss(linea);
      string token;
      vector<string> tokens;

      while (getline(ss, token, ',')) {
        tokens.push_back(token);
      }

      if (tokens.size() >= 3) {
        Estudiante estudiante(stoi(tokens[0]), tokens[1], tokens[2]);
        estudiantes.push_back(estudiante);
      }
    }
    archivoEstudiantes.close();
  }

  // Cargar libros
  ifstream archivoLibros("libros.csv");
  if (archivoLibros.is_open()) {
    string linea;
    getline(archivoLibros, linea); // Saltar encabezado
    while (getline(archivoLibros, linea)) {
      stringstream ss(linea);
      string token;
      vector<string> tokens;

      while (getline(ss, token, ',')) {
        tokens.push_back(token);
      }

      if (tokens.size() >= 6) {
        Libro libro(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]),
                    stoi(tokens[4]));
        libro.disponible = (tokens[5] == "1");
        libros.push_back(libro);
      }
    }
    archivoLibros.close();
  }

  // Cargar prestamos
  ifstream archivoPrestamos("prestamos.csv");
  if (archivoPrestamos.is_open()) {
    string linea;
    getline(archivoPrestamos, linea); // Saltar encabezado
    while (getline(archivoPrestamos, linea)) {
      stringstream ss(linea);
      string token;
      vector<string> tokens;

      while (getline(ss, token, ',')) {
        tokens.push_back(token);
      }

      if (tokens.size() >= 6) {
        Prestamo prestamo(stoi(tokens[0]), stoi(tokens[1]), stoi(tokens[2]),
                          tokens[3], tokens[4], tokens[5] == "1");
        prestamos.push_back(prestamo);
      }
    }
    archivoPrestamos.close();
  }
}

// Métodos de utilidad
void BibliotecaDB::mostrarMenu() {
  cout << "\n" << string(50, '=') << endl;
  cout << "        SISTEMA DE GESTION DE BIBLIOTECA" << endl;
  cout << string(50, '=') << endl;
  cout << "\nAUTORES:" << endl;
  cout << "  1. Agregar Autor" << endl;
  cout << "  2. Listar Autores" << endl;
  cout << "  3. Buscar Autor por ID" << endl;
  cout << "  4. Actualizar Autor" << endl;
  cout << "  5. Eliminar Autor" << endl;

  cout << "\nESTUDIANTES:" << endl;
  cout << "  6. Agregar Estudiante" << endl;
  cout << "  7. Listar Estudiantes" << endl;
  cout << "  8. Buscar Estudiante por ID" << endl;
  cout << "  9. Actualizar Estudiante" << endl;
  cout << " 10. Eliminar Estudiante" << endl;

  cout << "\nLIBROS:" << endl;
  cout << " 11. Agregar Libro" << endl;
  cout << " 12. Listar Libros" << endl;
  cout << " 13. Buscar Libro por ID" << endl;
  cout << " 14. Buscar Libros por Autor" << endl;
  cout << " 15. Actualizar Libro" << endl;
  cout << " 16. Eliminar Libro" << endl;

  cout << "\nPRESTAMOS:" << endl;
  cout << " 17. Realizar Prestamo" << endl;
  cout << " 18. Devolver Libro" << endl;
  cout << " 19. Listar Prestamos" << endl;
  cout << " 20. Buscar Prestamos por Estudiante" << endl;

  cout << "\nCONSULTAS ESPECIALES:" << endl;
  cout << " 21. Libros Prestados por Estudiante" << endl;
  cout << " 22. Autores con Mas Libros" << endl;

  cout << "\nSISTEMA:" << endl;
  cout << " 23. Guardar Datos" << endl;
  cout << "  0. Salir" << endl;
  cout << "\n" << string(50, '-') << endl;
  cout << "Seleccione una opcion: ";
}

void BibliotecaDB::limpiarPantalla() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void BibliotecaDB::pausar() {
  cout << "\nPresione Enter para continuar...";
  cin.ignore();
  cin.get();
}