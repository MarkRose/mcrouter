/*
 *  Copyright (c) 2017-present, Facebook, Inc.
 *
 *  This source code is licensed under the MIT license found in the LICENSE
 *  file in the root directory of this source tree.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 *  @generated
 */
#pragma once

#include <memory>
#include <string>
#include <utility>

#include <folly/Optional.h>
#include <folly/io/IOBuf.h>
#include <mcrouter/lib/carbon/CarbonProtocolReader.h>
#include <mcrouter/lib/carbon/CommonSerializationTraits.h>
#include <mcrouter/lib/carbon/Keys.h>
#include <mcrouter/lib/carbon/ReplyCommon.h>
#include <mcrouter/lib/carbon/RequestCommon.h>
#include <mcrouter/lib/carbon/RequestReplyUtil.h>
#include <mcrouter/lib/carbon/Result.h>
#include <mcrouter/lib/carbon/TypeList.h>
#include <mcrouter/lib/carbon/Variant.h>

namespace carbon {
namespace test2 {
namespace util {

enum class SimpleEnum : int64_t {
  Twenty = 20,
  Zero = 0,
  One = 1,
  Negative = -92233
};

std::string enumSimpleEnumToString(SimpleEnum val);

class SimpleStruct {
 public:
  static constexpr bool hasExptime = false;
  static constexpr bool hasFlags = false;
  static constexpr bool hasKey = false;
  static constexpr bool hasValue = false;

  SimpleStruct() = default;
  SimpleStruct(const SimpleStruct&) = default;
  SimpleStruct& operator=(const SimpleStruct&) = default;
  SimpleStruct(SimpleStruct&&) = default;
  SimpleStruct& operator=(SimpleStruct&&) = default;

  int64_t member1() const {
    return member1_;
  }
  int64_t& member1() {
    return member1_;
  }
  uint64_t flags() const {
    return 0;
  }
  int32_t exptime() const {
    return 0;
  }

  template <class Writer>
  void serialize(Writer&& writer) const;

  void deserialize(carbon::CarbonProtocolReader& reader);

  template <class V>
  void visitFields(V&& v);
  template <class V>
  void visitFields(V&& v) const;

 private:
  int64_t member1_{0};
};

class SimpleUnion {
 private:
  using _IdTypeMap = carbon::List<
      facebook::memcache::KV<1, int64_t>,
      facebook::memcache::KV<2, bool>,
      facebook::memcache::KV<3, std::string>>;

 public:
  enum class ValueType : uint32_t {
    EMPTY = 0,
    UMEMBER1 = 1,
    UMEMBER2 = 2,
    UMEMBER3 = 3
  };

  SimpleUnion() = default;
  SimpleUnion(const SimpleUnion&) = default;
  SimpleUnion& operator=(const SimpleUnion&) = default;
  SimpleUnion(SimpleUnion&&) = default;
  SimpleUnion& operator=(SimpleUnion&&) = default;

  ValueType which() const {
    return static_cast<ValueType>(_which_);
  }

