#include "TMCStepper.h"

void TMC2240UStepper::begin() {
  //set pins
	#if SW_CAPABLE_PLATFORM
		beginSerial(115200);
	#endif

  //TODO: Push shadow registers

  // toff(8); //off_time(8);
  // tbl(1); //blank_time(24);
}
int32_t TMC2240UStepper::read_ver() {
  return read(0x04);
}


uint16_t TMC2240UStepper::cs2rms(uint8_t CS) {
  // return (float)(CS+1)/32.0 * (vsense() ? 0.165 : 0.310)/(Rsense+0.02) / 1.41421 * 1000;
}

uint16_t TMC2240UStepper::rms_current() {

  uint8_t cur_run = run();
  return (cur_run * 3000 / 32);
  // return cs2rms(cs());
}
void TMC2240UStepper::rms_current(uint16_t mA) {

    // uint16_t cur_ma = 0;
    // uint16_t set_cur = 0;
    // uint32_t set_data = 0;
    // cur_ma = mA;

    // set_cur = (mA*32/3000);

    // set_data = 0x00060005;

    // set_data = set_data | (set_cur << 8);

    // IHOLD_IRUN(set_data);
    float rel_ma = mA * 1.414;
    uint16_t cur_ma = 0;
    uint16_t set_cur = 0;
    uint32_t set_data = 0;
    cur_ma = mA;

    set_cur = (rel_ma*32/3000);

    set_data = 0x00060005;

    set_data = set_data | (set_cur << 8);

    IHOLD_IRUN(set_data);
}

uint8_t TMC2240UStepper::test_connection() {
  uint32_t drv_status = read_ver()/*DRVSTATUS()*/;
  switch (drv_status & 0xff000000) {
      case 0x40000000: return 0;
      case 0: return 2;
      default: return 1;
  }
}

void TMC2240UStepper::hysteresis_end(int8_t value) { hend(value+3); }
int8_t TMC2240UStepper::hysteresis_end() { return hend()-3; };

void TMC2240UStepper::hysteresis_start(uint8_t value) { hstrt(value-1); }
uint8_t TMC2240UStepper::hysteresis_start() { return hstrt()+1; }

void TMC2240UStepper::microsteps(uint16_t ms) {
  switch(ms) {
    case 256: mres(0); break;
    case 128: mres(1); break;
    case  64: mres(2); break;
    case  32: mres(3); break;
    case  16: mres(4); break;
    case   8: mres(5); break;
    case   4: mres(6); break;
    case   2: mres(7); break;
    case   0: mres(8); break;
    default: break;
  }
}

uint16_t TMC2240UStepper::microsteps() {
  switch(mres()) {
    case 0: return 256;
    case 1: return 128;
    case 2: return  64;
    case 3: return  32;
    case 4: return  16;
    case 5: return   8;
    case 6: return   4;
    case 7: return   2;
    case 8: return   0;
  }
  return 0;
}

void TMC2240UStepper::blank_time(uint8_t value) {
  switch (value) {
    case 16: tbl(0b00); break;
    case 24: tbl(0b01); break;
    case 36: tbl(0b10); break;
    case 54: tbl(0b11); break;
  }
}

uint8_t TMC2240UStepper::blank_time() {
  switch (tbl()) {
    case 0b00: return 16;
    case 0b01: return 24;
    case 0b10: return 36;
    case 0b11: return 54;
  }
  return 0;
}