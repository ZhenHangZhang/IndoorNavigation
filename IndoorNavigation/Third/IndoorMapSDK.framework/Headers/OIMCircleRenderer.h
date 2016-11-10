//
//  OIMCircleRenderer.h
//  OIMMapKit
//
//  Created by yin cai on 11-12-30.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#import "OIMCircle.h"
#import "OIMOverlayPathRenderer.h"

/*!
 @brief 该类是OIMCircle的显示圆Renderer,可以通过OIMOverlayPathRenderer修改其fill和stroke attributes
 */
@interface OIMCircleRenderer : OIMOverlayPathRenderer

/*!
 @brief 根据指定圆生成对应的Renderer
 @param circle 指定的OIMCircle model
 @return 生成的Renderer
 */
- (instancetype)initWithCircle:(OIMCircle *)circle;

/*!
 @brief 关联的OIMcirlce model
 */
@property (nonatomic, readonly) OIMCircle *circle;

@end
