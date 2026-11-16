#include "Main/Scene/return_terminate_for_pulled_out.h"

// Returning 1 ends the program at once when the card is pulled out.
u32 InitGlobal_UserCardPulledOutCallback(void) {
    return 0x1u;
}
