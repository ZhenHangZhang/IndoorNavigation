//
//  OIMOverlay.h
//  OIMMapKit
//
//  
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//

#import "OIMAnnotation.h"
#import "OIMGeometry.h"
#import "OIMShape.h"

/*!
 @brief 该类是地图覆盖物的基类，所有地图的覆盖物需要继承自此类
 */
@interface OIMOverlay : OIMShape

///*!
// @brief 返回区域中心坐标.
// */
//@property (nonatomic, readonly) OIMCoordinate coordinate;

/*!
 @brief 区域外接矩形
 */
@property (nonatomic, readonly) OIMMapRect boundingMapRect;


@property (nonatomic, strong)NSString* overlayId;

@end