//
//  POSImageReaderIOS8.h
//  POSInputStreamLibrary
//
//  Created by Pavel Osipov on 12.05.15.
//  Copyright (c) 2015 Pavel Osipov. All rights reserved.
//

#import "POSAssetReader.h"
#import <Photos/Photos.h>

@interface POSImageReaderIOS8 : NSObject <POSAssetReader>

/// When you try to get adjusted photo just after taking it in Camera app,
/// Photos framework will provide data of 'SubstandardFullSizeRender.jpg'.
/// Asset reader will force Photos framework to generate 'FullSizeRender.jpg'
/// making 2nd attempt to open asset. I think a "suspicious" image size is
/// more adequate parameter to rely on, than the name of the file which you
/// can take from the info dictionary with 'PHImageFileURLKey' key.
@property (nonatomic, assign) long long suspiciousSize;

/// @brief Dispatch queue for fetching ALAsset from ALAssetsLibrary.
/// @remarks See POSBlobInputStreamAssetDataSource.h
@property (nonatomic, nullable) dispatch_queue_t completionDispatchQueue;

/// The designated initializer.
- (nonnull instancetype)initWithAsset:(nonnull PHAsset *)asset;

/// Deadly initializer.
- (nonnull instancetype)init NS_UNAVAILABLE;

/// Deadly factory method.
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end