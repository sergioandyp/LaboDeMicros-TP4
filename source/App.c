/***************************************************************************//**
  @file     App.c
  @brief    TP1: Access Control
  @author   Grupo 5
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "const.h"
#include "FSM_table.h"
#include "FSM_routines.h"
#include "event_queue/event_queue.h"
#include "userDatabase.h"
#include "magtek/MagtekWrapper.h"
#include "display/dispArr.h"
#include "encoder/encoder_hal.h"
#include "LEDMux/LEDMux.h"
#include "IOT/IOT.h"

/*******************************************************************************
 *******************************************************************************
                        	GLOBAL VARIABLES
 *******************************************************************************
 ******************************************************************************/

static STATE* p_tabla_estado_actual;

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/* Función que se llama 1 vez, al comienzo del programa */
void App_Init (void)
{
	// timerInit();
	Card2Init();
	encoderInit();
	LEDMuxInit();
	dispArrInit();
	init_Database();
    setUpIDTimer();
    IOTInit();
    init_queue();

	p_tabla_estado_actual = ID_state;
	id_init();

}

/* Función que se llama constantemente en un ciclo infinito */
void App_Run (void)
{
	event_t evento = wait_for_event();  // Espera nuevo evento de la cola de eventos.
	p_tabla_estado_actual = fsm_interprete(p_tabla_estado_actual, evento);  // Actualizo el estado
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

STATE *fsm_interprete(STATE * p_tabla_estado_actual, event_t evento_actual)
{
    while ((p_tabla_estado_actual -> evento) != evento_actual && (p_tabla_estado_actual -> evento) !=NULL_EVENT){
        ++p_tabla_estado_actual;
    } 

    (p_tabla_estado_actual -> p_rut_accion) (); // Ejecuta Rutina de accion correspondiente
    p_tabla_estado_actual = (p_tabla_estado_actual -> proximo_estado); // Encuentro próximo estado
    return (p_tabla_estado_actual);    
}

/*******************************************************************************
 ******************************************************************************/
