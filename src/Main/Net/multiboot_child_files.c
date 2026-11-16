#include "Main/Net/multiboot_child_files.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Net/download_screen_files.h"

struct DownloadScreenFiles *GetGlobal2DObject(void) {
    return g_Global2D;
}
