//
//  OIMPinAnnotationView.h
//  OIMMapKitDemo
//
//  Created by songjian on 13-1-7.
//  Copyright (c) 2013年 songjian. All rights reserved.
//

#import "OIMMapKit.h"

typedef NS_ENUM(NSUInteger, OIMPinAnnotationColor){
    OIMPinAnnotationColorRed = 0,
    OIMPinAnnotationColorGreen,
    OIMPinAnnotationColorPurple
};
//typedef NSUInteger OIMPinAnnotationColor;

/*!
 @brief 提供类似大头针效果的annotation view
 */
@interface OIMPinAnnotationView : OIMAnnotationView

/*!
 @brief 大头针的颜色，有OIMPinAnnotationColorRed, OIMPinAnnotationColorGreen, OIMPinAnnotationColorPurple三种
 */
@property (nonatomic) OIMPinAnnotationColor pinColor;

///*!
// @brief 动画效果
// */
//@property (nonatomic) BOOL animatesDrop;

@end
