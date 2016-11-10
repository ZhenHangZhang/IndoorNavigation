//
//  OIMGroundOverlayRenderer.h
//  MapKit_static
//
//  Created by Li Fei on 11/13/13.
//  Copyright (c) 2013 songjian. All rights reserved.
//

#import "OIMOverlayRenderer.h"
#import "OIMGroundOverlay.h"

/*!
 @brief 此类是将OIMGroundOverlay中的覆盖图片显示在地图上的renderer;
 */
@interface OIMGroundOverlayRenderer : OIMOverlayRenderer

/*!
 @brief groundOverlay 具有覆盖图片，以及图片覆盖的区域
 */
@property (nonatomic ,readonly) OIMGroundOverlay *groundOverlay;

/*!
 @brief 根据指定的GroundOverlay生成将图片显示在地图上Renderer
 @param groundOverlay 制定了覆盖图片，以及图片的覆盖区域的groundOverlay
 @return 以GroundOverlay新生成Renderer
 */
- (instancetype)initWithGroundOverlay:(OIMGroundOverlay *)groundOverlay;

@end
