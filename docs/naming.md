# File names

Units start as `code_<address>.c` in an `Unknown/` folder (or directly in an overlay's folder). A unit gets a name
once this repository shows what the file is: a file name the game itself contains, the subject its functions'
names share, or the files and strings it uses. This page records, for each renamed unit, what the name rests on.
Moves are made with `tools/rename_unit.py`, which also updates the header, every include, both versions'
`delinks.txt`, per-path settings in `tools/project.py` and paths in the docs.

A name says what is in the file now. A unit whose code still spans more than one original file keeps its address
name until its boundaries are fixed.

## Overlay 0: GameSpy (`src/00/GameSpy/`)

Overlay 0 contains the file names of the GameSpy sources it was built from, as the file arguments of their
assertions. Each unit below loads exactly one of these strings, and is named after it. Checked on the European
ROM; the addresses are the European ones.

| Unit | Former name | File name string |
| --- | --- | --- |
| `darray.c` | `code_0218d818.c` | `0x021b22dc` |
| `hashtable.c` | `code_0218dd8c.c` | `0x021b2358` |
| `nonport.c` | `code_0218e2dc.c` | `0x021b23d0` |
| `gp.c` | `code_0218e8d4.c` | `0x021b24d4` |
| `gpi.c` | `code_0218f15c.c` | `0x021b2620` |
| `gpiBuddy.c` | `code_0218f960.c` | `0x021b278c` |
| `gpiBuffer.c` | `code_021906e4.c` | `0x021b28a8` |
| `gpiCallback.c` | `code_02190cd4.c` | `0x021b2a58` |
| `gpiConnect.c` | `code_02190ff8.c` | `0x021b2b88` |
| `gpiInfo.c` | `code_0219218c.c` | `0x021b31f8` |
| `gpiOperation.c` | `code_02193634.c` | `0x021b32b0` |
| `gpiPeer.c` | `code_02193b88.c` | `0x021b333c` |
| `gpiProfile.c` | `code_021948f8.c` | `0x021b3554` |
| `gpiSearch.c` | `code_02194bb8.c` | `0x021b3628` |
| `gpiUtility.c` | `code_02196594.c` | `0x021b3a1c` |
| `gstats.c` | `code_0219742c.c` | `0x021b3e34` |
| `gt2Callback.c` | `code_02197e58.c` | `0x021b3f58` |
| `gt2Main.c` | `code_0219887c.c` | `0x021b3f98` |
| `gt2Message.c` | `code_02198d04.c` | `0x021b3fb8` |
| `gt2Utility.c` | `code_0219a654.c` | `0x021b3fec` |

Not renamed yet: `src/00/code_0218aea4.c` loads both `sb_server.c` and `sb_serverlist.c`, and
`src/00/code_02197b34.c` both `gt2Auth.c` and `gt2Buffer.c` (which `code_02197ddc.c` loads as well): each spans two
files, and its boundary has to be found first.

## Units that do not follow the unit rules

`src/Main/Unknown/code_0200007e.c` holds the BIOS call stubs of the secure area (`0x02000000`-`0x02000800`). Its
functions match, but the bytes around them are not in the source, so the unit is not linked and
`tools/check_units.py` reports its range (it does not start with a function, and bytes follow the last one) for
both versions. The stubs are at different addresses in the two versions.
