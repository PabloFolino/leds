// Listado de pruebas:
// --> Despues de la inicialización los leds deben estar apagados. Se puede pagar todos los leds
// --> Se puede prender un LED individual.
// --> Se puede apagar un led individual.
// --> Se puede prender y apagar múltiplas LEDś
// --> Revisar parámetros fuera de los límites
// --> Se puede consultar el estado de un led

#include "unity.h"
#include "leds.h"

//======================= Constantes locales =====================================

//======================== Variables locales ======================================
bool ledsVirtuales;

// ======================= Gestión de Errores =====================================
bool error_informado=false;

void RegistrarError(void) {
    error_informado=true;
}

//========================== Funciones del software de testeo =====================
void setUp(void) {                      // Se llama cada vez que comienza una prueba
   error_informado=false;
   Leds_Create(&ledsVirtuales, RegistrarError);
}

void tearDown(void) {                   // Se llama cada vez que termina una prueba

}

//======================================== Testeos===================================

//Se puede apagar todos los leds
void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales=0xFFFF;
    Leds_Create(&ledsVirtuales, RegistrarError);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//Se puede prender un LED individual
void test_prender_ledindividual(void) {
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1,ledsVirtuales);
}

// Se puede apagar un led individual
void test_apagar_ledindividual(void) {
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

// Se puede prender y apagar múltiplas LED's
void test_prender_apagar_multiples(void) {
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 3,ledsVirtuales);
}

// Revisar parámetros fuera de los límites
void test_prender_led_invalido(void) {
    Leds_On(17);
    TEST_ASSERT_TRUE(error_informado);
}

void test_prender_led_invalido1(void) {
    Leds_On(0);
    TEST_ASSERT_TRUE(error_informado);
}

// Se consulta el estado de un led
void test_consultar_led_ON(void) {
    Leds_On(16);
    TEST_ASSERT_TRUE(Leds_Test(16));
}

void test_consultar_led_OFF(void) {
    Leds_Off(16);
    TEST_ASSERT_FALSE(Leds_Test(16));
}