//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8LB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	WDT_0_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PORTS_2_enter_DefaultMode_from_RESET();
	PORTS_3_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	EXTOSC_0_enter_DefaultMode_from_RESET();
	CIP51_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	UARTE_1_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

extern void WDT_0_enter_DefaultMode_from_RESET(void) {
	// $[Watchdog Timer Init Variable Declarations]
	uint32_t i;
	bool ea;
	// [Watchdog Timer Init Variable Declarations]$

	// $[WDTCN - Watchdog Timer Control]
	// Deprecated
	// [WDTCN - Watchdog Timer Control]$

	// $[WDTCN_2 - Watchdog Timer Control]
	SFRPAGE = 0x00;

	// Feed WDT timer before disabling (Erratum WDT_E102)
	WDTCN = 0xA5;

	// Add 2 LFO cycle delay before disabling WDT (Erratum WDT_E102)
	for (i = 0; i < (2 * 3062500UL) / (80000 * 3); i++) {
		NOP();
	}

	// Disable WDT
	ea = IE_EA;
	IE_EA = 0;
	WDTCN = 0xDE;
	WDTCN = 0xAD;
	IE_EA = ea;

	// [WDTCN_2 - Watchdog Timer Control]$

}

extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/***********************************************************************
	 - P0.0 output is open-drain
	 - P0.1 output is push-pull
	 - P0.2 output is open-drain
	 - P0.3 output is open-drain
	 - P0.4 output is open-drain
	 - P0.5 output is open-drain
	 - P0.6 output is open-drain
	 - P0.7 output is open-drain
	 ***********************************************************************/
	P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__PUSH_PULL
			| P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__OPEN_DRAIN
			| P0MDOUT_B4__OPEN_DRAIN | P0MDOUT_B5__OPEN_DRAIN
			| P0MDOUT_B6__OPEN_DRAIN | P0MDOUT_B7__OPEN_DRAIN;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/***********************************************************************
	 - P0.0 pin is skipped by the crossbar
	 - P0.1 pin is not skipped by the crossbar
	 - P0.2 pin is not skipped by the crossbar
	 - P0.3 pin is skipped by the crossbar
	 - P0.4 pin is not skipped by the crossbar
	 - P0.5 pin is not skipped by the crossbar
	 - P0.6 pin is not skipped by the crossbar
	 - P0.7 pin is not skipped by the crossbar
	 ***********************************************************************/
	P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__NOT_SKIPPED
			| P0SKIP_B2__NOT_SKIPPED | P0SKIP_B3__SKIPPED
			| P0SKIP_B4__NOT_SKIPPED | P0SKIP_B5__NOT_SKIPPED
			| P0SKIP_B6__NOT_SKIPPED | P0SKIP_B7__NOT_SKIPPED;
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$

}

extern void PORTS_3_enter_DefaultMode_from_RESET(void) {
	// $[P3 - Port 3 Pin Latch]
	// [P3 - Port 3 Pin Latch]$

	// $[P3MDOUT - Port 3 Output Mode]
	/***********************************************************************
	 - P3.0 output is push-pull
	 - P3.1 output is open-drain
	 - P3.2 output is open-drain
	 - P3.3 output is push-pull
	 - P3.4 output is open-drain
	 - P3.7 output is open-drain
	 ***********************************************************************/
	SFRPAGE = 0x20;
	P3MDOUT = P3MDOUT_B0__PUSH_PULL | P3MDOUT_B1__OPEN_DRAIN
			| P3MDOUT_B2__OPEN_DRAIN | P3MDOUT_B3__PUSH_PULL
			| P3MDOUT_B4__OPEN_DRAIN | P3MDOUT_B7__OPEN_DRAIN;
	// [P3MDOUT - Port 3 Output Mode]$

	// $[P3MDIN - Port 3 Input Mode]
	// [P3MDIN - Port 3 Input Mode]$

}

extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 - UART1 TX1 RX1 routed to Port pins
	 - UART1 RTS1 unavailable at Port pin
	 - UART1 CTS1 unavailable at Port pin
	 ***********************************************************************/
	SFRPAGE = 0x00;
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED
			| XBR2_URT1E__ENABLED | XBR2_URT1RTSE__DISABLED
			| XBR2_URT1CTSE__DISABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[PRTDRV - Port Drive Strength]
	// [PRTDRV - Port Drive Strength]$

	// $[XBR0 - Port I/O Crossbar 0]
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

}

