/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205fbd0 func_0214fe88
#define func_0205fab4 func_0214fcb0
#include "../../vendor/sm64ds/include/types.h"
extern int func_0205fbd0(int v, int b, int c);

int func_0205fab4(int x, int b, int c)
{
    int v;
    switch (x) {
    case 1: v = 1; break;
    case 3: v = 2; break;
    case 2: v = 3; break;
    default: v = 0; break;
    }
    if (v == 0) return 0xffff;
    return func_0205fbd0(v, b, c);
}
