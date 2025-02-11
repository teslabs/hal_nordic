/*

Copyright (c) 2010 - 2023, Nordic Semiconductor ASA All rights reserved.

SPDX-License-Identifier: BSD-3-Clause

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of Nordic Semiconductor ASA nor the names of its
   contributors may be used to endorse or promote products derived from this
   software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef NRF54H20_ENGA_RADIOCORE_H
#define NRF54H20_ENGA_RADIOCORE_H

#ifdef __cplusplus
    extern "C" {
#endif


#ifdef NRF_RADIOCORE                                 /*!< Processor information is domain local.                               */


/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum {
/* ===================================================== Core Interrupts ===================================================== */
  Reset_IRQn                             = -15,      /*!< -15 Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn                    = -14,      /*!< -14 Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                         = -13,      /*!< -13 Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn                  = -12,      /*!< -12 Memory Management, MPU mismatch, including Access Violation and No
                                                          Match*/
  BusFault_IRQn                          = -11,      /*!< -11 Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                          related Fault*/
  UsageFault_IRQn                        = -10,      /*!< -10 Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SecureFault_IRQn                       = -9,       /*!<  -9 Secure Fault Handler                                             */
  SVCall_IRQn                            = -5,       /*!<  -5 System Service Call via SVC instruction                          */
  DebugMonitor_IRQn                      = -4,       /*!<  -4 Debug Monitor                                                    */
  PendSV_IRQn                            = -2,       /*!<  -2 Pendable request for system service                              */
  SysTick_IRQn                           = -1,       /*!<  -1 System Tick Timer                                                */
/* ============================================== Processor Specific Interrupts ============================================== */
  SPU000_IRQn                            = 0,        /*!< 0 SPU000                                                             */
  MPC_IRQn                               = 1,        /*!< 1 MPC                                                                */
  MVDMA_IRQn                             = 3,        /*!< 3 MVDMA                                                              */
  SPU010_IRQn                            = 16,       /*!< 16 SPU010                                                            */
  WDT010_IRQn                            = 19,       /*!< 19 WDT010                                                            */
  WDT011_IRQn                            = 20,       /*!< 20 WDT011                                                            */
  SPU020_IRQn                            = 32,       /*!< 32 SPU020                                                            */
  EGU020_IRQn                            = 37,       /*!< 37 EGU020                                                            */
  AAR020_CCM020_IRQn                     = 38,       /*!< 38 AAR020_CCM020                                                     */
  ECB020_IRQn                            = 39,       /*!< 39 ECB020                                                            */
  TIMER020_IRQn                          = 40,       /*!< 40 TIMER020                                                          */
  TIMER021_IRQn                          = 41,       /*!< 41 TIMER021                                                          */
  TIMER022_IRQn                          = 42,       /*!< 42 TIMER022                                                          */
  RTC_IRQn                               = 43,       /*!< 43 RTC                                                               */
  RADIO_0_IRQn                           = 44,       /*!< 44 RADIO_0                                                           */
  RADIO_1_IRQn                           = 45,       /*!< 45 RADIO_1                                                           */
  SPU030_IRQn                            = 48,       /*!< 48 SPU030                                                            */
  VPR_IRQn                               = 52,       /*!< 52 VPR                                                               */
  AAR030_CCM030_IRQn                     = 58,       /*!< 58 AAR030_CCM030                                                     */
  ECB030_IRQn                            = 59,       /*!< 59 ECB030                                                            */
  IPCT_0_IRQn                            = 64,       /*!< 64 IPCT_0                                                            */
  IPCT_1_IRQn                            = 65,       /*!< 65 IPCT_1                                                            */
  BELLBOARD_0_IRQn                       = 96,       /*!< 96 BELLBOARD_0                                                       */
  BELLBOARD_1_IRQn                       = 97,       /*!< 97 BELLBOARD_1                                                       */
  BELLBOARD_2_IRQn                       = 98,       /*!< 98 BELLBOARD_2                                                       */
  BELLBOARD_3_IRQn                       = 99,       /*!< 99 BELLBOARD_3                                                       */
  GPIOTE130_0_IRQn                       = 104,      /*!< 104 GPIOTE130_0                                                      */
  GPIOTE130_1_IRQn                       = 105,      /*!< 105 GPIOTE130_1                                                      */
  GRTC_0_IRQn                            = 108,      /*!< 108 GRTC_0                                                           */
  GRTC_1_IRQn                            = 109,      /*!< 109 GRTC_1                                                           */
  TBM_IRQn                               = 127,      /*!< 127 TBM                                                              */
  USBHS_IRQn                             = 134,      /*!< 134 USBHS                                                            */
  EXMIF_IRQn                             = 149,      /*!< 149 EXMIF                                                            */
  IPCT120_0_IRQn                         = 209,      /*!< 209 IPCT120_0                                                        */
  I3C120_IRQn                            = 211,      /*!< 211 I3C120                                                           */
  VPR121_IRQn                            = 212,      /*!< 212 VPR121                                                           */
  CAN_IRQn                               = 216,      /*!< 216 CAN                                                              */
  I3C121_IRQn                            = 222,      /*!< 222 I3C121                                                           */
  TIMER120_IRQn                          = 226,      /*!< 226 TIMER120                                                         */
  TIMER121_IRQn                          = 227,      /*!< 227 TIMER121                                                         */
  PWM120_IRQn                            = 228,      /*!< 228 PWM120                                                           */
  SPIS120_UARTE120_IRQn                  = 229,      /*!< 229 SPIS120_UARTE120                                                 */
  SPIM120_IRQn                           = 230,      /*!< 230 SPIM120                                                          */
  SPIM121_IRQn                           = 231,      /*!< 231 SPIM121                                                          */
  VPR130_IRQn                            = 264,      /*!< 264 VPR130                                                           */
  IPCT130_0_IRQn                         = 289,      /*!< 289 IPCT130_0                                                        */
  RTC130_IRQn                            = 296,      /*!< 296 RTC130                                                           */
  RTC131_IRQn                            = 297,      /*!< 297 RTC131                                                           */
  WDT131_IRQn                            = 299,      /*!< 299 WDT131                                                           */
  WDT132_IRQn                            = 300,      /*!< 300 WDT132                                                           */
  SAADC_IRQn                             = 386,      /*!< 386 SAADC                                                            */
  COMP_LPCOMP_IRQn                       = 387,      /*!< 387 COMP_LPCOMP                                                      */
  TEMP_IRQn                              = 388,      /*!< 388 TEMP                                                             */
  NFCT_IRQn                              = 389,      /*!< 389 NFCT                                                             */
  I2S130_IRQn                            = 402,      /*!< 402 I2S130                                                           */
  PDM_IRQn                               = 403,      /*!< 403 PDM                                                              */
  QDEC130_IRQn                           = 404,      /*!< 404 QDEC130                                                          */
  QDEC131_IRQn                           = 405,      /*!< 405 QDEC131                                                          */
  I2S131_IRQn                            = 407,      /*!< 407 I2S131                                                           */
  TIMER130_IRQn                          = 418,      /*!< 418 TIMER130                                                         */
  TIMER131_IRQn                          = 419,      /*!< 419 TIMER131                                                         */
  PWM130_IRQn                            = 420,      /*!< 420 PWM130                                                           */
  SERIAL0_IRQn                           = 421,      /*!< 421 SERIAL0                                                          */
  SERIAL1_IRQn                           = 422,      /*!< 422 SERIAL1                                                          */
  TIMER132_IRQn                          = 434,      /*!< 434 TIMER132                                                         */
  TIMER133_IRQn                          = 435,      /*!< 435 TIMER133                                                         */
  PWM131_IRQn                            = 436,      /*!< 436 PWM131                                                           */
  SERIAL2_IRQn                           = 437,      /*!< 437 SERIAL2                                                          */
  SERIAL3_IRQn                           = 438,      /*!< 438 SERIAL3                                                          */
  TIMER134_IRQn                          = 450,      /*!< 450 TIMER134                                                         */
  TIMER135_IRQn                          = 451,      /*!< 451 TIMER135                                                         */
  PWM132_IRQn                            = 452,      /*!< 452 PWM132                                                           */
  SERIAL4_IRQn                           = 453,      /*!< 453 SERIAL4                                                          */
  SERIAL5_IRQn                           = 454,      /*!< 454 SERIAL5                                                          */
  TIMER136_IRQn                          = 466,      /*!< 466 TIMER136                                                         */
  TIMER137_IRQn                          = 467,      /*!< 467 TIMER137                                                         */
  PWM133_IRQn                            = 468,      /*!< 468 PWM133                                                           */
  SERIAL6_IRQn                           = 469,      /*!< 469 SERIAL6                                                          */
  SERIAL7_IRQn                           = 470,      /*!< 470 SERIAL7                                                          */
} IRQn_Type;


