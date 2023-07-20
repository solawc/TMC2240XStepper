#pragma once


#include "source/TMC_MACROS.h"
#include "TMCStepper.h"

// #define GET_REG(SETTING) return GLOBALSCALER_register.SETTING;
#define GET_REG(SETTING) TMC2240U_n::GLOBALSCALER_t r{0}; r.sr = GLOBALSCALER(); return r.SETTING

#define SET_REG(SETTING) GLOBALSCALER_register.SETTING = B; write(GLOBALSCALER_register.address, GLOBALSCALER_register.sr)

uint32_t TMC2240UStepper::GLOBALSCALER() { return GLOBALSCALER_register.sr; }
void TMC2240UStepper::GLOBALSCALER(uint32_t data) {
  GLOBALSCALER_register.sr = data;
  write(GLOBALSCALER_register.address, GLOBALSCALER_register.sr);
}


// void TMC2240UStepper::cur_range(uint8_t B) 	{ SET_REG(cur_range); 	}
// void TMC2240UStepper::slo_control(uint8_t B) 	{ SET_REG(slo_control);	}



// uint8_t TMC2240UStepper::cur_range() 	{ GET_REG(cur_range); 	}
// uint8_t TMC2240UStepper::slo_control() 	{ GET_REG(slo_control);	}



