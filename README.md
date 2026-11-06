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

The halves talk over **full duplex serial** — TX on GP0 and RX on GP1 — so
both data lines have to reach the other side. Use a **TRRS** cable (four
contacts, three rings on the plug). A TRS cable has only three contacts: it
still carries power, so the far half looks alive, but one data line is
missing and the halves never talk.

## If the halves do not talk to each other

The telltale sign is that each half works on its own whenever USB is
plugged into *it*, and the other half gets power but does nothing.

1. **Check the cable is TRRS**, four contacts (see above). This is the
   first thing to rule out.
2. **Flash the right file to the right side.** `totem_vial_left.uf2` goes
   on the left half and `totem_vial_right.uf2` on the right. These builds
   carry the side inside them, so swapping them leaves two halves that both
   think they are the same side. Reflash each half with its own file.
3. **Check the TRRS jacks.** On the half that stays dead, the data pins of
   the jack (GP0 and GP1) are the usual suspects: a cold joint there still
   passes power through the outer contacts while the data lines never make
   contact. Reflow both jacks before suspecting anything else.

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
