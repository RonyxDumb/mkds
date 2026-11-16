#include "Main/Unknown/code_0203b070.h"
#include "Main/Unknown/unk_02164000.h"
#include "os_printf.h"

u32 race_getGhostFileName(u32 number, char *buffer, u32 size) {
    OS_SNPrintf(buffer, size, aDataGhostGho_1, number);
    return 1;
}
