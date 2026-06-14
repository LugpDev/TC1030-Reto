# TC1030 — Gestor de Streaming

Simulador de catálogo de contenido estilo Netflix para el curso TC1030 (POO con C++) del Tec de Monterrey.
El sistema permite gestionar películas, series y juegos mediante herencia, polimorfismo, interfaces y clases abstractas.

---

## Arquitectura

El diagrama completo está en `diagrama.puml` (renderizable con PlantUML).

### Jerarquía de clases

```
IReproducible          ITemporal
     |                     |
  Contenido  ──────────────┘
  (abstracta)
  /    |    \
Pelicula  Serie  Juego
              |
          Temporada
              |
           Episodio
```

| Clase | Descripción |
|---|---|
| `Contenido` | Clase abstracta base con `id`, `titulo`, `genero` |
| `Pelicula` | Película con `anio` y `duracion` |
| `Serie` | Serie compuesta de `Temporada`s |
| `Temporada` | Temporada compuesta de `Episodio`s |
| `Episodio` | Episodio con `titulo` y `duracion` |
| `Juego` | Juego con `offline`, `multijugador` y `dificultad` |
| `GestorContenidos` | Catálogo polimórfico de `Contenido*` |
| `IReproducible` | Interfaz: `reproducir()`, `mostrarInfo()` |
| `ITemporal` | Interfaz: `calcularDuracionTotal()` |

### Enums

- `Genero`: `ACCION`, `COMEDIA`, `DRAMA`, `FANTASIA`, `CIENCIA_FICCION`
- `Dificultad`: `FACIL`, `MEDIA`, `DIFICIL`

---

## Estructura del repositorio

```
include/          # Headers (.h) — uno por clase
src/              # Implementaciones (.cpp) — uno por clase
bin/              # Objetos compilados (generado por make)
main.cpp          # Punto de entrada y demostración de funcionalidades
Makefile          # Build system
diagrama.puml     # Diagrama de clases (PlantUML)
contenidos.txt    # Datos de ejemplo cargados al inicio
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

## Funcionalidades

- Carga de contenidos desde archivo (`contenidos.txt`)
- Listar todos los contenidos del catálogo
- Agregar contenidos con `operator+` (`gestor + contenido`)
- Buscar por ID o título (lanza excepción si no se encuentra)
- Filtrar por género
- Reproducir cualquier contenido polimórficamente
- Calcular duración total de películas, series y temporadas
- Eliminar contenido por ID

---

## Convenciones de código

- Identificadores en español, exactamente como en el diagrama
- Un `.h` y un `.cpp` por clase, en `include/` y `src/` respectivamente
- Memoria manual con `new` / `delete` — sin smart pointers
- Compilar con `make` antes de hacer push

### Nombrado

- Archivos: `PascalCase` — `Pelicula.cpp`, `GestorContenidos.h`
- Métodos: `camelCase` — `reproducir()`, `calcularDuracionTotal()`
- Getters/Setters: prefijo `get`/`set` — `getId()`, `setTitulo()`

### Conventional Commits

```
<tipo>[ámbito opcional]: <descripción>
```

| Tipo | Uso |
|---|---|
| `feat` | Nueva funcionalidad |
| `fix` | Corrección de errores |
| `docs` | Cambios en documentación |
| `style` | Formato (espacios, punto y coma, etc.) |
| `refactor` | Refactorización sin cambio de comportamiento |
| `chore` | Herramientas, configuración, Makefile |
