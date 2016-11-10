//
//  OIMMapView.h
//  IndoorMapSDK
//
//  Created by Macro on 15/11/27.
//  Copyright © 2015年 Macro. All rights reserved.
//


/*!
 *  @header OIMMapView.h
 *
 *  @brief 室内地图相关接口
 *
 *  @author Created by Macro on 2016/04/11.
 *
 *  @since 2.0.0
 */



#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "OIMFeature.h"
#import "OIMDataManager.h"
//#import "OIMType.h"
#import "OIMStyle.h"


#import "OIMMapKit.h"
//#import "OIMMapView+Overlay.h"

@protocol OIMMapViewDelegate;

/*!
 *  @brief  室内地图
 *
 *  @remark   所有对地图界面的操作都需要在地图加载完成后进行
 *
 *  @example  //使用室内地图
 *      NSString* key = @"请输入自己的KEY";
 *      NSString* buildingId = @"请输入建筑物ID";
 *      self.imMapView = [[OIMMapView alloc]initWithFrame:self.view.bounds];
 *      self.imMapView.key = key;
 *      self.imMapView.delegate = self;
 *      self.imMapView.buildingId = buildingId;
 *      [self.view addSubview:self.imMapView];
 *
 *  @since 2.0.0
 */
@interface OIMMapView : UIView

#pragma mark

/*!
 *  @brief  获取主版本号
 *
 *  @return 室内地图SDK当前的主版本号
 *
 *  @since 2.0.0
 */
+(NSString*)getVersion;

/*!
 *  @brief  获取次版本号
 *
 *  @return 室内地图SDK当前的次版本号
 *
 *  @since 2.0.0
 */
+(NSString*)getSubVersion;

/*!
 *  @brief  LBS开发者KEY
 *
 *  @remark KEY的获取请到 http://lbs.amap.com 申请
 *      如果KEY设置错误，将无法访问LBS服务器下载室内地图数据
 *      请从LBS官网申请KEY，并在程序中使用正确的KEY
 *      <a href="http://lbs.amap.com/dev/key/"> http://lbs.amap.com/dev/key/</a>
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* key;

/*!
 *  @brief  资源文件的路径
 *
 *  @remark 默认使用IndoorMapSDK.bundle中的资源文件（注意配置项目时要添加）
 *      修改该路径使用自定义资源文件请谨慎使用
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* resourcePath;

/*!
 *  @brief  地图事件
 *
 *  @since 2.0.0
 */
@property(nonatomic, weak)id<OIMMapViewDelegate> delegate;


#pragma mark

/*!
 *  @brief  室内地图数据管理对象
 *
 *  @remark 可以用这个数据管理对象获取楼层列表、搜索等
 *      不建议同时使用这个对象下载数据，这样会影响地图的显示
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)OIMDataManager* dataManager;

/*!
 *  @brief  当前显示的建筑物Id
 *
 *  @remark 请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *      设置当前建筑物是异步操作，也就是说设置完成后立即获取，可能不是刚刚设置的新值
 *      设置也有可能失败，失败后当前建筑物Id仍保持设置之前的值，在 OIMMapView 中使用会有相关事件
 *
 *  @example  //当前建筑物
 *      NSString* buildingId = self.imMapView.buildingId;
 *      buildingId = @"请输入建筑物ID";
 *      self.imMapView.buildingId = buildingId;
 *      //赋值后立即判断(如[self.imMapView.buildingId isEqualToString:buildingId])，结果可能为NO
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* buildingId;

/*!
 *  @brief  当前显示的楼层
 *
 *  @remark 设置当前楼层同样是异步操作，也有可能失败，在 OIMMapView 中使用会有相关事件
 *      设置floorNo为0，会加载当前建筑物的默认楼层，设置成功后floorNo不等于0
 *
 *  @example  //当前楼层
 *      int floorNo = self.imMapView.floorNo;
 *      floorNo = 2;
 *      self.imMapView.floorNo = floorNo;
 *
 *  @since 2.0.0
 */
@property(nonatomic)int floorNo;


/*!
 *  @brief  获取当前建筑物所有楼层的列表
 *
 *  @return 当前建筑物所有楼层的列表
 *
 *  @remark 返回的是 OIMFloor 对象数组
 *
 *  @example  //获取楼层列表
 *      NSArray* floorList = [self.imMapView getFloorList];
 *      for(OIMFloor* floor in floorList)
 *      {
 *          int floorNo = floor.floorNo;
 *      }
 *
 *  @since 2.0.0
 */
