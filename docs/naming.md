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

## Game code: names from the functions' names and files

These units are named after the subject all (or, where noted, most) of their functions' names share, and the files
they load where they load any. Each folder of `src/Main/` is one subsystem: `Race/` (what runs during a race and
its screens), `Kart/`, `Item/`, `Course/` (course objects and their models), `Save/` (backup memory and records),
`System/` (heaps and other services), `Scene/` (one screen of the menus each), `Ui/` (parts several screens use).
The folders are this repository's grouping; the game gives no folder names.

| Unit | Former name | Evidence |
| --- | --- | --- |
| `src/Main/Race/RaceHudSubScreen.c` | `code_020c7464.c` | 51 functions `Create`/`Update`/`Draw`/`Clear` + `RaceHudSubScreen` + karts, items, car, second hand and course objects |
| `src/Main/Race/RaceHudSubScreenObjects.c` | `code_020cccd8.c` | 67 functions `...RaceHudSubScreen<object>Cells` for course objects |
| `src/01/RaceHudSubScreenMissionObjects.c` | `code_021892ac.c` | 28 functions `...RaceHudSubScreen<object>Cells` for mission objects (`BombKing`, `MissionGate`, `StopSign` ...) |
| `src/Main/Race/RaceStartSequence.c` | `code_020b33d8.c` | 7 functions `...RaceStartSequence...` |
| `src/Main/Scene/RecordVSErase.c` | `code_021145b4.c` | 34 functions `...RecordVSErase...` |
| `src/Main/Scene/SelectCupCourse.c` | `code_0211952c.c` | 16 functions `...SelectCupCourse...`; `common.bmg`, `ghost.bmg` |
| `src/Main/Scene/SelectCupM.c` | `code_0211e4e8.c` | 10 functions `...SelectCupM...` |
| `src/Main/Kart/KartTurnEffects.c` | `code_0208c534.c` | 31 functions on `KartTurnEffects` and the level 2-4 effects |
| `src/Main/Kart/KartStates.c` | `code_0206a354.c` | 15 functions `Start`/`Advance`/`TryStart` + `KartState<n>`, `KartThunderShrink` |
| `src/Main/Item/ItemInUse.c` | `code_020ed5c0.c` | 15 functions on `ItemInUse` and item objects |
| `src/Main/Course/NsKiller.c` | `code_020937c4.c` | 15 functions on `NsKiller1` and `NsKiller2` |
| `src/Main/Course/Basabasa.c` | `code_0209219c.c` | 10 functions on `Basabasa` |
| `src/Main/Course/MapObjectModel.c` | `code_0209bc74.c` | 7 functions `CreateMapObjectModel...` |
| `src/Main/Save/GhostList.c` | `code_0202d990.c` | 10 functions on listed and slot ghosts |
| `src/Main/Save/BackupBlocks.c` | `code_02057a18.c` | 9 functions `ReadBackup...`/`WriteBackup...` |
| `src/Main/System/Heap.c` | `code_02036820.c` | 9 functions `Heap...`, `Create...Heap...` |
| `src/Main/Ui/KartIcon.c` | `code_021171a0.c` | 6 functions on `KartIcon` |
| `src/Main/Ui/CupPicture.c` | `code_020d0f78.c` | 4 functions on `CupPicture`; `_m_picture.NSCR`, `_m_b.NCGR` |
| `src/Main/Ui/BackScreen.c` | `code_021258f0.c` | `LoadBackScreen` and the loading of the text system, select choices and select return; `back_screen_*` files |
| `src/Main/Ui/ChoisesS.c` | `code_020b1de4.c` | 17 of its 52 functions named, `InitChoisesS`, `UpdateChoisesS` and the `ChoisesS` list; `choises_s_*` files |
| `src/03/EditKeyboard.c` | `code_021c04ec.c` | 18 functions on `EditKeyboard` |
| `src/03/EditAddrKeyboard.c` | `code_021c0fd8.c` | 28 functions on `EditAddrKeyboard` |

Not renamed yet, although their functions are named: the units of the logo screen (`code_02001080.c`,
`code_02001294.c`, `code_020019b0.c`) may be one file, and units whose functions have two subjects
(`code_020b9994.c`: race item slot and mode count; `code_0211de00.c`: cup mark and cup name; `code_02056700.c`:
mission, ghost and emblem records) need their boundaries checked first.

## Units that do not follow the unit rules

`src/Main/Unknown/code_0200007e.c` holds the BIOS call stubs of the secure area (`0x02000000`-`0x02000800`). Its
functions match, but the bytes around them are not in the source, so the unit is not linked and
`tools/check_units.py` reports its range (it does not start with a function, and bytes follow the last one) for
both versions. The stubs are at different addresses in the two versions.
