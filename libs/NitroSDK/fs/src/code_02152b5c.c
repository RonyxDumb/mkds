#include "code_02003024.h"

// Kept in .text after DWC_Init.
#pragma define_section ARCHIVE_TEXT ".text"                                                                            \
                                    ".bss" abs32 RWX
#pragma section ARCHIVE_TEXT begin

// The File functions in the order the command numbers index them.
s32 (*fsi_default_command[9])(FSFile *file) = {
    FSi_ReadFileCommand,     FSi_WriteFileCommand,      FSi_SeekDirCommand,
    FSi_ReadDirCommand,      FSi_FindPathCommand,       FSi_GetPathCommand,
    FSi_OpenFileFastCommand, FSi_OpenFileDirectCommand, FSi_CloseFileCommand,
};

#pragma section ARCHIVE_TEXT end
