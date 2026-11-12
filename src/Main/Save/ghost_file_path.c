#include "Main/Save/ghost_file_path.h"
#include "Main/Unknown/unk_02164000.h"
#include "os_printf.h"

u32 FormatGhostFilePath(u32 number, char *buffer, u32 size) {
    OS_SNPrintf(buffer, size, data_02164770, number);
    return 1;
}
