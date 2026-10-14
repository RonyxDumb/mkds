/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define WM_GetOtherElements func_02142f24
#include <nitro/wm.h>

#include "wm_arm9_private.h"

#pragma thumb off
WMOtherElements WM_GetOtherElements (WMBssDesc * bssDesc)
{
    WMOtherElements elems;
    u8 * p_elem;
    int i;
    u8 curr_elem_len;
    u8 elems_len;
    u8 elems_len_counter;

    if (bssDesc->gameInfoLength != 0) {
        elems.count = 0;
        return elems;
    }

    elems.count = (u8)(bssDesc->otherElementCount);

    if (elems.count == 0)
        return elems;

    if (elems.count > WM_SCAN_OTHER_ELEMENT_MAX)
        elems.count = WM_SCAN_OTHER_ELEMENT_MAX;

    p_elem = (u8 *)&(bssDesc->gameInfo);

    elems_len = (u8)((bssDesc->length * sizeof(u16)) - 64);
    elems_len_counter = 0;

    for (i = 0; i < elems.count; ++i) {
        elems.element[i].id = p_elem[0];
        elems.element[i].length = p_elem[1];
        elems.element[i].body = (u8 *)&(p_elem[2]);

        curr_elem_len = (u8)(elems.element[i].length + 2);
        elems_len_counter += curr_elem_len;

        if (elems_len_counter > elems_len) {
            WM_WARNING("Elements length error.\n");
            elems.count = 0;
            return elems;
        }

        p_elem = (u8 *)(p_elem + curr_elem_len);
    }

    return elems;
}