-(NSArray*)getFloorList;

/*!
 *  @brief  设置当前建筑物及楼层
 *
 *  @param buildingId 建筑物Id
 *  @param floorNo    楼层
 *
 *  @remark 请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *      该接口同时设置建筑物和楼层，[self.imMapView setBuildingId:@"请输入建筑物ID" floorNo:n];
 *      与self.imMapView.buildingId = @"请输入建筑物ID";self.imMapView.floorNo = n;
 *      不完全等价，前者直接加载，后者先加载建筑物的默认楼层，再切换到指定楼层，除非n即是默认楼层
 *
 *  @example  //当前建筑物
 *      NSString* buildingId = @"请输入建筑物ID";
 *      int floorNo = 2;
 *      [self.imMapView setBuildingId:buildingId floorNo:floorNo];  //直接加载floorNo这一层
 *      //与下面的代码不完全等价
 *      self.imMapView.buildingId = buildingId; //这一步会加载默认楼层
 *      self.imMapView.floorNo = floorNo;   //如果默认楼层不是floorNo，再切换到floorNo这一层
 *
 *  @since 2.0.0
 */
-(void)setBuildingId:(NSString *)buildingId floorNo:(int)floorNo;


#pragma mark

/*!
 *  @brief  显示路算结果开关
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL showRoutePlanning;

/*!
 *  @brief  设置当前路算结果
 *
 *  @param feature 路算结果（设置空nil的路算结果会清除地图上已经显示的路算）
 *
 *  @return IMOK  设置成功
 *          IMERR 设置失败
 *
 *  @since 2.0.0
 */
-(int)setRoutePlanning:(OIMFeature*)feature;

/*!
 *  @brief  显示当前定位点开关
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL showLocationPoint;

/*!
 *  @brief  设置当前定位点
 *
 *  @param point       定位点坐标，包括经纬度和楼层
 *  @param orientation 定位的方向
 *  @param accuracy    定位的精度
 *
 *  @return IMOK  设置成功
 *          IMERR 设置失败
 *
 *  @since 2.0.0
 */
-(int)setLocationPoint:(OIMPoint)point orientation:(float)orientation accuracy:(float)accuracy;

/*!
 *  @brief  当前的跟随模式
 *
 *  @remark   当前有3种模式
 *      OIMFollowingMode_DontFollow 地图不跟随模式，默认方式，显示动画
 *      OIMFollowingMode_FollowLocation 地图位置跟随模式，根据定位点的位置移动地图
 *      OIMFollowingMode_FollowLocationAndDirection 地图位置和方向跟随模式，根据定位点的位置移动地图，同时根据定位给出的方向旋转地图
 *
 *  @since 2.0.0
 */
@property(nonatomic)int followingMode;

/*!
 *  @brief  显示比例尺的开关
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL showPlottingScale;

/*!
 *  @brief  显示指南针的开关
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL showCompass;

/*!
 *  @brief  显示楼层控件的开关
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL showFloorList;

/*!
 *  @brief  显示缩放控件的开关
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL showZoomControl;


#pragma mark

/*!
 *  @brief  允许移动手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableTranslate;

/*!
 *  @brief  允许缩放手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableScale;

/*!
 *  @brief  允许旋转手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableRotate;

/*!
 *  @brief  允许倾斜手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableIncline;

/*!
 *  @brief  允许点击手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableClick;

/*!
 *  @brief  允许双击手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableDoubleClick;

/*!
 *  @brief  允许长按手势的开关
 *
 *  @value  YES 允许
 *          NO  不允许
 *
 *  @since 2.0.0
 */
@property(nonatomic)BOOL enableLongPress;


#pragma mark

/*!
 *  @brief  放大
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)zoomIn;

/*!
 *  @brief  缩小
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)zoomOut;

/*!
 *  @brief  移动地图
 *
 *  @param x X轴方向的相对移动距离（单位像素），正值向右，负值向左
 *  @param y Y轴方向的相对移动距离（单位像素），正值向上，负值向下
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)updateTranslation:(float)x y:(float)y;

/*!
 *  @brief  旋转地图
 *
 *  @param radian 旋转的角度（单位度[-180,180]，正值逆时针，负值顺时针）
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)updateRotation:(float)radian;

/*!
 *  @brief  缩放地图
 *
 *  @param scale 缩放的倍数（大于1放大，小于1缩小）
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)updateScale:(float)scale;

/*!
 *  @brief  倾斜地图
 *
 *  @param incline 倾斜的角度
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @remark   单位：度（[-60,60]），正值前倾，负值后仰
 *
 *  @since 2.0.0
 */
