#include "Main/Menu/wl_menu_kind.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"

u32 GetWLMenuKind(void) {
    return (gMenuShared->mWLMenuKind);
}
