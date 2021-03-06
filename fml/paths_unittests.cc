// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gtest/gtest.h"

#include "flutter/fml/paths.h"

TEST(Paths, SanitizeURI) {
  ASSERT_EQ(fml::paths::SanitizeURIEscapedCharacters("hello"), "hello");
  ASSERT_EQ(fml::paths::SanitizeURIEscapedCharacters(""), "");
  ASSERT_EQ(fml::paths::SanitizeURIEscapedCharacters("hello%20world"),
            "hello world");
  ASSERT_EQ(fml::paths::SanitizeURIEscapedCharacters(
                "%5Chello%5cworld%20foo%20bar%21"),
            "\\hello\\world foo bar!");
}
