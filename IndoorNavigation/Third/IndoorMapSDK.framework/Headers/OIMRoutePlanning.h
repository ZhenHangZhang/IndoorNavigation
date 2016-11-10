//
//  OIMRoutePlanning.h
//  IndoorMapSDK
//
//  Created by Macro on 15/11/27.
//  Copyright © 2015年 Macro. All rights reserved.
//


/*!
 *  @header OIMRoutePlanning.h
 *
 *  @brief 室内路算相关接口
 *
 *  @author Created by Macro on 2016/04/11.
 *
 *  @since 2.0.0
 */

#import <Foundation/Foundation.h>
//#import "OIMType.h"
#import "OIMFeature.h"

@protocol OIMRoutePlanningDelegate;

/*!
 *  @brief  室内路算
 *
 *  @remark
 *
 *  @example  //发起室内路算
 *      self.imRoutePlanning = [[OIMRoutePlanning alloc]initWithDelegate:self];
 *      self.imRoutePlanning.key = key;
 *      [self.imRoutePlanning requestRoutePlanning:buildingId fromPoiId:from toPoiId:to];
 *
 *  @since 2.0.0
 */
@interface OIMRoutePlanning : NSObject

/*!
 *  @brief  LBS开发者KEY
 *
 *  @remark KEY的获取请到 http://lbs.amap.com 申请
 *      如果KEY设置错误，将无法访问LBS服务器请求室内路算
 *      请从LBS官网申请KEY，并在程序中使用正确的KEY
 *      <a href="http://lbs.amap.com/dev/key/"> http://lbs.amap.com/dev/key/</a>
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* key;

/*!
 *  @brief  初始化室内路算对象
 *
 *  @param delegate 路算事件接口 OIMRoutePlanningDelegate
 *
 *  @return 室内路算对象
 *
 *  @since 2.0.0
 */
-(instancetype)initWithDelegate:(id<OIMRoutePlanningDelegate>)delegate;

/*!
 *  @brief  室内点到点路算
 *
 *  @param buildingId 室内建筑物Id
 *  @param from       路算起点坐标
 *  @param to         路算终点坐标
 *
 *  @return IMOK  路算发起成功
 *            IMERR 路算发起失败
 *
 *  @remark 点坐标需要包括楼层和经纬度
 *      请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *
 *  @since 2.0.0
 */
-(int)requestRoutePlanning:(NSString *)buildingId fromPoint:(OIMPoint)from toPoint:(OIMPoint)to;

/*!
 *  @brief  室内点到POI路算
 *
 *  @param buildingId 室内建筑物Id
 *  @param from       路算起点坐标
 *  @param to         路算终点POIID
 *
 *  @return IMOK  路算发起成功
 *            IMERR 路算发起失败
 *
 *  @remark 点坐标需要包括楼层和经纬度
 *      请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *
 *  @since 2.0.0
 */
-(int)requestRoutePlanning:(NSString *)buildingId fromPoint:(OIMPoint)from toPoiId:(NSString*)to;

/*!
 *  @brief  室内POI到POI路算
 *
 *  @param buildingId 室内建筑物Id
 *  @param from       路算起点POIID
 *  @param to         路算终点POIID
 *
 *  @return IMOK  路算发起成功
 *            IMERR 路算发起失败
 *
 *  @remark 请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *
 *  @since 2.0.0
 */
-(int)requestRoutePlanning:(NSString *)buildingId fromPoiId:(NSString*)from toPoiId:(NSString*)to;

/*!
 *  @brief  室内POI到点路算
 *
 *  @param buildingId 室内建筑物Id
 *  @param from       路算起点POIID
 *  @param to         路算终点坐标
 *
 *  @return IMOK  路算发起成功
 *            IMERR 路算发起失败
 *
 *  @remark 点坐标需要包括楼层和经纬度
 *      请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *
 *  @since 2.0.0
 */
-(int)requestRoutePlanning:(NSString *)buildingId fromPoiId:(NSString*)from toPoint:(OIMPoint)to;

@end

/*!
 *  @brief  室内路算事件
 *
 *  @since 2.0.0
 */
@protocol OIMRoutePlanningDelegate <NSObject>

/*!
 *  @brief  路算成功事件
 *
 *  @param routePlanning 执行路算的对象
 *  @param buildingId    路算对应的室内建筑物Id
 *  @param routeFeature  路算的结果
 *
 *  @example  //显示路算结果
 *      -(void)routePlanning:(OIMRoutePlanning *)routePlanning
 *              didRoutePlanningSuccess:(NSString *)buildingId
 *              routeFeature:(OIMFeature *)routeFeature
 *      {
 *          [self.imMapView setRoutePlanning:routeFeature];
 *      }
 *
 *  @remark 路算结果中包含了从服务器返回的json字符串，可用routeFeature.properties[@"json"]获取
 *
 *  @since 2.0.0
 */
-(void)routePlanning:(OIMRoutePlanning*)routePlanning didRoutePlanningSuccess:(NSString*)buildingId routeFeature:(OIMFeature*)routeFeature;

/*!
 *  @brief  路算失败事件
 *
 *  @param routePlanning 执行路算的对象
 *  @param buildingId    路算对应的室内建筑物Id
 *  @param error         失败的相关信息
 *
 *  @since 2.0.0
 */
-(void)routePlanning:(OIMRoutePlanning*)routePlanning didRoutePlanningFailure:(NSString *)buildingId error:(NSError*)error;

@end

