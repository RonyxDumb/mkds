#include "file_command_handlers.h"

// Kept in .text after MaybeInitializeDwc_from_thumb.
#pragma define_section ARCHIVE_TEXT ".text"                                                                            \
                                    ".bss" abs32 RWX
#pragma section ARCHIVE_TEXT begin

// The File functions in the order the command numbers index them.
s32 (*fsi_default_command[9])(FSFile *file) = {
    Fs_File_DefaultOperation_ReadFile,     Fs_File_DefaultOperation_WriteFile,      Fs_File_DefaultOperation_SeekDirectory,
    Fs_File_DefaultOperation_ReadDirectory,      Fs_File_DefaultOperation_FindPath,       Fs_File_DefaultOperation_GetPath,
    Fs_File_DefaultOperation_OpenFileById, Fs_File_DefaultOperation_OpenFileRaw, Fs_File_DefaultOperation_CloseFile,
};

#pragma section ARCHIVE_TEXT end