extern void CIP51_0_enter_DefaultMode_from_RESET(void) {
	// $[PFE0CN - Prefetch Engine Control]
	/***********************************************************************
	 - SYSCLK < 50 MHz
	 ***********************************************************************/
	SFRPAGE = 0x10;
	PFE0CN = PFE0CN_FLRT__SYSCLK_BELOW_50_MHZ;
	// [PFE0CN - Prefetch Engine Control]$

}

extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {
	// $[HFOSC1 Setup]
	// [HFOSC1 Setup]$

	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - Clock derived from the External Oscillator circuit
	 - SYSCLK is equal to selected clock source divided by 1
	 ***********************************************************************/
	SFRPAGE = 0x00;
	CLKSEL = CLKSEL_CLKSL__EXTOSC | CLKSEL_CLKDIV__SYSCLK_DIV_1;
	while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
		;
	// [CLKSEL - Clock Select]$

}

extern void UARTE_1_enter_DefaultMode_from_RESET(void) {
	// $[SBCON1 - UART1 Baud Rate Generator Control]
	/***********************************************************************
	 - Enable the baud rate generator
	 - Prescaler = 4
	 ***********************************************************************/
	SFRPAGE = 0x20;
	SBCON1 = SBCON1_BREN__ENABLED | SBCON1_BPS__DIV_BY_4;
	// [SBCON1 - UART1 Baud Rate Generator Control]$

	// $[SMOD1 - UART1 Mode]
	// [SMOD1 - UART1 Mode]$

	// $[UART1FCN0 - UART1 FIFO Control 0]
	// [UART1FCN0 - UART1 FIFO Control 0]$

	// $[SBRLH1 - UART1 Baud Rate Generator High Byte]
	/***********************************************************************
	 - UART1 Baud Rate Reload High = 0xFF
	 ***********************************************************************/
	SBRLH1 = (0xFF << SBRLH1_BRH__SHIFT);
	// [SBRLH1 - UART1 Baud Rate Generator High Byte]$

	// $[SBRLL1 - UART1 Baud Rate Generator Low Byte]
	/***********************************************************************
	 - UART1 Baud Rate Reload Low = 0xCC
	 ***********************************************************************/
	SBRLL1 = (0xCC << SBRLL1_BRL__SHIFT);
	// [SBRLL1 - UART1 Baud Rate Generator Low Byte]$

	// $[UART1LIN - UART1 LIN Configuration]
	// [UART1LIN - UART1 LIN Configuration]$

	// $[SCON1 - UART1 Serial Port Control]
	/***********************************************************************
	 - UART1 reception enabled
	 ***********************************************************************/
	SCON1 |= SCON1_REN__RECEIVE_ENABLED;
	// [SCON1 - UART1 Serial Port Control]$

	// $[UART1FCN1 - UART1 FIFO Control 1]
	// [UART1FCN1 - UART1 FIFO Control 1]$

}

extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	// [P1SKIP - Port 1 Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

}

extern void PORTS_2_enter_DefaultMode_from_RESET(void) {
	// $[P2 - Port 2 Pin Latch]
	// [P2 - Port 2 Pin Latch]$

	// $[P2MDOUT - Port 2 Output Mode]
	// [P2MDOUT - Port 2 Output Mode]$

	// $[P2MDIN - Port 2 Input Mode]
	// [P2MDIN - Port 2 Input Mode]$

	// $[P2SKIP - Port 2 Skip]
	// [P2SKIP - Port 2 Skip]$

	// $[P2MASK - Port 2 Mask]
	// [P2MASK - Port 2 Mask]$

	// $[P2MAT - Port 2 Match]
	// [P2MAT - Port 2 Match]$

}

extern void EXTOSC_0_enter_DefaultMode_from_RESET(void) {
	// $[Delay counter definition]
	// [Delay counter definition]$

	// $[XOSC0CN - External Oscillator Control]
	/***********************************************************************
	 - External CMOS Clock Mode
	 ***********************************************************************/
	XOSC0CN &= ~XOSC0CN_XOSCMD__FMASK;
	XOSC0CN |= XOSC0CN_XOSCMD__CMOS;
	// [XOSC0CN - External Oscillator Control]$

}

