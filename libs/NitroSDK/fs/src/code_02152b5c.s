// Two tables kept in .text after DWC_Init: the nine File functions in the order fsi_default_command is indexed, and the
// words of fsi_def_digest_key.
//
// Hand-written asm: the data has to sit in .text.

    .text
    .extern FSi_ReadFileCommand
    .extern FSi_WriteFileCommand
    .extern FSi_SeekDirCommand
    .extern FSi_ReadDirCommand
    .extern FSi_FindPathCommand
    .extern FSi_GetPathCommand
    .extern FSi_OpenFileFastCommand
    .extern FSi_OpenFileDirectCommand
    .extern FSi_CloseFileCommand

    .global fsi_default_command
    .type fsi_default_command, @object
fsi_default_command:
    .word FSi_ReadFileCommand
    .word FSi_WriteFileCommand
    .word FSi_SeekDirCommand
    .word FSi_ReadDirCommand
    .word FSi_FindPathCommand
    .word FSi_GetPathCommand
    .word FSi_OpenFileFastCommand
    .word FSi_OpenFileDirectCommand
    .word FSi_CloseFileCommand
    .size fsi_default_command, . - fsi_default_command

    .global fsi_def_digest_key
    .type fsi_def_digest_key, @object
fsi_def_digest_key:
    .word 0xdec00621
    .word 0x3fce98ba
    .word 0x9de392a6
    .word 0x01edf246
    .word 0x08cce376
    .word 0xfa632356
    .word 0xdfecd4ca
    .word 0x3478629a
    .word 0x3c636d8f
    .word 0x92ca22fe
    .word 0x23978820
    .word 0xc2aecfd2
    .word 0xfe8d6732
    .word 0x986483ca
    .word 0x373efdac
    .word 0x24584687
    .size fsi_def_digest_key, . - fsi_def_digest_key