-(int)updateIncline:(float)incline;

/*!
 *  @brief  重置地图
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @remark   地图的位置、旋转、缩放、倾斜等都重置为加载的默认状态
 *    等价于 translation={0,0}, rotation=0, scale=1, incline=0
 *
 *  @since 2.0.0
 */
-(int)resetMap;

/*!
 *  @brief  重置地图位置
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @remark   地图的中心点回到View的中心点，其它如旋转、缩放、倾斜都不变
 *    等价于 translation={0,0}
 *
 *  @since 2.0.0
 */
-(int)resetMapCenter;

/*!
 *  @brief  重置地图方向
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @remark   旋转和倾斜回到初始状态，其它如旋转、移动都不变
 *    等价于 rotation=0, incline=0
 *
 *  @since 2.0.0
 */
-(int)resetMapDirection;

/*!
 *  @brief  移动地图上的一点到View的中心
 *
 *  @param longitude 地图经度
 *  @param latitude 地图纬度
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)setCoordinateCenter:(double)longitude latitude:(double)latitude;

/*!
 *  @brief  移动指定POI的中心点到View的中心
 *
 *  @param feature 指定的POI
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)setFeatureCenter:(OIMFeature*)feature;

/*!
 *  @brief  把指定的POI按合适的缩放比例显示到View中
 *
 *  @param features 指定的POI列表
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)setFeaturesCenter:(NSArray*)features;

/*!
 *  @brief  地图的旋转角度
 *
 *  @remark   单位：度（[-180,180]），初始值为0（正北方向）
 *
 *  @since 2.0.0
 */
@property(nonatomic, getter=getRotation, setter=setRotation:)float rotation;

/*!
 *  @brief  地图的偏移量
 *
 *  @remark   x,y的单位是像素，初始值为(0,0)（建筑物中心与View的中心重合）
 *
 *  @since 2.0.0
 */
@property(nonatomic, getter=getTranslation, setter=setTranslation:)CGPoint translation;

/*!
 *  @brief  地图的缩放倍数
 *
 *  @remark   最初适配View大小时的缩放倍数是1
 *
 *  @since 2.0.0
 */
@property(nonatomic, getter=getScale, setter=setScale:)float scale;

/*!
 *  @brief  地图的倾斜角度
 *
 *  @remark   单位：度（[-60,0]），初始值为0，不倾斜
 *
 *  @since 2.0.0
 */
@property(nonatomic, getter=getIncline, setter=setIncline:)float incline;

/*!
 *  @brief  当前地图的比例
 *
 *  @remark   每个屏幕像素对应的实际地图距离，单位米/像素
 *      不同大小的建筑物在打开时的默认比例是不同的
 *
 *  @since 2.0.0
 */
@property(nonatomic, getter=getScaleUnit, setter=setScaleUnit:)float scaleUnit;

/*!
 *  @brief  最小的地图比例
 *
 *  @remark   地图缩小到最小时的地图比例
 *
 *  @since 2.0.0
 */
@property(nonatomic, readonly, getter=getMinScaleUnit)float minScaleUnit;

/*!
 *  @brief  最大的地图比例
 *
 *  @remark   地图放大到最大时的地图比例
 *      当前版本的最大地图比例是0.004米/像素
 *
 *  @since 2.0.0
 */
@property(nonatomic, readonly, getter=getMaxScaleUnit)float maxScaleUnit;


#pragma mark


/*!
 *  @brief  设置地图上POI的显示状态
 *
 *  @param feature 指定的POI
 *  @param status  显示状态（高亮、蓝色气泡、红色气泡、路算起点、路算终点）
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)setFeature:(OIMFeature*)feature status:(OIMFeatureStatus)status;

/*!
 *  @brief  设置地图上POI的显示状态
 *
 *  @param featureList 指定的POI列表
 *  @param status      显示状态（高亮、蓝色气泡、红色气泡、路算起点、路算终点）
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.0.0
 */
