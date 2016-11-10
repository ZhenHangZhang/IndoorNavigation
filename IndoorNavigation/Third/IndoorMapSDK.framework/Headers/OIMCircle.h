//
//  OIMCircle.h
//  OIMMapKit
//
//
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//

#import "OIMShape.h"
#import "OIMOverlay.h"
#import "OIMGeometry.h"

/*!
 @brief 该类用于定义一个圆, 通常OIMCircle是OIMCircleView的model
 */
@interface OIMCircle : OIMOverlay

/*!
 @brief 根据中心点和半径生成圆
 @param coord 中心点的经纬度坐标
 @param radius 半径，单位：米
 @return 新生成的圆
 */
+ (instancetype)circleWithCenterCoordinate:(CLLocationCoordinate2D)coord
                                    radius:(CLLocationDistance)radius;

/*!
 @brief 根据map rect生成圆
 @param mapRect 圆的最小外界矩形
 @return 新生成的圆
 */
+ (instancetype)circleWithMapRect:(OIMMapRect)mapRect;

/*!
 @brief 中心点经纬度坐标
 */
@property (nonatomic) OIMCoordinate coordinate;

/*!
 @brief 半径，单位：米
 */
@property (nonatomic) CLLocationDistance radius;

/*!
 @brief 该圆的外接map rect
 */
@property (nonatomic) OIMMapRect boundingMapRect;

@end
