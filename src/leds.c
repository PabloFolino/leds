#include "leds.h"

// Constantes locales
#define LEDS_ALL_OFF 0x0000
#define LSB          1
#define LED_OFFSET   1
#define MSB_LED      16       // Número de led máximo
#define LSB_LED      1        // Número de led inicial

#define FALSE 0
#define TRUE 1

// Variables globales
static uint16_t * direccion;

static LedError_t RegistrarError;

// Funciones locales
uint16_t LedToMask(uint8_t led) {
    if( led > MSB_LED || led < LSB_LED ){
        RegistrarError();
        return 0;
    }
    return (LSB << (led - LED_OFFSET));
}

// Funciones globales
void Leds_Create(uint16_t * puerto, LedError_t handler_error) {     //Sería el construcctor del objeto
    direccion=puerto;
    RegistrarError=handler_error;
    *direccion=LEDS_ALL_OFF;
}

void Leds_On(uint8_t led) {
    *direccion |= LedToMask(led);
}

void Leds_Off(uint8_t led){
    *direccion &= ~LedToMask(led);
}

uint8_t Leds_Test(uint8_t led ){
    uint16_t temp;
   
    temp=0;
    temp= *direccion & LedToMask(led);
    if(temp==FALSE)
            return FALSE;
    return TRUE;        
}