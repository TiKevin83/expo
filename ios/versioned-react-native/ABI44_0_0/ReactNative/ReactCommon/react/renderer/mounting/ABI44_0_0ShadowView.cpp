/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ABI44_0_0ShadowView.h"

#include <ABI44_0_0React/ABI44_0_0renderer/core/LayoutableShadowNode.h>

namespace ABI44_0_0facebook {
namespace ABI44_0_0React {

static LayoutMetrics layoutMetricsFromShadowNode(ShadowNode const &shadowNode) {
  auto layoutableShadowNode =
      traitCast<LayoutableShadowNode const *>(&shadowNode);
  return layoutableShadowNode ? layoutableShadowNode->getLayoutMetrics()
                              : EmptyLayoutMetrics;
}

ShadowView::ShadowView(const ShadowNode &shadowNode)
    : componentName(shadowNode.getComponentName()),
      componentHandle(shadowNode.getComponentHandle()),
      tag(shadowNode.getTag()),
      props(shadowNode.getProps()),
      eventEmitter(shadowNode.getEventEmitter()),
      layoutMetrics(layoutMetricsFromShadowNode(shadowNode)),
      state(shadowNode.getState()) {}

bool ShadowView::operator==(const ShadowView &rhs) const {
  return std::tie(
             this->tag,
             this->componentName,
             this->props,
             this->eventEmitter,
             this->layoutMetrics,
             this->state) ==
      std::tie(
             rhs.tag,
             rhs.componentName,
             rhs.props,
             rhs.eventEmitter,
             rhs.layoutMetrics,
             rhs.state);
}

bool ShadowView::operator!=(const ShadowView &rhs) const {
  return !(*this == rhs);
}

#if ABI44_0_0RN_DEBUG_STRING_CONVERTIBLE

std::string getDebugName(ShadowView const &object) {
  return object.componentHandle == 0 ? "Invalid" : object.componentName;
}

std::vector<DebugStringConvertibleObject> getDebugProps(
    ShadowView const &object,
    DebugStringConvertibleOptions options) {
  return {
      {"tag", getDebugDescription(object.tag, options)},
      {"props", getDebugDescription(object.props, options)},
      {"eventEmitter", getDebugDescription(object.eventEmitter, options)},
      {"layoutMetrics", getDebugDescription(object.layoutMetrics, options)},
      {"state", getDebugDescription(object.state, options)},
  };
}

#endif

bool ShadowViewNodePair::operator==(const ShadowViewNodePair &rhs) const {
  return this->shadowNode == rhs.shadowNode;
}

bool ShadowViewNodePair::operator!=(const ShadowViewNodePair &rhs) const {
  return !(*this == rhs);
}

} // namespace ABI44_0_0React
} // namespace ABI44_0_0facebook