/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* =========================== Configuration of the ARM Cortex-M33 Processor and Core Peripherals ============================ */
#define __CM33_REV                  r0p4             /*!< CM33 Core Revision                                                   */
#define __DSP_PRESENT                  1             /*!< DSP present or not                                                   */
#define __NVIC_PRIO_BITS               3             /*!< Number of Bits used for Priority Levels                              */
#define __VTOR_PRESENT                 1             /*!< CPU supports alternate Vector Table address                          */
#define __MPU_PRESENT                  1             /*!< MPU present                                                          */
#define __FPU_PRESENT                  1             /*!< FPU present                                                          */
#define __FPU_DP                       0             /*!< Double Precision FPU                                                 */
#define __INTERRUPTS_MAX             480             /*!< Size of interrupt vector table                                       */
#define __Vendor_SysTickConfig         0             /*!< Vendor SysTick Config implementation is used                         */
#define __SAUREGION_PRESENT            1             /*!< SAU present                                                          */
#define __NUM_SAUREGIONS               4             /*!< Number of regions                                                    */

#include "core_cm33.h"                               /*!< ARM Cortex-M33 processor and core peripherals                        */
#include "system_nrf.h"                              /*!< nrf54h20_enga_radiocore System Library                               */

#endif                                               /*!< NRF_RADIOCORE                                                        */


