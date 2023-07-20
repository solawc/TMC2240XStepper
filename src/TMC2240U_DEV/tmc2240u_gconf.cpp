#pragma once


#include "source/TMC_MACROS.h"
#include "TMCStepper.h"

// #define GET_REG(SETTING) return GCONF_register.SETTING;
#define GET_REG(SETTING) TMC2240U_n::GCONF_t r{0}; r.sr = GCONF(); return r.SETTING

#define SET_REG(SETTING) GCONF_register.SETTING = B; write(GCONF_register.address, GCONF_register.sr)

uint32_t TMC2240UStepper::GCONF() { return GCONF_register.sr; }
void TMC2240UStepper::GCONF(uint32_t data) {
  GCONF_register.sr = data;
  write(GCONF_register.address, GCONF_register.sr);
}

void TMC2240UStepper::en_pwm_mode(uint8_t B) 	{ SET_REG(en_pwm_mode); 	}
uint8_t TMC2240UStepper::en_pwm_mode() 	{ GET_REG(en_pwm_mode); 	}


void TMC2240UStepper::diag1_stall(uint8_t B) 	{ SET_REG(diag1_stall); 	}
// void TMC2240UStepper::slo_control(uint8_t B) 	{ SET_REG(slo_control);	}



uint8_t TMC2240UStepper::diag1_stall() 	{ GET_REG(diag1_stall); 	}
// uint8_t TMC2240UStepper::slo_control() 	{ GET_REG(slo_control);	}