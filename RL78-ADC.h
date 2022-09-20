/**
 * @file RL78-ADC.h
 * @author Felipe Torrezan
 * @date 2019-08-17
 * @brief Simulates an RL78 ADC
 *
 * @license See LICENSE for detailed license information
 *
 * For C-SPY Macros documentation refer to
 * https://netstorage.iar.com/SuppDB/Public/UPDINFO/015020/arm/doc/EWARM_DebuggingGuide.ENU.pdf#page=413 (EWARM 8.50.9)
 */

#ifndef UTILITIES_H
# define UTILITIES_H
# include <stdint.h>
# include <stdio.h>
# include <intrinsics.h>
# include <ior5f10a6a.h>
# define ADC_VECTOR INTAD_vect
# define MAX_ADC 256
#endif
