// SPDX-FileCopyrightText: Copyright 2026 Eden Emulator Project
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include <cstddef>
#include <cstdint>

namespace ooz {

/// Extra bytes the decoder may write past `dst_len`; size the output buffer for them.
inline constexpr size_t SafeSpace = 64;

/// Decodes an Oodle Kraken, Mermaid or Leviathan stream into exactly `dst_len` bytes.
/// Returns `dst_len`, or -1 when the stream is invalid. Not hardened against hostile input.
int Kraken_Decompress(const uint8_t* src, size_t src_len, uint8_t* dst, size_t dst_len);

} // namespace ooz
