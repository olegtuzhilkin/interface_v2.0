//=========================================================
// src/interface_v1.0_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include <math.h>
// $[Generated Includes]
// [Generated Includes]$

#define THR 2		//LED switching threshold

void getdataslice(unsigned char *Addr, unsigned int *Data);

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup(void) {
	// $[SiLabs Startup]
	// [SiLabs Startup]$
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void) {
	unsigned char addr, i;
	unsigned int dat, U1, U2, txRel, result;
	unsigned char packet[9] = "#U1%1234!";
	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	SFRPAGE = 0x20;

	while (1) {
// $[Generated Run-time code]
// [Generated Run-time code]$
		while (!WR)
			;
		getdataslice(&addr, &dat);
		switch (addr) {
		case AU1: {
			U1 = dat;
			break;
		}
		case AU2: {
			U2 = dat;
			/*		 packet[1] = 'U'; packet[2] = '2';
			 packet[4] = 0x30|((dat&0x3000)>>12);
			 packet[5] = 0x30|((dat&0x0F00)>>8);
			 packet[6] = 0x30|((dat&0x00F0)>>4);
			 packet[7] = 0x30|((dat&0x000F));*/
			if (abs(U1-U2) <= THR)
				ZERO = 1;
			else
				ZERO = 0;
			break;
		}
		case AKU: {
			txRel = dat;
			/*		 packet[1] = 'K'; packet[2] = 'U';
			 packet[4] = 0x30|((dat&0x3000)>>12);
			 packet[5] = 0x30|((dat&0x0F00)>>8);
			 packet[6] = 0x30|((dat&0x00F0)>>4);
			 packet[7] = 0x30|((dat&0x000F));*/
			break;
		}
		case ARE: {
			result = dat;

			//DE = 1;

			packet[1] = 'U';
			packet[2] = '1';
			packet[4] = 0x30 | ((U1 & 0x3000) >> 12);
			packet[5] = 0x30 | ((U1 & 0x0F00) >> 8);
			packet[6] = 0x30 | ((U1 & 0x00F0) >> 4);
			packet[7] = 0x30 | ((U1 & 0x000F));

			for (i = 0; i < 9; i++) {
				while (!UART1FCN1_TXNF)
					;
				SBUF1 = packet[i];
			};

			packet[1] = 'U';
			packet[2] = '2';
			packet[4] = 0x30 | ((U2 & 0x3000) >> 12);
			packet[5] = 0x30 | ((U2 & 0x0F00) >> 8);
			packet[6] = 0x30 | ((U2 & 0x00F0) >> 4);
			packet[7] = 0x30 | ((U2 & 0x000F));

			for (i = 0; i < 9; i++) {
				while (!UART1FCN1_TXNF)
					;
				SBUF1 = packet[i];
			};

			packet[1] = 'D';
			packet[2] = 'S';
			packet[4] = 0x30 | ((txRel & 0x3000) >> 12);
			packet[5] = 0x30 | ((txRel & 0x0F00) >> 8);
			packet[6] = 0x30 | ((txRel & 0x00F0) >> 4);
			packet[7] = 0x30 | ((txRel & 0x000F));

			for (i = 0; i < 9; i++) {
				while (!UART1FCN1_TXNF)
					;
				SBUF1 = packet[i];
			};

			packet[1] = 'R';
			packet[2] = 'S';
			packet[4] = 0x30 | ((result & 0x3000) >> 12);
			packet[5] = 0x30 | ((result & 0x0F00) >> 8);
			packet[6] = 0x30 | ((result & 0x00F0) >> 4);
			packet[7] = 0x30 | ((result & 0x000F));

			for (i = 0; i < 9; i++) {
				while (!UART1FCN1_TXNF)
					;
				SBUF1 = packet[i];
			};

			break;
		}
		default:
			break;
		}
	}
}
//-----------------------------------------------------------------------------
// Getting data and address from port
// ----------------------------------------------------------------------------
void getdataslice(unsigned char *Addr, unsigned int *Data) {
	unsigned int p0, p1, p2;

	p0 = P0;
	p1 = P1;
	p2 = P2;
//				P2^2		P2^3			P2^4
	*Addr = ((p2 & 0x04)) | ((p2 & 0x08) >> 2) | ((p2 & 0x10) >> 4);
//				P0^4			P0^5			P0^6		P0^7
	*Data = ((p0 & 0x10) << 9) | ((p0 & 0x20) << 7) | ((p0 & 0x40) << 5)
			| ((p0 & 0x80) << 3)
			|
//				P1^0			P1^1			P1^2			P1^3
			((p1 & 0x01) << 9) | ((p1 & 0x02) << 7) | ((p1 & 0x04) << 5)
			| ((p1 & 0x08) << 3)
			|
//				P1^4			P1^5			P1^6			P1^7
			((p1 & 0x10) << 1) | ((p1 & 0x20) >> 1) | ((p1 & 0x40) >> 3)
			| ((p1 & 0x80) >> 5) |
//				P2^0			P2^1
			((p2 & 0x01) << 1) | ((p2 & 0x02) >> 1);
	return;
}

