//
//  OIMPolygonRenderer.h
//  OIMMapKit
//
//  
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "OIMPolygon.h"
#import "OIMOverlayPathRenderer.h"

/*!
 @brief 此类用于绘制OIMPolygon,可以通过OIMOverlayPathRenderer修改其fill和stroke attributes
 */
@interface OIMPolygonRenderer : OIMOverlayPathRenderer

/*!
 @brief 根据指定的多边形生成一个多边形Renderer
 @param polygon 指定的多边形数据对象
 @return 新生成的多边形Renderer
 */
- (instancetype)initWithPolygon:(OIMPolygon *)polygon;

/*!
 @brief 关联的OIMPolygon model
 */
@property (nonatomic, readonly) OIMPolygon *polygon;

@end