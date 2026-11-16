#include "startup_entry.h"

void NtrStartup(void) {}

const void *Os_ReferSymbol(const void *symbol) {
    return symbol;
}