-(int)setFeatures:(NSArray *)featureList status:(OIMFeatureStatus)status;

/*!
 *  @brief  清除显示状态
 *
 *  @param status 要清除的显示状态
 *
 *  @remark   显示的状态包括：高亮、蓝色气泡、红色气泡、路算起点、路算终点
 *      该接口清除所有POI的指定状态（暂不支持清除指定POI的指定状态）
 *
 *  @since 2.0.0
 */
-(void)clearStatus:(OIMFeatureStatus)status;


/*!
 *  @brief  设置对象高亮显示
 *
 *  @param feature   指定的POI对象
 *  @param highlight 是否高亮显示
 *
 *  @return IMOK  成功
 *          IMERR 失败
 *
 *  @since 2.1.0
 */
-(int)setFeature:(OIMFeature *)feature highlight:(BOOL)highlight;



/*!
 *  @brief  显示外延数据
 *
 *  @value  YES 显示
 *          NO  不显示
 *
 *  @since 2.1.0
 */
@property(nonatomic)BOOL showExtension;

/*!
 *  @brief  加载外延数据
 *
 *  @param extensionData 外延数据
 *
 *  @return IMOK    成功
 *          IMERR   失败
 *
 *  @since 2.1.0
 */
-(int)loadExtensionData:(NSData*)extensionData;


/*!
 *  @brief  设置POI不同级别的样式
 *
 *  @param poiid POI的唯一标识
 *  @param style 样式
 *
 *  @return IMOK    成功
 *          IMERR   失败
 *
 *  @remark 相同级别的样式会被覆盖，不同级别的样式会被保留
 *
 *  @since 2.1.0
 */
-(int)setStyleById:(NSString*)poiid style:(OIMStyle*)style;

/*!
 *  @brief  设置分类不同级别的样式
 *
 *  @param category 分类代码
 *  @param style    样式
 *
 *  @return IMOK    成功
 *          IMERR   失败
 *
 *  @remark 相同级别的样式会被覆盖，不同级别的样式会被保留
 *
 *  @since 2.1.0
 */
-(int)setStyleByCategory:(int)category style:(OIMStyle*)style;

/*!
 *  @brief  批量设置POI或分类的样式
 *
 *  @param styleMap 样式表
 *
 *  @return IMOK    成功
 *          IMERR   失败
 *
 *  @remark 对分类样式，NSDictionary的key是NSNumber类型，
 *          对POI样式，NSDictionary的key是NSString类型
 *          只有一个级别的样式，NSDictionary的value是OIMStyle类型
 *          同一个分类或POI的多个不同级别样式可以放到一个数组里，NSDictionary的value是NSArray类型
 *
 *  @since 2.1.0
 */
-(int)setStyleMap:(NSDictionary*)styleMap;

/*!
 *  @brief  地理坐标转换成屏幕坐标
 *
 *  @param coordinate 地理坐标（经纬度）
 *
 *  @return 屏幕坐标
 *
 *  @since 2.2.0
 */
-(CGPoint)convertCoordinate:(CGPoint)coordinate;


@end

/*!
 *  @brief  地图事件
 *
 *  @since 2.0.0
 */
@protocol OIMMapViewDelegate <NSObject>

@optional