/* ========================================= Start of section using anonymous unions ========================================= */

#include "compiler_abstraction.h"

#if defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
  #pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
  #pragma clang diagnostic ignored "-Wnested-anon-types"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Unsupported compiler type
#endif

/* =========================================================================================================================== */
/* ================                                  Peripheral Address Map                                  ================ */
/* =========================================================================================================================== */

#define NRF_RADIOCORE_UICR_NS_BASE        0x0FFFA000UL
#define NRF_RADIOCORE_ICACHEDATA_S_BASE   0x13F00000UL
#define NRF_RADIOCORE_ICACHEINFO_S_BASE   0x13F10000UL
#define NRF_RADIOCORE_DCACHEDATA_S_BASE   0x33F00000UL
#define NRF_RADIOCORE_DCACHEINFO_S_BASE   0x33F10000UL
#define NRF_RADIOCORE_ETM_NS_BASE         0xE0041000UL
#define NRF_RADIOCORE_CTI_S_BASE          0xE0042000UL
#define NRF_RADIOCORE_CPUC_S_BASE         0xE0080000UL
#define NRF_RADIOCORE_ICACHE_S_BASE       0xE0082000UL
#define NRF_RADIOCORE_DCACHE_S_BASE       0xE0083000UL
#define NRF_RADIOCORE_SPU000_S_BASE       0x53000000UL
#define NRF_RADIOCORE_MPC_S_BASE          0x53001000UL
#define NRF_RADIOCORE_MVDMA_NS_BASE       0x43003000UL
#define NRF_RADIOCORE_MVDMA_S_BASE        0x53003000UL
#define NRF_RADIOCORE_RAMC000_NS_BASE     0x43004000UL
#define NRF_RADIOCORE_RAMC000_S_BASE      0x53004000UL
#define NRF_RADIOCORE_HSFLL_S_BASE        0x5300D000UL
#define NRF_RADIOCORE_LRCCONF000_S_BASE   0x5300E000UL
#define NRF_RADIOCORE_SPU010_S_BASE       0x53010000UL
#define NRF_RADIOCORE_MEMCONF_NS_BASE     0x43012000UL
#define NRF_RADIOCORE_MEMCONF_S_BASE      0x53012000UL
#define NRF_RADIOCORE_WDT010_NS_BASE      0x43013000UL
#define NRF_RADIOCORE_WDT010_S_BASE       0x53013000UL
#define NRF_RADIOCORE_WDT011_NS_BASE      0x43014000UL
#define NRF_RADIOCORE_WDT011_S_BASE       0x53014000UL
#define NRF_RADIOCORE_LRCCONF010_S_BASE   0x5301E000UL
#define NRF_RADIOCORE_RESETINFO_S_BASE    0x5301E000UL
#define NRF_RADIOCORE_SPU020_S_BASE       0x53020000UL
#define NRF_RADIOCORE_DPPIC020_NS_BASE    0x43022000UL
#define NRF_RADIOCORE_DPPIC020_S_BASE     0x53022000UL
#define NRF_RADIOCORE_PPIB020_S_BASE      0x53023000UL
#define NRF_RADIOCORE_EGU020_NS_BASE      0x43025000UL
#define NRF_RADIOCORE_EGU020_S_BASE       0x53025000UL
#define NRF_RADIOCORE_AAR020_NS_BASE      0x43026000UL
#define NRF_RADIOCORE_CCM020_NS_BASE      0x43026000UL
#define NRF_RADIOCORE_AAR020_S_BASE       0x53026000UL
#define NRF_RADIOCORE_CCM020_S_BASE       0x53026000UL
#define NRF_RADIOCORE_ECB020_NS_BASE      0x43027000UL
#define NRF_RADIOCORE_ECB020_S_BASE       0x53027000UL
#define NRF_RADIOCORE_TIMER020_NS_BASE    0x43028000UL
#define NRF_RADIOCORE_TIMER020_S_BASE     0x53028000UL
#define NRF_RADIOCORE_TIMER021_NS_BASE    0x43029000UL
#define NRF_RADIOCORE_TIMER021_S_BASE     0x53029000UL
#define NRF_RADIOCORE_TIMER022_NS_BASE    0x4302A000UL
#define NRF_RADIOCORE_TIMER022_S_BASE     0x5302A000UL
#define NRF_RADIOCORE_RTC_NS_BASE         0x4302B000UL
#define NRF_RADIOCORE_RTC_S_BASE          0x5302B000UL
#define NRF_RADIOCORE_RADIO_NS_BASE       0x4302C000UL
#define NRF_RADIOCORE_RADIO_S_BASE        0x5302C000UL
#define NRF_RADIOCORE_LRCCONF020_S_BASE   0x5302E000UL
#define NRF_RADIOCORE_SPU030_S_BASE       0x53030000UL
#define NRF_RADIOCORE_PPIB030_S_BASE      0x53031000UL
#define NRF_RADIOCORE_VPR_NS_BASE         0x43034000UL
#define NRF_RADIOCORE_VPR_S_BASE          0x53034000UL
#define NRF_RADIOCORE_RAMC001_NS_BASE     0x43038000UL
#define NRF_RADIOCORE_RAMC001_S_BASE      0x53038000UL
#define NRF_RADIOCORE_AAR030_NS_BASE      0x4303A000UL
#define NRF_RADIOCORE_CCM030_NS_BASE      0x4303A000UL
#define NRF_RADIOCORE_AAR030_S_BASE       0x5303A000UL
#define NRF_RADIOCORE_CCM030_S_BASE       0x5303A000UL
#define NRF_RADIOCORE_ECB030_NS_BASE      0x4303B000UL
#define NRF_RADIOCORE_ECB030_S_BASE       0x5303B000UL
#define NRF_RADIOCORE_IPCT_NS_BASE        0x43024000UL
#define NRF_RADIOCORE_IPCT_S_BASE         0x53024000UL
#define NRF_RADIOCORE_BELLBOARD_NS_BASE   0x4F09B000UL
#define NRF_RADIOCORE_BELLBOARD_S_BASE    0x5F09B000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral Declaration                                  ================ */
/* =========================================================================================================================== */

