#include "Main/Net/multiboot_child_files.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Net/download_screen_files.h"

struct DownloadScreenFiles *GetDownloadScreenFiles(void) {
    return gDownloadScreenFiles;
}
