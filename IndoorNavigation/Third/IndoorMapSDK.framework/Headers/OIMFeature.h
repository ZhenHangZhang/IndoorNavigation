//
//  OIMFeature.h
//  IndoorMapSDK
//
//  Created by Macro on 15/11/30.
//  Copyright © 2015年 Macro. All rights reserved.
//



/*!
 *  @header OIMFeature.h
 *
 *  @brief 室内POI数据结构定义
 *
 *  @author Created by Macro on 2016/04/11.
 *
 *  @since 2.0.0
 */


#import <Foundation/Foundation.h>
#import "OIMType.h"


/*!
 *  @brief  室内通用数据结构
 *
 *  @since 2.0.0
 */
@interface OIMFeature : NSObject

/*!
 *  @brief  数据标识
 *
 *  @remark 文档中的buildingId、featureId、poiId、pid都是指高德室内地图的数据标识
 *      请在线申请建筑物数据，建筑物数据申请详情请参阅：http://lbs.amap.com/console/apply/
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* pid;

/*!
 *  @brief  名称
 *
 *  @remark 默认是中文名称，中文名称的内容里是可能有英文的
 *      对建筑物，name对应name_cn
 *      对楼层，name对应floor_nona
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* name;

/*!
 *  @brief  类型
 *
 *  @since 2.0.0
 */
@property(nonatomic)int type;

/*!
 *  @brief  Feature的高德分类
 *
 *  @since 2.0.0
 */
@property(nonatomic)int category;

/*!
 *  @brief  其它的属性
 *
 *  @remark 属性值对应的类型需要在具体使用的地方明确
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSMutableDictionary* properties;

/*!
 *  @brief  相关联的Feature列表
 *
 *  @remark 相关联的Feature列表
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSMutableArray* features;

/*!
 *  @brief  Feature的几何信息
 *
 *  @remark Feature包含的点信息，多个点是线还是面要根据Feature来判断
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSMutableArray* points;


@end


/*!
 *  @brief  楼层数据结构
 *
 *  @since 2.0.0
 */
@interface OIMFloor : OIMFeature

/*!
 *  @brief  楼层编号
 *
 *  @remark 不同于楼层，floorNo为3的楼层不一定是F3层
 *      地上的楼层用正值，地下的楼层用负值，没有floorNo为0的楼层
 *
 *  @since 2.0.0
 */
@property(nonatomic)int floorNo;

/*!
 *  @brief  楼层名称
 *
 *  @remark 不同于name，不建议用于楼层控件
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* floorName;

@end


/*!
 *  @brief  建筑物数据结构
 *
 *  @since 2.0.0
 */
@interface OIMBuilding : OIMFeature

/*!
 *  @brief  建筑物的默认楼层
 *
 *  @remark 默认楼层通常是1，但不一定是1
 *
 *  @since 2.0.0
 */
@property(nonatomic, readonly)int defaultFloorNo;

/*!
 *  @brief  建筑物的楼层数量
 *
 *  @since 2.0.0
 */
@property(nonatomic)int floorCount;

/*!
 *  @brief  建筑物的英文名称（name默认是中文名称）
 *
 *  @since 2.0.0
 */
@property(nonatomic, strong)NSString* nameEN;

@end



/*!
 *  @brief  室内POI数据结构
 *
 *  @since 2.0.0
 */
@interface OIMPoi : OIMFeature

/*!
 *  @brief  POI所属楼层
 *
 *  @since 2.0.0
 */
@property(nonatomic)int floorNo;

@end




