//
//  OIMMultiColoredPolylineRenderer.h
//  MapKit_static
//
//  Created by yi chen on 12/11/15.
//  Copyright © 2015 songjian. All rights reserved.
//

#import "OIMPolylineRenderer.h"
#import "OIMMultiPolyline.h"

/*!
此类用于绘制OIMMultiPolyline对应的多段线，支持分段颜色绘制
 */
@interface OIMMultiColoredPolylineRenderer : OIMPolylineRenderer

/*!
 @brief 根据指定的OIMPolyline生成一个多段线Renderer
 @param polyline 指定OIMMultiPolyline
 @return 新生成的多段线Renderer
 */
- (instancetype)initWithMultiPolyline:(OIMMultiPolyline *)multiPolyline;

/*!
 @brief 关联的OIMMultiPolyline model
 */
@property (nonatomic, readonly) OIMMultiPolyline *multiPolyline;

/*!
 @brief  分段绘制的颜色。
 需要分段颜色绘制时，必须设置（内容必须为UIColor）
 */
@property (nonatomic, strong) NSArray *strokeColors;

/*!
 @brief  颜色是否渐变。
 */
@property (nonatomic, getter=isGradient) BOOL gradient;

@end