#define NRF_RADIOCORE_UICR_NS             ((NRF_UICR_Type*)                     NRF_RADIOCORE_UICR_NS_BASE)
#define NRF_RADIOCORE_ICACHEDATA_S        ((NRF_CACHEDATA_Type*)                NRF_RADIOCORE_ICACHEDATA_S_BASE)
#define NRF_RADIOCORE_ICACHEINFO_S        ((NRF_CACHEINFO_Type*)                NRF_RADIOCORE_ICACHEINFO_S_BASE)
#define NRF_RADIOCORE_DCACHEDATA_S        ((NRF_CACHEDATA_Type*)                NRF_RADIOCORE_DCACHEDATA_S_BASE)
#define NRF_RADIOCORE_DCACHEINFO_S        ((NRF_CACHEINFO_Type*)                NRF_RADIOCORE_DCACHEINFO_S_BASE)
#define NRF_RADIOCORE_ETM_NS              ((NRF_ETM_Type*)                      NRF_RADIOCORE_ETM_NS_BASE)
#define NRF_RADIOCORE_CTI_S               ((NRF_CTI_Type*)                      NRF_RADIOCORE_CTI_S_BASE)
#define NRF_RADIOCORE_CPUC_S              ((NRF_CM33SS_Type*)                   NRF_RADIOCORE_CPUC_S_BASE)
#define NRF_RADIOCORE_ICACHE_S            ((NRF_CACHE_Type*)                    NRF_RADIOCORE_ICACHE_S_BASE)
#define NRF_RADIOCORE_DCACHE_S            ((NRF_CACHE_Type*)                    NRF_RADIOCORE_DCACHE_S_BASE)
#define NRF_RADIOCORE_SPU000_S            ((NRF_SPU_Type*)                      NRF_RADIOCORE_SPU000_S_BASE)
#define NRF_RADIOCORE_MPC_S               ((NRF_MPC_Type*)                      NRF_RADIOCORE_MPC_S_BASE)
#define NRF_RADIOCORE_MVDMA_NS            ((NRF_MVDMA_Type*)                    NRF_RADIOCORE_MVDMA_NS_BASE)
#define NRF_RADIOCORE_MVDMA_S             ((NRF_MVDMA_Type*)                    NRF_RADIOCORE_MVDMA_S_BASE)
#define NRF_RADIOCORE_RAMC000_NS          ((NRF_RAMC_Type*)                     NRF_RADIOCORE_RAMC000_NS_BASE)
#define NRF_RADIOCORE_RAMC000_S           ((NRF_RAMC_Type*)                     NRF_RADIOCORE_RAMC000_S_BASE)
#define NRF_RADIOCORE_HSFLL_S             ((NRF_HSFLL_Type*)                    NRF_RADIOCORE_HSFLL_S_BASE)
#define NRF_RADIOCORE_LRCCONF000_S        ((NRF_LRCCONF_Type*)                  NRF_RADIOCORE_LRCCONF000_S_BASE)
#define NRF_RADIOCORE_SPU010_S            ((NRF_SPU_Type*)                      NRF_RADIOCORE_SPU010_S_BASE)
#define NRF_RADIOCORE_MEMCONF_NS          ((NRF_MEMCONF_Type*)                  NRF_RADIOCORE_MEMCONF_NS_BASE)
#define NRF_RADIOCORE_MEMCONF_S           ((NRF_MEMCONF_Type*)                  NRF_RADIOCORE_MEMCONF_S_BASE)
#define NRF_RADIOCORE_WDT010_NS           ((NRF_WDT_Type*)                      NRF_RADIOCORE_WDT010_NS_BASE)
#define NRF_RADIOCORE_WDT010_S            ((NRF_WDT_Type*)                      NRF_RADIOCORE_WDT010_S_BASE)
#define NRF_RADIOCORE_WDT011_NS           ((NRF_WDT_Type*)                      NRF_RADIOCORE_WDT011_NS_BASE)
#define NRF_RADIOCORE_WDT011_S            ((NRF_WDT_Type*)                      NRF_RADIOCORE_WDT011_S_BASE)
#define NRF_RADIOCORE_LRCCONF010_S        ((NRF_LRCCONF_Type*)                  NRF_RADIOCORE_LRCCONF010_S_BASE)
#define NRF_RADIOCORE_RESETINFO_S         ((NRF_RESETINFO_Type*)                NRF_RADIOCORE_RESETINFO_S_BASE)
#define NRF_RADIOCORE_SPU020_S            ((NRF_SPU_Type*)                      NRF_RADIOCORE_SPU020_S_BASE)
#define NRF_RADIOCORE_DPPIC020_NS         ((NRF_DPPIC_Type*)                    NRF_RADIOCORE_DPPIC020_NS_BASE)
#define NRF_RADIOCORE_DPPIC020_S          ((NRF_DPPIC_Type*)                    NRF_RADIOCORE_DPPIC020_S_BASE)
#define NRF_RADIOCORE_PPIB020_S           ((NRF_PPIB_Type*)                     NRF_RADIOCORE_PPIB020_S_BASE)
#define NRF_RADIOCORE_EGU020_NS           ((NRF_EGU_Type*)                      NRF_RADIOCORE_EGU020_NS_BASE)
#define NRF_RADIOCORE_EGU020_S            ((NRF_EGU_Type*)                      NRF_RADIOCORE_EGU020_S_BASE)
#define NRF_RADIOCORE_AAR020_NS           ((NRF_AAR_Type*)                      NRF_RADIOCORE_AAR020_NS_BASE)
#define NRF_RADIOCORE_CCM020_NS           ((NRF_CCM_Type*)                      NRF_RADIOCORE_CCM020_NS_BASE)
#define NRF_RADIOCORE_AAR020_S            ((NRF_AAR_Type*)                      NRF_RADIOCORE_AAR020_S_BASE)
#define NRF_RADIOCORE_CCM020_S            ((NRF_CCM_Type*)                      NRF_RADIOCORE_CCM020_S_BASE)
#define NRF_RADIOCORE_ECB020_NS           ((NRF_ECB_Type*)                      NRF_RADIOCORE_ECB020_NS_BASE)
#define NRF_RADIOCORE_ECB020_S            ((NRF_ECB_Type*)                      NRF_RADIOCORE_ECB020_S_BASE)
#define NRF_RADIOCORE_TIMER020_NS         ((NRF_TIMER_Type*)                    NRF_RADIOCORE_TIMER020_NS_BASE)
#define NRF_RADIOCORE_TIMER020_S          ((NRF_TIMER_Type*)                    NRF_RADIOCORE_TIMER020_S_BASE)
#define NRF_RADIOCORE_TIMER021_NS         ((NRF_TIMER_Type*)                    NRF_RADIOCORE_TIMER021_NS_BASE)
#define NRF_RADIOCORE_TIMER021_S          ((NRF_TIMER_Type*)                    NRF_RADIOCORE_TIMER021_S_BASE)
#define NRF_RADIOCORE_TIMER022_NS         ((NRF_TIMER_Type*)                    NRF_RADIOCORE_TIMER022_NS_BASE)
#define NRF_RADIOCORE_TIMER022_S          ((NRF_TIMER_Type*)                    NRF_RADIOCORE_TIMER022_S_BASE)
#define NRF_RADIOCORE_RTC_NS              ((NRF_RTC_Type*)                      NRF_RADIOCORE_RTC_NS_BASE)
#define NRF_RADIOCORE_RTC_S               ((NRF_RTC_Type*)                      NRF_RADIOCORE_RTC_S_BASE)
#define NRF_RADIOCORE_RADIO_NS            ((NRF_RADIO_Type*)                    NRF_RADIOCORE_RADIO_NS_BASE)
#define NRF_RADIOCORE_RADIO_S             ((NRF_RADIO_Type*)                    NRF_RADIOCORE_RADIO_S_BASE)
#define NRF_RADIOCORE_LRCCONF020_S        ((NRF_LRCCONF_Type*)                  NRF_RADIOCORE_LRCCONF020_S_BASE)
#define NRF_RADIOCORE_SPU030_S            ((NRF_SPU_Type*)                      NRF_RADIOCORE_SPU030_S_BASE)
#define NRF_RADIOCORE_PPIB030_S           ((NRF_PPIB_Type*)                     NRF_RADIOCORE_PPIB030_S_BASE)
#define NRF_RADIOCORE_VPR_NS              ((NRF_VPR_Type*)                      NRF_RADIOCORE_VPR_NS_BASE)
#define NRF_RADIOCORE_VPR_S               ((NRF_VPR_Type*)                      NRF_RADIOCORE_VPR_S_BASE)
#define NRF_RADIOCORE_RAMC001_NS          ((NRF_RAMC_Type*)                     NRF_RADIOCORE_RAMC001_NS_BASE)
#define NRF_RADIOCORE_RAMC001_S           ((NRF_RAMC_Type*)                     NRF_RADIOCORE_RAMC001_S_BASE)
#define NRF_RADIOCORE_AAR030_NS           ((NRF_AAR_Type*)                      NRF_RADIOCORE_AAR030_NS_BASE)
#define NRF_RADIOCORE_CCM030_NS           ((NRF_CCM_Type*)                      NRF_RADIOCORE_CCM030_NS_BASE)
#define NRF_RADIOCORE_AAR030_S            ((NRF_AAR_Type*)                      NRF_RADIOCORE_AAR030_S_BASE)
#define NRF_RADIOCORE_CCM030_S            ((NRF_CCM_Type*)                      NRF_RADIOCORE_CCM030_S_BASE)
#define NRF_RADIOCORE_ECB030_NS           ((NRF_ECB_Type*)                      NRF_RADIOCORE_ECB030_NS_BASE)
#define NRF_RADIOCORE_ECB030_S            ((NRF_ECB_Type*)                      NRF_RADIOCORE_ECB030_S_BASE)
#define NRF_RADIOCORE_IPCT_NS             ((NRF_IPCT_Type*)                     NRF_RADIOCORE_IPCT_NS_BASE)
#define NRF_RADIOCORE_IPCT_S              ((NRF_IPCT_Type*)                     NRF_RADIOCORE_IPCT_S_BASE)
#define NRF_RADIOCORE_BELLBOARD_NS        ((NRF_BELLBOARD_Type*)                NRF_RADIOCORE_BELLBOARD_NS_BASE)
#define NRF_RADIOCORE_BELLBOARD_S         ((NRF_BELLBOARD_Type*)                NRF_RADIOCORE_BELLBOARD_S_BASE)

