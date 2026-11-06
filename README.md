# Totem — QMK / Vial

QMK firmware for the **Totem** split keyboard, built with **Vial** so the
layout can be remapped from the browser with no rebuild.

These are the author's own builds, mirrored here so they are easy to find:
the `.uf2` files are byte-for-byte the ones published in
[GEIGEIGEIST/TOTEM](https://github.com/GEIGEIGEIST/TOTEM/tree/main/firmware/QMK).

## Specs

| | |
|---|---|
| Model | Totem |
| Firmware | QMK + Vial |
| Layout | Split column-staggered 3×5 + 3 thumb keys (38 keys) |
| Switches | Kailh Choc (low profile) |
| Controller | Seeed XIAO RP2040 |
| Connection | USB-C, wired between halves |

> The controller matters: these builds target the **XIAO RP2040**. They will
> not run on the XIAO nRF52840 (BLE), which uses a different chip.

## Download

Grab the zip from [Releases](../../releases) — it holds all three `.uf2`
files.

| File | What it is |
|---|---|
| `totem_vial_left.uf2` | Left half, Vial enabled |
| `totem_vial_right.uf2` | Right half, Vial enabled |
| `totem_default.uf2` | Stock QMK keymap, no Vial — a fallback |

## Flashing

You flash each half separately, and both need to be done.

1. Unzip the download.
2. Connect **one half** over USB-C.
3. **Double-tap the reset button** on that half. It mounts as a USB drive
   called `RPI-RP2`.
4. Drag the matching `.uf2` onto that drive:
   - Left half → `totem_vial_left.uf2`
   - Right half → `totem_vial_right.uf2`
5. The drive disappears on its own and the half reboots. That one is done.
6. Repeat for the other half.

If the drive does not appear, press reset twice faster — the two taps have
to be quick.

## The cable

The halves talk over **half duplex serial** on a single data line (GP0),
the same wiring the stock firmware uses. A standard **TRRS** cable works.

## If the halves do not talk to each other

The telltale sign is that each half types its own keys whenever USB is
plugged into *it*, while the other half gets power but does nothing.

**The usual cause is the wrong Vial build.** The firmware published by the
keyboard's author is compiled for **full duplex** serial, which needs a
second data line (GP1) that these boards do not use. Flash it on one of
these and the halves can never reach each other, with no fault in the
hardware. The builds in this repo are compiled for half duplex instead, so
use these.

If you are on the author's build and want the keyboard working right now,
`totem_default.uf2` is the stock firmware and talks over half duplex — you
lose Vial until you flash the build from here.

If the halves still do not talk after flashing these files to the correct
sides, then look at the hardware: with the cable plugged into both halves,
check continuity between **GP0 on one board and GP0 on the other**. The
data pin of a TRRS jack can be open while the outer contacts still pass
power, which looks exactly like this.

## Remapping with Vial

1. Open [vial.rocks](https://vial.rocks) in Chrome or Edge (Firefox and
   Safari cannot talk to the keyboard), or install the
   [desktop app](https://get.vial.today).
2. Connect the **left half** over USB.
3. Click **Authorize device** and pick the Totem from the list.
4. Edit the layout. Changes are written to the keyboard as you make them —
   there is no save button and no recompiling.

## Credits

- [TOTEM by GEIGEIGEIST](https://github.com/GEIGEIGEIST/TOTEM) — the keyboard
- [qmk-config-totem](https://github.com/GEIGEIGEIST/qmk-config-totem) — the author's QMK config
- [Vial](https://get.vial.today) — the remapping layer
