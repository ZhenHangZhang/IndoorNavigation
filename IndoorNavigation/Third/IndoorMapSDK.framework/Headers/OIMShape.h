//
//  OIMShape.h
//  OIMMapKit
//
//  
//  Copyright (c) 2011年 Autonavi Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OIMAnnotation.h"

/*!
 @brief 该类为一个抽象类，定义了基于OIMAnnotation的OIMShape类的基本属性和行为，不能直接使用，必须子类化之后才能使用
 */
@interface OIMShape : NSObject<OIMAnnotation>

@property (nonatomic, readwrite) OIMCoordinate coordinate;

///*!
// @brief 标题
// */
//@property (copy) NSString *title;
//
///*!
// @brief 副标题
// */
//@property (copy) NSString *subtitle;

@end