# Totem — QMK / Vial

QMK firmware for the **Totem** split keyboard, built with **Vial** so the
layout can be remapped from the browser with no rebuild.

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
- [QMK](https://github.com/qmk/qmk_firmware/tree/master/keyboards/geigeigeist/totem) — the stock firmware
- [Vial](https://get.vial.today) — the remapping layer
