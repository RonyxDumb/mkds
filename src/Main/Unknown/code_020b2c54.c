#include "Main/Unknown/code_020b2c54.h"

#include "Main/Unknown/code_020b2c68.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b2da4.h"
#include "Main/Unknown/code_020b2ecc.h"
#include "01/code_021956dc.h"

#pragma thumb on

void WriteChoisesSListScreenMap(void) {
    WriteChoisesSListTiles();
    MoveChoisesSSelectedValue(0);
    WriteChoisesSSelectedValueTiles();
}

#pragma thumb off

u32 ChoisesSIsBackupEnabled(void) {
    return (gBackupAccess->mBackupEnabled);
}
