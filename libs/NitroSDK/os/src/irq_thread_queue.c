#include "irq_wait_handler.h"

#pragma explicit_zero_data on
OSThreadQueue g_DTCM = {NULL, NULL};
#pragma explicit_zero_data off
