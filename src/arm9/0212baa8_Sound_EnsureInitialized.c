/* Decompiled C draft; module arm9; ROM address 0212baa8. No matching claim. */
#include "types.h"
#include "deps/0212baa8_Sound_EnsureInitialized.h"

void Sound_EnsureInitialized(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*(uint *)((uint)puRam0212bb34 & 0xfffffffc) >> ((uint)puRam0212bb34 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0212bb34 & 0xfffffffc) << ((uint)puRam0212bb34 & 3) * -8 + 0x20 == 0) {
    *puRam0212bb34 = 1;
    Sound_InitializeImpl();
    uVar3 = uRam0212bb44;
    puVar2 = puRam0212bb40;
    puVar1 = puRam0212bb3c;
    *puRam0212bb3c = uRam0212bb38;
    puVar1[1] = 0;
    *puVar2 = uVar3;
    puVar2[1] = 0;
    func_0214f4ec();
    func_0214f4d4((undefined4)(uintptr_t)(puRam0212bb40));
    func_0212bb50();
    func_0212d0ec();
    func_0212c310();
    puVar1 = puRam0212bb4c;
    *puRam0212bb48 = 0xff;
    *puVar1 = 1;
    return;
  }
  return;
}