/* =========================================================================================================================== */
/* ================                                    TrustZone Remapping                                    ================ */
/* =========================================================================================================================== */

#ifdef NRF_TRUSTZONE_NONSECURE                       /*!< Remap NRF_X_NS instances to NRF_X symbol for ease of use.            */
  #define NRF_RADIOCORE_UICR                      NRF_RADIOCORE_UICR_NS
  #define NRF_RADIOCORE_ETM                       NRF_RADIOCORE_ETM_NS
  #define NRF_RADIOCORE_MVDMA                     NRF_RADIOCORE_MVDMA_NS
  #define NRF_RADIOCORE_RAMC000                   NRF_RADIOCORE_RAMC000_NS
  #define NRF_RADIOCORE_MEMCONF                   NRF_RADIOCORE_MEMCONF_NS
  #define NRF_RADIOCORE_WDT010                    NRF_RADIOCORE_WDT010_NS
  #define NRF_RADIOCORE_WDT011                    NRF_RADIOCORE_WDT011_NS
  #define NRF_RADIOCORE_DPPIC020                  NRF_RADIOCORE_DPPIC020_NS
  #define NRF_RADIOCORE_EGU020                    NRF_RADIOCORE_EGU020_NS
  #define NRF_RADIOCORE_AAR020                    NRF_RADIOCORE_AAR020_NS
  #define NRF_RADIOCORE_CCM020                    NRF_RADIOCORE_CCM020_NS
  #define NRF_RADIOCORE_ECB020                    NRF_RADIOCORE_ECB020_NS
  #define NRF_RADIOCORE_TIMER020                  NRF_RADIOCORE_TIMER020_NS
  #define NRF_RADIOCORE_TIMER021                  NRF_RADIOCORE_TIMER021_NS
  #define NRF_RADIOCORE_TIMER022                  NRF_RADIOCORE_TIMER022_NS
  #define NRF_RADIOCORE_RTC                       NRF_RADIOCORE_RTC_NS
  #define NRF_RADIOCORE_RADIO                     NRF_RADIOCORE_RADIO_NS
  #define NRF_RADIOCORE_VPR                       NRF_RADIOCORE_VPR_NS
  #define NRF_RADIOCORE_RAMC001                   NRF_RADIOCORE_RAMC001_NS
  #define NRF_RADIOCORE_AAR030                    NRF_RADIOCORE_AAR030_NS
  #define NRF_RADIOCORE_CCM030                    NRF_RADIOCORE_CCM030_NS
  #define NRF_RADIOCORE_ECB030                    NRF_RADIOCORE_ECB030_NS
  #define NRF_RADIOCORE_IPCT                      NRF_RADIOCORE_IPCT_NS
  #define NRF_RADIOCORE_BELLBOARD                 NRF_RADIOCORE_BELLBOARD_NS
