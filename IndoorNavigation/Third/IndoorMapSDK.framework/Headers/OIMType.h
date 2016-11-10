//
//  OIMType.h
//  IndoorMapSDK
//
//  Created by Macro on 15/11/27.
//  Copyright © 2015年 Macro. All rights reserved.
//


#import <Foundation/Foundation.h>

/*!
 *  @header OIMType.h
 *
 *  @brief 室内地图SDK的一些基本数据定义
 *
 *  @author Created by Macro on 2016/04/08.
 *
 *  @since 2.0.0
 */



/*!
 *  @brief  室内错误码
 *
 *  @since 2.0.0
 */
typedef int OIMErrorCode;

/*!
 *  @brief  错误（没有明确指定的错误）
 *
 *  @since 2.0.0
 */
#define OIMError_Error              -1

/*!
 *  @brief  网络错误（没有明确指定的网络错误）
 *
 *  @since 2.0.0
 */
#define OIMError_NetworkError       -300

/*!
 *  @brief  网络连接错误（没有网络、网络不通、连接不上等错误）
 *
 *  @since 2.0.0
 */
#define OIMError_NetworkDisconnect  -301

/*!
 *  @brief  网络连接超时
 *
 *  @since 2.0.0
 */
#define OIMError_NetworkTimeout     -302

/*!
 *  @brief  网络返回的内容不可识别
 *
 *  @since 2.0.0
 */
#define OIMError_ContentWrong       -303

/*!
 *  @brief  访问LBS服务器失败
 *
 *  @since 2.0.0
 */
#define OIMError_LBSError           -400

/*!
 *  @brief  访问LBS服务器时使用的KEY不对
 *
 *  @remark KEY的获取请到 http://lbs.amap.com 申请
 *      请从LBS官网申请KEY，并在程序中使用正确的KEY
 *      <a href="http://lbs.amap.com/dev/key/"> http://lbs.amap.com/dev/key/</a>
 *
 *  @since 2.0.0
 */
#define OIMError_LBSErrorKey        -401

/*!
 *  @brief  加载地图样式失败
 *
 *  @remark 如果出现这个错误，请先检查项目配置，是否添加了资源文件
 *      默认的资源文件在库里，需要添加到项目中，否则地图无法加载
 *      如果资源文件中已经包含了样式文件，并且修改过样式文件，请确认修改是否正确
 *
 *  @since 2.0.0
 */
#define OIMError_StyleError         -500

/*!
 *  @brief  地图样式Json文件格式错误
 *
 *  @since 2.0.0
 */
#define OIMError_StyleErrorJson     -501

/*!
 *  @brief  无效的或不存在的楼层
 *
 *  @since 2.0.0
 */
#define OIMError_FloorNoInvalid     -511

/*!
 *  @brief  无效的路算结果
 *
 *  @since 2.0.0
 */
#define OIMError_RouteInvalid       -521

/*!
 *  @brief  数据错误
 *
 *  @since 2.1.0
 */
#define OIMError_DataError          -530

/*!
 *  @brief  数据不存在
 *
 *  @since 2.1.0
 */
#define OIMError_DataNotExist          -531


/*!
 *  @brief  正确，无错误
 *
 *  @since 2.0.0
 */
#define OIMOK                       0

/*!
 *  @brief  错误，OIMError_Error的简写
 *
 *  @since 2.0.0
 */
#define OIMERR                      OIMError_Error



/*!
 *  @brief  室内POI的状态
 *
 *  @since 2.0.0
 */
typedef int OIMFeatureStatus;

/*!
 *  @brief  默认状态，按样式正常显示POI
 *
 *  @since 2.0.0
 */
#define OIMFeatureStatus_Normal              0

/*!
 *  @brief  显示蓝色气泡
 *
 *  @since 2.0.0
 */
#define OIMFeatureStatus_Selected            2

/*!
 *  @brief  显示红色气泡
 *
 *  @since 2.0.0
 */
#define OIMFeatureStatus_Checked             4

/*!
 *  @brief  显示路算起点气泡
 *
 *  @since 2.0.0
 */
#define OIMFeatureStatus_RouteStart          8

/*!
 *  @brief  显示路算终点气泡
 *
 *  @since 2.0.0
 */
#define OIMFeatureStatus_RouteStop          16


/*!
 *  @brief  地图跟随模式
 *
 *  @since 2.0.0
 */
typedef int OIMFollowingMode;

/*!
 *  @brief  地图不跟随，默认方式，显示动画
 *
 *  @since 2.0.0
 */
#define OIMFollowingMode_DontFollow                     0

/*!
 *  @brief  地图位置跟随模式
 *
 *  @remark 根据定位点的位置移动地图
 *      移动时动画关闭
 *
 *  @since 2.0.0
 */
#define OIMFollowingMode_FollowLocation                 1

/*!
 *  @brief  地图位置和方向跟随模式
 *
 *  @remark 根据定位点的位置移动地图，同时根据定位给出的方向旋转地图
 *      移动或旋转时动画关闭
 *
 *  @since 2.0.0
 */
#define OIMFollowingMode_FollowLocationAndDirection     3


/*!
 *  @brief  三维点坐标
 *
 *  @since 2.0.0
 */
typedef union OIMPoint
{
    /*!
     *  @brief  x, y, z 三维坐标
     *
     *  @since 2.0.0
     */
    struct { double x, y, z; };

    /*!
     *  @brief  longitude, latitude, floorNo 室内三维坐标，经纬度+楼层
     *
     *  @remark floorNo实际为整数，这里是浮点数只是为了适配这个结构体
     *
     *  @since 2.0.0
     */
    struct { double longitude, latitude, floorNo; };

    /*!
     *  @brief  v[3] 数组形式的值
     *
     *  @since 2.0.0
     */
    double v[3];

}   OIMPoint;

/*!
 *  @brief  室内坐标
 *
 *  @since 2.1.0
 */
typedef OIMPoint OIMCoordinate;

/*!
 *  @brief  构造OIMPoint
 *
 *  @param x 经度
 *  @param y 纬度
 *  @param z 楼层
 *
 *  @return 室内坐标点
 *
 *  @since 2.1.0
 */
inline OIMPoint OIMPointMake(double x, double y, double z)
{
    OIMPoint p = {x, y, z};
    return p;
}

