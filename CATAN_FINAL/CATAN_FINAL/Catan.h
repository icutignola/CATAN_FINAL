#pragma once
#include "Robber.h"
#include "Map.h"
#include "Coordinates.h"
#include "Rules.h"
#include "defines.h"

class Catan
{
public:
	/** --------- Constructores --------- */
	//Catan(Player *, Player*, char[MAP_ITEMS_NUMBER], char[ISLANDS_AMMOUNT]);

	/** Crea el objeto Catan con los punteros a los jugadores. */
	Catan(Player * player1, Player * player2);

	/** Constructor por default. */
	Catan();
	//~Catan();


	/** --------- Getters --------- */
	Robber * getRobber();
	Player * getPlayer1();
	Player * getPlayer2();
	errorT getError();
	Map * getMap();
	Rules getRules();

    /** @return nullptr si ninguno lo tiene todavia */
    Player * getLongestRoadPlayer();


    /** --------- Setters --------- */
    void setError(errorT);
    void setLongestRoadPlayer(Player *);


    /** Agrega aleatoriedad al juego (Llamar solamente una vez y al principio del juego). */
	void randomize();

	/** @return: Cantidad total de recursos que tiene el player. */
	int resourcesQuantity(Player * player);

	//NOTA: TODOS LOS ARRAYS DE RESOURCES DEBEN TERMINAR CON UN RESOURCE END (VER RESOURCES.H)

	/** Realiza el intercambio entre los recursos de player (give) y los de other (request).
	 ** @param: player. El jugador que hace el pedido del intercambio.
	 ** @param: other. El jugador que acepta el intercambio.
	 ** @param: give. Los recursos que ofrece player para el intercambio.
	 ** @param: request. Los recursos pedidos por player en el intercambio.
	 */
	 void validTrade(tradeIn give, tradeIn request, Player *player, Player *other);

	/** Verifica que player tenga la cantidad de recursos de resources1 y que other tenga resources2.
	 ** @param: resources1. Los recursos que quiere ofrecer player.
	 ** @param: resources2. Los recursos que quiere ofrecer other.
	 ** @return: true si ambos tienen los recursos.
	 ** @return: false en caso contrario.
	*/
	bool canTrade(tradeIn resources1, tradeIn resources2, Player * player, Player * other);

	/** Construye un town para player en el lugar de coordinates (Siempre llamar a canBuildTown antes de esta funcion). */
	void buildTown(const Coordinates &coordinates, Player * player);

    /** Construye un city para player en el lugar de coordinates (Siempre llamar a canBuildCity antes de esta funcion). */
    void buildCity(const Coordinates &coordinates, Player * player);

    /** Construye un road para player en el lugar de coordinates (Siempre llamar a canBuildRoad antes de esta funcion). */
	void buildRoad(const Coordinates &coordinates, Player * player);

	/** Verifica que en las coordenadas mandada haya un puerto, si las hay, se fija que en give que haya suficientes para
	 ** hacer un intercambio.
	 **
	 ** @param: player. El jugador que quiere intercambiar con el puerto.
	 ** @param: coordinates. La posicion del edificio que quiere intercambiar con un puerto.
	 ** @param: give. Los recursos que ofrece player para el intercambio.
	 ** @return: ERROR_TRADING_PORT si no habia puerto en esas coordenadas o hubo algun caso que no deberia pasar.
	 ** @return: NO_RESOURCES_ERROR si no habia suficientes recursos para hacer el intercambio.
	 **
	 ** WARNING: No se fija que los recursos mandados en give sean los del puerto correspondiente porque en teoria no
	 ** no es un caso posible.
	 */
	errorT checkDockTrade(Player * player, tradeIn give, Coordinates coordinates);

	/** Se le da a player los recursos que por los towns/cities construidos en una o más islas cuando se tira el dado.
	 **
	 ** @param: diceNumber. Numero del 2 al 12, la suma de los dos dados tirados en el turno.
	 ** @param: player. El jugador que reclama los recursos.
	 */
	void getResource(int diceNumber, Player * player);

	/** Le da a player los recursos de dockResources y le saca los de myResources (SIEMPRE llamar a checkDockTrade antes).
	 **
	 ** WARNING: Siempre llamar a la funcion checkDockTrade antes.
	 ** WARNING: Actualmente no verifica la cantidad de recursos recibidos en los tradeIns.
	 */
	void tradeDock(tradeIn myResources, tradeIn dockResources, Player * player);

	/** Verifica que player tiene al menos 4 recursos de give, si los tiene, le saca esos 4 recursos
	 ** y se le da un recurso de tipo take.
	 **
	 ** @param: player. Jugador que quiere intercambiar con el banco.
	 ** @param: give. Tipo de recurso que entrega player.
	 ** @param: take. Tipo de recurso que player le pide al banco.
	 ** @return: NO_ERROR_t si se pudo realizar el intercambio.
	 ** @return: ERROR_NO_RESOURCES si no tenia los recursos para hacer el intercambio.
	 */
	errorT tradeBank(char give, char take, Player * player);

