// Copyright 2018-present 650 Industries. All rights reserved.

#import <UIKit/UIKit.h>

@protocol UMFontScalerInterface

- (UIFont *)scaledFont:(UIFont *)font toSize:(CGFloat)fontSize;

@end
