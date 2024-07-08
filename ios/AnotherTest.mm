#import "AnotherTest.h"

#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

#import <React/RCTUtils.h>
#import <ReactCommon/CallInvoker.h>

#import <memory>

@implementation AnotherTest

@synthesize bridge = _bridge;

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup
{
    return YES;
}

- (void)setBridge:(RCTBridge *)bridge
{
  _bridge = bridge;
  _setBridgeOnMainQueue = RCTIsMainQueue();

  // Cxx <=> C++
  RCTCxxBridge * cxxBridge = (RCTCxxBridge *)self.bridge;

  // Early exist if runtime is not available
  if (!cxxBridge.runtime) {
    return;
  }

  installSequel(*(facebook::jsi::Runtime *)cxxBridge.runtime);
}

- (void)invalidate {
  cleanUpSequel();
}

@end
