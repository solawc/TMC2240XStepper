#pragma once


#include "source/TMC_MACROS.h"
#include "TMCStepper.h"

// #define GET_REG(SETTING) return TCOOLTHRS_register.SETTING;
#define GET_REG(SETTING) TMC2240U_n::TCOOLTHRS_t r{0}; r.sr = TCOOLTHRS(); return r.SETTING

#define SET_REG(SETTING) TCOOLTHRS_register.SETTING = B; write(TCOOLTHRS_register.address, TCOOLTHRS_register.sr)

uint32_t TMC2240UStepper::TCOOLTHRS() { return TCOOLTHRS_register.sr; }
void TMC2240UStepper::TCOOLTHRS(uint32_t data) {
  TCOOLTHRS_register.sr = data;
  write(TCOOLTHRS_register.address, TCOOLTHRS_register.sr);
}


void TMC2240UStepper::tcoolthrs(uint8_t B) 	{ SET_REG(tcoolthrs); 	}
uint8_t TMC2240UStepper::tcoolthrs() 	{ GET_REG(tcoolthrs); 	}


