#include "Main/Save/ghost_file_path.h"
#include "Main/Race/data_02164000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "os_printf.h"

u32 FormatGhostFilePath(u32 number, char *buffer, u32 size) {
    OS_SNPrintf(buffer, size, data_02164770, number);
    return 1;
}
