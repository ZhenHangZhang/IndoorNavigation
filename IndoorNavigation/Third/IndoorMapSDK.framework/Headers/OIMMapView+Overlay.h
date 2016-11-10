//
//  OIMMapView+Overlay.h
//  IndoorMapSDK
//
//  Created by Macro on 16/5/10.
//  Copyright © 2016年 Macro. All rights reserved.
//

#import <IndoorMapSDK/IndoorMapSDK.h>

//#import "OIMMapView.h"
//#import "OIMMapKit.h"


//
//typedef NS_ENUM(NSInteger, OIMUserTrackingMode)
//{
//    OIMUserTrackingModeNone              = 0,    // 不追踪用户的location更新
//    OIMUserTrackingModeFollow            = 1,    // 追踪用户的location更新
//    OIMUserTrackingModeFollowWithHeading = 2     // 追踪用户的location与heading更新
//};
//


@interface OIMMapView (Overlay)


//
///*!
// @brief logo位置, 必须在mapView.bounds之内，否则会被忽略
// */
//@property (nonatomic) CGPoint logoCenter;
//
///*!
// @brief logo的宽高
// */
//@property (nonatomic, readonly) CGSize logoSize;
//
//
//
///*!
// @brief 是否支持缩放
// */
//@property (nonatomic, getter = isZoomEnabled) BOOL zoomEnabled;
//
///*!
// @brief 是否支持平移
// */
//@property (nonatomic, getter = isScrollEnabled) BOOL scrollEnabled;
//
///*!
// @brief 是否支持旋转
// */
//@property (nonatomic, getter = isRotateEnabled) BOOL rotateEnabled;
//
///*!
// @brief 是否支持单击地图获取POI信息(默认为YES)
// 对应的回调是 - (void)mapView:(OIMMapView *)mapView didTouchPois:(NSArray *)pois
// */
//@property (nonatomic) BOOL touchPOIEnabled;
//
///*!
// @brief 设置地图旋转角度(逆时针为正向)
// */
//@property (nonatomic) CGFloat rotationDegree;
//
//
///*!
// @brief 是否支持天空模式，默认为YES. 开启后，进入天空模式后，annotation重用可视范围会缩减
// */
//@property (nonatomic, getter = isSkyModelEnabled) BOOL skyModelEnable;
//
///*!
// @brief 设置地图旋转角度(逆时针为正向)
// @param animated 动画
// @param duration 动画时间
// */
//- (void)setRotationDegree:(CGFloat)rotationDegree animated:(BOOL)animated duration:(CFTimeInterval)duration;
//
///*!
// @brief 设置地图相机角度(范围为[0.f, 60.f]，但高于40度的角度需要在16级以上才能生效)
// @param cameraDegree 角度
// */
//@property (nonatomic) CGFloat cameraDegree;
//
//- (void)setCameraDegree:(CGFloat)cameraDegree animated:(BOOL)animated duration:(CFTimeInterval)duration;
//
///*!
// @brief 是否支持camera旋转
// */
//@property (nonatomic, getter = isRotateCameraEnabled) BOOL rotateCameraEnabled;
//
///*!
// @brief 是否显示罗盘
// */
//@property (nonatomic, assign) BOOL showsCompass;
//
///*!
// @brief 罗盘原点位置
// */
//@property (nonatomic) CGPoint compassOrigin;
//
///*!
// @brief 罗盘的宽高
// */
//@property (nonatomic, readonly) CGSize compassSize;
//
///*!
// @brief 设置罗盘的图片
// */
//- (void)setCompassImage:(UIImage *)image;
//
///*!
// @brief 是否显示比例尺
// */
//@property (nonatomic) BOOL showsScale;
//
///*!
// @brief 比例尺原点位置
// */
//@property (nonatomic) CGPoint scaleOrigin;
//
///*!
// @brief 比例尺的最大宽高
// */
//@property (nonatomic, readonly) CGSize scaleSize;
//
///*!
// @brief 室内地图控件的最大宽高
// */
//@property (nonatomic, readonly) CGSize indoorMapControlSize;
//
///*!
// @brief 在当前缩放级别下, 基于地图中心点, 1 screen point 对应的距离(单位是米).
// */
//@property (nonatomic, readonly) double metersPerPointForCurrentZoom;
//
//
//
//
//
///*!
// @brief 在指定的缩放级别下, 基于地图中心点, 1 screen point 对应的距离(单位是米).
// @param zoomLevel 指定的缩放级别, 在[minZoomLevel, maxZoomLevel]范围内.
// @return 对应的距离(单位是米)
// */
//- (double)metersPerPointForZoomLevel:(CGFloat)zoomLevel;
//
///*!
// @brief 当前地图的经纬度范围，设定的该范围可能会被调整为适合地图窗口显示的范围
// */
//@property (nonatomic) OIMCoordinateRegion region;
//- (void)setRegion:(OIMCoordinateRegion)region animated:(BOOL)animated;
//
///*!
// @brief 当前地图的中心点，改变该值时，地图的比例尺级别不会发生变化
// */
//@property (nonatomic) CLLocationCoordinate2D centerCoordinate;
//- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;
//
///*!
// @brief 设置地图状态
// @param animated 是否动画
// @param duration 动画时间 默认动画时间为0.35s
// */
//- (void)setMapStatus:(OIMMapStatus *)status
//            animated:(BOOL)animated;
//
//- (void)setMapStatus:(OIMMapStatus *)status
//            animated:(BOOL)animated
//            duration:(CFTimeInterval)duration;
//
//- (OIMMapStatus *)getMapStatus;
//
///*!
// @brief 根据当前地图视图frame的大小调整region范围
// @param region 要调整的经纬度范围
// @return 调整后的经纬度范围
// */
//- (OIMCoordinateRegion)regionThatFits:(OIMCoordinateRegion)region;
//
///*!
// @brief 可见区域
// */
//@property (nonatomic) OIMMapRect visibleMapRect;
//- (void)setVisibleMapRect:(OIMMapRect)mapRect animated:(BOOL)animated;
//
///*!
// @brief 缩放级别
// */
//@property (nonatomic) CGFloat zoomLevel;
//- (void)setZoomLevel:(CGFloat)zoomLevel animated:(BOOL)animated;
//
///*!
// @brief 根据指定的枢纽点来缩放地图
// @param zoomLevel 缩放级别
// @param pivot 枢纽点(基于地图view的坐标系)
// @param animated 是否动画
// */
//- (void)setZoomLevel:(CGFloat)zoomLevel atPivot:(CGPoint)pivot animated:(BOOL)animated;
//
///*!
// @brief 最小缩放级别
// */
//@property (nonatomic, readonly) CGFloat minZoomLevel;
//
///*!
// @brief 最大缩放级别
// */
//@property (nonatomic, readonly) CGFloat maxZoomLevel;
//
///*!
// @brief 调整投影矩形比例
// @param mapRect 要调整的投影矩形
// @return 调整后的投影矩形
// */
//- (OIMMapRect)mapRectThatFits:(OIMMapRect)mapRect;
//
///*!
// @brief 根据当前地图视图frame的大小调整投影范围
// @param mapRect 要调整的投影范围
// @return 调整后的投影范围
// */
//- (void)setVisibleMapRect:(OIMMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animate;
//
///*!
// @brief 根据嵌入数据来调整投影矩形比例
// @param mapRect 要调整的投影矩形
// @param insets 嵌入数据
// @return 调整后的投影矩形
// */
//- (OIMMapRect)mapRectThatFits:(OIMMapRect)mapRect edgePadding:(UIEdgeInsets)insets;
//
///*!
// @brief 将经纬度转换为指定view坐标系的坐标
// @param coordinate 经纬度
// @param view 指定的view
// @return 基于指定view坐标系的坐标
// */
//- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView *)view;
//
///*!
// @brief 将指定view坐标系的坐标转换为经纬度
// @param point 指定view坐标系的坐标
// @param view 指定的view
// @return 经纬度
// */
//- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView *)view;
//
///*!
// @brief 将经纬度region转换为指定view坐标系的rect
// @param region 经纬度region
// @param view 指定的view
// @return 指定view坐标系的rect
// */
//- (CGRect)convertRegion:(OIMCoordinateRegion)region toRectToView:(UIView *)view;
//
///*!
// @brief 将指定view坐标系的rect转换为经纬度region
// @param rect 指定view坐标系的rect
// @param view 指定的view
// @return 经纬度region
// */
//- (OIMCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView *)view;
//
//
//
//
///*!
// @brief 是否显示用户位置
// */
//@property (nonatomic) BOOL showsUserLocation;
//
///*!
// @brief 当前的位置数据
// */
//@property (nonatomic, readonly) OIMUserLocation *userLocation;
//
///*!
// @brief 是否自定义用户位置精度圈(userLocationAccuracyCircle)对应的 view, 默认为 NO.
// 如果为YES: 会调用 - (OIMOverlayRenderer *)mapView:(OIMMapView *)mapView rendererForOverlay:(OIMOverlay*)overlay 若返回nil, 则不加载.
// 如果为NO : 会使用默认的样式.
// */
//@property (nonatomic) BOOL customizeUserLocationAccuracyCircleRepresentation;
//
///*!
// @brief 用户位置精度圈 对应的overlay.
// */
//@property (nonatomic, readonly) OIMCircle *userLocationAccuracyCircle;
//
///*!
// @brief 定位用户位置的模式
// */
//@property (nonatomic) OIMUserTrackingMode userTrackingMode;
//- (void)setUserTrackingMode:(OIMUserTrackingMode)mode animated:(BOOL)animated;
//
///*!
// @brief 当前位置再地图中是否可见
// */
//@property (nonatomic, readonly, getter=isUserLocationVisible) BOOL userLocationVisible;
//
//





