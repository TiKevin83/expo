// Copyright 2022-present 650 Industries. All rights reserved.

import ABI45_0_0ExpoModulesCore

internal struct DigestOptions: Record {
  @Field
  var encoding: Encoding = .hex

  internal enum Encoding: String, EnumArgument {
    case hex = "hex"
    case base64 = "base64"
  }
}
