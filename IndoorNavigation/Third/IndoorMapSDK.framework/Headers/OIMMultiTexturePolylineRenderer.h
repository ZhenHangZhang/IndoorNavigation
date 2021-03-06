//
//  OIMMultiTexturePolylineRenderer.h
//  MapKit_static
//
//  Created by yi chen on 12/11/15.
//  Copyright © 2015 songjian. All rights reserved.
//

#import "OIMPolylineRenderer.h"
#import "OIMMultiPolyline.h"

/*!
 此类用于绘制OIMMultiPolyline对应的多段线，支持分段纹理绘制
 */
@interface OIMMultiTexturePolylineRenderer : OIMPolylineRenderer

/*!
 @brief 根据指定的OIMMultiPolyline生成一个多段线Renderer
 @param multiPolyline 指定OIMMultiPolyline
 @return 新生成的多段线Renderer
 */
- (instancetype)initWithMultiPolyline:(OIMMultiPolyline *)multiPolyline;

/*!
 @brief 关联的OIMMultiPolyline model
 */
@property (nonatomic, readonly) OIMMultiPolyline *multiPolyline;

/*!
 @brief  取分段纹理id
 @return 分段纹理id数组
 */
@property (nonatomic, strong, readonly) NSArray * strokeTextureIDs;

/*!
 加载分段绘制的纹理图片
 需要分段纹理绘制时，必须设置。否则使用默认纹理绘制。
 @param textureImages 必须为UIImage数组，纹理图片（需满足：长宽相等，且宽度值为2的次幂）。若为nil，则清空原有纹理。
 @return 是否成功，若纹理加载失败返回0。
 */
- (BOOL)loadStrokeTextureImages:(NSArray *)textureImages;


@end
