#pragma once


#include "source/TMC_MACROS.h"
#include "TMCStepper.h"

// #define GET_REG(SETTING) return TPOWERDOWM_register.SETTING;
#define GET_REG(SETTING) TMC2240U_n::TPOWERDOWM_t r{0}; r.sr = TPOWERDOWM(); return r.SETTING

#define SET_REG(SETTING) TPOWERDOWM_register.SETTING = B; write(TPOWERDOWM_register.address, TPOWERDOWM_register.sr)

uint32_t TMC2240UStepper::TPOWERDOWM() { return TPOWERDOWM_register.sr; }
void TMC2240UStepper::TPOWERDOWM(uint32_t data) {
  TPOWERDOWM_register.sr = data;
  write(TPOWERDOWM_register.address, TPOWERDOWM_register.sr);
}

void TMC2240UStepper::semin(uint8_t B) 	{ SET_REG(semin); 	}
uint8_t TMC2240UStepper::semin() 	{ GET_REG(semin); 	}



