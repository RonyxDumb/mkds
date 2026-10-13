/* Decompiled C draft; module arm9; ROM address 0207851c. No matching claim. */
#include "types.h"
#include "deps/0207851c_StructCESub_SomeFn_from_thumb.h"

void StructCESub_SomeFn_from_thumb(int param_1)

{
  if ((*(int *)(*piRam02078570 + iRam02078574) != 0) && (*(int *)(param_1 + 0xb4) != 0)) {
    func_02010458(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4),uRam02078578);
    func_020101e8(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4),uRam0207857c);
    func_0201050c(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4),*(undefined4 *)(param_1 + 0xb4),
                  uRam02078578);
    func_02010294(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4),*(undefined4 *)(param_1 + 0xb4),
                  uRam0207857c);
  }
  return;
}

