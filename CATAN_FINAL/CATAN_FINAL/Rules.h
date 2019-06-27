#pragma once
#include "Player.h"

class Rules {
public:
    /** Verifica que el jugador player pueda construir un town en las coordenadas coordinates.
     *
     * @param player. Jugador que quiere construir.
     * @param other. El otro jugador.
     * @param coordinates. Las coordenadas donde se quiere construir el town.
     * @param isFirstTurn. True si es parte de las rondas de inicializacion. False en caso contrario.
     * @return ERROR_NO_RESOURCES si player no tiene los recursos necesarios para construir un town.
     * @return ERROR_NO_TOWNS_AVAILABLE si player no tiene mas towns disponibles para construir.
     * @return ERROR_INVALID_COORDINATES si player no puede construir un town en esas coordenadas.
     * @return NO_ERROR_t caso contrario.
     */
	errorT canBuildTown(Player * player, Player * other, Coordinates coordinates, bool isFirstTurn);

	/** Verifica que player pueda construir una ciudad en esas coordenadas
	 *
	 * @param player. El jugador que quiere construir.
	 * @param coordinates. Las coordenadas donde se quiere construir el city.
	 * @@return ERROR_NO_RESOURCES si player no tiene los recursos necesarios para construir un city.
     * @return ERROR_NO_CITIES_AVAILABLE si player no tiene mas cities disponibles para construir.
     * @return ERROR_INVALID_COORDINATES si player no puede construir un city en esas coordenadas.
     * @return NO_ERROR_t caso contrario.
	 */
	errorT canBuildCity(Player * player, const Coordinates &coordinates);

	/** Verifica que player pueda construir un camino en esas coordenadas
	 *
	 * @param player. El jugador que quiere construir.
	 * @param other. El otro jugador.
	 * @param coordinates. Las coordenadas donde se quiere constuir un road.
	 * @@return ERROR_NO_RESOURCES si player no tiene los recursos necesarios para construir un road.
     * @return ERROR_NO_ROADS_AVAILABLE si player no tiene mas road disponibles para construir.
     * @return ERROR_INVALID_COORDINATES si player no puede construir un road en esas coordenadas.
     * @return NO_ERROR_t caso contrario.
	 */
	errorT canBuildRoad(Player * player, Player * other, Coordinates coordinates);

	// bool canBuyDevelopment(Player *, Coordinates);

	/** Verifica que se puede construir un camino en esas coordenadas en los turnos de inicializacion
	 *
	 * @param player. Jugador que quiere construir.
	 * @param coordinates. Coordenadas donde se quiere construir el camino.
	 * @return ERROR_INVALID_COORDINATES si no puede construir en esa posicion, NO_ERROR_t en caso contrario.
	 */
	errorT firstCanBuildRoad(Player * player, Coordinates coordinates);

    /** Funcion auxiliar. Verifica que haya algun camino conectado a las coordenadas donde se quiere construir un town.
     * (Se llama en canBuildTown)
     *
     * @param player. El jugador del cual se va a verificar si sus caminos se llegan a la coordenada.
     * @param coordinates. Coordenada donde se quiere verificar si llegan caminos de player.
     * @return True si hay caminos de player que lleguen a coordinates. False en caso contrario.
     */
    bool verifyRoads(Player * player, Coordinates coordinates);

    /** Funcion auxiliar. Verifica que haya algun camino conectado a las coordenadas donde se quiere construir un road.
     * (Se llama en canBuildRoad)
     *
     * @param player. El jugador del cual se va a verificar si sus caminos se llegan a la coordenada.
     * @param coordinates. Coordenada donde se quiere verificar si llegan caminos de player.
     * @return True si hay caminos de player que lleguen a coordinates. False en caso contrario.
     */
	bool hasAdjacentRoad(Player * player, Coordinates coordinates);

private:
	Coordinates allVertex[VERTEX_AMMOUNT] = { Coordinates('0','A', EMPTY), Coordinates('0','B',EMPTY), Coordinates('0','1','C'),
	Coordinates('0','5','A'), Coordinates('0','A','B'), Coordinates('0','B','C'), Coordinates('1','C',EMPTY), Coordinates('5','A','D'),
	Coordinates('A','B','E'), Coordinates('B','C','F'), Coordinates('1','C','G'), Coordinates('5','D',EMPTY), Coordinates('A','D','E'),
	Coordinates('B','E','F'), Coordinates('C','F','G'), Coordinates('1','G',EMPTY), Coordinates('5','D','H'), Coordinates('D','E','I'),
	Coordinates('E','F','J'), Coordinates('F','G','K'), Coordinates('1','G','L'), Coordinates('5','H',EMPTY), Coordinates('D','H','I'),
	Coordinates('E','I','J'), Coordinates('F','J','K'), Coordinates('G','K','L'), Coordinates('1','2','L'), Coordinates('4','5','H'),
	Coordinates('H','I','M'), Coordinates('I','J','N'), Coordinates('J','K','O'), Coordinates('K','L','P'), Coordinates('2','L',EMPTY),
	Coordinates('4','H','M'), Coordinates('I','M','N'), Coordinates('J','N','O'), Coordinates('K','O','P'), Coordinates('2','L','P'),
	Coordinates('4','M',EMPTY), Coordinates('N','M','Q'), Coordinates('N','O','R'), Coordinates('O','P','S'), Coordinates('2','P',EMPTY),
	Coordinates('4','M','Q'), Coordinates('N','Q','R'), Coordinates('O','R','S'), Coordinates('2','P','S'), Coordinates('4','Q',EMPTY),
	Coordinates('3','Q','R'), Coordinates('3','R','S'), Coordinates('2','3','S'), Coordinates('3','4','Q'), Coordinates('3','R',EMPTY),
	Coordinates('3','S',EMPTY) };
};