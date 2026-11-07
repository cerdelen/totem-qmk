# Totem — QMK / Vial

QMK firmware for the **Totem** split keyboard, built with **Vial** so the
layout can be remapped from the browser with no rebuild.

The source lives in [`totem/`](totem) and every release is built from it
by CI. It starts from the keyboard author's Vial source with one change
that matters: the link between the halves uses **half duplex** serial,
like the stock firmware these boards ship with. See
[Why not the author's Vial build](#why-not-the-authors-vial-build).

## Specs

| | |
|---|---|
| Model | Totem |
| Firmware | QMK + Vial |
| Layout | Split column-staggered 3×5 + 3 thumb keys (38 keys) |
| Switches | Kailh Choc (low profile) |
| Controller | Seeed XIAO RP2040 |
| Connection | USB-C, TRRS cable between halves |

> The controller matters: these builds target the **XIAO RP2040**. They will
> not run on the XIAO nRF52840 (BLE), which uses a different chip.

## Download

Grab the zip from [Releases](../../releases).

| File | What it is |
|---|---|
| `totem_vial.uf2` | The firmware, Vial enabled — goes on **both** halves |
| `totem_default.uf2` | Stock QMK keymap, no Vial — a fallback |

## Flashing

The same file goes on both halves, but each half is flashed separately.

1. Unzip the download.
2. Connect **one half** over USB-C.
3. **Double-tap the reset button** on that half. It mounts as a USB drive
   called `RPI-RP2`.
4. Drag `totem_vial.uf2` onto that drive.
5. The drive disappears on its own and the half reboots. That one is done.
6. Repeat for the other half, with the same file.

If the drive does not appear, press reset twice faster — the two taps have
to be quick.

**When you use the keyboard, plug the USB cable into the left half.** The
half with USB is the one that takes the left side.

## Remapping with Vial

1. Open [vial.rocks](https://vial.rocks) in Chrome or Edge (Firefox and
   Safari cannot talk to the keyboard), or install the
   [desktop app](https://get.vial.today).
2. Connect the **left half** over USB.
3. Click **Authorize device** and pick the Totem from the list.
4. Edit the layout. Changes are written to the keyboard as you make them —
   there is no save button and no recompiling.

## If the halves do not talk to each other

The telltale sign is that each half types its own keys whenever USB is
plugged into *it*, while the other half gets power but does nothing.

1. **Make sure both halves run `totem_vial.uf2` from this repo.** If either
   one still has the author's Vial build, this is exactly what you get —
   see below.
2. **Use a TRRS cable** (four contacts, three rings on the plug).
3. If it still fails, check the hardware: with the cable plugged into both
   halves, test continuity between **GP0 on one board and GP0 on the
   other**. The data pin of a TRRS jack can be open while the outer
   contacts still pass power, which looks exactly like this.

## Why not the author's Vial build

The keyboard's author publishes precompiled Vial firmware, but it is built
for **full duplex** serial: TX on GP0 and RX on GP1, two data lines. The
stock QMK firmware for the same keyboard uses **half duplex** on GP0 alone.

Boards that work with the stock firmware cannot work with that Vial build:
each half runs fine over USB, but they never reach each other because the
second data line is not there. Nothing is broken in the hardware. That is
why this repo builds Vial itself, with the serial setup of the firmware
that already works.

## Credits

- [TOTEM by GEIGEIGEIST](https://github.com/GEIGEIGEIST/TOTEM) — the keyboard and the Vial source this starts from
- [qmk-config-totem](https://github.com/GEIGEIGEIST/qmk-config-totem) — the author's QMK config and stock firmware
- [Vial](https://get.vial.today) — the remapping layer