/*!
 @brief 向地图窗口添加标注，需要实现OIMMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 @param annotation 要添加的标注
 */
- (void)addAnnotation:(id<OIMAnnotation>)annotation;

/*!
 @brief 向地图窗口添加一组标注，需要实现OIMMapViewDelegate的-mapView:viewForAnnotation:函数来生成标注对应的View
 @param annotations 要添加的标注数组
 */
- (void)addAnnotations:(NSArray *)annotations;

/*!
 @brief 移除标注
 @param annotation 要移除的标注
 */
- (void)removeAnnotation:(id<OIMAnnotation>)annotation;

/*!
 @brief 移除一组标注
 @param annotation 要移除的标注数组
 */
- (void)removeAnnotations:(NSArray *)annotations;

/*!
 @brief 标注数组
 */
@property (nonatomic, readonly) NSArray *annotations;

///*!
// @brief 获取指定投影矩形范围内的标注
// @param mapRect 投影矩形范围
// @return 标注集合
// */
//- (NSSet *)annotationsInMapRect:(OIMMapRect)mapRect;

/*!
 @brief 根据标注数据获取标注view
 @param annotation 标注数据
 @return 对应的标注view
 */
- (OIMAnnotationView *)viewForAnnotation:(id<OIMAnnotation>)annotation;

