#import <React/RCTView.h>
#import <React/RCTViewManager.h>

#if TARGET_OS_OSX
#define RNCWebViewContainerView NSView
@class NSView;
#else
#define RNCWebViewContainerView UIView
@class UIView;
#endif // TARGET_OS_OSX

#ifdef RCT_NEW_ARCH_ENABLED

#import "RNCWebViewRetainedContainerShadowNode.h"

#import <React/RCTViewComponentView.h>
#import <react/renderer/components/RNCWebViewSpec/RCTComponentViewHelpers.h>

using namespace facebook::react;

@interface RNCWebViewRetainedContainer : RCTViewComponentView <RCTRNCWebViewRetainedContainerViewProtocol>
@end

@implementation RNCWebViewRetainedContainer

+ (ComponentDescriptorProvider)componentDescriptorProvider
{
  return concreteComponentDescriptorProvider<RNCWebViewRetainedContainerRetainingComponentDescriptor>();
}

@end

#else

@interface RNCWebViewRetainedContainerManager : RCTViewManager
@end

@implementation RNCWebViewRetainedContainerManager

RCT_EXPORT_MODULE(RNCWebViewRetainedContainer)

- (RNCWebViewContainerView *)view
{
  return [RCTView new];
}

@end

#endif // RCT_NEW_ARCH_ENABLED
