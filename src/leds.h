#include "stdint.h"


// Declaro el tipo de función que recibe los errores
typedef void (*LedError_t) (void);

void Leds_Create( uint16_t * puerto, LedError_t handler_error );

void Leds_On( uint8_t led );

void Leds_Off( uint8_t led );

uint8_t Leds_Test(uint8_t led );

