#include "xtmrctr.h"
#include "xintc.h"
#include "xparameters.h"
#include "xtmrctr_l.h"
#include "xintc_l.h"
#include "mb_interface.h"
#include <xbasic_types.h>
#include <xio.h>
#include "xgpio.h"


void display_stopwatch();
void update_time();
void toggle_start_stop();
void reset_stopwatch();
void toggle_mode();
void decrement_time();
void increment_time() ;
void changeCountParas(unsigned int btn);