	/** Le saca a player todos los recursos en el tradeIn. Se usa cuando el robber tiene que sacar los recursos al jugador.
	 **
	 ** @param: player. Jugador al que se le tiene que sacar los recursos.
	 ** @param: resources. Recursos que hay que sacarle a player.
	 **
	 ** WARNING: No hace ninguna verificacion sobre la cantidad de recursos o si el player tiene esos recursos. Un mal
	 ** uso de esta funcion podria hacer que player tenga recursos negativos.
	 */
	void takeResources(Player * player, tradeIn resources);

	/** Le da a player una quantity cantidad de recursos de tipo resourceType.
	 **
	 ** @return: ERROR_GET_RESOURCE si el resourceType mandado era de tipo DESIERTO.
	 ** @return: NO_ERROR_t en caso contrario.
	 */
	errorT getResourceBuildings(Player * player, char resourceType, int quantity);

	/** Mueve al robber a coordinates y si other tenia algun edificio ahi, se le saca un recurso aleatorio y se lo da a player.
	 **
	 ** @param: player. El jugador que mueve al robber.
	 ** @param: other. El jugador que no esta moviendo al robber.
	 ** @param: coordinates. La posicion donde se quiere mover al robber.
	 */
	void moveRobber(Player * player, Player * other, const Coordinates &coordinates);

	/** Verifica que player puede construir un town en esa posicion
	 **
	 ** @param: player. El jugador que quiere construir
	 ** @param: other. El otro jugador
	 ** @param: coordinates. La posicion donde se quiere construir el town
	 ** @param: isFirstTurn. True si es uno de los turnos de inicializacion del juego, false en caso contrario.
	 ** @return: true si puede construir ahi, false en caso contrario.
	 */
	bool canBuildTown(Player * player, Player * other, const Coordinates &coordinates, bool isFirstTurn);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo (bool en true si es el primer turno)

	/** Verifica que player puede construir una ciudad en esa posicion
	 **
	 ** @param: player. El jugador que quiere construir la ciudad
	 ** @param: coordinates. La posicion donde se quiere construir la ciudad
	 ** @return: true si puede construir ahi, false en caso contrario.
	 */
	bool canBuildCity(Player * player, const Coordinates &coordinates);

    /** Verifica que player puede construir un road en esa posicion
     **
     ** @param: player. El jugador que quiere construir
     ** @param: other. El otro jugador
     ** @param: coordinates. La posicion donde se quiere construir el road
     ** @param: isFirstTurn. True si es uno de los turnos de inicializacion del juego, false en caso contrario.
     ** @return: true si puede construir ahi, false en caso contrario.
     */
	bool canBuildRoad(Player * player, Player * other, const Coordinates &coordinates, bool isFirstTurn);

	/** Inicializador del juego para cliente. Copia los datos del mapa pasados.
	 **
	 ** @param: P1. Jugador 1.
	 ** @param: P2. Jugador 2.
	 ** @param: types. Arreglo del tipo de recurso de la isla ordenado por coordenada.
	 ** @param: tokens. Arreglo del valor de dado de la isla ordenado por coordenada. No se agrega el desierto.
	 ** @param: dock. Arreglo del tipo de puerto ordenado por coordenada
	 */
	void setGame(Player* P1, Player* P2, char types[ISLANDS_AMMOUNT], char tokens[ISLANDS_AMMOUNT - 1], char dock[DOCKS_AMMOUNT]);

    /** Inicializador del juego para server. Crea el mapa y mezcla las islas y puertos.
     **
     ** @param: P1. Jugador 1.
     ** @param: P2. Jugador 2.
     */
	void setGame(Player* P1, Player* P2);

private:
	Player * player1;
	Player * player2;
	Robber robber;
	errorT catanError;
	Map map;
	Rules rules;
	Player * longestRoad = nullptr;
	Coordinates singlePortVertexes[SINGLE_PORT_VERTEX_AMMOUNT] = { Coordinates('0','A','B'), Coordinates('0','B', EMPTY),
																  Coordinates('1','C','G'), Coordinates('1','G', EMPTY),
																  Coordinates('2','L','P'), Coordinates('2','P', EMPTY),
																  Coordinates('3','R','S'), Coordinates('3','R', EMPTY),
																  Coordinates('4','M','Q'), Coordinates('4','M', EMPTY),
																  Coordinates('5','D','H'), Coordinates('5','D', EMPTY) };

	Coordinates doublePortVertexes[DOUBLE_PORT_VERTEX_AMMOUNT] = { Coordinates('0','5','A'), Coordinates('0','A', EMPTY),
																  Coordinates('0','B',EMPTY), Coordinates('0','B','C'),
																  Coordinates('0','1','C'), Coordinates('1','C', EMPTY),
																  Coordinates('1','G',EMPTY), Coordinates('1','G','L'),
																  Coordinates('1','2','L'), Coordinates('2','L',EMPTY),
																  Coordinates('2','P',EMPTY), Coordinates('2','P','S'),
																  Coordinates('2','3','S'), Coordinates('3','S',EMPTY),
																  Coordinates('3','R',EMPTY), Coordinates('3','Q','R'),
																  Coordinates('3','4','Q'), Coordinates('4','Q',EMPTY),
																  Coordinates('4','M',EMPTY), Coordinates('4','H','M'),
																  Coordinates('4','5','H'), Coordinates('5','H',EMPTY),
																  Coordinates('5','D',EMPTY), Coordinates('5','A','D')
	};
};