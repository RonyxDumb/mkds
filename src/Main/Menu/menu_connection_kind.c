#include "Main/Menu/menu_connection_kind.h"
#include "Main/Unknown/unk_02175000.h"

u32 MenuGetConnectionKind(void) {
    return (gStartupWork->mConnectionKind);
}
