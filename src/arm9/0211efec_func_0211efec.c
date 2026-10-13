/* Decompiled C draft; module arm9; ROM address 0211efec. No matching claim. */
#include "types.h"
#include "deps/0211efec_func_0211efec.h"

void func_0211efec(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (*psRam0211f208 != 2) {
    uVar1 = find_buf_fn_from_thumb(*puRam0211f20c);
    MaybeReadCharBlock_1(&local_20,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f210);
    Gfx_ReadPaletteRelative(&local_18,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f214);
    MaybeReadScreenBlock(&local_1c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f20c);
    MaybeReadCharBlock_1(&local_14,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f210);
    Gfx_ReadPaletteRelative(&local_c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f214);
    MaybeReadScreenBlock(&local_10,uVar1);
    uVar1 = Mem_AllocateHeap(*(undefined4 *)(*piRam0211f218 + 0x28),uRam0211f21c);
    *(undefined4 *)(*piRam0211f218 + 0x20) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211f220);
    *(undefined4 *)(*piRam0211f218 + 4) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211f224);
    *(undefined4 *)(*piRam0211f218 + 8) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211f228);
    Gfx_ReadCharGraphicsRelative(&local_30,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f22c);
    func_020b48b4((int *)(uintptr_t)(*piRam0211f218),uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f230);
    Gfx_ReadPaletteRelative(&local_2c,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f220);
    *(undefined4 *)(*piRam0211f218 + 0x10) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211f224);
    *(undefined4 *)(*piRam0211f218 + 0x14) = uVar1;
    uVar1 = find_buf_fn_from_thumb(*puRam0211f228);
    Gfx_ReadCharGraphicsRelative(&local_28,uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f22c);
    func_020b48b4((int *)(uintptr_t)(*piRam0211f218 + 0xc),uVar1);
    uVar1 = find_buf_fn_from_thumb(*puRam0211f230);
    Gfx_ReadPaletteRelative(&local_24,uVar1);
    iVar3 = *(int *)(local_2c + 0xc);
    iVar2 = func_020cccb4();
    if ((iVar2 != 0x17) && (iVar2 = func_020cccb4(), iVar2 != 0xb)) {
      AllocateReserveTEQSub(4,0,*(undefined4 *)(local_20 + 0x14),*(undefined4 *)(local_20 + 0x10));
      AllocateReserveTEQSub(0xf,0,*(undefined4 *)(local_18 + 0xc),uRam0211f234);
      AllocateReserveTEQSub(8,0,local_1c + 0xc,*(undefined4 *)(local_1c + 8));
      AllocateReserveTEQSub(8,uRam0211f21c,*(undefined4 *)(*piRam0211f218 + 0x20),uRam0211f21c);
    }
    iVar2 = func_020cccb4();
    if ((iVar2 != 0x19) && (iVar2 = func_020cccb4(), iVar2 != 0xd)) {
      AllocateReserveTEQSub
                (0x17,0,*(undefined4 *)(local_14 + 0x14),*(undefined4 *)(local_14 + 0x10));
      AllocateReserveTEQSub(0x1f,0,*(undefined4 *)(local_c + 0xc),uRam0211f234);
      AllocateReserveTEQSub(0x1b,0,local_10 + 0xc,*(undefined4 *)(local_10 + 8));
      AllocateReserveTEQSub(0x1b,uRam0211f21c,*(undefined4 *)(*piRam0211f218 + 0x20),uRam0211f21c);
    }
    AllocateReserveTEQSub(0x13,0,*(undefined4 *)(local_30 + 0x14),*(undefined4 *)(local_30 + 0x10));
    AllocateReserveTEQSub(0xe,0,*(undefined4 *)(local_2c + 0xc),uRam0211f238);
    AllocateReserveTEQSub(0xe,iRam0211f23c,iVar3 + iRam0211f23c,0x40);
    AllocateReserveTEQSub(0x23,0,*(undefined4 *)(local_28 + 0x14),*(undefined4 *)(local_28 + 0x10));
    AllocateReserveTEQSub(0x1e,0,*(undefined4 *)(local_24 + 0xc),*(undefined4 *)(local_24 + 8));
  }
  return;
}

