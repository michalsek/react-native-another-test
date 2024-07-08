#import <React/RCTBridgeModule.h>
#import "react-native-another-test.h"

@interface AnotherTest : NSObject <RCTBridgeModule>

@property(nonatomic, assign) BOOL setBridgeOnMainQueue;

@end

// #ifdef __cplusplus
// #import "react-native-another-test.h"
// #endif

// #ifdef RCT_NEW_ARCH_ENABLED
// #import "RNAnotherTestSpec.h"

// @interface AnotherTest : NSObject <NativeAnotherTestSpec>
// #else
// #import <React/RCTBridgeModule.h>

// @interface AnotherTest : NSObject <RCTBridgeModule>

// @property
// #endif

// @end
