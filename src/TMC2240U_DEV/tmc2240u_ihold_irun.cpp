#pragma once


#include "source/TMC_MACROS.h"
#include "TMCStepper.h"

// #define GET_REG(SETTING) return IHOLD_IRUN_register.SETTING;
#define GET_REG(SETTING) TMC2240U_n::IHOLD_IRUN_t r{0}; r.sr = IHOLD_IRUN(); return r.SETTING

#define SET_REG(SETTING) IHOLD_IRUN_register.SETTING = B; write(IHOLD_IRUN_register.address, IHOLD_IRUN_register.sr)

uint32_t TMC2240UStepper::IHOLD_IRUN() { return IHOLD_IRUN_register.sr; }
void TMC2240UStepper::IHOLD_IRUN(uint32_t data) {
  IHOLD_IRUN_register.sr = data;
  write(IHOLD_IRUN_register.address, IHOLD_IRUN_register.sr);
}

void TMC2240UStepper::ihold(uint8_t B) 	{ SET_REG(ihold); 	}
void TMC2240UStepper::run(uint8_t B) 	{ SET_REG(run);	}
void TMC2240UStepper::iholddelay(uint8_t B) 	{ SET_REG(iholddelay); 	}
void TMC2240UStepper::irundelay(uint8_t B) 	{ SET_REG(irundelay);	}



uint8_t TMC2240UStepper::ihold() 	{ GET_REG(ihold); 	}
uint8_t TMC2240UStepper::run() 	{ GET_REG(run);	}
uint8_t TMC2240UStepper::iholddelay() 	{ GET_REG(iholddelay); 	}
uint8_t TMC2240UStepper::irundelay() 	{ GET_REG(irundelay);	}


