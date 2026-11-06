// Copyright 2022 GEIST @geigeigeist
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

/*
 * CODEKEEB: half duplex instead of the upstream full duplex.
 *
 * The author ships two different serial configurations for the same
 * keyboard. The precompiled Vial binaries use FULL duplex (TX on GP0, RX
 * on GP1), which needs both data conductors of the TRRS cable wired
 * through. The default QMK build in GEIGEIGEIST/qmk-config-totem -- the
 * one these boards ship with and the one known to work on them -- uses
 * HALF duplex over a single pin, GP0.
 *
 * Flashing the full-duplex Vial build onto a board wired for half duplex
 * gives you two halves that each type their own keys over USB but never
 * see each other, because the second data line is not there. So this
 * keeps the serial setup identical to the firmware that already works and
 * only adds Vial on top.
 */
#define SOFT_SERIAL_PIN GP0
#define SERIAL_USE_MULTI_TRANSACTION
#define SERIAL_PIO_USE_PIO1

/*
 * EE_HANDS is deliberately NOT set, matching the working default build:
 * handedness comes from the left/right bootloader target at flash time,
 * so there is no separate handedness-writing step for the customer.
 */

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
