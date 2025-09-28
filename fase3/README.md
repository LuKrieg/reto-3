# Sistema de Gestión de Biblioteca en C++ - WINDOWS

Este proyecto implementa un sistema básico de gestión de biblioteca en C++ específicamente para Windows que permite administrar autores, estudiantes, libros y préstamos.

##  Características Implementadas

### Entidades Principales
- **Autor**: ID único, nombre, nacionalidad
- **Estudiante**: ID único, nombre, grado
- **Libro**: ID único, título, ISBN, año de publicación, ID del autor, estado de disponibilidad
- **Préstamo**: ID único, ID del libro, ID del estudiante, fecha de préstamo, fecha de devolución, estado activo

### Funcionalidades CRUD (100% Cobertura)
- **Create**: Agregar nuevas entidades
- **Read**: Listar y buscar entidades
- **Update**: Actualizar información existente
- **Delete**: Eliminar entidades (con validaciones)

### Operaciones Especiales
- Realizar préstamos de libros
- Devolver libros
- Consultar libros prestados por estudiante
- Estadísticas de autores con más libros

### Persistencia de Datos
- Guardado en archivos CSV con encabezados
- Carga automática al iniciar el programa
- Archivos separados por entidad (autores.csv, estudiantes.csv, libros.csv, prestamos.csv)

##  Estructura del Proyecto

```
fase3/
├── biblioteca.h          # Definiciones de estructuras y clase principal
├── biblioteca.cpp        # Implementación completa del sistema
├── main.cpp             # Programa principal con menú interactivo
├── README.md            # Documentación completa
└── archivos generados/  # Se crean automáticamente al ejecutar
    ├── autores.csv
    ├── estudiantes.csv
    ├── libros.csv
    ├── prestamos.csv
    └── contadores.csv
```

## Compilación y Ejecución en Windows

### Requisitos Previos
1. **Instalar MinGW-w64** (compilador g++ para Windows):
   - Descargar desde: https://www.mingw-w64.org/downloads/
   - O usar MSYS2: https://www.msys2.org/
   - Asegurarse de que `g++` esté en el PATH del sistema

2. **Verificar instalación**:
   ```cmd
   g++ -version
   ```

### Compilación y Ejecución
```cmd
# Compilar
g++ -std=c++11 -Wall -O2 -o biblioteca.exe main.cpp biblioteca.cpp

# Ejecutar
./biblioteca.exe
```

## Menú Principal (23 opciones)

### Autores (1-5)
1. Agregar Autor
2. Listar Autores
3. Buscar Autor por ID
4. Actualizar Autor
5. Eliminar Autor

### Estudiantes (6-10)
6. Agregar Estudiante
7. Listar Estudiantes
8. Buscar Estudiante por ID
9. Actualizar Estudiante
10. Eliminar Estudiante

### Libros (11-16)
11. Agregar Libro
12. Listar Libros
13. Buscar Libro por ID
14. Buscar Libros por Autor
15. Actualizar Libro
16. Eliminar Libro

### Préstamos (17-20)
17. Realizar Préstamo
18. Devolver Libro
19. Listar Préstamos
20. Buscar Préstamos por Estudiante

### Consultas Especiales (21-22)
21. Libros Prestados por Estudiante
22. Autores con Más Libros

### Sistema (23-0)
23. Guardar Datos
0. Salir

##  Archivos CSV Generados

- `autores.csv` - Con encabezados: ID,Nombre,Nacionalidad
- `estudiantes.csv` - Con encabezados: ID,Nombre,Grado
- `libros.csv` - Con encabezados: ID,Titulo,ISBN,Ano,ID_Autor,Disponible
- `prestamos.csv` - Con encabezados: ID,ID_Libro,ID_Estudiante,Fecha_Prestamo,Fecha_Devolucion,Activo
- `contadores.csv` - Con encabezados: Next_Autor_ID,Next_Estudiante_ID,Next_Libro_ID,Next_Prestamo_ID

## Validaciones y Manejo de Errores

- **IDs únicos**: El sistema genera automáticamente IDs únicos para cada entidad
- **Validación de relaciones**: No se puede eliminar un autor que tiene libros asociados
- **Control de disponibilidad**: No se puede prestar un libro que ya está prestado
- **Validación de préstamos**: No se puede eliminar un estudiante con préstamos activos
- **Campos obligatorios**: Validación de campos vacíos y datos inválidos

##  Ejemplo de Uso

1. **Ejecutar el programa**: `biblioteca.exe`
2. **Agregar un autor**: Opción 1
3. **Agregar un estudiante**: Opción 6
4. **Agregar un libro**: Opción 11
5. **Realizar un préstamo**: Opción 17
6. **Consultar estadísticas**: Opción 22
7. **Guardar datos**: Opción 23
8. **Salir**: Opción 0
