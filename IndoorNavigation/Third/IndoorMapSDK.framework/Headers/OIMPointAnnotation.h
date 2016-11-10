//
//  OIMPointAnnotation.h
//  OIMMapKitDemo
//
//  Created by songjian on 13-1-7.
//  Copyright (c) 2013年 songjian. All rights reserved.
//

#import "OIMShape.h"
#import <CoreLocation/CLLocation.h>

/*!
 @brief 点标注数据
 */
@interface OIMPointAnnotation : OIMShape

/*!
 @brief 经纬度
 */
@property (nonatomic, readwrite) OIMCoordinate coordinate;
//
@end
