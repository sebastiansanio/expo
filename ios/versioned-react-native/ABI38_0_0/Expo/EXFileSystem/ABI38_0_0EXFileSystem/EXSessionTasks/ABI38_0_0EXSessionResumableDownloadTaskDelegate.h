// Copyright 2015-present 650 Industries. All rights reserved.

#import <ABI38_0_0EXFileSystem/ABI38_0_0EXSessionDownloadTaskDelegate.h>
#import <ABI38_0_0EXFileSystem/ABI38_0_0EXResumablesManager.h>

typedef void (^ABI38_0_0EXDownloadDelegateOnWriteCallback)(NSURLSessionDownloadTask *task, int64_t bytesWritten, int64_t totalBytesWritten, int64_t totalBytesExpectedToWrite);

@interface ABI38_0_0EXSessionResumableDownloadTaskDelegate : ABI38_0_0EXSessionDownloadTaskDelegate

- (instancetype)initWithResolve:(ABI38_0_0UMPromiseResolveBlock)resolve
                         reject:(ABI38_0_0UMPromiseRejectBlock)reject
                       localUrl:(NSURL *)localUrl
             shouldCalculateMd5:(BOOL)shouldCalculateMd5
                onWriteCallback:(ABI38_0_0EXDownloadDelegateOnWriteCallback)onWriteCallback
               resumableManager:(ABI38_0_0EXResumablesManager *)manager
                           uuid:(NSString *)uuid;

@end
