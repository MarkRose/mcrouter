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

#include <functional>
#include <unordered_map>

#include <folly/Range.h>

#include <mcrouter/lib/carbon/Stats.h>

#include "mcrouter/lib/network/gen/MemcacheRouteHandleIf.h"
#include "mcrouter/lib/network/gen/MemcacheRouterStats.h"
#include "mcrouter/lib/network/gen/MemcacheRoutingGroups.h"

// Forward declarations
namespace folly {
struct dynamic;
} // namespace folly

namespace facebook {
namespace memcache {
template <class RouteHandleIf>
class RouteHandleFactory;
namespace mcrouter {
template <class RouterInfo>
class ExtraRouteHandleProviderIf;
} // namespace mcrouter
} // namespace memcache
} // namespace facebook

namespace facebook {
namespace memcache {
namespace mcrouter {
class AdditionalProxyRequestLogger;
} // namespace mcrouter
} // namespace memcache
} // namespace facebook

namespace facebook {
namespace memcache {

namespace detail {

using MemcacheRoutableRequests = carbon::List<
    McAddRequest,
    McAppendRequest,
    McCasRequest,
    McDecrRequest,
    McDeleteRequest,
    McFlushAllRequest,
    McFlushReRequest,
    McGatRequest,
    McGatsRequest,
    McGetRequest,
    McGetsRequest,
    McIncrRequest,
    McLeaseGetRequest,
    McLeaseSetRequest,
    McMetagetRequest,
    McPrependRequest,
    McReplaceRequest,
    McSetRequest,
    McTouchRequest>;
} // namespace detail

struct MemcacheRouterInfo {
  using RouteHandleIf = MemcacheRouteHandleIf;
  using RouteHandlePtr = std::shared_ptr<RouteHandleIf>;

  static constexpr const char* name = "Memcache";

  template <class Route>
  using RouteHandle = MemcacheRouteHandle<Route>;
  using RoutableRequests = detail::MemcacheRoutableRequests;
  using AdditionalLogger = facebook::memcache::mcrouter::AdditionalProxyRequestLogger;
  using RouterStats = carbon::Stats<MemcacheRouterStatsConfig>;

  using RouteHandleFactoryMap = std::unordered_map<
      folly::StringPiece,
      std::function<RouteHandlePtr(
          facebook::memcache::RouteHandleFactory<RouteHandleIf>&,
          const folly::dynamic&)>,
      folly::Hash>;

  static RouteHandleFactoryMap buildRouteMap();

  static std::unique_ptr<facebook::memcache::mcrouter::
                             ExtraRouteHandleProviderIf<MemcacheRouterInfo>>
  buildExtraProvider();
};
} // namespace memcache
} // namespace facebook
