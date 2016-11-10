//
//  OIMOverlayPathRenderer.h
//  OIMMapKit
//
//
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "OIMOverlayRenderer.h"

/*!
 @brief 该类设置overlay绘制的属性，可以使用该类的子类OIMCircleRenderer, OIMPolylineRenderer, OIMPolygonRenderer或者继承该类
 */
@interface OIMOverlayPathRenderer : OIMOverlayRenderer

/*!
 @brief 填充颜色,默认是kOIMOverlayRendererDefaultFillColor
 */
@property (retain) UIColor *fillColor;

/*!
 @brief 笔触颜色,默认是kOIMOverlayRendererDefaultStrokeColor
 */
@property (retain) UIColor *strokeColor;

/*!
 @brief 笔触宽度,默认是0
 */
@property CGFloat lineWidth;

///*!
// @brief LineJoin,默认是kOIMLineJoinBevel
// */
//@property OIMLineJoinType lineJoinType;
//
///*!
// @brief LineCap,默认是kOIMLineCapButt
// */
//@property OIMLineCapType lineCapType;
//
///*!
// @brief MiterLimit,默认是10.f
// */
//@property CGFloat miterLimit;
//
///*!
// @brief 是否绘制成虚线, 默认是NO
// */
//@property BOOL lineDash;


@end