///*!
// @brief 从复用内存池中获取制定复用标识的annotation view
// @param identifier 复用标识
// @return annotation view
// */
//- (OIMAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

/*!
 @brief 选中标注数据对应的view
 @param annotation 标注数据
 @param animated 是否有动画效果
 */
- (void)selectAnnotation:(id<OIMAnnotation>)annotation animated:(BOOL)animated;

/*!
 @brief 取消选中标注数据对应的view
 @param annotation 标注数据
 @param animated 是否有动画效果
 */
- (void)deselectAnnotation:(id<OIMAnnotation>)annotation animated:(BOOL)animated;

/*!
 @brief 处于选中状态的标注数据数据(其count == 0 或 1)
 */
@property (nonatomic, copy) NSArray *selectedAnnotations;

///*!
// @brief annotation 可见区域
// */
//@property (nonatomic, readonly) CGRect annotationVisibleRect;

/*!
 设置地图使其可以显示数组中所有的annotation, 如果数组中只有一个则直接设置地图中心为annotation的位置。
 @param annotations 需要显示的annotation
 @param animated    是否执行动画
 */
- (void)showAnnotations:(NSArray *)annotations animated:(BOOL)animated;

///**
// *  设置地图使其可以显示数组中所有的annotation, 如果数组中只有一个则直接设置地图中心为annotation的位置。
// *
// *  @param annotations 需要显示的annotation
// *  @param insets      insets 嵌入边界
// *  @param animated    是否执行动画
// */
//- (void)showAnnotations:(NSArray *)annotations edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;















@end






///*!
// @brief 绘制overlay的层级
// */
//typedef NS_ENUM(NSInteger, OIMOverlayLevel) {
//    OIMOverlayLevelAboveRoads = 0, // 在地图底图标注和兴趣点图标之下绘制overlay
//    OIMOverlayLevelAboveLabels // 在地图底图标注和兴趣点图标之上绘制overlay
//};

/*!
 @brief 地图view关于overlay类别
 */