/*!
 *  @brief  开始加载地图
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 将要加载的建筑物Id
 *  @param floorNo    将要加载的楼层
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willStartLoadingMap:(NSString*)buildingId floorNo:(int)floorNo;

/*!
 *  @brief  地图加载完成
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 加载完成的建筑物Id
 *  @param floorNo    加载完成的楼层
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didFinishLoadingMap:(NSString*)buildingId floorNo:(int)floorNo;

/*!
 *  @brief  地图加载失败
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 加载失败的建筑物Id
 *  @param floorNo    加载失败的楼层
 *  @param error      加载失败的错误信息
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didFailLoadingMap:(NSString*)buildingId floorNo:(int)floorNo withError:(NSError *)error;

/*!
 *  @brief  开始加载楼层
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 将要加载的建筑物Id
 *  @param floorNo    将要加载的楼层
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willStartLoadingFloor:(NSString*)buildingId floorNo:(int)floorNo;

/*!
 *  @brief  楼层加载完成
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 加载完成的建筑物Id
 *  @param floorNo    加载完成的楼层
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didFinishLoadingFloor:(NSString*)buildingId floorNo:(int)floorNo;

/*!
 *  @brief  楼层加载失败
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 加载失败的建筑物Id
 *  @param floorNo    加载失败的楼层
 *  @param error      加载失败的错误信息
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didFailLoadingFloor:(NSString*)buildingId floorNo:(int)floorNo withError:(NSError *)error;

/*!
 *  @brief  地图开始渲染
 *
 *  @param mapView    室内地图对象
 *  @param buildingId 将要渲染的建筑物Id
 *  @param floorNo    将要渲染的楼层
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willStartRenderingMap:(NSString*)buildingId floorNo:(int)floorNo;

/*!
 *  @brief  地图渲染完成
 *
 *  @param mapView       室内地图对象
 *  @param buildingId    渲染的建筑物Id
 *  @param floorNo       渲染的楼层
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didFinishRenderingMap:(NSString*)buildingId floorNo:(int)floorNo;

/*!
 *  @brief  开始移动地图
 *
 *  @param mapView 室内地图对象
 *  @param x       X轴位移
 *  @param y       Y轴位移
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willTranslate:(float)x y:(float)y;

/*!
 *  @brief  地图移动完成
 *
 *  @param mapView 室内地图对象
 *  @param x       X轴位移
 *  @param y       Y轴位移
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didTranslate:(float)x y:(float)y;

/*!
 *  @brief  开始地图缩放
 *
 *  @param mapView 室内地图对象
 *  @param scale   缩放倍数
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willScale:(float)scale;

/*!
 *  @brief  地图缩放完成
 *
 *  @param mapView 室内地图对象
 *  @param scale   缩放倍数
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didScale:(float)scale;

/*!
 *  @brief  开始地图旋转
 *
 *  @param mapView  室内地图对象
 *  @param rotation 旋转角度
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willRotate:(float)rotation;

/*!
 *  @brief  地图旋转完成
 *
 *  @param mapView  室内地图对象
 *  @param rotation 旋转角度
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didRotate:(float)rotation;

/*!
 *  @brief  开始地图倾斜
 *
 *  @param mapView 室内地图对象
 *  @param incline 倾斜角度
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willIncline:(float)incline;

/*!
 *  @brief  地图倾斜完成
 *
 *  @param mapView 室内地图对象
 *  @param incline 倾斜角度
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didIncline:(float)incline;

/*!
 *  @brief  开始点击地图
 *
 *  @param mapView 室内地图对象
 *  @param longitude 点击的经度
 *  @param latitude  点击的纬度
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willClickFeature:(double)longitude latitude:(double)latitude;

/*!
 *  @brief  点击地图完成
 *
 *  @param mapView 室内地图对象
 *  @param feature 点击的POI
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didClickFeature:(OIMFeature*)feature;

/*!
 *  @brief  开始长按地图
 *
 *  @param mapView 室内地图对象
 *  @param x       长按点的X轴坐标
 *  @param y       长按点的Y轴坐标
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView willLongPressFeature:(float)x y:(float)y;

/*!
 *  @brief  长按地图完成
 *
 *  @param mapView 室内地图对象
 *  @param feature 长按的POI
 *
 *  @since 2.0.0
 */
-(void)mapView:(OIMMapView*)mapView didLongPressFeature:(OIMFeature*)feature;



@optional

/*!
 *  @brief  根据anntation生成对应的View
 *
 *  @param mapView    室内地图对象
 *  @param annotation 指定的标注
 *
 *  @return 生成的标注View
 *
 *  @since 2.1.0
 */
- (OIMAnnotationView *)mapView:(OIMMapView *)mapView viewForAnnotation:(id<OIMAnnotation>)annotation;

/*!
 *  @brief  当选中一个annotation views时，调用此接口
 *
 *  @param mapView 室内地图对象
 *  @param view    选中的annotation view
 *
 *  @since 2.1.0
 */
- (void)mapView:(OIMMapView *)mapView didSelectAnnotationView:(OIMAnnotationView *)view;


/*!
 *  @brief  根据overlay生成对应的Renderer
 *
 *  @param mapView 室内地图对象
 *  @param overlay 指定的overlay
 *
 *  @return 生成的覆盖物Renderer
 *
 *  @since 2.1.0
 */
- (OIMOverlayRenderer *)mapView:(OIMMapView *)mapView rendererForOverlay:(OIMOverlay*)overlay;






@end

