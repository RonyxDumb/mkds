#include "code_02003024.h"
#include "code_02004dc0.h"

// Kept in .text after DWC_Init.
#pragma define_section ARCHIVE_TEXT ".text"                                                                                 \
                               ".bss" abs32 RWX
#pragma section ARCHIVE_TEXT begin

// The File functions in the order the command numbers index them.
s32 (*fsi_default_command[9])(FSFile *a) = {
    FSi_ReadFileCommand,     FSi_WriteFileCommand,      FSi_SeekDirCommand,
    FSi_ReadDirCommand,      FSi_FindPathCommand,       FSi_GetPathCommand,
    FSi_OpenFileFastCommand, FSi_OpenFileDirectCommand, FSi_CloseFileCommand,
};

u32 fsi_def_digest_key[16] = {
    0xdec00621, 0x3fce98ba, 0x9de392a6, 0x01edf246, 0x08cce376, 0xfa632356, 0xdfecd4ca, 0x3478629a,
    0x3c636d8f, 0x92ca22fe, 0x23978820, 0xc2aecfd2, 0xfe8d6732, 0x986483ca, 0x373efdac, 0x24584687,
};

#pragma section ARCHIVE_TEXT end
