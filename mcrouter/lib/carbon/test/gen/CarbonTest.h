/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

/*
 *  THIS FILE IS AUTOGENERATED. DO NOT MODIFY IT; ALL CHANGES WILL BE LOST IN
 *  VAIN.
 *
 */
#pragma once

#include <mcrouter/lib/carbon/RequestReplyUtil.h>
#include <mcrouter/lib/carbon/TypeList.h>
#include <mcrouter/lib/fbi/cpp/util.h>
#include <mcrouter/lib/network/CarbonMessageDispatcher.h>

#include "mcrouter/lib/carbon/test/gen/CarbonTestMessages.h"

namespace carbon {
namespace test {

namespace detail {

using CarbonTestRequestList = carbon::List<
    AnotherRequest,
    TestRequest,
    carbon::test2::util::YetAnotherRequest,
    facebook::memcache::McExecRequest,
    facebook::memcache::McQuitRequest,
    facebook::memcache::McShutdownRequest,
    facebook::memcache::McStatsRequest,
    facebook::memcache::McVersionRequest>;

} // detail

template <class OnRequest>
class CarbonTestRequestHandler
    : public facebook::memcache::CarbonMessageDispatcher<
          detail::CarbonTestRequestList,
          CarbonTestRequestHandler<OnRequest>,
          facebook::memcache::McServerRequestContext&&> {
 public:
  template <class... Args>
  explicit CarbonTestRequestHandler(Args&&... args)
      : onRequest_(std::forward<Args>(args)...) {}

  template <class Request>
  void onRequest(
      facebook::memcache::McServerRequestContext&& ctx,
      Request&& req) {
    onRequestImpl(
        std::move(ctx),
        std::move(req),
        carbon::detail::CanHandleRequest::value<Request, OnRequest>());
  }

 private:
  OnRequest onRequest_;

  template <class Request>
  void onRequestImpl(
      facebook::memcache::McServerRequestContext&& ctx,
      Request&& req,
      std::true_type) {
    onRequest_.onRequest(std::move(ctx), std::move(req));
  }

  template <class Request>
  void onRequestImpl(
      facebook::memcache::McServerRequestContext&& ctx,
      Request&& req,
      std::false_type) {
    facebook::memcache::throwRuntime(
        "onRequest for {} not defined", typeid(Request).name());
  }
};

} // test
} // carbon
