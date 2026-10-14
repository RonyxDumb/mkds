/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define Maybe_check_0287c8 Maybe_check_03075c
typedef unsigned short u16;
typedef struct { u16 pad0[2]; u16 f4; u16 pad6[3]; u16 fc; } S;

int Maybe_check_0287c8(S *obj) {
    return obj->fc == 0 && obj->f4 != 0;
}
