//
//  OIMPolylineRenderer.h
//  OIMMapKit
//
//  
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//


#import <UIKit/UIKit.h>

#import "OIMPolyline.h"
#import "OIMOverlayPathRenderer.h"

/*!
 @brief 此类用于绘制OIMPolyline,可以通过OIMOverlayPathRenderer修改其fill和stroke attributes
 */
@interface OIMPolylineRenderer : OIMOverlayPathRenderer

/*!
 @brief 根据指定的OIMPolyline生成一个多段线Renderer
 @param polyline 指定OIMPolyline
 @return 新生成的多段线Renderer
 */
- (instancetype)initWithPolyline:(OIMPolyline *)polyline;

/*!
 @brief 关联的OIMPolyline model
 */
@property (nonatomic, readonly) OIMPolyline *polyline;

@end
