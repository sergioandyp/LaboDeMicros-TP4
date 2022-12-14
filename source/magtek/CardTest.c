/***************************************************************************//**
  @file     CardTest.c
  @brief    Testbench del modulo de tarjeta
  @author   Grupo 5
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "MagtekWrapper.h"
#include <stdio.h>

/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
WrapperCardCb mainCb;

void callback (bool state, const char* data);

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/


void App_Init (void)
{

   mainCb=*callback;
   Card2Init (mainCb);


}

void App_Run (void)
{
	static int k;
	k++;
}


/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void callback (bool state, const char* data){
	printf("State: %d \t Id:%s\n", state, data);
}

/*******************************************************************************
 ******************************************************************************/