@interface OIMMapView (OverlaysAPI)

/*!
 @brief Overlay数组
 */
@property (nonatomic, readonly) NSArray *overlays;

///*!
// @brief 取位于level下的overlays
// */
//- (NSArray *)overlaysInLevel:(OIMOverlayLevel)level;

/*!
 @brief 向地图窗口添加Overlay。
 需要实现OIMMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer。
 默认添加层级：OIMGroundOverlay默认层级为OIMOverlayLevelAboveRoads，其余overlay类型默认层级为OIMOverlayLevelAboveLabels
 @param overlay 要添加的overlay
 */
- (void)addOverlay:(OIMOverlay *)overlay;

/*!
 @brief 向地图窗口添加一组Overlay，需要实现OIMMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer
 默认添加层级：OIMOverlayLevelAboveLabels

 @param overlays 要添加的overlay数组
 */
- (void)addOverlays:(NSArray *)overlays;

///*!
// @brief 向地图窗口添加Overlay，需要实现OIMMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer
// @param overlay 要添加的overlay
// @param level 添加的overlay所在层级
// */
//- (void)addOverlay:(OIMOverlay*)overlay level:(OIMOverlayLevel)level;
//
///*!
// @brief 向地图窗口添加一组Overlay，需要实现OIMMapViewDelegate的-mapView:rendererForOverlay:函数来生成标注对应的Renderer
// @param overlays 要添加的overlay数组
// @param level 添加的overlay所在层级
// */
//- (void)addOverlays:(NSArray *)overlays level:(OIMOverlayLevel)level;

/*!
 @brief 移除Overlay
 @param overlay 要移除的overlay
 */
- (void)removeOverlay:(OIMOverlay*)overlay;

/*!
 @brief 移除一组Overlay
 @param overlays 要移除的overlay数组
 */
- (void)removeOverlays:(NSArray *)overlays;

///*!
// @brief 在指定层级的指定的索引处添加一个Overlay
// @param overlay 要添加的overlay
// @param index 指定的索引
// @param level 指定的层级
//
// 注：各个层级的索引分开计数；
// 若index大于level层级的最大索引，则添加至level层级的最大索引之后。
// */
//- (void)insertOverlay:(OIMOverlay*)overlay atIndex:(NSUInteger)index level:(OIMOverlayLevel)level;
//
///*!
// @brief 在指定的Overlay之上插入一个overlay
// @param overlay 带添加的Overlay
// @param sibling 用于指定相对位置的Overlay
// */
//- (void)insertOverlay:(OIMOverlay*)overlay aboveOverlay:(OIMOverlay*)sibling;
//
///*!
// @brief 在指定的Overlay之下插入一个overlay
// @param overlay 带添加的Overlay
// @param sibling 用于指定相对位置的Overlay
// */
//- (void)insertOverlay:(OIMOverlay*)overlay belowOverlay:(OIMOverlay*)sibling;
//
///*!
// @brief 在指定的索引处添加一个Overlay
// @param overlay 要添加的overlay
// @param index 指定的索引
// */
//- (void)insertOverlay:(OIMOverlay*)overlay atIndex:(NSUInteger)index;
//
///*!
// @brief 交换指定索引处的Overlay
// @param index1 索引1
// @param index2 索引2
// */
//- (void)exchangeOverlayAtIndex:(NSUInteger)index1 withOverlayAtIndex:(NSUInteger)index2;
//
///*!
// @brief 交换两个overlay
// @param overlay1
// @param overlay2
// */
//- (void)exchangeOverlay:(OIMOverlay*)overlay1 withOverlay:(OIMOverlay*)overlay2;

/*!
 @brief 查找指定overlay对应的Renderer，如果该View尚未创建，返回nil
 @param overlay 指定的overlay
 @return 指定overlay对应的Renderer
 */
- (OIMOverlayRenderer *)rendererForOverlay:(OIMOverlay*)overlay;

#pragma mark - deprecated

///*!
// @brief 查找指定overlay对应的View，如果该View尚未创建，返回nil
// @param overlay 指定的overlay
// @return 指定overlay对应的View
// */
//- (OIMOverlayView *)viewForOverlay:(OIMOverlay*)overlay __attribute__ ((deprecated("use - (OIMOverlayRenderer *)mapView:(OIMMapView *)mapView rendererForOverlay:(OIMOverlay*)overlay instead")));

@end



