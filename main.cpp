#include "include/GestorContenidos.h"
#include "include/Pelicula.h"
#include "include/Serie.h"
#include "include/Juego.h"
#include "include/Temporada.h"
#include "include/Episodio.h"

#include <iostream>

using namespace std;

static void separador(const string &titulo)
{
    cout << "\n========================================" << endl;
    cout << "  " << titulo << endl;
    cout << "========================================" << endl;
}

int main()
{
    // ── 1. Carga desde archivo ────────────────────────────────────────────────
    separador("1. CARGA DESDE ARCHIVO");
    GestorContenidos gestor;
    gestor.cargarDesdeArchivo("contenidos.txt");
    cout << "Contenidos cargados desde 'contenidos.txt'." << endl;

    // ── 2. Listar todos los contenidos ───────────────────────────────────────
    separador("2. LISTAR TODOS LOS CONTENIDOS");
    gestor.listarContenidos();

    // ── 3. Agregar contenido manualmente (operator+) ─────────────────────────
    separador("3. AGREGAR CONTENIDO MANUALMENTE (operator+)");

    Pelicula *peli = new Pelicula("P99", "Interstellar", CIENCIA_FICCION, 2014, 169);
    gestor + peli;
    cout << "Película 'Interstellar' agregada con operator+." << endl;

    Serie *serie = new Serie("S99", "Stranger Things", CIENCIA_FICCION, 2016);
    Temporada *temp1 = new Temporada(1);
    *temp1 + new Episodio("El experimento", 47);
    *temp1 + new Episodio("La apertura", 55);
    *temp1 + new Episodio("La semilla del mal", 51);
    *serie + temp1;
    Temporada *temp2 = new Temporada(2);
    *temp2 + new Episodio("El regreso de Madmax", 48);
    *temp2 + new Episodio("El chico del mapa estelar", 52);
    *serie + temp2;
    gestor + serie;
    cout << "Serie 'Stranger Things' (2 temporadas, 5 episodios) agregada." << endl;

    Juego *juego = new Juego("J99", "Minecraft", FANTASIA, true, true, Dificultad::FACIL);
    gestor + juego;
    cout << "Juego 'Minecraft' agregado." << endl;

    // ── 4. Buscar por ID ─────────────────────────────────────────────────────
    separador("4. BUSCAR POR ID");
    cout << "Buscando ID 'P99':" << endl;
    try
    {
        gestor.buscarPorId("P99");
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    cout << "\nBuscando ID inexistente 'X00':" << endl;
    try
    {
        gestor.buscarPorId("X00");
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    // ── 5. Buscar por título ──────────────────────────────────────────────────
    separador("5. BUSCAR POR TITULO");
    cout << "Buscando título 'Minecraft':" << endl;
    try
    {
        gestor.buscarPorTitulo("Minecraft");
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    // ── 6. Filtrar por género ─────────────────────────────────────────────────
    separador("6. FILTRAR POR GENERO: CIENCIA_FICCION");
    gestor.listarContenidosPorGenero(CIENCIA_FICCION);

    separador("7. FILTRAR POR GENERO: FANTASIA");
    gestor.listarContenidosPorGenero(FANTASIA);

    // ── 7. Reproducir contenidos ──────────────────────────────────────────────
    separador("8. REPRODUCIR CONTENIDOS (polimorfismo)");

    cout << ">> Reproduciendo pelicula:" << endl;
    peli->reproducir();

    cout << "\n>> Reproduciendo serie:" << endl;
    serie->reproducir();

    cout << "\n>> Reproduciendo juego:" << endl;
    juego->reproducir();

    // ── 8. Duración total (ITemporal) ─────────────────────────────────────────
    separador("9. DURACION TOTAL (ITemporal)");
    cout << "Interstellar: " << peli->calcularDuracionTotal() << " minutos" << endl;
    cout << "Stranger Things: " << serie->calcularDuracionTotal() << " minutos en total" << endl;
    cout << "  Temporada 1: " << temp1->calcularDuracionTotal() << " minutos" << endl;
    cout << "  Temporada 2: " << temp2->calcularDuracionTotal() << " minutos" << endl;

    // ── 9. Eliminar contenido ─────────────────────────────────────────────────
    separador("10. ELIMINAR CONTENIDO");
    cout << "Eliminando ID 'J99' (Minecraft)..." << endl;
    try
    {
        gestor.eliminarContenido("J99");
        cout << "Eliminado correctamente." << endl;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    cout << "\nIntentando eliminar ID inexistente 'J99' otra vez:" << endl;
    try
    {
        gestor.eliminarContenido("J99");
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    // ── 10. Catálogo final ───────────────────────────────────────────────────
    separador("11. CATALOGO FINAL");
    gestor.listarContenidos();

    return 0;
}