#else                                                /*!< Remap NRF_X_S instances to NRF_X symbol for ease of use.             */
  #define NRF_RADIOCORE_UICR                      NRF_RADIOCORE_UICR_NS
  #define NRF_RADIOCORE_ICACHEDATA                NRF_RADIOCORE_ICACHEDATA_S
  #define NRF_RADIOCORE_ICACHEINFO                NRF_RADIOCORE_ICACHEINFO_S
  #define NRF_RADIOCORE_DCACHEDATA                NRF_RADIOCORE_DCACHEDATA_S
  #define NRF_RADIOCORE_DCACHEINFO                NRF_RADIOCORE_DCACHEINFO_S
  #define NRF_RADIOCORE_ETM                       NRF_RADIOCORE_ETM_NS
  #define NRF_RADIOCORE_CTI                       NRF_RADIOCORE_CTI_S
  #define NRF_RADIOCORE_CPUC                      NRF_RADIOCORE_CPUC_S
  #define NRF_RADIOCORE_ICACHE                    NRF_RADIOCORE_ICACHE_S
  #define NRF_RADIOCORE_DCACHE                    NRF_RADIOCORE_DCACHE_S
  #define NRF_RADIOCORE_SPU000                    NRF_RADIOCORE_SPU000_S
  #define NRF_RADIOCORE_MPC                       NRF_RADIOCORE_MPC_S
  #define NRF_RADIOCORE_MVDMA                     NRF_RADIOCORE_MVDMA_S
  #define NRF_RADIOCORE_RAMC000                   NRF_RADIOCORE_RAMC000_S
  #define NRF_RADIOCORE_HSFLL                     NRF_RADIOCORE_HSFLL_S
  #define NRF_RADIOCORE_LRCCONF000                NRF_RADIOCORE_LRCCONF000_S
  #define NRF_RADIOCORE_SPU010                    NRF_RADIOCORE_SPU010_S
  #define NRF_RADIOCORE_MEMCONF                   NRF_RADIOCORE_MEMCONF_S
  #define NRF_RADIOCORE_WDT010                    NRF_RADIOCORE_WDT010_S
  #define NRF_RADIOCORE_WDT011                    NRF_RADIOCORE_WDT011_S
  #define NRF_RADIOCORE_LRCCONF010                NRF_RADIOCORE_LRCCONF010_S
  #define NRF_RADIOCORE_RESETINFO                 NRF_RADIOCORE_RESETINFO_S
  #define NRF_RADIOCORE_SPU020                    NRF_RADIOCORE_SPU020_S
  #define NRF_RADIOCORE_DPPIC020                  NRF_RADIOCORE_DPPIC020_S
  #define NRF_RADIOCORE_PPIB020                   NRF_RADIOCORE_PPIB020_S
  #define NRF_RADIOCORE_EGU020                    NRF_RADIOCORE_EGU020_S
  #define NRF_RADIOCORE_AAR020                    NRF_RADIOCORE_AAR020_S
  #define NRF_RADIOCORE_CCM020                    NRF_RADIOCORE_CCM020_S
  #define NRF_RADIOCORE_ECB020                    NRF_RADIOCORE_ECB020_S
  #define NRF_RADIOCORE_TIMER020                  NRF_RADIOCORE_TIMER020_S
  #define NRF_RADIOCORE_TIMER021                  NRF_RADIOCORE_TIMER021_S
  #define NRF_RADIOCORE_TIMER022                  NRF_RADIOCORE_TIMER022_S
  #define NRF_RADIOCORE_RTC                       NRF_RADIOCORE_RTC_S
  #define NRF_RADIOCORE_RADIO                     NRF_RADIOCORE_RADIO_S
  #define NRF_RADIOCORE_LRCCONF020                NRF_RADIOCORE_LRCCONF020_S
  #define NRF_RADIOCORE_SPU030                    NRF_RADIOCORE_SPU030_S
  #define NRF_RADIOCORE_PPIB030                   NRF_RADIOCORE_PPIB030_S
  #define NRF_RADIOCORE_VPR                       NRF_RADIOCORE_VPR_S
  #define NRF_RADIOCORE_RAMC001                   NRF_RADIOCORE_RAMC001_S
  #define NRF_RADIOCORE_AAR030                    NRF_RADIOCORE_AAR030_S
  #define NRF_RADIOCORE_CCM030                    NRF_RADIOCORE_CCM030_S
  #define NRF_RADIOCORE_ECB030                    NRF_RADIOCORE_ECB030_S
  #define NRF_RADIOCORE_IPCT                      NRF_RADIOCORE_IPCT_S
  #define NRF_RADIOCORE_BELLBOARD                 NRF_RADIOCORE_BELLBOARD_S