  int64_t& umember1() {
    if (_which_ == 0) {
      return emplace<1>();
    }
    if (_which_ != 1) {
      throw std::runtime_error("umember1 is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<int64_t>();
  }
  int64_t umember1() const {
    if (_which_ != 1) {
      throw std::runtime_error("umember1 is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<int64_t>();
  }
  bool& umember2() {
    if (_which_ == 0) {
      return emplace<2>();
    }
    if (_which_ != 2) {
      throw std::runtime_error("umember2 is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<bool>();
  }
  bool umember2() const {
    if (_which_ != 2) {
      throw std::runtime_error("umember2 is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<bool>();
  }
  std::string& umember3() {
    if (_which_ == 0) {
      return emplace<3>();
    }
    if (_which_ != 3) {
      throw std::runtime_error("umember3 is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<std::string>();
  }
  const std::string& umember3() const {
    if (_which_ != 3) {
      throw std::runtime_error("umember3 is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<std::string>();
  }

  template <
      uint32_t id,
      class C = typename carbon::FindByKey<id, _IdTypeMap>::type>
  C& get() {
    if (id != _which_) {
      throw std::runtime_error("Type id is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<C>();
  }

  template <
      uint32_t id,
      class C = typename carbon::FindByKey<id, _IdTypeMap>::type>
  const C& get() const {
    if (id != _which_) {
      throw std::runtime_error("Type id is not set in union SimpleUnion.");
    }
    return _carbon_variant.get<C>();
  }

  /* Note: Emplace invalidates all previous accessor references.
   * Please exercise caution.
   */
  template <
      uint32_t id,
      class... Args,
      class C = typename carbon::FindByKey<id, _IdTypeMap>::type>
  C& emplace(Args&&... args) {
    _which_ = id;
    return _carbon_variant.emplace<C>(std::forward<Args>(args)...);
  }

  template <
      ValueType id,
      class... Args,
      class C = typename carbon::
          FindByKey<static_cast<uint32_t>(id), _IdTypeMap>::type>
  C& emplace(Args&&... args) {
    _which_ = static_cast<uint32_t>(id);
    return _carbon_variant.emplace<C>(std::forward<Args>(args)...);
  }
  template <class Writer>
  void serialize(Writer&& writer) const;

  void deserialize(carbon::CarbonProtocolReader& reader);

  template <class V>
  void visitFields(V&& v);
  template <class V>
  void visitFields(V&& v) const;
  template <class V>
  void foreachMember(V&& v);
  template <class V>
  void foreachMember(V&& v) const;

 private:
  carbon::Variant<
      int64_t,
      bool,
      std::string> _carbon_variant;
  uint32_t _which_{0};
};

class YetAnotherReply;

class YetAnotherRequest : public carbon::RequestCommon {
 public:
  using reply_type = YetAnotherReply;
  static constexpr bool hasExptime = false;
  static constexpr bool hasFlags = false;
  static constexpr bool hasKey = true;
  static constexpr bool hasValue = false;
  static constexpr size_t typeId = 67;
  static constexpr const char* name = "yet_another";

  YetAnotherRequest() = default;
  YetAnotherRequest(const YetAnotherRequest&) = default;
  YetAnotherRequest& operator=(const YetAnotherRequest&) = default;
  YetAnotherRequest(YetAnotherRequest&&) = default;
  YetAnotherRequest& operator=(YetAnotherRequest&&) = default;
  explicit YetAnotherRequest(folly::StringPiece sp)
      : key_(sp) {}
  explicit YetAnotherRequest(folly::IOBuf&& carbonKey)
      : key_(std::move(carbonKey)) {}

  const carbon::Keys<folly::IOBuf>& key() const {
    return key_;
  }
  carbon::Keys<folly::IOBuf>& key() {
    markBufferAsDirty();
    return key_;
  }
  uint64_t flags() const {
    return 0;
  }
  int32_t exptime() const {
    return 0;
  }
  template <class Writer>
  void serialize(Writer&& writer) const;

  void deserialize(carbon::CarbonProtocolReader& reader);

  template <class V>
  void visitFields(V&& v);
  template <class V>
  void visitFields(V&& v) const;

 private:
  carbon::Keys<folly::IOBuf> key_;
};

class YetAnotherReply : public carbon::ReplyCommon {
 public:
  static constexpr bool hasExptime = false;
  static constexpr bool hasFlags = false;
  static constexpr bool hasKey = false;
  static constexpr bool hasValue = false;
  static constexpr size_t typeId = 68;

  YetAnotherReply() = default;
  YetAnotherReply(const YetAnotherReply&) = default;
  YetAnotherReply& operator=(const YetAnotherReply&) = default;
  YetAnotherReply(YetAnotherReply&&) = default;
  YetAnotherReply& operator=(YetAnotherReply&&) = default;
  explicit YetAnotherReply(carbon::Result carbonResult)
      : result_(carbonResult) {}

  carbon::Result result() const {
    return result_;
  }
  carbon::Result& result() {
    return result_;
  }
  uint64_t flags() const {
    return 0;
  }
  int32_t exptime() const {
    return 0;
  }

  template <class Writer>
  void serialize(Writer&& writer) const;

  void deserialize(carbon::CarbonProtocolReader& reader);

  template <class V>
  void visitFields(V&& v);
  template <class V>
  void visitFields(V&& v) const;

 private:
  carbon::Result result_{carbon::Result::UNKNOWN};
};
} // namespace util
} // namespace test2
} // namespace carbon

#include "BMessages-inl.h"
