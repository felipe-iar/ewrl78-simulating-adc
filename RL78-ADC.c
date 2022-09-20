/**
 * @file RL78-ADC.c
 * @author Felipe Torrezan
 * @date 2019-08-17
 * @brief Simulates an RL78 ADC
 *
 * @license See LICENSE for detailed license information
 *
 * For C-SPY Macros documentation refer to
 * https://netstorage.iar.com/SuppDB/Public/UPDINFO/015020/arm/doc/EWARM_DebuggingGuide.ENU.pdf#page=413 (EWARM 8.50.9)
 */

#pragma language=extended
#include "RL78-ADC.h"

/* Tracks the current number in the sequence. */
uint_fast8_t ADCcount = 0;
uint_fast16_t ADCval[MAX_ADC];


/**
 * @brief Initializes the ADC
 */
void InitADC(void) {
  __disable_interrupt();
  ADMK  = 0;   /* Enable */
  ADPR0 = 0;   /* Prio 0 */
  ADPR1 = 0;   /* Prio 1 */
  ADIF  = 0;   /* Clear IF */
  __enable_interrupt();
}

/**
 * @brief Called while waiting for interrupts
 */
void DoForegroundProcess(void) {
  putchar('.');
}

/**
 * @brief ADC's ISR
 */
#pragma vector=ADC_VECTOR
__interrupt void ADCHandler(void) {
  ADCval[ADCcount] = ADCR;
  ++ADCcount;
}

/**
 * @brief Main function for interrupt simulation
 */
int main(void) {
  /* Initialize the ADC */
  InitADC();
  /* Loops 'forever', taking input when interrupted. */
  while (ADCcount < MAX_ADC) {
    DoForegroundProcess();
  }
  return 0;
}
