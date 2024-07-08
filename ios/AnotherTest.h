#ifdef __cplusplus
#import "react-native-another-test.h"
#endif

#ifdef RCT_NEW_ARCH_ENABLED
#import "RNAnotherTestSpec.h"

@interface AnotherTest : NSObject <NativeAnotherTestSpec>
#else
#import <React/RCTBridgeModule.h>

@interface AnotherTest : NSObject <RCTBridgeModule>
#endif

@end
