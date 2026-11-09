<!--
SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
SPDX-License-Identifier: GPL-3.0-or-later
-->

# ooz (Kraken decoder)

`kraken.cpp` is the decoder half of [powzix/ooz](https://github.com/powzix/ooz) at
0503806 (GPL-3.0-or-later), used by the shader precache to open FromSoftware's DCX KRAK
shader bundles (The Duskbloods). Changes from upstream:

- The command line tool, the Oodle DLL loader, LZNA and BitKnit are removed; Kraken, Mermaid and
  Leviathan streams decode.
- `ooz_compat.h` replaces the Windows `stdafx.h`; everything is in `namespace ooz`.
- A block whose header sets the restart bit is decoded with that block as the start of the
  window. Upstream ignores the bit and fails on streams that reset every 256 KiB block, such as
  `shaderbdle.shaderbdlebnd.dcx`.

The decoder uses SSE2 intrinsics and is built on x86-64 only. It is not hardened against hostile
input; it only reads the user's own game files.
