# SP0256-AL2 Allophones

This table combines the repository's original allophone spreadsheet with the
SP0256-AL2 datasheet notes. The AL2 pattern uses six address lines (`A1`-`A6`)
for 64 locations: 59 speech allophones plus five pauses. `A7` and `A8` can be
tied to ground for this set.

The `Duration` column comes from the SP0256-AL2 datasheet address table. The
values are nominal allophone lengths and are useful for timing estimates, not
for exact sentence duration because phrase rhythm also depends on pauses and
how the chip blends adjacent sounds.

The code in this repository keeps the historical method names `D1`, `D2`, and
`S` to avoid conflicts with common C/C++ names that appeared in older examples.

| Hex | Octal | Allophone | Example | Duration | CMU phones |
| --- | --- | --- | --- | --- | --- |
| `00` | `000` | `PA1` | PAUSE | 10 ms |  |
| `01` | `001` | `PA2` | PAUSE | 30 ms |  |
| `02` | `002` | `PA3` | PAUSE | 50 ms |  |
| `03` | `003` | `PA4` | PAUSE | 100 ms |  |
| `04` | `004` | `PA5` | PAUSE | 200 ms |  |
| `05` | `005` | `OY` | Boy | 420 ms | OY, OY0, OY1, OY2 |
| `06` | `006` | `AY` | Sky | 260 ms | AY, AY0, AY1, AY2 |
| `07` | `007` | `EH` | End | 70 ms | EH, EH0, EH1, EH2 |
| `08` | `010` | `KK3` | Comb | 120 ms | K |
| `09` | `011` | `PP` | Pow | 210 ms | P |
| `0A` | `012` | `JH` | Dodge | 140 ms | JH |
| `0B` | `013` | `NN1` | Thin | 140 ms | N |
| `0C` | `014` | `IH` | Sit | 70 ms | IH, IH0, IH1, IH2 |
| `0D` | `015` | `TT2` | To | 140 ms | T |
| `0E` | `016` | `RR1` | Rural | 170 ms | R |
| `0F` | `017` | `AX` | Succeed | 70 ms | AH, AH0, AH1, AH2 |
| `10` | `020` | `MM` | Milk | 180 ms | M |
| `11` | `021` | `TT1` | Part | 100 ms | T |
| `12` | `022` | `DH1` | They | 290 ms | DH |
| `13` | `023` | `IY` | See | 250 ms | IY, IY0, IY1, IY2 |
| `14` | `024` | `EY` | Beige | 280 ms | EY, EY0, EY1, EY2 |
| `15` | `025` | `D1` | Could | 70 ms | D |
| `16` | `026` | `UW1` | To | 100 ms | UW, UW0, UW1, UW2 |
| `17` | `027` | `AO` | Aught | 100 ms | AO, AO0, AO1, AO2 |
| `18` | `030` | `AA` | Hot | 100 ms | AA, AA0, AA1, AA2 |
| `19` | `031` | `YY2` | Yes | 180 ms | Y |
| `1A` | `032` | `AE` | Hat | 120 ms | AE, AE0, AE1, AE2 |
| `1B` | `033` | `HH1` | He | 130 ms | HH |
| `1C` | `034` | `BB1` | Business | 80 ms | B |
| `1D` | `035` | `TH` | Thin | 180 ms | TH |
| `1E` | `036` | `UH` | Book | 100 ms | UH, UH0, UH1, UH2 |
| `1F` | `037` | `UW2` | Food | 260 ms | UW, UW0, UW1, UW2 |
| `20` | `040` | `AW` | Out | 370 ms | AW, AW0, AW1, AW2 |
| `21` | `041` | `D2` | Do | 160 ms | D |
| `22` | `042` | `GG3` | Wig | 140 ms | G |
| `23` | `043` | `VV` | Vest | 190 ms | V |
| `24` | `044` | `GG1` | Got | 80 ms | G |
| `25` | `045` | `SH` | Ship | 160 ms | SH |
| `26` | `046` | `ZH` | Azure | 190 ms | ZH |
| `27` | `047` | `RR2` | Brain | 120 ms | R |
| `28` | `050` | `FF` | Food | 150 ms | F |
| `29` | `051` | `KK2` | Sky | 190 ms | K |
| `2A` | `052` | `KK1` | Can't | 160 ms | K |
| `2B` | `053` | `ZZ` | Zoo | 210 ms | Z |
| `2C` | `054` | `NG` | Anchor | 220 ms | NG |
| `2D` | `055` | `LL` | Lake | 110 ms | L |
| `2E` | `056` | `WW` | Wool | 180 ms | W |
| `2F` | `057` | `XR` | Repair | 360 ms | R |
| `30` | `060` | `WH` | Whig | 200 ms |  |
| `31` | `061` | `YY1` | Yes | 130 ms | Y |
| `32` | `062` | `CH` | Church | 190 ms | CH |
| `33` | `063` | `ER1` | Fir | 160 ms | ER, ER0, ER1, ER2 |
| `34` | `064` | `ER2` | Fir | 300 ms | ER, ER0, ER1, ER2 |
| `35` | `065` | `OW` | Beau | 240 ms | OW, OW0, OW1, OW2 |
| `36` | `066` | `DH2` | They | 240 ms | DH |
| `37` | `067` | `S` | Vest | 90 ms | S |
| `38` | `070` | `NN2` | No | 190 ms | N |
| `39` | `071` | `HH2` | Hoe | 180 ms | HH |
| `3A` | `072` | `OR` | Store | 330 ms |  |
| `3B` | `073` | `AR` | Alarm | 290 ms |  |
| `3C` | `074` | `YR` | Clear | 350 ms |  |
| `3D` | `075` | `GG2` | Guest | 40 ms | G |
| `3E` | `076` | `EL` | Saddle | 190 ms | L |
| `3F` | `077` | `BB2` | Business | 50 ms | B |
