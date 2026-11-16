#include "Main/Menu/wl_menu_kind_set.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"

void SetWLMenuKind(u32 value) {
    g_GlobalB488->mWLMenuKind = value;
}
