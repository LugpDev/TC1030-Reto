# TC1030 — Gestor de Streaming

Simulador de catálogo de contenido (estilo Netflix) para el curso TC1030 (POO con C++) del Tec de Monterrey.
El sistema permite gestionar películas, series y juegos mediante polimorfismo y herencia.

---

## Estado actual

> **Fase de diseño.** El diagrama de clases (`diagrama.puml`) es la fuente de verdad de la arquitectura.
> Los directorios `include/` y `src/` están vacíos — la implementación aún no ha comenzado.

---

## Arquitectura

El diagrama completo está en `diagrama.puml`.

---

## Estructura del repositorio

```
include/        # Headers (.h) — uno por clase
src/            # Implementaciones (.cpp) — uno por clase
bin/            # Objetos compilados (generado por make)
main.cpp        # Punto de entrada
Makefile        # Build system
diagrama.puml   # Diagrama de clases (PlantUML)
```

---

## Compilar y ejecutar

Requiere `g++` con soporte C++17.

```bash
make        # compila todo
make run    # compila y ejecuta
make clean  # elimina binarios generados
```

---

## Convenciones de código

- **Identificadores en español**, exactamente como aparecen en el diagrama
- **Un `.h` y un `.cpp` por clase**, ubicados en `include/` y `src/` respectivamente
- Memoria manual con `new` / `delete` — sin smart pointers
- Compilar con `make` antes de hacer push para verificar que no hay errores

---

## Reglas

### Nombre de los archivos

- **Archivos fuente**: Usar `PascalCase`
  - Ejemplo: `Pelicula.cpp`, `Serie.cpp`, `GestorContenidos.cpp`
- **Archivos de encabezado**: Mismo nombre que el archivo fuente con extensión `.h`
  - Ejemplo: `Pelicula.h`, `Serie.h`, `GestorContenidos.h`

### Creación de métodos

- **Métodos**: Usar `camelCase`
  - Ejemplo: `reproducir()`, `mostrarInfo()`, `calcularDuracionTotal()`
- **Getters**: Prefijo `get` seguido del nombre del atributo
  - Ejemplo: `getId()`, `getTitulo()`, `getGenero()`
- **Setters**: Prefijo `set` seguido del nombre del atributo
  - Ejemplo: `setId()`, `setTitulo()`, `setGenero()`

### Conventional Commits

Seguimos la especificación de [Conventional Commits](https://www.conventionalcommits.org/) para los mensajes de commit.

#### Estructura

```
<tipo>[ámbito opcional]: <descripción>
```

#### Tipos

- **feat**: Nueva funcionalidad
  - Ejemplo: `feat(Pelicula): agregar método calcularDuracionTotal`
- **fix**: Corrección de errores
  - Ejemplo: `fix(GestorContenidos): corregir búsqueda por título`
- **docs**: Cambios en documentación
  - Ejemplo: `docs(README): actualizar instrucciones de compilación`
- **style**: Cambios de formato (espacios, punto y coma, etc.)
  - Ejemplo: `style(Serie): formatear código según estándares`
- **refactor**: Refactorización de código
  - Ejemplo: `refactor(GestorContenidos): simplificar lógica de filtrado`
- **test**: Agregar o modificar pruebas
  - Ejemplo: `test(Pelicula): agregar pruebas unitarias`
- **chore**: Cambios en herramientas, configuración, etc.
  - Ejemplo: `chore(Makefile): actualizar flags de compilación`
