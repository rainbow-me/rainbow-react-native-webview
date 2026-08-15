#pragma once

#ifdef RCT_NEW_ARCH_ENABLED

#import <react/renderer/components/RNCWebViewSpec/ShadowNodes.h>
#import <react/renderer/components/view/ConcreteViewShadowNode.h>
#import <react/renderer/core/ConcreteComponentDescriptor.h>

namespace facebook::react {

class RNCWebViewRetainedContainerHostShadowNode final
    : public ConcreteViewShadowNode<
          RNCWebViewRetainedContainerComponentName,
          RNCWebViewRetainedContainerProps,
          RNCWebViewRetainedContainerEventEmitter,
          RNCWebViewRetainedContainerState> {
 public:
  using BaseShadowNode = ConcreteViewShadowNode<
      RNCWebViewRetainedContainerComponentName,
      RNCWebViewRetainedContainerProps,
      RNCWebViewRetainedContainerEventEmitter,
      RNCWebViewRetainedContainerState>;

  RNCWebViewRetainedContainerHostShadowNode(
      const ShadowNodeFragment &fragment,
      const ShadowNodeFamily::Shared &family,
      ShadowNodeTraits traits)
      : BaseShadowNode(fragment, family, traits) {
    retainWhenHidden();
  }

  RNCWebViewRetainedContainerHostShadowNode(
      const ShadowNode &sourceShadowNode,
      const ShadowNodeFragment &fragment)
      : BaseShadowNode(sourceShadowNode, fragment) {
    retainWhenHidden();
  }

 private:
  void retainWhenHidden() noexcept {
    BaseShadowNode::traits_.unset(ShadowNodeTraits::Trait::Hidden);
  }
};

using RNCWebViewRetainedContainerRetainingComponentDescriptor =
    ConcreteComponentDescriptor<RNCWebViewRetainedContainerHostShadowNode>;

} // namespace facebook::react

#endif // RCT_NEW_ARCH_ENABLED
