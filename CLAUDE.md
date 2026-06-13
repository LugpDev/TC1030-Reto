# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project overview

A C++ content management system modeled after Netflix, built for the TC1030 (OOP with C++) course at Tec de Monterrey. The project simulates a streaming catalog that supports movies, series, and games.

## Current state

The project is in the **design phase**. The class diagram (`diagrama.puml`) is the single source of truth for the intended architecture. No C++ source files exist yet.

## Architecture (from `diagrama.puml`)

**Interfaces:**
- `Reproducible` — `reproducir()`, `mostrarInfo()`
- `Temporal` — `calcularDuracionTotal(): int`

**Abstract base:**
- `Contenido` — holds `id`, `titulo`, `genero`; declares `mostrarInfo()` as pure virtual

**Concrete subclasses of `Contenido`:**
- `Pelicula` — implements `Reproducible` + `Temporal`; has `anio`, `duracion`
- `Serie` — implements `Reproducible` + `Temporal`; composes `Temporada` objects
- `Juego` — implements `Reproducible`; has `offline`, `multijugador`, `dificultad` (`Dificultad` enum: `FACIL`, `MEDIA`, `DIFICIL`)

**Composition chain for Series:**
`Serie` → `Temporada` → `Episodio` (both implement `Reproducible` + `Temporal`)

**Catalog manager:**
`GestorContenidos` — owns a collection of `Contenido*` (polymorphic); supports add (`operator+` overload), remove by id, list all, filter by genre, search by id/title.

## Rendering the diagram

```bash
# Requires PlantUML (brew install plantuml on macOS)
plantuml diagrama.puml
```

## C++ conventions expected by this course

- Use `.h` / `.cpp` file pairs per class
- Spanish identifiers (names match the diagram exactly)
- Memory managed manually with `new`/`delete` (no smart pointers unless approved)
- `std::vector<Contenido*>` is the expected container for `GestorContenidos`
