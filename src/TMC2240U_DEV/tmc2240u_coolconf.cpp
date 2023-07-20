#pragma once


#include "source/TMC_MACROS.h"
#include "TMCStepper.h"

// #define GET_REG(SETTING) return COOLCONF_register.SETTING;
#define GET_REG(SETTING) TMC2240U_n::COOLCONF_t r{0}; r.sr = COOLCONF(); return r.SETTING

#define SET_REG(SETTING) COOLCONF_register.SETTING = B; write(COOLCONF_register.address, COOLCONF_register.sr)


uint32_t TMC2240UStepper::COOLCONF() { return COOLCONF_register.sr; }
void TMC2240UStepper::COOLCONF(uint32_t data) {
  COOLCONF_register.sr = data;
  write(COOLCONF_register.address, COOLCONF_register.sr);
}

void TMC2240UStepper::sgt(uint8_t B) { SET_REG(sgt); }
uint8_t TMC2240UStepper::sgt(){ GET_REG(sgt); }