#endif                                               /*!<  NRF_TRUSTZONE_NONSECURE                                             */

/* =========================================================================================================================== */
/* ================                                  Local Domain Remapping                                  ================ */
/* =========================================================================================================================== */

#ifdef NRF_RADIOCORE                                 /*!< Remap NRF_DOMAIN instances to NRF_X symbol for ease of use.          */
  #define NRF_UICR                                NRF_RADIOCORE_UICR
  #define NRF_ICACHEDATA                          NRF_RADIOCORE_ICACHEDATA
  #define NRF_ICACHEINFO                          NRF_RADIOCORE_ICACHEINFO
  #define NRF_DCACHEDATA                          NRF_RADIOCORE_DCACHEDATA
  #define NRF_DCACHEINFO                          NRF_RADIOCORE_DCACHEINFO
  #define NRF_ETM                                 NRF_RADIOCORE_ETM
  #define NRF_CTI                                 NRF_RADIOCORE_CTI
  #define NRF_CPUC                                NRF_RADIOCORE_CPUC
  #define NRF_ICACHE                              NRF_RADIOCORE_ICACHE
  #define NRF_DCACHE                              NRF_RADIOCORE_DCACHE
  #define NRF_SPU000                              NRF_RADIOCORE_SPU000
  #define NRF_MPC                                 NRF_RADIOCORE_MPC
  #define NRF_MVDMA                               NRF_RADIOCORE_MVDMA
  #define NRF_RAMC000                             NRF_RADIOCORE_RAMC000
  #define NRF_HSFLL                               NRF_RADIOCORE_HSFLL
  #define NRF_LRCCONF000                          NRF_RADIOCORE_LRCCONF000
  #define NRF_SPU010                              NRF_RADIOCORE_SPU010
  #define NRF_MEMCONF                             NRF_RADIOCORE_MEMCONF
  #define NRF_WDT010                              NRF_RADIOCORE_WDT010
  #define NRF_WDT011                              NRF_RADIOCORE_WDT011
  #define NRF_LRCCONF010                          NRF_RADIOCORE_LRCCONF010
  #define NRF_RESETINFO                           NRF_RADIOCORE_RESETINFO
  #define NRF_SPU020                              NRF_RADIOCORE_SPU020
  #define NRF_DPPIC020                            NRF_RADIOCORE_DPPIC020
  #define NRF_PPIB020                             NRF_RADIOCORE_PPIB020
  #define NRF_EGU020                              NRF_RADIOCORE_EGU020
  #define NRF_AAR020                              NRF_RADIOCORE_AAR020
  #define NRF_CCM020                              NRF_RADIOCORE_CCM020
  #define NRF_ECB020                              NRF_RADIOCORE_ECB020
  #define NRF_TIMER020                            NRF_RADIOCORE_TIMER020
  #define NRF_TIMER021                            NRF_RADIOCORE_TIMER021
  #define NRF_TIMER022                            NRF_RADIOCORE_TIMER022
  #define NRF_RTC                                 NRF_RADIOCORE_RTC
  #define NRF_RADIO                               NRF_RADIOCORE_RADIO
  #define NRF_LRCCONF020                          NRF_RADIOCORE_LRCCONF020
  #define NRF_SPU030                              NRF_RADIOCORE_SPU030
  #define NRF_PPIB030                             NRF_RADIOCORE_PPIB030
  #define NRF_VPR                                 NRF_RADIOCORE_VPR
  #define NRF_RAMC001                             NRF_RADIOCORE_RAMC001
  #define NRF_AAR030                              NRF_RADIOCORE_AAR030
  #define NRF_CCM030                              NRF_RADIOCORE_CCM030
  #define NRF_ECB030                              NRF_RADIOCORE_ECB030
  #define NRF_IPCT                                NRF_RADIOCORE_IPCT
  #define NRF_BELLBOARD                           NRF_RADIOCORE_BELLBOARD
#endif                                               /*!< NRF_RADIOCORE                                                        */

/* ========================================== End of section using anonymous unions ========================================== */

#if defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#endif


#ifdef __cplusplus
}
#endif
#endif /* NRF54H20_ENGA_RADIOCORE_H */

